# SISE_2 - Sieć Neuronowa
Zadanie polega na zaimplementowaniu sieci neuronowej, która uczy się na podstawie **statycznych** danych, które są dołączone do zadania na Wikampie.

Program ma dwa pliki wykonywalne:
- `AI.py` - wczytuje dane pomiarowe oraz uczy naszą sieć neuronową
- `genStats.py` - generuje statystyki sieci neuronowej

Implementacja sieci jest stricte z pakietu `sklearn` korzystając z klasy `MLPRegressor`, przyjmujący **liczbę warstw**, **liczebność neuronów na warstwę**(?) oraz **funkcję aktywacji** (w przypadku programu jest to ReLU).
