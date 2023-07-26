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
import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;

public class StackPaneController {
    private static String level;

    public static String getLevel() {
        return level;
    }

    @FXML
    private ComboBox<?> comboBoxDifficulty;

    @FXML
    public void startGameButtonAction() throws IOException {
        if (!comboBoxDifficulty.getSelectionModel().isEmpty()) {
            level = comboBoxDifficulty.getSelectionModel().getSelectedItem().toString();
        } else {
            level = "Latwy";
        }
        FxmlStageSetup.buildStage("/sudokuBoard.fxml");
    }
}
