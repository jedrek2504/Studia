import pandas as pd
import plotly.graph_objects as go
import matplotlib.pyplot as plt
import numpy as np
from math import floor, ceil

products = ["Dlugosc dzialki kielicha", "Szerokosc dzialki kielicha", "Dlugosc platka", "Szerokosc platka", "Gatunek"]

df = pd.read_csv('data.csv', header=None, names=products)
DlDzial_tab = df['Dlugosc dzialki kielicha'].values.tolist()
SzDzial_tab = df['Szerokosc dzialki kielicha'].values.tolist()
DlPlatka_tab = df['Dlugosc platka'].values.tolist()
SzPlatka_tab = df['Szerokosc platka'].values.tolist()
Gat_tab = df['Gatunek'].values.tolist()

def sortuj(tablica):
    i = len(tablica) - 1
    while i > 0:
        if tablica[i] < tablica[i - 1]:
            temp = tablica[i]
            tablica[i] = tablica[i - 1]
            tablica[i - 1] = temp
            i = len(tablica)
        i -= 1
    return tablica


def srednia_arytm(lista):
    srednia = sum(lista) / len(lista)
    return srednia


def odchylenie_stand(lista, srednia):
    N = len(lista)
    suma = 0
    i = 0
    while i < N:
        suma += (lista[i] - srednia) * (lista[i] - srednia)
        i += 1
    var = suma / N
    odchylenie = var ** 0.5
    return odchylenie


def mediana(tablica):
    indeks = (len(tablica) - 1) / 2
    if len(tablica) % 2 == 0:
        return (tablica[floor(indeks)] + tablica[ceil(indeks)]) / 2
    else:
        return tablica[floor(indeks)]


def kwartylQ1(tablica):
    srodek = (len(tablica)) // 2
    if srodek % 2 == 0:
        return mediana(tablica[:srodek + 1])
    else:
        return mediana(tablica[:srodek])


def kwartylQ3(tablica):
    srodek = (len(tablica)) // 2
    return mediana(tablica[srodek:])


def tabelki():
    fig1 = go.Figure(data=[go.Table(header=dict(values=['Gatunek', 'Liczebność (%)']),
                                    cells=dict(values=[['setosa', 'versicolor', 'virginica', 'Razem'],
                                                       [str(setosa) + ' (' + str(LiczebnoscSetosa) + '%)',
                                                        str(versicolor) + ' (' + str(LiczebnoscVersicolor) + '%)',
                                                        str(virginica) + ' (' + str(LiczebnoscVirginica) + '%)',
                                                        str(setosa + virginica + versicolor) + ' (100%)']]))
                           ])
    fig1.show()

    fig2 = go.Figure(data=[go.Table(
        header=dict(values=['Cecha', 'Minimum', 'Śr. arytm. (±  odch. stand.)', 'Mediana (Q1 - Q3)', 'Maksimum']),
        cells=dict(values=[['Długość działki kielicha (cm)', 'Szerokość działki kielicha (cm)', 'Długość płatka (cm)',
                            'Szerokość płatka (cm)'],
                           [str(dl_dzial_kielicha_min), str(szer_dzial_kielicha_min), str(dl_platka_min),
                            str(szer_platka_min)], [str(dl_dzial_kielicha_srednia)
                                                    + ' (± ' + str(dl_dzial_kielicha_odchylenie) + ')',
                                                    str(szer_dzial_kielicha_srednia) + ' (± ' + str(
                                                        szer_dzial_kielicha_odchylenie) + ')', str(dl_platka_srednia)
                                                    + ' (± ' + str(dl_platka_odchylenie) + ')',
                                                    str(szer_platka_srednia) + ' (± ' + str(
                                                        szer_platka_odchylenie) + ')'],
                           [str(dl_dzial_kielicha_mediana) + ' (' + str(dl_dzial_kielicha_q1)
                            + ' - ' + str(dl_dzial_kielicha_q3) + ')',
                            str(szer_dzial_kielicha_mediana) + ' (' + str(szer_dzial_kielicha_q1) + ' - ' + str(
                                szer_dzial_kielicha_q3) + ')', str(dl_platka_mediana)
                            + ' (' + str(dl_platka_q1) + ' - ' + str(dl_platka_q3) + ')',
                            str(szer_platka_mediana) + ' (' + str(szer_platka_q1) + ' - ' + str(szer_platka_q3) + ')'],
                           [str(dl_dzial_kielicha_max),
                            str(szer_dzial_kielicha_max), str(dl_platka_max), str(szer_platka_max)]]))
                           ])
    fig2.show()

