import numpy as np


def loadMatrix(file):
    matrix = np.genfromtxt('data' + str(file) + '.csv', delimiter=',', dtype="float")
    return matrix


def addVectorB(file):
    if file == 1:
        b = np.array([12., 33., 8.])
    if file == 2:
        b = np.array([1., 20., -40.])
    if file == 3:
        b = np.array([1., 20., -40.])
    if file == 4:
        b = np.array([1.5, -1.625, 1.0, 0.4375])
    if file == 5:
        b = np.array([0., -4., 4., 6.])
    if file == 6:
        b = np.array([-13., 1., 21., -5.])
    if file == 7:
        b = np.array([3., 7., 5.])
    if file == 8:
        b = np.array([3., -4., 19.])
    if file == 9:
        b = np.array([4., 11., 13.5])
    if file == 10:
        b = np.array([1.5, 0.8, 0.7])
    return b


def wyswietlanie():
    for i in range(1, 11):
        a = loadMatrix(i)
        b = addVectorB(i)
        print(f'Układ {i}')
        for i in range(a.shape[0]):
            row = ["{}*x{}".format(a[i, j], j + 1) for j in range(a.shape[1])]
            print(f'{" + ".join(row)} = {b[i]}')
        print()
