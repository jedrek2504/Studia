package model;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

public class SudokuBoardTest {
    private final SudokuBoard board = new SudokuBoard();

    @Test //checks if the board is generated in a random manner(no board is the same)
    void fillBoard() {
        this.board.fillBoard();
        var boards = new ArrayList<String>(); //List that contains String representations of my 2d sudoku boards
        for (var i = 0; i < 10; i++) {
            this.board.fillBoard();
            for (var board: boards) {
                assertNotEquals(board, this.board.toString());
            }
            boards.add(this.board.toString());
        }
    }

    @Test //checks if board is generated correctly
    void isCorrect() {
        this.board.fillBoard();
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                int temp = this.board.getValue(row, col); //temp stores given value
                this.board.setValue(row, col, 0); //original value is set to 0
                // checks if we put original value back to its place (is currently 0) would it be correct?
                assertTrue(this.board.checkAllConditions(row, col, temp));
                this.board.setValue(row, col, temp); //makes original value the way it was
            }
        }
    }
}