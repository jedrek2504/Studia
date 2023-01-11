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

import java.io.File;
import java.io.IOException;
import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Font;
import javafx.stage.FileChooser;
import model.exception.DaoException;
import model.exception.DatabaseException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class SudokuBoardController {

    @FXML
    private GridPane sudokuBoardGrid;

    PopUpWindow popUpWindow = new PopUpWindow();
    private SudokuBoard sudokuBoard = new SudokuBoard();
    private final Difficulty difficulty = new Difficulty();
    private static final Logger log = LoggerFactory.getLogger(SudokuBoardController.class);


    @FXML
    private void initialize() {
        if (WindowController.getSudokuBoardFromFile() != null) {
            sudokuBoard = WindowController.getSudokuBoardFromFile();
        } else if (WindowController.getSudokuBoardFromDatabase() != null) {
            sudokuBoard = WindowController.getSudokuBoardFromDatabase();
        } else {
            sudokuBoard.solveGame();
            String level = WindowController.getLevel();
            if (level == null) {
                level = "Easy";
            }
            difficulty.chooseLevel(sudokuBoard, level);
        }
        fillGrid();
    }

    private boolean isFieldValid(String fieldValue) {
        return ((fieldValue.matches("[1-9]")));
    }

    private void fillGrid() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                TextField textField = new TextField();
                textField.setMinSize(50, 50);
                textField.setFont(Font.font("Poor Richard", 32));
                if (sudokuBoard.get(i, j) != 0) {
                    if (!sudokuBoard.isFieldEditable(i, j)) {
                        textField.setDisable(true);
                    }
                    textField.setText(String.valueOf(sudokuBoard.get(i, j)));
                    log.info("Field [" + i + ", " + j + "]: New value: "
                            + sudokuBoard.get(i, j) + ".");

                }
                sudokuBoardGrid.add(textField, i, j);

                int finalI = i;
                int finalJ = j;
                textField.textProperty().addListener((observable, oldValue, newValue) -> {
                    String lastChar = null;
                    if (newValue.length() == 2) {
                        newValue = newValue.substring(1, 2);
                    }
                    if (oldValue.length() == 2) {
                        lastChar = oldValue;
                        oldValue = oldValue.substring(0, 1);
                    }

                    if (oldValue.isEmpty()) {
                        if (isFieldValid(newValue)) {
                            sudokuBoard.set(finalI, finalJ, Integer.parseInt(newValue));
                            log.info("Field [" + finalI + ", " + finalJ + "]: "
                                    + "New value: " + newValue + ".");
                        } else {
                            log.info("Field [" + finalI + ", " + finalJ + "]: Input (" + newValue
                                    + ") not in [1-9].");
                            textField.clear();
                        }
                    } else if (isFieldValid(oldValue) && isFieldValid(newValue)
                            && !oldValue.equals(newValue) && lastChar == null) {
                        log.info("Field [" + finalI + ", " + finalJ + "]: Value changed from: "
                                + oldValue + " to " + newValue + ".");
                        sudokuBoard.set(finalI, finalJ, Integer.parseInt(newValue));
                        textField.setText(newValue);
                    } else if (isFieldValid(oldValue) && !isFieldValid(newValue)) {
                        log.info("Field [" + finalI + ", " + finalJ + "]: Input (" + newValue
                                + ") not in [1-9].");
                        textField.setText(oldValue);
                    } else if (oldValue.equals(newValue)) {
                        textField.setText(oldValue);
                    }
                });
            }
        }
    }

    @FXML
    private void backButtonAction() {
        try {
            FxmlStageSetup.buildStage("/window.fxml");
        } catch (IOException e) {
            log.warn("Stage building failed!");
        }
    }

    @FXML
    private void saveButtonAction() {
        FileChooser fileChooser = new FileChooser();
        FileChooser.ExtensionFilter extFilter =
                new FileChooser.ExtensionFilter("Sudoku board files (*.sudoku)", "*.sudoku");
        fileChooser.getExtensionFilters().add(extFilter);
        boolean success = true;
        try {
            File file = fileChooser.showSaveDialog(FxmlStageSetup.getStage());
            FileSudokuBoardDao fileSudokuBoardDao = new FileSudokuBoardDao(file.getName());
            fileSudokuBoardDao.write(sudokuBoard);
        } catch (NullPointerException | DaoException e) {
            success = false;
            log.warn("Cannot save to file!");
        }
        if (success) {
            log.info("Game saved successfully!");
        }
    }

    @FXML
    private void saveDatabaseButtonAction() throws DatabaseException {
        boolean success = true;
        try {
            String name = popUpWindow.textInputDialog();
            JdbcSudokuBoardDao databaseBoard = new JdbcSudokuBoardDao(name);
            databaseBoard.write(sudokuBoard);
        } catch (DatabaseException e) {
            success = false;
            log.warn("Cannot save to DB");
        }
        if (success) {
            log.warn("Game saved successfully to DB");
        }
    }
}

