from src.Puzzle import *
import sys


def puzzleInit(algo, algo_param, task_file, sol_file, stats_file, strategy="", state="", parent="", path_cost=""):
    if algo == "astr":
        strategy = algo_param
        algo_param = "RDUL"
    puzzle = Puzzle(algo, algo_param, task_file, sol_file, stats_file, strategy, state, parent, path_cost)
    return puzzle


# Przykładowe wywołanie programu:
# python main.py dfs LURD 4x4_07_00101.txt 4x4_07_00101_sol.txt 4x4_07_00101_stat.txt
# pliki do wczytania znajdują się w folderze ./files/puzzles
# rozwiązania tworzone są w folderze ./files/solutions
# pliki z informacjami dodatkowymi tworzone są w folderze ./files/stats
puzzle = puzzleInit(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])
puzzle.process()
puzzle.saveSolution()
puzzle.saveStats()
