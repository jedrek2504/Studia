package model;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;

public class SudokuBoardTest {
    public static int row = 1;
    public static int column = 2;
    public static int value = 3;

    SudokuBoard testSudokuBoard;

    @BeforeEach //makes this method execute before each test
    public void newBoard() {
        testSudokuBoard = new SudokuBoard(new BacktrackingSudokuSolver());
    }

    @Test
    public void testSetGetGrid() {
        testSudokuBoard.setGrid(row, column, value);
        assertEquals(testSudokuBoard.getGrid(1, 2), 3);
    }

    @Test
    public void testSetGridWrongValues() {
        testSudokuBoard.setGrid(row, column, 10); //it shouldn't assign 10
        assertEquals(testSudokuBoard.getGrid(row,column), 0);
    }

    @Test
    public void testXCheck() {
        for (int i = 0; i < 9; i++) {
            testSudokuBoard.setGrid(1, i, i + 1);
        }
        testSudokuBoard.setGrid(row, column, 0);
        assertTrue(testSudokuBoard.isRowGood(row, 3));
    }

    @Test
    public void testXCheckFailed() {
        for (int i = 0; i < 9; i++) {
            testSudokuBoard.setGrid(1, i, i + 1);
        }
        testSudokuBoard.setGrid(row, column, 0);
        assertFalse(testSudokuBoard.isRowGood(row, 2));
    }

    @Test
    public void testYCheck() {
        for (int i = 0; i < 9; i++) {
            testSudokuBoard.setGrid(i, 1, i + 1);
        }
        testSudokuBoard.setGrid(row, 1, 0);
        assertTrue(testSudokuBoard.isColGood(1, 2));
    }

    @Test
    public void testYCheckFailed() {
        for (int i = 0; i < 9; i++) {
            testSudokuBoard.setGrid(i, 1, i + 1);
        }
        testSudokuBoard.setGrid(row, 1, 0);
        assertFalse(testSudokuBoard.isColGood(1, 1));
    }

    @Test
    public void testSqrCheck() {
        int tmp = 0;
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < 2; j++) {
                testSudokuBoard.setGrid(i, j, tmp++);
            }
        }
        assertTrue(testSudokuBoard.isSqrGood(2, 2,5));
    }

    @Test
    public void testSqrCheckFailed() {
        int tmp = 0;
        for(int i=0; i<2; i++){
            for(int j=0; j < 2; j++){
                testSudokuBoard.setGrid(i, j, tmp++);
            }
        }
        assertFalse(testSudokuBoard.isSqrGood(2,2,2));
    }

    @Test
    public void testCheckAllConditions() {
        int tmp = 0;
        //changing the top-left square
        for(int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                testSudokuBoard.setGrid(i, j, ++tmp); //Pre-increment
            }
        }
        testSudokuBoard.setGrid(2, 2, 0);
        assertTrue(testSudokuBoard.checkAllConditions(2, 2, 9));
    }

    @Test
    public void testCheckAllConditionsFailed() {
        int tmp = 0;
        //changing the top-left square
        for(int i=0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                testSudokuBoard.setGrid(i, j, ++tmp);
            }
        }
        testSudokuBoard.setGrid(2, 2, 0);
        assertFalse(testSudokuBoard.checkAllConditions(2, 2, 8));
    }

    @Test //checks if method solveGame() was executed
    public void testSolveGame() {
        testSudokuBoard.solveGame();
        assertTrue(testSudokuBoard.isBoardCorrect());
    }

}