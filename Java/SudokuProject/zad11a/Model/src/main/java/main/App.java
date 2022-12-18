/**
 *   DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                     Version 2, December 2004
 *  Copyright (C) 2004 Sam Hocevar
 *  Everyone is permitted to copy and distribute verbatim or modified
 *  copies of this license document, and changing it is allowed as long
 *  as the name is changed.
 *             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *    TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *   0. You just DO WHAT THE FUCK YOU WANT TO.
 */

package main;

import model.BacktrackingSudokuSolver;
import model.SudokuBoard;

public class App {
    public static void main(String[] args) {
        SudokuBoard sudokuBoard1 = new SudokuBoard(new BacktrackingSudokuSolver());

        sudokuBoard1.solveGame();
        System.out.println(sudokuBoard1.toString());
        //sudokuBoard1.printBoard();

    }
}