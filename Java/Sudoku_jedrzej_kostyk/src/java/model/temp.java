package model;

import java.util.Random;

public class temp {
//declarations:
    private int[][] board;
    private final int row = 9; //size of the board stored in variables to help with future refactoring
    private final int col = 9;

//fills board following sudoku rules in a random manner.
    public void fillBoard(){
        this.board = new int[this.row][this.col];

        Random rand = new Random();

        //generates 2d array filled with random numbers
        for(int i=0 ; i<this.row ; i++) {
            for(int j=0 ; j<this.col ; j++) {
                this.board[i][j] = rand.nextInt(this.board.length) + 1;
            }
        }
        this.resolveBoard();
    }

//checks if row (as a whole) has a given value
    public boolean rowCheck(final int row , int value){
        for(int i=0; i<this.row ; i++){
            if(this.board[row][i] == value) return false;
        }
        return true;
    }

//checks if column (as a whole) has a given value
    public boolean colCheck(final int col , int value){
        for(int i=0; i<this.col ; i++){
            if(this.board[i][col] == value) return false;
        }
        return true;
    }

//checks if specific square has a given value
    public boolean sqrCheck(final int row , final int col , int value){
        //first I need coords of left right corner of the square:
        int currentSqrRow = row - (row % 3); //determines what row the mentioned square begins
        int currentSqrCol = col - (col % 3); //determines what col the mentioned square begins

        //we go trough every (of the 9) given places and check if given value is in any of them
        for(int i=currentSqrRow ; i<currentSqrRow+3 ; i++){
            for(int j=currentSqrCol; j<currentSqrCol+3 ; j++){
                if(this.board[i][j]==value){
                    return false;
                }
            }
        }
        return true;
    }

//checks if given number in given place(row,col) abides Sudoku rules
    public boolean checkAllConditions(final int row, final int col , int value){
        if(this.rowCheck(row,value)==true && this.colCheck(col,value)==true && this.sqrCheck(row,col,value)==true) return true;
        return false;
    }

    public boolean resolveBoard(){
        for(int row=0; row<this.row ; row++){
            for(int col=0; col<this.col ; col++){
                if(this.board[row][col]==0){
                    for(int value=1 ; value<=9 ; value++){
                        if(this.checkAllConditions(row, col, value)) {
                            this.board[row][col] = value;
                            if(resolveBoard()){
                                return true;
                            }
                            else {
                                this.board[row][col]=0;
                            }
                        }
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public String toString(){
        StringBuilder chain = new StringBuilder();

        for(int i=0 ; i<row ; i++) {
            for(int j=0 ; j<col ; j++){
                chain.append(this.board[i][j]);
                chain.append(' ');
            }
            chain.append('\n');
        }
        return chain.toString();
    }

}


