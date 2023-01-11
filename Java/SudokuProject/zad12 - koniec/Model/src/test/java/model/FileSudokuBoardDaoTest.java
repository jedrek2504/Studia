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

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.Test;
import model.exception.FileIoException;

class FileSudokuBoardDaoTest {

    @Test
    public void testReadException() {
        FileSudokuBoardDao fileSudokuBoardDao = (FileSudokuBoardDao) SudokuBoardDaoFactory
                .getFileDao("null");
        assertThrows(FileIoException.class, fileSudokuBoardDao::read);
    }

    @Test
    public void testWriteException() {
        FileSudokuBoardDao fileSudokuBoardDao = (FileSudokuBoardDao) SudokuBoardDaoFactory
                .getFileDao("");

        SudokuBoard sudokuBoard = new SudokuBoard(new BacktrackingSudokuSolver());
        sudokuBoard.solveGame();
        assertThrows(FileIoException.class,
                () -> fileSudokuBoardDao.write(sudokuBoard));
    }

    @Test
    public void testWriteRead() throws FileIoException {
        FileSudokuBoardDao fileSudokuBoardDao = (FileSudokuBoardDao) SudokuBoardDaoFactory
                .getFileDao("sudokuBoard");

        SudokuBoard sudokuBoard = new SudokuBoard();
        sudokuBoard.solveGame();

        fileSudokuBoardDao.write(sudokuBoard);
        assertEquals(fileSudokuBoardDao.read(), sudokuBoard);
    }
}