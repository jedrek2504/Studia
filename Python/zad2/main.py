import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def wykresy():

    # wykres 1:
    plt1 = plt
    #znajduje wspolczynniki: r, a, b
    wsp_r = np.corrcoef(DlDzial_tab, SzDzial_tab)[0][1]
    wsp_a, wsp_b = np.polyfit(DlDzial_tab, SzDzial_tab, 1)
    # przypisuję wartość tytułu wykresu do zmiennej tytul oraz
    # ustawiam odpowiedni znak +/- dla współczynnika b
    if wsp_b > 0:
        tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    else:
        tytul = "r = %s; y = %sx - %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.abs(np.round(wsp_b, 1)))
    # tworzę wykres punktowy
    plt1.scatter(DlDzial_tab, SzDzial_tab)
    # nanoszę linię regresji liniowej (y = ax + b)
    plt1.plot(DlDzial_tab, wsp_a * DlDzial_tab + wsp_b, color='red')
    # ustawiam wspomniany tytuł wykresu
    plt1.title(tytul)
    # ustawiam tytuły osi wykresu z jednostkami
    plt1.xlabel('Długość działki kielicha (cm)')
    plt1.ylabel('Szerokość działki kielicha (cm)')
    plt1.show()

    # wykres 2
    plt2 = plt
    wsp_r = np.corrcoef(DlDzial_tab, DlPlatka_tab)[0][1]
    wsp_a, wsp_b = np.polyfit(DlDzial_tab, DlPlatka_tab, 1)
    if wsp_b > 0:
        tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    else:
        tytul = "r = %s; y = %sx - %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.abs(np.round(wsp_b, 1)))
    plt2.scatter(DlDzial_tab, DlPlatka_tab)
    plt2.plot(DlDzial_tab, wsp_a * DlDzial_tab + wsp_b, color='red')
    plt2.title(tytul)
    plt2.xlabel("Długość działki kielicha (cm)")
    plt2.ylabel("Długość płatka (cm)")
    plt2.show()

    # wykres 3
    plt3 = plt
    wsp_r = np.corrcoef(DlDzial_tab, SzPlatka_tab)[0][1]
    wsp_a, wsp_b = np.polyfit(DlDzial_tab, SzPlatka_tab, 1)
    if wsp_b > 0:
        tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    else:
        tytul = "r = %s; y = %sx - %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.abs(np.round(wsp_b, 1)))
    plt3.scatter(DlDzial_tab, SzPlatka_tab)
    plt3.plot(DlDzial_tab, wsp_a * DlDzial_tab + wsp_b, color='red')
    plt3.title(tytul)
    plt3.xlabel("Długość działki kielicha (cm)")
    plt3.ylabel("Szerokość płatka (cm)")
    plt3.show()

    # wykres 4
    plt4 = plt
    wsp_r = np.corrcoef(SzDzial_tab, DlPlatka_tab)[0][1]
    wsp_a, wsp_b = np.polyfit(SzDzial_tab, DlPlatka_tab, 1)
    if wsp_b > 0:
        tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    else:
        tytul = "r = %s; y = %sx - %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.abs(np.round(wsp_b, 1)))
    plt4.scatter(SzDzial_tab, DlPlatka_tab)
    plt4.plot(SzDzial_tab, wsp_a * SzDzial_tab + wsp_b, color='red')
    plt4.title(tytul)
    plt4.xlabel("Szerokość działki kielicha (cm)")
    plt4.ylabel("Długość płatka (cm)")
    plt4.show()

    # wykres 5
    plt5 = plt
    wsp_r = np.corrcoef(SzDzial_tab, SzPlatka_tab)[0][1]
    wsp_a, wsp_b = np.polyfit(SzDzial_tab, SzPlatka_tab, 1)
    if wsp_b > 0:
        tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    else:
        tytul = "r = %s; y = %sx - %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.abs(np.round(wsp_b, 1)))
    plt5.scatter(SzDzial_tab, SzPlatka_tab)
    plt5.plot(SzDzial_tab, wsp_a * SzDzial_tab + wsp_b, color='red')
    plt5.title(tytul)
    plt5.xlabel("Szerokość działki kielicha (cm)")
    plt5.ylabel("Szerokość płatka (cm)")
    plt5.show()

    # wykres 6
    plt6 = plt
    wsp_r = np.corrcoef(DlPlatka_tab, SzPlatka_tab)[0][1]
    wsp_a, wsp_b = np.polyfit(DlPlatka_tab, SzPlatka_tab, 1)
    if wsp_b > 0:
        tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    else:
        tytul = "r = %s; y = %sx - %s" % (np.round(wsp_r, 2), np.round(wsp_a, 1), np.abs(np.round(wsp_b, 1)))
    plt6.scatter(DlPlatka_tab, SzPlatka_tab)
    plt6.plot(DlPlatka_tab, wsp_a * DlPlatka_tab + wsp_b, color='red')
    plt6.title(tytul)
    plt6.xlabel("Długość płatka (cm)")
    plt6.ylabel("Szerokość płatka (cm)")
    plt6.show()


if __name__ == '__main__':
    ####################################################################################################################
    #
    # ZMIENNE POMOCNICZE:
    #
    products = ["Dlugosc dzialki kielicha", "Szerokosc dzialki kielicha", "Dlugosc platka", "Szerokosc platka",
                "Gatunek"]
    #
    # tablice zawierające wartości poszczególnych cech roślin:
    df = pd.read_csv('data.csv', header=None, names=products)
    DlDzial_tab = np.array(df['Dlugosc dzialki kielicha'].values)
    SzDzial_tab = np.array(df['Szerokosc dzialki kielicha'].values)
    DlPlatka_tab = np.array(df['Dlugosc platka'].values)
    SzPlatka_tab = np.array(df['Szerokosc platka'].values)
    #
    #
    ####################################################################################################################
    #
    # WYWOŁANIA FUNKCJI:
    wykresy()
