import math
import numpy as np
from matplotlib import pylab
import functions


def drawGraph(a, b, func, x0):  # x0 - punkt który trzeba narysować na wykresie
    podzialka = (b - a) / 100
    argx = np.arange(a, b + podzialka, podzialka)  # lista argumentów x #b+1 bo pokazywalo jedno mniej
    argy = []  # lista wartości
    if func == 1:
        for i in argx:
            argy.append(1 * i * i * i + 5 * i * i - 2 * i - 10)  # x^3 + 5x^2 - 2x - 10
        pylab.title('Wykres f(x) = x^3 + 5x^2 - 2x - 10')
    if func == 2:
        for i in argx:
            argy.append(3 * math.cos(0.5 * i) + 2)  # 3 * cos(0.5 * x) + 2
        pylab.title('Wykres f(x) = 3 * cos(0.5 * x) + 2')
    if func == 3:
        for i in argx:
            argy.append(2 ** i - 5)  # 2^x - 5
        pylab.title('Wykres f(x) = 2^x - 5')
    if func == 4:
        for i in argx:
            argy.append(math.e ** i - 5 * math.cos(i - 1))  # e^x - 5 * cos(x-1)
        pylab.title('Wykres f(x) = e^x - 5 * cos(x-1)')
    pylab.plot(argx, argy)
    if x0 != 'no':  # jesli x0 = no - rysujemy wykres poczatkowy wiec nie ma obliczonego x0 jeszcze
        # wartosc pktu os x
        pkty = functions.calcValAtPt(func, x0)  # wartosc pktu os y
        pylab.plot(x0, pkty, marker="o")
    pylab.grid(True)
    pylab.show()
