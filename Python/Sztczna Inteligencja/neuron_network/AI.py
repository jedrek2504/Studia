import pickle

from os.path import isfile, join
from os import listdir
from sklearn.neural_network import MLPRegressor

from lib.xlsxReader import smart_read
from lib.data import get_training_data, get_verification_data


F8 = [
    file for file in listdir('./pomiary/F8') if isfile(join('./pomiary/F8', file))
]
F10 = [
    file for file in listdir('./pomiary/F10') if isfile(join('./pomiary/F10', file))
]
rooms = F8 + F10
data = smart_read(rooms, "data.pkl")

static_training, static_target = get_training_data(data)
dynamic_training, dynamic_target = get_verification_data(data)

layers = 15
clf = MLPRegressor(
    solver='lbfgs', alpha=1e-4, tol=1e-5, hidden_layer_sizes=layers,
    random_state=1, max_iter=1000, verbose=True, epsilon=1e-8,
    activation='relu', batch_size=300)

clf.fit(static_training, static_target)

with open('model.pkl', 'wb') as file:
    pickle.dump(clf, file)
