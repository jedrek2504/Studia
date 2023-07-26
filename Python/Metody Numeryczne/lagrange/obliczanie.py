"""

import numpy as np


def horner_interpolation(x, a, xi):
    n = len(xi) - 1
    result = a[n]
    for i in range(n - 1, -1, -1):
        result = result * (x - xi[i]) + a[i]
    return result


def wezly_czebyszewa(x_min, x_max, n):
    """Funkcja obliczająca węzły interpolacyjne w oparciu o węzły Czebyszewa."""
    k = np.arange(1, n + 1)
    x = 0.5 * (x_min + x_max) + 0.5 * (x_max - x_min) * np.cos((2 * k - 1) * np.pi / (2 * n))
    return x


def wezly_rowne(x_min, x_max, n):
    """Generuje n równo rozmieszczonych węzłów interpolacyjnych między x_min a x_max."""
    return np.linspace(x_min, x_max, n)


def lagrange_interpolation(x, y, z):
    """Funkcja obliczająca wartości wielomianu interpolacyjnego na podstawie węzłów interpolacyjnych i wartości funkcji
    w tych punktach za pomocą wzoru Lagrange'a.

    :param x: lista zawierająca węzły interpolacyjne
    :param y: lista zawierająca wartości funkcji w węzłach interpolacyjnych
    :param z: lista punktów, dla których należy obliczyć wartości wielomianu interpolacyjnego
    :return: lista wartości wielomianu interpolacyjnego w punktach z
    """
    n = len(x)
    m = len(z)
    p = [0.0] * m
    for i in range(n):
        c = 1.0
        for j in range(n):
            if i != j:
                c *= (x[i] - x[j])
        for k in range(m):
            s = 0.0
            for j in range(n):
                if i != j:
                    s += y[j] * (z[k] - x[j]) / (x[i] - x[j])
            p[k] += s * y[i] / c
    return p


def f_liniowa(x):
    """Funkcja liniowa."""
    return 2 * x + 3


def f_modul(x):
    """Funkcja wartości bezwzględnej."""
    return abs(x)


def f_wielomian(x):
    """Funkcja wielomianowa 4 stopnia."""
    return x ** 4 - 2 * x ** 3 + 3 * x ** 2 - 4 * x


def f_trygonometryczna(x):
    return np.sin(x)


def f_zlozenie(x):
    return abs(np.sin(x))
"""