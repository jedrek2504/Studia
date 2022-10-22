package model;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class BacktrackingSudokuSolverTest {

    @Test
    public void testSolve() {
        BacktrackingSudokuSolver sudokuSolver = new BacktrackingSudokuSolver();
        SudokuBoard testSudokuBoard = new SudokuBoard(sudokuSolver);
        sudokuSolver.solve(testSudokuBoard);
        assertTrue(testSudokuBoard.isBoardCorrect());
    }

    @Test
    public void testDifferentSolves() {
        boolean isBoardTheSame = false;
        for (int i = 0; i < 10; i++) { //loop solves 10 pairs of sudoku boards
            SudokuBoard testSudokuBoard1 = new SudokuBoard(new BacktrackingSudokuSolver());
            SudokuBoard testSudokuBoard2 = new SudokuBoard(new BacktrackingSudokuSolver());
            testSudokuBoard1.getSudokuSolver().solve(testSudokuBoard1);
            testSudokuBoard2.getSudokuSolver().solve(testSudokuBoard2);

            compareBoards: //I use label so the break doesn't stop the first loop
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k++) {
                    if (testSudokuBoard1.getGrid(j, k) != testSudokuBoard2.getGrid(j, k)) { //if any grid is not the same the compareBoards: loops break
                        break compareBoards;
                    }
                    if (j == 8 && k == 8) { //if the loop did not break we assign true - the boards ARE the same
                        isBoardTheSame = true;
                    }
                }
            }
        }
        assertFalse(isBoardTheSame);
    }
}