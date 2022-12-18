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

import java.io.IOException;


class FileSudokuBoardDaoTest {

    @Test
    public void testWriteRead() {
        SudokuBoard sudokuBoard = new SudokuBoard(new BacktrackingSudokuSolver());
        sudokuBoard.solveGame();
        FileSudokuBoardDao fileSudokuBoardDao = new FileSudokuBoardDao("sudokuboard");
        fileSudokuBoardDao.write(sudokuBoard);
        assertEquals(fileSudokuBoardDao.read(), sudokuBoard);

    }

    @Test
    public void testReadException() {
        FileSudokuBoardDao fileSudokuBoardDao = new FileSudokuBoardDao("null");
        Throwable exception = assertThrows(RuntimeException.class, fileSudokuBoardDao::read);
        assertEquals("java.io.FileNotFoundException: null (Nie można odnaleźć określonego pliku)",
                exception.getMessage());
    }

    @Test
    public void testWriteException() {
        SudokuBoard sudokuBoard = new SudokuBoard(new BacktrackingSudokuSolver());
        sudokuBoard.solveGame();
        FileSudokuBoardDao fileSudokuBoardDao = new FileSudokuBoardDao("");
        Throwable exception = assertThrows(RuntimeException.class,
                () -> fileSudokuBoardDao.write(sudokuBoard));
        assertEquals("java.io.FileNotFoundException:  "
                        + "(System nie może odnaleźć określonej ścieżki)",
                exception.getMessage());
    }

    @Test
    void fullSerializationDeserializationTest() {
        String filename = "fullSerializationDeserializationTestFile";

        SudokuBoard writeBoard = new SudokuBoard(new BacktrackingSudokuSolver()) ;
        writeBoard.solveGame();
        try (FileSudokuBoardDao sudokuDao = (FileSudokuBoardDao) SudokuBoardDaoFactory
                .getFileDao(filename)) {
            sudokuDao.write(writeBoard) ;
            SudokuBoard readBoard = sudokuDao.read() ;
            assertEquals(writeBoard, readBoard) ;
        } catch (IOException e) {
            throw new RuntimeException(e) ;
        } catch(ClassNotFoundException e) {
            throw new RuntimeException(e) ;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
