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

import java.io.IOException;
import java.util.ResourceBundle;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import model.exception.NoFileException;

public class FxmlStageSetup {

    private static final Logger log = LoggerFactory.getLogger(FxmlStageSetup.class);
    private static Stage stage;
    private static final String title = "Sudoku";


    public static Stage getStage() {
        return stage;
    }

    private static void setStage(Stage stage) {
        FxmlStageSetup.stage = stage;
    }

    private static Parent loadFxml(String fxml, ResourceBundle resourceBundle)
            throws NoFileException {
        try {
            return new FXMLLoader(FxmlStageSetup.class.getResource(fxml), resourceBundle).load();
        } catch (IOException e) {
            log.warn("Cannot load FXML file!");
            throw new NoFileException(e);
        }
    }

    public static void buildStage(String filePath) throws NoFileException {
        try {
            stage.setScene(new Scene(loadFxml(filePath, ResourceBundle.getBundle("lang"))));
            stage.setTitle(title);
            stage.sizeToScene();
            stage.show();
        } catch (IOException e) {
            log.warn("Cannot build a stage!");
            throw new NoFileException(e);
        }
    }

    public static void buildStage(Stage stage, String filePath) throws NoFileException {
        try {
            setStage(stage);
            stage.setScene(new Scene(loadFxml(filePath, ResourceBundle.getBundle("lang"))));
            stage.setTitle(title);
            stage.sizeToScene();
            stage.show();
        } catch (IOException e) {
            log.warn("Cannot build a stage!");
            throw new NoFileException(e);
        }
    }
}