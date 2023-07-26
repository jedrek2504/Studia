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
import java.util.Locale;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.stage.FileChooser;
import model.exception.DaoException;
import model.exception.DatabaseException;
import model.exception.NoFileException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;


public class WindowController {

    private final Logger log = LoggerFactory.getLogger(WindowController.class);
    PopUpWindow popUpWindow = new PopUpWindow();

    @FXML
    private ComboBox<String> comboBoxDifficulty;
    @FXML
    private ComboBox<String> comboBoxLanguage;

    private static String level;
    private final ResourceBundle resourceBundle = ResourceBundle.getBundle("lang");
    private static SudokuBoard sudokuBoardFromFile;
    private static SudokuBoard sudokuBoardFromDatabase;

    public static String getLevel() {
        return level;
    }

    public static SudokuBoard getSudokuBoardFromFile() {
        return sudokuBoardFromFile;
    }

    public static SudokuBoard getSudokuBoardFromDatabase() {
        return sudokuBoardFromDatabase;
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
    public void startGameButtonAction() {
        try {
            FxmlStageSetup.buildStage("/sudokuBoard.fxml");
        } catch (IOException e) {
            log.warn("Cannot build a stage!");
        }
        log.info("Game started!");
    }

    @FXML
    private void confirmLanguageButtonAction() {
        if (!comboBoxLanguage.getSelectionModel().isEmpty()) {
            String language = comboBoxLanguage.getSelectionModel().getSelectedItem();

            if (language.equals(resourceBundle.getString("comboBoxPolish"))) {
                Locale.setDefault(new Locale("pl"));
            } else if (language.equals(resourceBundle.getString("comboBoxEnglish"))) {
                Locale.setDefault(new Locale("en"));
            }

            try {
                FxmlStageSetup.buildStage("/window.fxml");
            } catch (IOException e) {
                log.warn("Stage building failed!");
            }
            log.info("Language changed to: "
                    + comboBoxLanguage.getSelectionModel().getSelectedItem());
        }
    }

    @FXML
    private void loadFromFileButtonAction() throws IOException {
        FileChooser fileChooser = new FileChooser();
        FileChooser.ExtensionFilter extFilter =
                new FileChooser.ExtensionFilter("Sudoku board files (*.sudoku)", "*.sudoku");
        fileChooser.getExtensionFilters().add(extFilter);
        boolean success = true;
        try {
            File file = fileChooser.showOpenDialog(FxmlStageSetup.getStage());
            FileSudokuBoardDao fileSudokuBoardDao = new FileSudokuBoardDao(file.getName());
            sudokuBoardFromFile = fileSudokuBoardDao.read();
            FxmlStageSetup.buildStage("/sudokuBoard.fxml");
        } catch (NullPointerException | DaoException | NoFileException e) {
            success = false;
            log.warn("Cannot read from file!");
        }
        if (success) {
            log.info("Sudoku successfully loaded from file!");
        }
    }

    @FXML
    private void getAuthorButtonAction() {
        ResourceBundle listBundle = ResourceBundle.getBundle("model.Author");
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setContentText(listBundle.getObject("--> ") + "\n");
        alert.showAndWait();
        log.info("Author has been displayed");
    }

    @FXML
    private void confirmDifficultyButtonAction() {
        if (!comboBoxDifficulty.getSelectionModel().isEmpty()) {
            level = comboBoxDifficulty.getSelectionModel().getSelectedItem();
        }
        log.info("Difficulty changed to: "
                + comboBoxDifficulty.getSelectionModel().getSelectedItem());
    }

    @FXML
    private void loadFromDatabaseButtonAction() {
        boolean success = true;
        try {
            var boardsList = JdbcSudokuBoardDao.boardsList();
            String boardName = popUpWindow.choiceDialog(boardsList);
            JdbcSudokuBoardDao databaseBoard = new JdbcSudokuBoardDao(boardName);
            sudokuBoardFromDatabase = databaseBoard.read();
            FxmlStageSetup.buildStage("/sudokuBoard.fxml");
        } catch (DatabaseException | NoFileException e) {
            success = false;
            log.warn("Cannot read from DB");
        }
        if (success) {
            log.warn("Sudoku successfully loaded from DB");
        }
    }

}