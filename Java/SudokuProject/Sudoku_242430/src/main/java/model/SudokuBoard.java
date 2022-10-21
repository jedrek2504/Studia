package model;

import java.util.Random;

public class SudokuBoard {
    //declarations:
    private int[][] board;
    private SudokuSolver sudokuSolver;

    //constructor
    public SudokuBoard(SudokuSolver sudokuSolver) {
        this.board = new int[9][9];
        this.sudokuSolver = sudokuSolver;
    }

    //returns the value of a certain grid
    public int getGrid(int x, int y) {
        return this.board[x][y];
    }

    //sets the value of a certain grid
    public void setGrid(int x, int y, int value) {
        if (x >= 0 && y <= 8 && value >= 1 && value <= 9) {
            this.board[x][y] = value;
        }
    }

    //solves the game
    public void solveGame() {
        sudokuSolver.solve(this);
    }

    public boolean isBoardFull() {
        for(int x = 0; x < 9 ; x++)  {
            for(int y = 0; y < 9 ; y++) {
                if (this.getGrid(x, y) == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    //checks if row (as a whole) has a given value
    private boolean xCheck(final int x, int value) {
        for (int i = 0; i < 9; i++) {
            if (this.board[x][i] == value) {
                return false;
            }
        }
        return true;
    }

    //checks if column (as a whole) has a given value
    private boolean yCheck(final int y, int value) {
        for (int i = 0; i < 9; i++) {
            if (this.board[i][y] == value) {
                return false;
            }
        }
        return true;
    }

    //checks if a square has a given value
    private boolean sqrCheck(final int x, final int y, int value) {
        //first I need coords of left right corner of the square:
        int currentSqrRow = x - (x % 3);
        int currentSqrCol = y - (y % 3);

        //we go through every place (9 total) and check if given value is in any of them
        for (int i = currentSqrRow; i < currentSqrRow + 3; i++) {
            for (int j = currentSqrCol; j < currentSqrCol + 3; j++) {
                if (this.board[i][j] == value) {
                    return false;
                }
            }
        }
        return true;
    }

    //checks all conditions
    public boolean checkAllConditions(final int x, final int y, int value) {
        return this.xCheck(x, value) && this.yCheck(y, value)
                && this.sqrCheck(x, y, value);
    }

    /*
   //solves board
    private boolean resolveBoard() {
        for (int row = 0; row < this.row; row++) {
            for (int col = 0; col < this.col; col++) {
                //searching for 0
                if (this.board[row][col] == 0) {
                    //when found, we go through every value 1-9
                    for (int value = 1; value <= 9; value++) {
                        //to see if its correct
                        if (this.checkAllConditions(row, col, value)) {
                            //when correct -> we assign this value to the place
                            this.board[row][col] = value;
                            //we return true and use recursion to find the next empty spot ("0")
                            //if a found value not we set the value back to 0 and search for
                            // a higher value
                            if (this.resolveBoard()) {
                                return true;
                            } else {
                                this.board[row][col] = 0;
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

     */

    public String toString() {
        StringBuilder chain = new StringBuilder();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                chain.append(this.board[i][j]);
                chain.append(' ');
            }
            chain.append('\n');
        }
        return chain.toString();
    }

}


