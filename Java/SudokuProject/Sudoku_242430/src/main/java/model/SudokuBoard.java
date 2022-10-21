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
    
    public int getGrid(int x, int y) {
        return this.board[x][y];
    }

    public void setGrid(int x, int y, int value) {
        this.board[x][y] = value;
    }

    public void solveGame() {

    }

    /*
    //fills board following sudoku rules in a random manner.
    public void fillBoard() {
        this.board = new int[this.row][this.col];

        Random rand = new Random();

        //fills random place in every row with increasing value(1,2,3,...,9)
        for (int i = 0; i < this.row; i++) {
            this.board[i][rand.nextInt(this.row)] = i + 1;
        }

        this.resolveBoard();
    }

    //checks if row (as a whole) has a given value
    private boolean rowCheck(final int row, int value) {
        for (int i = 0; i < this.row; i++) {
            if (this.board[row][i] == value) {
                return false;
            }
        }
        return true;
    }

    //checks if column (as a whole) has a given value
    private boolean colCheck(final int col, int value) {
        for (int i = 0; i < this.col; i++) {
            if (this.board[i][col] == value) {
                return false;
            }
        }
        return true;
    }

    //checks if specific square has a given value
    private boolean sqrCheck(final int row, final int col, int value) {
        //first I need coords of left right corner of the square:
        int currentSqrRow = row - (row % 3); //determines what row the mentioned square begins
        int currentSqrCol = col - (col % 3); //determines what col the mentioned square begins

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

    //checks if given number in given place(row,col) abides Sudoku rules
    public boolean checkAllConditions(final int row, final int col, int value) {
        return this.rowCheck(row, value) && this.colCheck(col, value)
                && this.sqrCheck(row, col, value);
    }

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

    public String toString() {
        StringBuilder chain = new StringBuilder();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                chain.append(this.board[i][j]);
                chain.append(' ');
            }
            chain.append('\n');
        }
        return chain.toString();
    }

    //getters and setters -> used in tests
    public int getValue(final int row, final int col) {
        return this.board[row][col];
    }

    public void setValue(final int row, final int col, int value) {
        this.board[row][col] = value;
    }

     */
}


