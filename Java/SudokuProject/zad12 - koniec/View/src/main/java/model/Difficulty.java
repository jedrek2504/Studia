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

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Difficulty {
    private final Random random = new Random();
    private final List<Field> fieldsToDelete = new ArrayList<>();

    private void deleteFields(int quantity) {
        for (int i = 0; i < quantity; i++) {
            boolean isElementAdded = false;
            while (!isElementAdded) {
                int x = random.nextInt(9);
                int y = random.nextInt(9);
                isElementAdded = fieldsToDelete.add(new Field(x, y));
            }
        }
    }

    public void chooseLevel(SudokuBoard sudokuBoard, String level) {
        switch (level) {
            case "Easy","Latwy" -> {
                deleteFields(20);
                break;
            }
            case "Medium","Sredni" -> {
                deleteFields(40);
                break;
            }
            case "Hard","Trudny" -> {
                deleteFields(60);
                break;
            }
            default -> {
                deleteFields(20);
            }
        }

        for (Field field : fieldsToDelete) {
            sudokuBoard.set(field.getX(), field.getY(), 0);
            sudokuBoard.setFieldEditable(field.getX(), field.getY());
        }
    }

}
