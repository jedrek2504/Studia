package model;
public class BacktrackingSudokuSolver implements SudokuSolver  {

    @Override
    public void solve(SudokuBoard board) {
        /*
        for (int row = 0; row < this.row; row++) {
            for (int col = 0; col < this.col; col++) {
                if (this.board[row][col] == 0) {
                    for (int value = 1; value <= 9; value++) {
                        if (this.checkAllConditions(row, col, value)) {
                            this.board[row][col] = value;
                            if (this.resolveBoard()) {
                                return true;
                            } else {
                                this.board[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        */

    }

}
