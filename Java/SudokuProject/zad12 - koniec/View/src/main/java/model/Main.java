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
import javafx.application.Application;
import javafx.stage.Stage;
import model.exception.NoFileException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;


public class Main extends Application {

    private static final Logger log = LoggerFactory.getLogger(Main.class);

    public static void main(String[] args) {
        log.info("App started!");
        launch(args);
    }

    @Override
    public void start(Stage stage) throws NoFileException {
        try {
            FxmlStageSetup.buildStage(stage, "/window.fxml");
        } catch (IOException e) {
            log.warn("Stage building failed!");
            throw new NoFileException(e);
        }
    }
}