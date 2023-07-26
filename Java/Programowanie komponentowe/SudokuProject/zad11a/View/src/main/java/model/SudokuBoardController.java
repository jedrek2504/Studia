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

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Font;
import javafx.stage.FileChooser;
import java.io.File;

public class SudokuBoardController {

    @FXML
    private GridPane sudokuBoardGrid;
    private final BacktrackingSudokuSolver backtrackingSudokuSolver =
            new BacktrackingSudokuSolver();
    private SudokuBoard sudokuBoard = new SudokuBoard(backtrackingSudokuSolver);
    private final Difficulty difficulty = new Difficulty();

    @FXML
    private void initialize() {
        if (StackPaneController.getSudokuBoardFromFile() != null) {
            sudokuBoard = StackPaneController.getSudokuBoardFromFile();
        } else {
            sudokuBoard.solveGame();
            difficulty.chooseLevel(sudokuBoard, StackPaneController.getLevel());
        }
        fillGrid();
    }

    private boolean isFieldValid(String fieldValue) {
        return ((fieldValue.matches("[1-9]") && (!fieldValue.isEmpty())));
    }

    private void fillGrid() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                TextField textField = new TextField();
                textField.setMinSize(50, 50);
                textField.setFont(Font.font("Poor Richard",32));
                if (sudokuBoard.get(i, j) != 0) {
                    textField.setDisable(true);
                    textField.setText(String.valueOf(sudokuBoard.get(i, j)));
                }
                sudokuBoardGrid.add(textField, i, j);
            }
        }
    }

    @FXML
    private void saveButtonAction() {
        FileChooser fileChooser = new FileChooser();
        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("Sudoku board files (*.sudoku)", "*.sudoku");
        fileChooser.getExtensionFilters().add(extFilter);
        File file = fileChooser.showSaveDialog(FxmlStageSetup.getStage());

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sudokuBoard.get(i, j) == 0) {
                    String fieldValue = ((TextField) sudokuBoardGrid.getChildren().get(i * 9 + j)).getText();
                    if (isFieldValid(fieldValue)) {
                        sudokuBoard.set(i, j, Integer.parseInt(fieldValue));
                    }
                }
            }
        }

        FileSudokuBoardDao fileSudokuBoardDao = new FileSudokuBoardDao(file.getName());
        fileSudokuBoardDao.write(sudokuBoard);
    }
}
