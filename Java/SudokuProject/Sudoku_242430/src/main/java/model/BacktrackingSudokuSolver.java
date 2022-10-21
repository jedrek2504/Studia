package model;

import java.util.Random;

public class BacktrackingSudokuSolver implements SudokuSolver {
    Random rand = new Random();


    @Override
    public void solve(SudokuBoard board) {
        for (int row=0; row <= 9; row++) {
            board.setGrid(row, rand.nextInt(9), row + 1);
        }

        solveSudoku(board);
    }


    private boolean solveSudoku(SudokuBoard board) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                //searching for 0
                if (board.getGrid(row, col) == 0) {
                    //when found, we go through every value 1-9
                    for (int value = 1; value <= 9; value++) {
                        //to see if it's correct
                        if (board.checkAllConditions(row, col, value)) {
                            //when correct -> we assign this value to the place
                            board.setGrid(row, col, value);
                            //we return true and use recursion to find the next empty spot ("0")
                            //if a found value not we set the value back to 0 and search for
                            // a higher value
                            if (this.solveSudoku(board)) {
                                return true;
                            } else {
                                board.setGrid(row, col, 0);
                            }
                        }
                    }
                    //if we cant find a right value for a specific spot at all
                    // , we return false and it means that a sudoku board is unsolvable
                    // (cant happen in my implementation)
                    return false;
                }
            }
        }
        return true;
    }
}


