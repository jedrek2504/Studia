package main;

import model.BacktrackingSudokuSolver;
import model.SudokuBoard;
import model.SudokuField;
import model.SudokuVerify;

public class Main {
    public static void main(String[] args) {
        SudokuBoard sudokuBoard1 = new SudokuBoard(new BacktrackingSudokuSolver());

        sudokuBoard1.solveGame();
        sudokuBoard1.printBoard();
    }
}