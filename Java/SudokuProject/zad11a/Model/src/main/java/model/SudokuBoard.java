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

import java.io.Serializable;
import java.util.Arrays;
import java.util.List;
import org.apache.commons.lang3.builder.EqualsBuilder;
import org.apache.commons.lang3.builder.HashCodeBuilder;
import org.apache.commons.lang3.builder.ToStringBuilder;


public class SudokuBoard implements Serializable, Cloneable {
    private final SudokuField[][] board;
    private final SudokuSolver sudokuSolver;

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
        if (x >= 0 && x <= 8 && y >= 0 && y <= 8) {
            return board[x][y].getFieldValue();
        } else {
            return -1;
        }
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

    public boolean checkAllConditions(int x, int y, int value) {
        return this.isRowGood(x, value) && this.isColGood(y, value)
                && this.isBoxGood(x, y, value);
    }

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

    public SudokuRow getRow(int y) {
        SudokuRow row = new SudokuRow(Arrays.asList(new SudokuField[9]));
        for (int i = 0;i < 9;i++) {
            row.getSudokuElement().set(i, new SudokuField(get(i, y)));
        }
        return row;
    }

    public SudokuColumn getColumn(int x) {
        SudokuColumn column = new SudokuColumn(Arrays.asList(new SudokuField[9]));
        for (int i = 0;i < 9;i++) {
            column.getSudokuElement().set(i, new SudokuField(get(x, i)));
        }
        return column;
    }

    public SudokuBox getBox(int x, int y) {
        SudokuBox box = new SudokuBox(Arrays.asList(new SudokuField[9]));
        x = x - (x % 3);
        y = y - (y % 3);
        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++, k++) {
                box.getSudokuElement().set(k, new SudokuField(get(x + i, y + j)));
            }
        }
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


    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || this.getClass() != o.getClass()) {
            return false;
        }
        SudokuBoard that = (SudokuBoard) o;
        return new EqualsBuilder().append(this.board, that.board)
                .isEquals();
    }

    @Override
    public int hashCode() {
        return new HashCodeBuilder(17, 37).append(board).toHashCode();
    }

    @Override
    public String toString() {
        return new ToStringBuilder(this)
                .append("board", board)
                .append("sudokuSolver", sudokuSolver)
                .toString();
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        BacktrackingSudokuSolver backtrackingSudokuSolver = new BacktrackingSudokuSolver();
        SudokuBoard sudokuBoard = new SudokuBoard(backtrackingSudokuSolver);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sudokuBoard.set(i, j, get(i, j));
            }
        }
        return sudokuBoard;
    }


}