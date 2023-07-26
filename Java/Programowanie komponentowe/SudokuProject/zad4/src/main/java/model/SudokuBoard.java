package model;

public class SudokuBoard {
    //declarations:
    private final SudokuField[][] board;
    private final SudokuSolver sudokuSolver;

    //constructor
    public SudokuBoard(SudokuSolver sudokuSolver) {
        this.board = new SudokuField[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = new SudokuField();
            }
        }
        this.sudokuSolver = sudokuSolver;
    }

    public int get(int x, int y) {
        return board[x][y].getFieldValue();
    }

    public void set(int x, int y, int value) {
        if (x >= 0 && x <= 8 && y >= 0 && y <= 8 && value >= 0 && value <= 9) {
            board[x][y].setFieldValue(value);
        }
    }

    //returns solver
    public SudokuSolver getSudokuSolver() {
        return sudokuSolver;
    }

    //solves the game
    public void solveGame() {
        sudokuSolver.solve(this);
    }

    //checks if row (as a whole) has a given value
    public boolean isRowGood(int x, int value) {
        for (int i = 0; i < 9; i++) {
            if (get(x, i) == value) {
                return false;
            }
        }
        return true;
    }

    //checks if column (as a whole) has a given value
    public boolean isColGood(int y, int value) {
        for (int i = 0; i < 9; i++) {
            if (get(i, y) == value) {
                return false;
            }
        }
        return true;
    }

    //checks if a square has a given value
    public boolean isBoxGood(int x, int y, int value) {
        //first I need coords of left right corner of the square:
        int currentSqrRow = x - (x % 3);
        int currentSqrCol = y - (y % 3);

        //we go through every place (9 total) and check if given value is in any of them
        for (int i = currentSqrRow; i < currentSqrRow + 3; i++) {
            for (int j = currentSqrCol; j < currentSqrCol + 3; j++) {
                if (get(i, j) == value) {
                    return false;
                }
            }
        }
        return true;
    }

    //checks all conditions
    public boolean checkAllConditions(int x, int y, int value) {
        return this.isRowGood(x, value) && this.isColGood(y, value)
                && this.isBoxGood(x, y, value);
    }

    //method checks if board is filled in a correct way
    public boolean isBoardCorrect() {
        int temp;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                temp = get(i, j);
                set(i, j, 0);
                if (checkAllConditions(i, j, temp)) {
                    set(i, j, temp);
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    //returns address of a row
    public SudokuRow getRow(int y) {
        SudokuRow row = new SudokuRow();
        SudokuField[] values = new SudokuField[9];
        for (int i = 0;i < 9;i++) {
            values[i] = board[i][y];
        }
        row.setSudokuVerify(values);
        return row;
    }

    //returns address of a column
    public SudokuColumn getColumn(int x) {
        SudokuColumn column = new SudokuColumn();
        SudokuField[] values = new SudokuField[9];
        System.arraycopy(board[x], 0, values, 0, 9);
        column.setSudokuVerify(values);
        return column;
    }

    //returns address of a box
    public SudokuBox getBox(int x, int y) {
        SudokuField[] values = new SudokuField[9];
        x = x - (x % 3);
        y = y - (y % 3);
        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++, k++) {
                values[k] = board[x + i][y + j];
            }
        }
        SudokuBox box = new SudokuBox();
        box.setSudokuVerify(values);
        return box;
    }


    public boolean checkBoard() {
        int j = 0;
        for (int i = 0;i < 9;i++, j++) {
            if (!getRow(i).verify() || !getColumn(i).verify() || !getBox(i,j).verify()) {
                return false;
            }
        }
        return true;
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
                System.out.print(get(i, j) + " ");
            }
            System.out.print("|");
            System.out.println();
        }
        System.out.print("+-------+-------+-------+\n");
    }
}