package model;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class SudokuBoardTest {


    SudokuBoard testSudokuBoard;

    @BeforeEach
    public void sudokuSet() {
        testSudokuBoard = new SudokuBoard(new BacktrackingSudokuSolver());
    }

    @Test
    public void testSetGood() {
        int row = 1;
        int column = 2;
        int value = 3;

        testSudokuBoard.set(row, column, value);
        assertEquals(testSudokuBoard.get(row, column), value);
    }

    @Test
    public void testGet() {
        int row = 1;
        int column = 2;
        int value = 3;

        testSudokuBoard.set(row, column, value);
        assertEquals(testSudokuBoard.get(row, column), value);
    }

    @Test
    public void testSetNotGood() {
        int row = 1;
        int column = 2;
        int value = 11;

        testSudokuBoard.set(row, column, value);
        assertEquals(testSudokuBoard.get(row, column), 0);
    }

    @Test
    public void testIsBoardGood() {
        testSudokuBoard.solveGame();
        assertTrue(testSudokuBoard.checkBoard());
    }

    @Test
    public void testIsBoardNotGood() {
        testSudokuBoard.solveGame();
        testSudokuBoard.set(0, 0, (testSudokuBoard.get(0, 0) + 1) % 9 + 1);
        assertFalse(testSudokuBoard.checkBoard());
    }

    @Test
    public void testIsRowGood() {
        for(int i=0; i<8; i++) {
            testSudokuBoard.set(0,i,i);
        }
        assertTrue(testSudokuBoard.isRowGood(0,9));
    }

    @Test
    public void testIsRowNotGood() {
        for(int i=0; i<9; i++) {
            testSudokuBoard.set(0,i,i);
        }
        assertFalse(testSudokuBoard.isRowGood(0,8));
    }

    @Test
    public void testIsColumnGood() {
        for(int i=0; i<8; i++){
            testSudokuBoard.set(i,0,i);
        }
        assertTrue(testSudokuBoard.isColGood(0,9));
    }

    @Test
    public void testIsColumnNotGood() {
        for(int i=0; i<9; i++){
            testSudokuBoard.set(i,0,i);
        }
        assertFalse(testSudokuBoard.isColGood(0,8));
    }

    @Test
    public void testIsBoxGood() {
        int tmp = 0;
        for(int i=0; i<2; i++){
            for(int j=0; j < 2; j++){
                testSudokuBoard.set(i,j,++tmp);
            }
        }
        assertTrue(testSudokuBoard.isBoxGood(2,2,5));
    }

    @Test
    public void testIsBoxNotGood() {
        int tmp = 0;
        for(int i=0; i<2; i++){
            for(int j=0; j < 2; j++){
                testSudokuBoard.set(i,j,++tmp);
            }
        }
        assertFalse(testSudokuBoard.isBoxGood(2,2,2));
    }

    @Test
    public void testIsAllGood() {
        int tmp = 0;
        for(int i=0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                testSudokuBoard.set(i, j, ++tmp);
            }
        }
        testSudokuBoard.set(2,2,0);
        assertTrue(testSudokuBoard.checkAllConditions(2,2,9));
    }

    @Test
    public void testIsNotAllGood() {
        int tmp = 0;
        for(int i=0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                testSudokuBoard.set(i, j, ++tmp);
            }
        }
        testSudokuBoard.set(2,2,0);
        assertFalse(testSudokuBoard.checkAllConditions(2,2,8));
    }

    @Test
    public void testSolveGame() {
        testSudokuBoard.solveGame();
        assertTrue(testSudokuBoard.isBoardCorrect());
    }

    @Test
    public void testIsBoardNotCorrect() {
        testSudokuBoard.solveGame();
        testSudokuBoard.set(2,2,0);
        assertFalse(testSudokuBoard.isBoardCorrect());
    }
}