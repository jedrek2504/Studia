import math
import numpy as np
from matplotlib import pyplot as plt

tab = [1, -4, 1, -2]  # tablica na fkcje 4 do hornera


def horner(coefficients, x):
    n = len(coefficients) - 1
    result = coefficients[n]
    for i in range(n - 1, -1, -1):
        result = result * x + coefficients[i]
    return result


def findValue(x, fkcja):
    if fkcja == 1:
        return 2 * x + 1
    if fkcja == 2:
        return abs(x)
    if fkcja == 3:
        return horner(tab, x)
    if fkcja == 4:
        return 0.5 * x * math.sin(x) - x * math.cos(x)
    if fkcja == 5:
        return -math.cos(x) - 2 * x


"""
Funkcja chebyshev_nodes generuje n węzłów interpolacji dla przedziału [a, b] z wykorzystaniem węzłów Czebyszewa.
nodes to lista, w której będą przechowywane wygenerowane węzły interpolacji.
W pętli for generowane są węzły zgodnie z formułą 
node = 0.5 * ((a + b) + (b - a) * math.cos((2 * k - 1) * math.pi / (2 * n))), gdzie k to numer węzła, a n to ilość węzłów.
Ostatecznie funkcja zwraca listę wygenerowanych węzłów interpolacji.
"""


def chebyshev_nodes(n, a, b):
    nodes = []
    for k in range(1, n + 1):
        node = 0.5 * ((a + b) + (b - a) * math.cos((2 * k - 1) * math.pi / (2 * n)))
        nodes.append(node)
    return nodes


def lagrange_interpolation(x, y, z):
    n = len(x)
    L = np.zeros((n, len(z)))
    for i in range(n):
        p = np.ones(len(z))
        for j in range(n):
            if i != j:
                p *= (z - x[j]) / (x[i] - x[j])
        L[i] = y[i] * p
    return np.sum(L, axis=0)


print('Dostepne funkcje:\n'
      '1) 2*x + 1\n'
      '2) |x|\n'
      '3) x^3 - 4x^2 + x - 2\n'
      '4) 0.5x*sin(x) - x*cos(x)\n'
      '5) -cos(x) - 2x\n')

fkcja = int(input("Twoj wybor: "))

rangeBegin = float(input("Podaj poczatek przedzialu interpolacji: "))
rangeEnd = float(input("Podaj koniec przedzialu interpolacji: "))
n = int(input("Podaj ilosc wezlow interpolacji: "))

X = chebyshev_nodes(n, rangeBegin, rangeEnd)
print('Wezly interpolacji: ', X)

Y = [findValue(x, fkcja) for x in X]
print('Wartosci funkcji w wezlach interpolacji: ', Y)

interpolX = np.linspace(rangeBegin, rangeEnd)
interpolY = lagrange_interpolation(X, Y, interpolX)


def wykres(fkcja):
    pierwotnax = np.arange(rangeBegin, rangeEnd, 0.01)
    pierwotnay = np.zeros(pierwotnax.size)
    for i in range(len(pierwotnax)):
        pierwotnay[i] = (findValue(pierwotnax[i], fkcja))
    plt.plot(X, Y, 'ro', label='Węzły interpolacji')
    plt.plot(interpolX, interpolY, color='black', linestyle='--', label='Funkcja interpolująca')
    plt.plot(pierwotnax, pierwotnay, color='green', linestyle='solid', label='Funkcja pierwotna')
    plt.xlim(rangeBegin, rangeEnd)
    plt.ylim(min(pierwotnay) - 1, max(pierwotnay) + 1)
    plt.title(f'Interpolacja funkcji {fkcja}')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend(['Węzły interpolacji', 'Funkcja interpolująca', 'Funkcja pierwotna'])
    plt.show()


wykres(fkcja)
