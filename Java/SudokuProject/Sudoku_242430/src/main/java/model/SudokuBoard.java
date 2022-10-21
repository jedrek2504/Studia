package model;

public class SudokuBoard {
    //declarations:
    private final int[][] board;
    private final SudokuSolver sudokuSolver;

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
        if (x >= 0 && y <= 8 && value >= 0 && value <= 9) {
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
    private boolean xCheck(int x, int value) {
        for (int i = 0; i < 9; i++) {
            if (this.board[x][i] == value) {
                return false;
            }
        }
        return true;
    }

    //checks if column (as a whole) has a given value
    private boolean yCheck(int y, int value) {
        for (int i = 0; i < 9; i++) {
            if (this.board[i][y] == value) {
                return false;
            }
        }
        return true;
    }

    //checks if a square has a given value
    private boolean sqrCheck(int x, int y, int value) {
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
    public boolean checkAllConditions(int x, int y, int value) {
        return this.xCheck(x, value) && this.yCheck(y, value)
                && this.sqrCheck(x, y, value);
    }

    //prints board
     public void printBoard() {
             for (int i = 0; i < 9; i++) {
                 if (i % 3 == 0) {
                     System.out.print("+-------+-------+-------+\n");
                 }

                 for (int j = 0; j < 9; j++) {
                     if (j % 3 == 0) {
                         System.out.print("| ");
                     }
                     System.out.print(getGrid(i, j) + " ");
                 }
                 System.out.print("|");
                 System.out.println();
             }
             System.out.print("+-------+-------+-------+\n");
         }

}


