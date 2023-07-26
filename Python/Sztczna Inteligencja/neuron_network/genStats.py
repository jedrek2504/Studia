import os
import pickle
import json
import numpy as np
import matplotlib.pyplot as plt

from math import dist
from statistics import mean
from sklearn import metrics
from sklearn.neural_network import MLPRegressor
from prettytable import PrettyTable
from typing import Any
from openpyxl import Workbook

from lib.data import get_training_data, get_verification_data
from lib.xlsxReader import read_data_file


# Save weights to .json file
class NumpyEncoder(json.JSONEncoder):
    def default(self, o: Any) -> Any:
        if isinstance(o, np.ndarray):
            return o.tolist()
        return json.JSONEncoder.default(self, o)


output_directory = './out'

if not os.path.exists(output_directory):
    os.makedirs(output_directory)

with open('./model.pkl', 'rb') as file:
    clf: MLPRegressor = pickle.load(file)

data = read_data_file('data.pkl')

static_training, static_target = get_training_data(data)
static_read = []
for i in range(len(static_training)):
    length = len(static_training[i])
    static_read.append([static_training[i][length - 3],
                        static_training[i][length - 2]])
static_predicts = clf.predict(static_training)

dynamic_training, dynamic_target = get_verification_data(data)
dynamic_read = []
for i in range(len(dynamic_training)):
    length = len(dynamic_training[i])
    dynamic_read.append([dynamic_training[i][length - 3],
                         dynamic_training[i][length - 2]])
dynamic_predicts = clf.predict(dynamic_training)


def calc_dists(train, target):
    dists = []
    for it in range(len(train)):
        dists.append(dist(train[it], target[it]))
    return dists


def stats(train, target) -> tuple:
    r2_score = metrics.r2_score(target, train)
    mean_absolute_err = metrics.mean_absolute_error(target, train)
    mean_squared_err = metrics.mean_squared_error(target, train)
    median_absolute_err = metrics.median_absolute_error(target, train)
    mean_absolute_percentage_err = metrics.mean_absolute_percentage_error(target, train)
    avg_distance = mean(calc_dists(train, target))

    return \
        f"{round(r2_score * 100, 2)}%", \
        round(mean_absolute_err, 2), \
        round(mean_squared_err, 2), \
        round(median_absolute_err, 2), \
        f"{round(mean_absolute_percentage_err * 100, 2)}%", \
        round(avg_distance, 2)


# Create a table with stats from data.pkl
stat_table = PrettyTable([
    "dane",
    "r2_score",
    "mean_absolute_error",
    "mean_squared_error",
    "median_absolute_error",
    "mean_absolute_percentage_error",
    "avg_distance"
])
stat_table.add_row(["static_read", *stats(static_read, static_target)])
stat_table.add_row(["static_predict", *stats(static_predicts, static_target)])
stat_table.add_row(["dynamic_read", *stats(dynamic_read, dynamic_target)])
stat_table.add_row(["dynamic_predicts", *stats(dynamic_predicts, dynamic_target)])

print(stat_table)

# Save average distances to .xlsx file
book = Workbook()
sheet = book.active
distances = calc_dists(dynamic_predicts, dynamic_target)
for distance in distances:
    sheet.append([distance])
book.save(output_directory + "/error_distribution.xlsx")

static_predicts = np.rot90(static_predicts)
static_read = np.rot90(static_read)
static_target = np.rot90(static_target)

# Generate plot for static data
plt.title("Static")
plt.scatter(static_predicts[0], static_predicts[1],
            c='red', label='predicted', s=1)
plt.scatter(static_read[0], static_read[1],
            c='blue', label='read', s=1)
plt.scatter(static_target[0], static_target[1],
            c='green', label='target', s=1)
plt.legend()
plt.ylabel('y', loc='top')
plt.xlabel('x', loc="right")
plt.savefig(output_directory + "/static.png")
plt.show()

dynamic_read = np.rot90(dynamic_read)
dynamic_predicts = np.rot90(dynamic_predicts)
dynamic_target = np.rot90(dynamic_target)

# Generate plot for dynamic data
plt.title("Dynamic")
plt.scatter(dynamic_read[0], dynamic_read[1],
            c='blue', label='read', s=1)
plt.scatter(dynamic_predicts[0], dynamic_predicts[1],
            c='red', label='predicted', s=1)
plt.scatter(dynamic_target[0], dynamic_target[1],
            c='green', label='target', s=1)
plt.legend()
plt.ylabel('y', loc='top')
plt.xlabel('x', loc='right')
plt.savefig(output_directory + "/dynamic.png")
plt.show()

with open(output_directory + "/weights.json", "w") as file:
    json.dump(clf.coefs_, file, ensure_ascii=False, indent=2, cls=NumpyEncoder)
