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
import java.io.File;
import java.io.IOException;
import java.util.Locale;
import java.util.ResourceBundle;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.stage.FileChooser;


public class StackPaneController {
    @FXML
    private ComboBox<String> comboBoxDifficulty;
    @FXML
    private ComboBox<String> comboBoxLanguage;

    private final Author author = new Author();
    private static String level;
    private static String language;
    private final ResourceBundle resourceBundle = ResourceBundle.getBundle("lang");
    private static SudokuBoard sudokuBoardFromFile;

    public static String getLevel() {
        return level;
    }

    public static SudokuBoard getSudokuBoardFromFile() {
        return sudokuBoardFromFile;
    }

    @FXML
    private void initialize() {
        comboBoxLanguage.getItems().addAll(
                resourceBundle.getString("comboBoxPolish"),
                resourceBundle.getString("comboBoxEnglish")
        );

        comboBoxDifficulty.getItems().addAll(
                resourceBundle.getString("comboBoxEasy"),
                resourceBundle.getString("comboBoxMedium"),
                resourceBundle.getString("comboBoxHard")
        );
    }

    @FXML
    public void startGameButtonAction() throws IOException {
        if(!comboBoxDifficulty.getSelectionModel().isEmpty()) {
            level = comboBoxDifficulty.getSelectionModel().getSelectedItem().toString();
        } else {
            level = "Easy";
        }
        FxmlStageSetup.buildStage("/sudokuBoard.fxml", resourceBundle);
    }

    @FXML
    private void confirmLanguageButtonAction() throws IOException {
        language = comboBoxLanguage.getSelectionModel().getSelectedItem().toString();

        if (language.equals(resourceBundle.getString("comboBoxPolish"))) {
            Locale.setDefault(new Locale("pl"));
        } else if (language.equals(resourceBundle.getString("comboBoxEnglish"))) {
            Locale.setDefault(new Locale("en"));
        }

        FxmlStageSetup.buildStage("/main.fxml", resourceBundle.getString("title"), resourceBundle);

    }

    @FXML
    private void loadFromFileButtonAction() throws IOException {
        FileChooser fileChooser = new FileChooser();
        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("Sudoku board files (*.sudoku)", "*.sudoku");
        fileChooser.getExtensionFilters().add(extFilter);
        File file = fileChooser.showOpenDialog(FxmlStageSetup.getStage());
        FileSudokuBoardDao fileSudokuBoardDao = new FileSudokuBoardDao(file.getName());
        sudokuBoardFromFile = fileSudokuBoardDao.read();
        FxmlStageSetup.buildStage("/sudokuBoard.fxml", resourceBundle);
    }

    @FXML
    private void getAuthorButtonAction() {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setContentText(author.getObject("--> ") + "\n");
        alert.showAndWait();
    }
}