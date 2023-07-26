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

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.LinkedList;
import java.util.List;
import model.exception.DatabaseException;

public class JdbcSudokuBoardDao implements Dao<SudokuBoard> {
    Connection connection;
    String boardName;

    public JdbcSudokuBoardDao(String boardName) {
        this.boardName = boardName;
    }

    private void connectionToDerby() throws DatabaseException {
        var dbUrl = "jdbc:derby:C:\\Derby\\SudokuDb";
        try {
            connection = DriverManager.getConnection(dbUrl);
        } catch (SQLException e) {
            throw new DatabaseException(e);
        }
    }

    @Override
    public SudokuBoard read() throws DatabaseException {
        connectionToDerby();
        SudokuBoard sudokuBoard = new SudokuBoard();
        try (Statement stmt = connection.createStatement()) {
            var sudokuBoardIdQuery = "Select ID FROM SUDOKUBOARDS WHERE NAME = '"
                    + boardName + "'";
            var rsIDs = stmt.executeQuery(sudokuBoardIdQuery);
            rsIDs.next();
            int boardID = rsIDs.getInt(1);

            var sudokuBoardFieldsQuery = "Select POSITION_X, POSITION_Y, VALUE, IS_ENABLED "
                    + "FROM SUDOKUFIELDS WHERE BOARD_ID = " + boardID;
            var fields = stmt.executeQuery(sudokuBoardFieldsQuery);

            int i = 0;
            while (i < 9) {
                for (int j = 0; j < 9; j++) {
                    fields.next();
                    var positionX = fields.getInt(1);
                    var positionY = fields.getInt(2);
                    var value = fields.getInt(3);
                    boolean isEnabled;
                    if (fields.getBoolean(4)) {
                        isEnabled = true;
                    } else {
                        isEnabled = false;
                    }
                    sudokuBoard.set(positionX, positionY, value);
                    if (isEnabled) {
                        sudokuBoard.setFieldEditable(positionX, positionY);
                    }
                }
                i++;
            }
        } catch (SQLException e) {
            throw new DatabaseException(e);
        }

        try {
            connection.close();
        } catch (SQLException e) {
            throw new DatabaseException(e);
        }
        return sudokuBoard;
    }

    @Override
    public void write(SudokuBoard sudokuBoard) throws DatabaseException {
        connectionToDerby();
        String sudokuBoardQuery = "insert into SUDOKUBOARDS (NAME) values ('" + boardName + "')";

        try (PreparedStatement pstmt = connection.prepareStatement(sudokuBoardQuery,
                Statement.RETURN_GENERATED_KEYS)) {
            pstmt.executeUpdate();
            ResultSet keys = pstmt.getGeneratedKeys();
            keys.next();
            int boardID = keys.getInt(1);

            Statement stmt = connection.createStatement();
            int i = 0;
            while (i < 9) {
                for (int j = 0; j < 9; j++) {
                    stmt.executeUpdate("insert into SUDOKUFIELDS (BOARD_ID, "
                            + "POSITION_X, POSITION_Y, VALUE, IS_ENABLED)" + "values (" + boardID
                            + "," + i + "," + j + "," + sudokuBoard.get(i, j)
                            + "," + sudokuBoard.isFieldEditable(i, j) + ")");
                }
                i++;
            }
        } catch (SQLException e) {
            throw new DatabaseException(e);
        }

        try {
            connection.close();
        } catch (SQLException e) {
            throw new DatabaseException(e);
        }
    }

    public static List<String> boardsList() throws DatabaseException {
        Connection connection;
        var dbUrl = "jdbc:derby:C:\\Derby\\SudokuDb";
        try {
            connection = DriverManager.getConnection(dbUrl);
        } catch (SQLException e) {
            throw new DatabaseException(e);
        }

        String sudokuBoardQuery = "Select NAME FROM SUDOKUBOARDS";
        List<String> boardList = new LinkedList<>();

        try (Statement stmt = connection.createStatement()) {
            ResultSet rs = stmt.executeQuery(sudokuBoardQuery);

            while (rs.next()) {
                String str = rs.getString("NAME");
                boardList.add(str);
            }
        } catch (SQLException e) {
            throw new DatabaseException(e);
        }
        return boardList;
    }

    @Override
    public void close() throws DatabaseException {
        try {
            connection.close();
        } catch (SQLException e) {
            throw new DatabaseException(e);
        }
    }

}
