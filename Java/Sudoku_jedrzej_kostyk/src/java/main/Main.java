package main;

import model.SudokuBoard;
import model.temp;

import java.util.Arrays;


public class Main {
    public static void main(String[] args) {
        var board = new temp();
        board.fillBoard();
        System.out.println(board.toString());

        System.out.println(board.rowCheck(0,3));
        System.out.println(board.colCheck(0,3));
        System.out.println(board.sqrCheck(0,0,3));
        System.out.println(board.checkAllConditions(0,0 , 3));


    }
}
