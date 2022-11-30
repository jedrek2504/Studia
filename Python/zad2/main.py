import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def wykresy():
    plt1 = plt
    wsp_r = np.corrcoef(DlDzial_2Dtab, SzDzial_2Dtab)
    wsp_a, wsp_b = np.polyfit(DlDzial_tab, SzDzial_tab, 1)
    tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r[0][1], 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    plt1.scatter(DlDzial_2Dtab, SzDzial_2Dtab)
    plt1.plot(DlDzial_2Dtab, wsp_a * DlDzial_2Dtab + wsp_b, color='red')
    plt1.title(tytul)
    plt1.xlabel('Długość działki kielicha (cm)')
    plt1.ylabel('Szerokość działki kielicha (cm)')
    plt1.show()

    plt2 = plt
    wsp_r = np.corrcoef(DlDzial_2Dtab, DlPlatka_2Dtab)
    wsp_a, wsp_b = np.polyfit(DlDzial_tab, DlPlatka_tab, 1)
    tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r[0][1], 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    plt2.scatter(DlDzial_2Dtab, DlPlatka_2Dtab)
    plt2.plot(DlDzial_2Dtab, wsp_a * DlDzial_2Dtab + wsp_b, color='red')
    plt2.title(tytul)
    plt2.xlabel("Długość działki kielicha (cm)")
    plt2.ylabel("Długość płatka (cm)")
    plt2.show()

    plt3 = plt
    wsp_r = np.corrcoef(DlDzial_2Dtab, SzPlatka_2Dtab)
    wsp_a, wsp_b = np.polyfit(DlDzial_tab, SzPlatka_tab, 1)
    tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r[0][1], 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    plt3.scatter(DlDzial_2Dtab, SzPlatka_2Dtab)
    plt3.plot(DlDzial_2Dtab, wsp_a * DlDzial_2Dtab + wsp_b, color='red')
    plt3.title(tytul)
    plt3.xlabel("Długość działki kielicha (cm)")
    plt3.ylabel("Szerokość płatka (cm)")
    plt3.show()

    plt4 = plt
    wsp_r = np.corrcoef(SzDzial_2Dtab, DlPlatka_2Dtab)
    wsp_a, wsp_b = np.polyfit(SzDzial_tab, DlPlatka_tab, 1)
    tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r[0][1], 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    plt4.scatter(SzDzial_2Dtab, DlPlatka_2Dtab)
    plt4.plot(SzDzial_2Dtab, wsp_a * SzDzial_2Dtab + wsp_b, color='red')
    plt4.title(tytul)
    plt4.xlabel("Szerokość działki kielicha (cm)")
    plt4.ylabel("Długość płatka (cm)")
    plt4.show()

    plt5 = plt
    wsp_r = np.corrcoef(SzDzial_2Dtab, SzPlatka_2Dtab)
    wsp_a, wsp_b = np.polyfit(SzDzial_tab, SzPlatka_tab, 1)
    tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r[0][1], 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    plt5.scatter(SzDzial_2Dtab, SzPlatka_2Dtab)
    plt5.plot(SzDzial_2Dtab, wsp_a * SzDzial_2Dtab + wsp_b, color='red')
    plt5.title(tytul)
    plt5.xlabel("Szerokość działki kielicha (cm)")
    plt5.ylabel("Szerokość płatka (cm)")
    plt5.show()

    plt6 = plt
    wsp_r = np.corrcoef(DlPlatka_2Dtab, SzPlatka_2Dtab)
    wsp_a, wsp_b = np.polyfit(DlPlatka_tab, SzPlatka_tab, 1)
    tytul = "r = %s; y = %sx + %s" % (np.round(wsp_r[0][1], 2), np.round(wsp_a, 1), np.round(wsp_b, 1))
    plt6.scatter(DlPlatka_2Dtab, SzPlatka_2Dtab)
    plt6.plot(DlPlatka_2Dtab, wsp_a * DlPlatka_2Dtab + wsp_b, color='red')
    plt6.title(tytul)
    plt6.xlabel("Szerokość działki kielicha (cm)")
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
    # listy zawierające wartości poszczególnych cech roślin
    df = pd.read_csv('data.csv', header=None, names=products)
    DlDzial_tab = df['Dlugosc dzialki kielicha'].values.tolist()
    SzDzial_tab = df['Szerokosc dzialki kielicha'].values.tolist()
    DlPlatka_tab = df['Dlugosc platka'].values.tolist()
    SzPlatka_tab = df['Szerokosc platka'].values.tolist()
    #
    # tablice2d
    DlDzial_2Dtab = np.array(DlDzial_tab)
    SzDzial_2Dtab = np.array(SzDzial_tab)
    DlPlatka_2Dtab = np.array(DlPlatka_tab)
    SzPlatka_2Dtab = np.array(SzPlatka_tab)
    #
    #
    ####################################################################################################################
    wykresy()
