import numpy as np

import wczytywanie
import obliczanie

flag = 1
eps = -1
it = 500

while flag:
    wczytywanie.wyswietlanie()
    file = int(input("Wprowadz numer wariantu, ktory ma zostac wczyatny:\n"))
    if file < 1 or file > 10:
        print("Podano niewlasciwa wartosc!\n")
        flag = 0
    stop = int(input("Wybierz warunek stopu.\n1. Epislon\n2. Iteracje\n"))
    if stop == 2:
        it = int(input("Podaj ilosc iteracji\n"))
    elif stop == 1:
        eps = float(input("Podaj epsilon\n"))
    else:
        print("Podano niewlasciwa wartosc!\n")
        flag = 0

    A = wczytywanie.loadMatrix(file)
    b = wczytywanie.addVectorB(file)

    if obliczanie.permute_rows(A, b):
        print("Spelnieniony warunek zbierznosci")
        print(obliczanie.jacobi(A, b, it, eps))
    else:
        print("Brak spelnienia warunku zbierznosci")
        flag = 0

    wybor = str(input("Czy chcesz obliczyc inna macierz T/N: \n"))
    if wybor == 'T' or wybor == 't':
        flag = True
    else:
        flag = False
