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

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class FileSudokuBoardDao implements Dao<SudokuBoard> {

    private final String fileName;

    public FileSudokuBoardDao(String fileName) {
        this.fileName = fileName;
    }

    @Override
    public SudokuBoard read() {
        SudokuBoard sudokuBoard = new SudokuBoard(null);
        String line;

        try (BufferedReader fileReader = new BufferedReader(new FileReader(fileName))) {
            for (int i = 0; i < 9; i++) {
                line = fileReader.readLine();
                String[] pieces = line.split(",");
                for (int j = 0;j < 9; j++) {
                    sudokuBoard.set(i,j,Integer.parseInt(pieces[j]));
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return sudokuBoard;
    }

    @Override
    public void write(SudokuBoard sudokuBoard) {
        try (PrintWriter printWriter = new PrintWriter(new File(fileName))) {
            for (int i = 0;i < 9; i++) {
                for (int j = 0;j < 9; j++) {
                    printWriter.print(sudokuBoard.get(i,j));
                    if (j < 8) {
                        printWriter.print(",");
                    } else {
                        printWriter.println();
                    }
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void close() throws Exception {

    }

}
