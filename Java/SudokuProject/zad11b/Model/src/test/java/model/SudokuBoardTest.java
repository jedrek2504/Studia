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
    public void testSetOverextendingValue() {
        int row = 1;
        int column = 2;
        int value = 11;

        testSudokuBoard.set(row, column, value);
        assertEquals(testSudokuBoard.get(row, column), 0);
    }

    @Test
    public void testSetMinusValue() {
        int row = 1;
        int column = 2;
        int value = -1;

        testSudokuBoard.set(row, column, value);
        assertEquals(testSudokuBoard.get(row, column), 0);
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

    @Test
    public void testCheckBoardPositive() {
        testSudokuBoard.solveGame();
        assertTrue(testSudokuBoard.checkBoard());
    }

    @Test
    public void testCheckBoardNegative() {
        assertFalse(testSudokuBoard.checkBoard());
    }

    @Test
    public void testEqualsGood() {
        SudokuBoard testSudokuBoard2 = testSudokuBoard;
        assertTrue(testSudokuBoard2.equals(testSudokuBoard));
    }

    @Test
    public void testEqualsSameObject() {
        assertTrue(testSudokuBoard.equals(testSudokuBoard));
    }

    @Test
    public void testEqualsNotGood() {
        SudokuBoard testSudokuBoard2 = new SudokuBoard(new BacktrackingSudokuSolver());
        testSudokuBoard2.solveGame();
        assertFalse(testSudokuBoard2.equals(testSudokuBoard));
    }

    @Test
    public void testEqualsNULLValue() {
        SudokuBoard testSudokuBoard2 = null;
        assertFalse(testSudokuBoard.equals(testSudokuBoard2));
    }

    @Test
    public void testEqualsDifferentClasses() {
        SudokuSolver testSudokuSolver = new BacktrackingSudokuSolver();
        assertFalse(testSudokuBoard.equals(testSudokuSolver));
    }

    @Test
    public void testHashCodeGood() {
        SudokuBoard testSudokuBoard2 = testSudokuBoard;
        assertTrue(testSudokuBoard2.hashCode() == testSudokuBoard.hashCode());
    }

    @Test
    public void testHashCodeNotGood() {
        SudokuBoard testSudokuBoard2 = new SudokuBoard(new BacktrackingSudokuSolver());
        testSudokuBoard2.solveGame();
        assertFalse(testSudokuBoard2.hashCode() == testSudokuBoard.hashCode());
    }

    @Test
    public void toStringDifferentValues() {
        SudokuBoard testSudokuBoard2 = new SudokuBoard(new BacktrackingSudokuSolver());
        assertNotEquals(testSudokuBoard.toString(), testSudokuBoard2.toString());
    }

    @Test
    public void testToString() {
        assertFalse(testSudokuBoard.toString().isEmpty());
    }

    @Test
    void testHashCode() {
        SudokuBoard testSudokuBoard1 = new SudokuBoard(new BacktrackingSudokuSolver());
        testSudokuBoard.solveGame();
        assertNotEquals(testSudokuBoard.hashCode(),testSudokuBoard1.hashCode());

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                testSudokuBoard1.set(i,j,testSudokuBoard.get(i,j));
            }
        }
        assertEquals(testSudokuBoard.hashCode(),testSudokuBoard1.hashCode());
    }

    @Test
    public void cloneTest() throws CloneNotSupportedException {
        BacktrackingSudokuSolver backtrackingSudokuSolver = new BacktrackingSudokuSolver();
        SudokuBoard sudokuBoard = new SudokuBoard(backtrackingSudokuSolver);
        sudokuBoard.solveGame();
        SudokuBoard sudokuBoard2 = (SudokuBoard) sudokuBoard.clone();

        assertTrue(sudokuBoard.equals(sudokuBoard2)
                && sudokuBoard2.equals(sudokuBoard));
    }

}