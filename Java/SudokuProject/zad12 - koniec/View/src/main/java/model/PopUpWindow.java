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

import java.util.List;
import java.util.Optional;
import javafx.scene.control.ChoiceDialog;
import javafx.scene.control.TextInputDialog;


public class PopUpWindow {

    public String textInputDialog() {
        var dialog = new TextInputDialog();
        dialog.setTitle("Save to DB");
        dialog.setHeaderText("Saving board to DB");
        dialog.setContentText("Enter board name:");
        Optional<String> result = dialog.showAndWait();
        return result.orElse("");
    }

    public String choiceDialog(List<String> boardsList) {
        var dialog = new ChoiceDialog<String>("choose",boardsList);
        dialog.setTitle("Load from DB");
        dialog.setHeaderText("Loading board from DB");
        dialog.setContentText("Choose saved board:");
        Optional<String> result = dialog.showAndWait();
        return result.orElse("");
    }
}