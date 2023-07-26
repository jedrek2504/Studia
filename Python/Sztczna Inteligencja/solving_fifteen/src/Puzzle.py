from collections import deque
import copy
import time
import os
from math import ceil


class Puzzle:
    def __init__(self, algo, order, fileName: str, solName: str, statsName: str, strategy, state, parent, pathCost):
        self.width = 0  # Szerokość układanki
        self.height = 0  # Wysokość układanki
        self.order = order  # Kolejność przeszukiwania sąsiedztwa (np. RDUL)
        self.values = []  # wczytane wartości układanki do rozwiązania
        self.template = []  # wczytana plansza wzorcowa (rozwiązana)
        self.moves = []  # lista ruchów wykonanych przy rozwiązywaniu układanki
        self.fileName = fileName  # nazwa pliku, z którego ma zostać wczytana układanka
        self.solName = solName  # nazwa pliku, do którego ma zostać zapisane rozwiązanie
        self.statsName = statsName  # nazwa pliku, do którego mają zostać zapisane dodatkowe informacje
        self.processedTime = 0  # długość wykonywanych obliczeń [ms]
        self.algoReturn = 0  # status wykonanego algorytmu (-1 brak rozwiązania, 1 rozwiązanie)
        self.algo = algo  # obecnie przetwarzany algorytm
        self.maxLevel = 20  # maksymalny dopuszczalny poziom rekurencji
        self.openList = []  # lista stanów już odwiedzonych
        self.processed = 0  # liczba stanów przetworzonych
        self.recursionLevel = 0
        self.readValues()
        self.readTemplate("./files/template")
        if self.algo == "bfs":
            self.fifo = deque()  # kolejka wykorzystywana przy algorytmie bfs
        elif self.algo == "dfs":
            self.prevMove = ""  # informacja o poprzednim wykonanym ruchu
        elif self.algo == "astr":
            self.strategy = strategy  # manh/hamm
            self.state = state  # aktualny układ
            self.parent = parent  # rodzic; poprzedni układ
            self.pathCost = pathCost  # koszt ruchu
            self.lastMove = order  # ostatni wykonany ruch
            self.openListLen = 0

    # wczytujemy dane z pliku .txt, przechowywane
    # są w postaci 2 wymiarowej tablicy int'ów
    @staticmethod
    def readFromFile(fileName: str):
        linesNumber = 5
        content = []
        with open(f"{fileName}", "r") as file:
            for i in range(linesNumber):
                singleLine = file.readline()
                singleLine = singleLine.translate({ord('\n'): None})
                singleLine = [int(s) for s in singleLine.split(' ')]
                content.append(singleLine)
        return content

    # wczytane dane dotyczące zadanej układanki
    # ustawiamy jako atrybuty klasy
    def readValues(self):
        content = self.readFromFile(f"{self.fileName}")
        self.width = content[0][0]
        self.height = content[0][1]
        content.pop(0)
        self.values = content

    # wczytujemy dane wzorca rozwiązania
    def readTemplate(self, templateName):
        content = self.readFromFile(templateName)
        content.pop(0)
        self.template = content

    # uniwersalna funkcja do zapisywania danych do pliku
    @staticmethod
    def saveToFile(fileName: str, content):
        file = open(f"{fileName}.txt", "w")
        file.write(content)
        file.close()

    # zapisywanie pliku z rozwiązaniem
    def saveSolution(self):
        if self.algoReturn == 1:
            moves = "".join(self.moves)
            saved = f"{len(self.moves)}\n{moves}"
        elif self.algoReturn == -1 or self.algoReturn is None:
            saved = "-1"
        if self.algo == "astr":
            param = self.strategy
        else:
            param = self.order
        filePath = os.path.splitext(self.fileName)[0]
        filePath = filePath.translate({ord('\n'): None})
        self.saveToFile(
            f"./files/solutions/{filePath}_{self.algo}_{param}_sol", saved)

    # zapisywanie pliku z dodatkowymi informacjami
    def saveStats(self):
        param = ""
        if self.algoReturn == 1:
            if self.algo != "astr":
                saved = f"{len(self.moves)}\n{len(self.openList)}\n{self.processed}\n{self.recursionLevel}\n" \
                        f"{format(self.processedTime, '.3f')}"
                param = self.order
            else:
                saved = f"{len(self.moves)}\n{self.openListLen}\n{self.processed}\n{self.recursionLevel}\n" \
                        f"{format(self.processedTime, '.3f')}"
                param = self.strategy
        elif self.algoReturn == -1 or self.algoReturn is None:
            saved = "-1"
        filePath = os.path.splitext(self.fileName)[0]
        filePath = filePath.translate({ord('\n'): None})
        self.saveToFile(
            f"./files/stats/{filePath}_{self.algo}_{param}_stats", saved)

    # sprawdzamy, czy rozwiązywana układanka
    # osiągnęła postać wzorca
    def compareArr(self, array):
        return array == self.template

    # funkcja do zamiany miejscami 2 pól tablicy 2-wymiarowej
    @staticmethod
    def switchValues(array, value1Position, value2Position):
        copyValue = array[value1Position[0]][value1Position[1]]
        array[value1Position[0]][value1Position[1]] = array[value2Position[0]][value2Position[1]]
        array[value2Position[0]][value2Position[1]] = copyValue
        return array

    # znajdujemy pozycje zera w naszej układance
    @staticmethod
    def getZero(array):
        for i in range(len(array)):
            for j in range(len(array[0])):
                if array[i][j] == 0:
                    return [i, j]

    # sprawdzamy, czy możemy wykonać ruch do góry
    # oraz w poniższych funkcjach odpowiednio w
    # pozostałych kierunkach
    def checkUp(self, array):
        if self.getZero(array)[0] > 0:
            return True
        else:
            return False

    def checkDown(self, array):
        if self.getZero(array)[0] < 3:
            return True
        else:
            return False

    def checkLeft(self, array):
        if self.getZero(array)[1] > 0:
            return True
        else:
            return False

    def checkRight(self, array):
        if self.getZero(array)[1] < 3:
            return True
        else:
            return False

    # zwraca string ze wszystkimi ruchami, jakie
    # możemy wykonać w danym momencie
    def checkMoves(self, array):
        moves = ""
        if self.checkUp(array):
            moves = moves + "U"
        if self.checkDown(array):
            moves = moves + "D"
        if self.checkRight(array):
            moves = moves + "R"
        if self.checkLeft(array):
            moves = moves + "L"
        return moves

    # uzyskujemy możliwe do wykonania w danym momencie
    # ruchy uwzględniające kolejność podaną przy wywołaniu
    def compareMoves(self, array):
        allowedMoves = self.checkMoves(array)
        moves = ""
        for i in range(len(self.order)):
            if self.order[i] in allowedMoves:
                moves = moves + self.order[i]
        return moves

    # ta funkcja również zwraca możliwe do wykonania ruchy, lecz
    # w postaci tablicy z wartościami 0/1 (gdzie 1 to możliwość ruchu
    # w danym kierunku) zawsze z zachowaniem określonej kolejności
    # ruchów (UDRL) - funkcja na potrzeby algorytmu dfs
    def checkAllMoves(self, array):
        moves = [0] * len(self.order)
        allowedMoves = self.checkMoves(array)
        allMoves = ["U", "D", "R", "L"]
        for i in range(len(moves)):
            for j in range(len(allMoves)):
                if self.order[i] == allMoves[j] and allMoves[j] in allowedMoves:
                    moves[i] = 1
        return moves

    # funkcja poruszająca pustym polem w zadanym kierunku
    def moveNode(self, array, move):
        if self.algo == "astr":
            array = copy.deepcopy(array)  # tworze nowy obiekt na bazie array
        if move == "U":
            moveParams = self.getZero(array)
            moveParams[0] = moveParams[0] - 1
            array = self.switchValues(
                array, self.getZero(array), moveParams)
        if move == "D":
            moveParams = self.getZero(array)
            moveParams[0] = moveParams[0] + 1
            array = self.switchValues(
                array, self.getZero(array), moveParams)
        if move == "R":
            moveParams = self.getZero(array)
            moveParams[1] = moveParams[1] + 1
            array = self.switchValues(
                array, self.getZero(array), moveParams)
        if move == "L":
            moveParams = self.getZero(array)
            moveParams[1] = moveParams[1] - 1
            array = self.switchValues(
                array, self.getZero(array), moveParams)
        # zwraca kopie po ruchu
        return array

    # sprawdzamy, czy dany układ piętnastki znajduje się na liście odwiedzonych
    def isVisited(self, array):
        if len(self.openList) == 0:
            return False
        for i in range(len(self.openList)):
            if self.openList[i] == array:
                return True
        return False

    # algorytm bfs-zwraca rozwiązaną plansze lub -1
    def bfs(self):
        # rozpoczynamy liczenie czasu obliczeniowego
        startTime = time.time()

        # przeglądanie grafu zaczynamy od wybranego wierzchołka v-stan początkowy układanki
        vDict = {
            "values": self.values.copy(),
            "moves": []
        }

        # umieszczamy wierzchołek v w kolejce fifo
        self.fifo.append(vDict)

        # ustawiamy początkowy poziom rozwiązania
        solutionLevel = 0

        # rozpoczynamy obliczenia (dopóki kolejka nie jest pusta)
        while len(self.fifo) != 0:
            # pobieramy wierzchołek z kolejki
            v = self.fifo.popleft()

            # dodajemy go do listy stanów odwiedzonych
            valuesCopy = v["values"].copy()
            self.openList.append(valuesCopy)

            # sprawdzamy, czy stanowi on rozwiązanie-jeśli tak to zwracamy plansze
            if self.compareArr(v["values"]):
                # ustawiamy wartości atrybutów potrzebnych do statystyk
                self.moves = v["moves"].copy()
                self.algoReturn = 1
                self.recursionLevel = len(self.moves)

                # kończymy obliczanie czasu i wyznaczamy długość trwania obliczeń
                endTime = time.time()
                self.processedTime = float((endTime - startTime) * 1000)
                return v

            # aktualizujemy poziom rozwiązania, jeśli wzrósł
            if solutionLevel < len(v["moves"]):
                solutionLevel = len(v["moves"])

            # sprawdzamy, jakie ruchy możemy wykonać i porównujemy je z parametrami wywołania
            # (w tym przypadku kolejność ruchów nie ma znaczenia)
            allowedMoves = self.compareMoves(valuesCopy)

            # wykonujemy odpowiednie ruchy i w zachowanej kolejności dodajemy plansze do kolejki fifo
            for i in range(len(allowedMoves)):
                arrayCopy = copy.deepcopy(v)
                arrayCopy["values"] = self.moveNode(
                    arrayCopy["values"], allowedMoves[i])

                # w każdym ze słowników zapisujemy wykonany ruch
                arrayCopy["moves"] += allowedMoves[i]

                # sprawdzamy, czy dany układ nie był wcześniej przetwarzany,
                # robiąc to w tym miejscu, unikamy dodania do kolejki i wielokrotnego przetworzenia
                # tego samego układu
                if not self.isVisited(arrayCopy["values"]):
                    self.fifo.append(arrayCopy)

            # zwiększamy liczbę stanów przetworzonych, bo odpytaliśmy
            # już o sąsiedztwo obecnie przetwarzanego węzła
            self.processed += 1

            # postępowanie w przypadku niepowodzenia w rozwiązaniu układanki
            if solutionLevel == self.maxLevel:
                # ustawiamy status zakończenia algorytmu (-1 -> niepowodzenie)
                # i kończymy liczenie czasu działania
                self.algoReturn = -1
                endTime = time.time()
                self.processedTime = float((endTime - startTime) * 1000)
                return -1

    # algorytm dfs-zwraca rozwiązaną plansze lub -1
    def dfs(self, vDict):
        # w sytuacji osiągnięcia maksymalnego poziomu rekurencji zwraca none i powraca poziom wyżej
        if len(vDict["moves"]) >= self.maxLevel:
            return None

        # ustawiamy poziom rekurencji (jeśli poziom planszy różni się od obecnie przyjętego)
        if len(vDict["moves"]) > self.recursionLevel:
            self.recursionLevel = len(vDict["moves"])

        # sprawdzenie, czy układanka jest rozwiązana (jeśli tak ustawia status = 1 i zwraca rozwiązaną plansze)
        if self.compareArr(vDict["values"]):
            self.moves = vDict["moves"].copy()
            self.algoReturn = 1
            self.recursionLevel = len(self.moves)
            return vDict

        # sprawdzamy, jakie ruchy możemy wykonać, ale w odróżnieniu od algorytmu bfs
        # zawsze zachowujemy tę samą kolejność ruchów
        moves = self.checkAllMoves(vDict["values"])

        # odpytujemy po kolei wszystkie kierunki
        for i in range(len(moves)):
            # wykonujemy ruch w danym kierunku, jeśli możemy, aktualizujemy
            # wartość ostatnio wykonanego ruchu, dodajemy ten ruch do listy
            # a układankę po wykonaniu ruchu dodajemy do listy odwiedzonych
            # wywołujemy algorytm dla nowej planszy
            if moves[i] == 1:
                dictCopy = copy.deepcopy(vDict)
                dictCopy["values"] = self.moveNode(
                    dictCopy["values"], self.order[i])
                self.prevMove = self.order[i]
                dictCopy["moves"] += self.order[i]
                self.openList.append(dictCopy)
                newDict = self.dfs(dictCopy)
                # jeśli algorytm znajdzie rozwiązanie-ustawiamy status na 1 oraz
                # zwracamy rozwiązaną planszę
                if newDict is not None and self.compareArr(newDict["values"]):
                    self.moves = newDict["moves"].copy()
                    self.algoReturn = 1
                    self.recursionLevel = len(self.moves)
                    return newDict

        # zwiększamy liczbę przetworzonych stanów po odpytaniu sąsiedztwa
        self.processed += 1

    # Zwraca, jakie ruchy możemy wykonać dla danego układu
    # w postaci listy
    def getValidMoves(self):
        x = self.getZero(self.state)[0]
        y = self.getZero(self.state)[1]
        rows = len(self.state)
        cols = len(self.state[0])
        moves = []
        if x > 0 and self.lastMove != 'D':
            moves.append('U')
        if (x < (rows - 1)) and self.lastMove != 'U':
            moves.append('D')
        if y > 0 and self.lastMove != 'R':
            moves.append('L')
        if (y < (cols - 1)) and self.lastMove != 'L':
            moves.append('R')
        return moves

    # zwraca ścieżkę z wykonanymi ruchami w postaci string
    def getPath(self):
        path = ''
        if self.parent is None:
            return path
        path += self.parent.getPath() + str(self.lastMove)
        return path

    # metoda tworząca obiekt klasy Astar i wywołująca dla niego metodę solve, która rozwiązuje układ
    def aStar(self):
        self.state = self.values
        return AStar(self.state, self.template, self.fileName, self.solName, self.statsName, self.strategy,
                     self.order).solve()

    # funkcja wywołująca odpowiednią funkcję w zależności od
    # wybranego algorytmu
    def process(self):
        if self.algo == "bfs":
            return self.bfs()
        elif self.algo == "dfs":
            vDict = {
                "values": self.values.copy(),
                "moves": []
            }
            start = time.time()
            result = self.dfs(vDict)
            if result is not None:
                self.algoReturn = 1
            else:
                self.algoReturn = -1
            stop = time.time()
            self.processedTime = float((stop - start) * 1000)
            return result
        elif self.algo == "astr":
            result = self.aStar()
            if result[0] != -1:
                self.algoReturn = 1
                self.moves = result[0]
                self.recursionLevel = len(self.moves)
                self.openListLen = result[1]
                self.processed = result[2]
                self.processedTime = result[4]
            else:
                self.algoReturn = -1
            print(self.moves)
            return result


