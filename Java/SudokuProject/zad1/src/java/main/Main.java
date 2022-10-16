package main;

import model.SudokuBoard;


public class Main {
    public static void main(String[] args) {
        var board = new SudokuBoard();
        
        board.fillBoard();
        System.out.println(board.toString());



    }
}
