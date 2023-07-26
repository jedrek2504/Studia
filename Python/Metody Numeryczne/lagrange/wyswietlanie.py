"""
import matplotlib.pyplot as plt
import numpy as np

from numerki.num3 import obliczanie


def wykres(x_min, x_max, a, f, x, y):
    # generowanie siatki punktów
    x_grid = np.linspace(x_min, x_max, 1000)
    y_grid = f(x_grid)

    # rysowanie wykresu
    plt.plot(x_grid, y_grid, label='funkcja')

    # dodanie węzłów interpolacji
    plt.scatter(x, y, color='red', label='węzły interpolacji')

    # rysowanie wielomianu interpolacyjnego
    P = sum(a[i] * obliczanie.interpolacja_lagrangea(x, i)(x_grid) for i in range(len(x)))
    plt.plot(x_grid, P, label='wielomian interpolacyjny')

    # ustawienie tytułu i etykiet osi
    plt.title('Interpolacja Lagrange\'a na węzłach Czebyszewa')
    plt.xlabel('x')
    plt.ylabel('y')

    # wyświetlenie legendy
    plt.legend()

    # wyświetlenie wykresu
    plt.show()
"""