class AStar:
    frontier = {}  # do przetworzenia
    explored = {}  # przetworzone

    def __init__(self, start, target, fileName, solName, statsName, strategy, order):
        self.target = target  # wzorcowe rozwiązanie
        self.path = []  # ścieżka wykonanych ruchów
        self.strategy = strategy  # heurestyka
        self.start = Puzzle("astr", order, fileName, solName,
                            statsName, strategy, start, None, 0)  # początkowy układ
        self.maxDepth = 7  # maksymalna głębokość
        self.maxRecursion = 20  # kiedy zawraca algorytm
        self.rows = len(start)
        self.columns = len(start[0])
        # jeżeli układ początkowy jest różny od wzorcowego; wyliczanie dystansu na podstawie wybranej heurestyki
        if self.start != self.target:
            if self.strategy == 'manh':
                distance = self.manhattanDistance(self.start.state)
            elif self.strategy == 'hamm':
                distance = self.hammingDistance(self.start.state)
            self.frontier.setdefault(distance, []).append(self.start.state)
            self.explored[str(self.start.state)] = self.start

    def manhattanDistance(self, state):  # liczenie odległości pola od jego poprawnego miejsca
        distance = 0
        for x in state:
            for y in x:
                if y != 0:
                    temp = y % self.columns
                    if temp == 0:
                        temp = self.columns
                    distance += abs((state.index(x) + 1) - ceil(y / self.rows)) + abs((x.index(y) + 1) - temp)
        return distance

    def hammingDistance(self, state):  # koszt zwiększa się za każde pole, które nie jest na swoim miejscu
        distance = 0
        for x in state:
            for y in x:
                if y != 0:
                    temp = y % self.columns
                    if temp == 0:
                        temp = self.columns
                    if ((state.index(x) + 1) != ceil(y / self.rows)) or ((x.index(y) + 1) != temp):
                        distance += 1
        return distance

    # zwraca ścieżkę ruchów
    def returnPath(self):
        return self.path

    def solve(self):
        startTime = time.time()  # uruchomienie timera
        solutionLevel = 0  # ustawienie początkowego poziomu rozwiązania na 0
        while len(self.frontier) > 0:  # dopóki cos jest w słowniku "do przetworzenia"
            if solutionLevel < self.maxRecursion:  # wykonuje się, dopóki poziom rozwiązania < 20
                closest = min(
                    self.frontier)  # wybranie indeksu układanki o najmniejszym koszcie z układów do przetworzenia
                currentState = self.frontier[closest].pop(0)  # wybranie układanki i zdjęcie jej ze słownika
                if len(self.frontier[closest]) == 0:
                    del (self.frontier[closest])
                currentStateStr = currentState.__str__()
                currentState = self.explored[currentStateStr]
                moves = currentState.getValidMoves()  # Możliwe do wykonania ruchy w danej układance
                for move in moves:  # dla możliwego ruchu
                    newArr = currentState.moveNode(
                        currentState.state, move)  # wykonanie ruchu
                    solutionLevel = len(currentState.getPath())  # wpisanie wykonanego ruchu do długości rozwiązania
                    # wyliczenie częsciowego kosztu na podstawie długości rozwiązania (bez heurstyki)
                    newCost = currentState.pathCost + 1
                    newMove = move
                    newState = Puzzle("astr", newMove, self.start.fileName, self.start.solName,
                                      self.start.statsName, self.start.strategy, newArr, currentState,
                                      newCost)  # tworzymy nowy obiekt w celu dodania do słownika "do przetworzenia"

                    # string do porównania łańcuchów znaków czy nie są identyczne
                    newStateStr = newArr.__str__()
                    if newStateStr not in self.explored:  # sprawdzenie, czy nowy obiekt nie był już przetworzony
                        self.explored[newStateStr] = newState  # jesli nie jest w przetworzonych to jest dodawany

                        # sprawdzenie, czy dlugosc rozwiazania jest wieksza od obecnie najwiekszej
                        if newCost > self.maxDepth:
                            self.maxDepth = newCost  # jezeli jest wieksza to jest nadpisywana
                        if newArr == self.target:  # sprawdzenie, czy nowy obiekt jest rozwiązaniem
                            solvingTime = time.time() - startTime
                            solved = round(solvingTime, 3)
                            path = newState.getPath()
                            explored = (len(self.explored) + 1)
                            frontier = len(self.explored) - len(self.frontier)
                            return [path, explored, frontier, self.maxDepth, solved]  # zwracanie wyniku
                        if self.strategy == 'manh':  # obliczenie nowgo kosztu z uwzglednieniem heurestyki manhattan
                            distance = self.manhattanDistance(newArr)
                        elif self.strategy == 'hamm':  # obliczenie nowgo kosztu z uwzglednieniem heurestyki hamminga
                            distance = self.hammingDistance(newArr)

                        # dodanie nowej ukladanki do slownika "do przetworzenia", jezeli jeszcze takiej nie ma
                        if distance not in self.frontier:
                            self.frontier.setdefault(
                                distance, []).append(newArr)
                        else:
                            self.frontier[distance].append(newArr)
            else:
                return -1