def histogramy():

    his1=plt
    his1.hist(DlDzial_tab, edgecolor='black')
    his1.title('Długość działki kielicha')
    his1.xlabel('Dlugość (cm)')
    his1.ylabel('Liczebność')
    his1.xticks(np.arange(4, 8.2, step=0.5))
    his1.yticks(np.arange(0, 35, step=5))
    his1.show()

    his2 = plt
    his2.hist(SzDzial_tab, color='red', edgecolor='black')
    his2.title('Szerokość działki kielicha')
    his2.xlabel('Dlugość (cm)')
    his2.ylabel('Liczebność')
    his2.xticks(np.arange(1.5, 5, step=0.5))
    his2.yticks(np.arange(0, 40, step=5))
    his2.show()

    his3 = plt
    his3.hist(DlPlatka_tab, color='green', edgecolor='black')
    his3.title('Długość płatka')
    his3.xlabel('Dlugość (cm)')
    his3.ylabel('Liczebność')
    his3.xticks(np.arange(0.5, 7.5, step=0.5))
    his3.yticks(np.arange(0, 40, step=5))
    his3.show()

    his4 = plt
    his4.hist(SzPlatka_tab, color='yellow', edgecolor='black')
    his4.title('Szerokość płatka')
    his4.xlabel('Dlugość (cm)')
    his4.ylabel('Liczebność')
    his4.xticks(np.arange(0, 3, step=0.5))
    his4.yticks(np.arange(0, 45, step=5))
    his4.show()

def pudelkowe():

    #użycie funkcji .loc pozwala na pozbycie sie z diagramu numerow - 0, 1, 2 --> 'setosa', 'versicolor', 'virginica'
    df.loc[df['Gatunek'] == 0, 'Gatunek'] = 'setosa'
    df.loc[df['Gatunek'] == 1, 'Gatunek'] = 'versicolor'
    df.loc[df['Gatunek'] == 2, 'Gatunek'] = 'virginica'

    df.boxplot(by='Gatunek', column=['Dlugosc dzialki kielicha'])
    pud1 = plt
    pud1.title('Długość działki kielicha')
    pud1.xlabel('gatunek')
    pud1.ylabel('długość')
    pud1.show()


if __name__ == "__main__":

    ####################################################################################################################
    #
    #ZMIENNE POMOCNICZE:
    #
    #ilość poszczególnych gatunków roślin
    setosa = Gat_tab.count(0)
    versicolor = Gat_tab.count(1)
    virginica = Gat_tab.count(2)

    #procentowa liczebność poszczególnych roślin
    LiczebnoscSetosa = round((setosa / len(Gat_tab)) * 100, 1)
    LiczebnoscVersicolor = round((versicolor / len(Gat_tab)) * 100, 1)
    LiczebnoscVirginica = round((virginica / len(Gat_tab)) * 100, 1)

    #minimalna / maksymalna wartość poszczególnych cech roślin
    dl_dzial_kielicha_min = round(sortuj(DlDzial_tab)[0], 2)
    dl_dzial_kielicha_max = round(sortuj(DlDzial_tab)[len(DlDzial_tab) - 1], 2)
    szer_dzial_kielicha_min = round(sortuj(SzDzial_tab)[0], 2)
    szer_dzial_kielicha_max = round(sortuj(SzDzial_tab)[len(SzDzial_tab) - 1], 2)
    dl_platka_min = round(sortuj(DlPlatka_tab)[0], 2)
    dl_platka_max = round(sortuj(DlPlatka_tab)[len(DlPlatka_tab) - 1], 2)
    szer_platka_min = round(sortuj(SzPlatka_tab)[0], 2)
    szer_platka_max = round(sortuj(SzPlatka_tab)[len(SzPlatka_tab) - 1], 2)

    #średnie wartości poszczególnych cech roślin
    dl_dzial_kielicha_srednia = round(srednia_arytm(DlDzial_tab), 2)
    szer_dzial_kielicha_srednia = round(srednia_arytm(SzDzial_tab), 2)
    dl_platka_srednia = round(srednia_arytm(DlPlatka_tab), 2)
    szer_platka_srednia = round(srednia_arytm(SzPlatka_tab), 2)

    #wartość odchylenia standardowego dla poszczególncyh cech
    dl_dzial_kielicha_odchylenie = round(float(odchylenie_stand(DlDzial_tab, dl_dzial_kielicha_srednia)), 2)
    szer_dzial_kielicha_odchylenie = round(float(odchylenie_stand(SzDzial_tab, szer_dzial_kielicha_srednia)), 2)
    dl_platka_odchylenie = round(float(odchylenie_stand(DlPlatka_tab, dl_platka_srednia)), 2)
    szer_platka_odchylenie = round(float(odchylenie_stand(SzPlatka_tab, szer_platka_srednia)), 2)

    #wartość mediany poszczególnych cech roślin
    dl_dzial_kielicha_mediana = mediana(DlDzial_tab)
    szer_dzial_kielicha_mediana = mediana(SzDzial_tab)
    dl_platka_mediana = mediana(DlPlatka_tab)
    szer_platka_mediana = mediana(SzPlatka_tab)

    #kwartyle (Q1 oraz Q3)
    dl_dzial_kielicha_q1 = kwartylQ1(DlDzial_tab)
    dl_dzial_kielicha_q3 = kwartylQ3(DlDzial_tab)
    szer_dzial_kielicha_q1 = kwartylQ1(SzDzial_tab)
    szer_dzial_kielicha_q3 = kwartylQ3(SzDzial_tab)
    dl_platka_q1 = kwartylQ1(DlPlatka_tab)
    dl_platka_q3 = kwartylQ3(DlPlatka_tab)
    szer_platka_q1 = kwartylQ1(SzPlatka_tab)
    szer_platka_q3 = kwartylQ3(SzPlatka_tab)
    #
    ####################################################################################################################
    #
    #WYWOŁANIA FUNKCJI
    #tabelki()
    #histogramy()
    pudelkowe()