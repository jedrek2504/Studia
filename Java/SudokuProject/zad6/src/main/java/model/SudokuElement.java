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

import java.util.Arrays;
import java.util.List;
import org.apache.commons.lang3.builder.EqualsBuilder;
import org.apache.commons.lang3.builder.HashCodeBuilder;

public class SudokuElement {
    private final List<SudokuField> list = Arrays.asList(new SudokuField[9]);

    public SudokuElement() {
        for (int i = 0; i < 9; i++) {
            list.set(i, new SudokuField());
        }
    }

    public List<SudokuField> getSudokuElement() {
        return list;
    }

    public void setSudokuElement(List<SudokuField> lista) {
        for (int i = 0;i < 9; i++) {
            list.set(i, lista.get(i));
        }
    }

    public boolean verify() {
        for (int i = 0;i < 9;i++) {
            if (list.get(i).getFieldValue() < 1 || list.get(i).getFieldValue() > 9) {
                return false;
            }
        }
        for (int i = 0;i < 9;i++) {
            for (int j = 0; j < 9; j++) {
                if (list.get(i).getFieldValue() == list.get(j).getFieldValue() && i != j) {
                    return false;
                }
            }
        }
        return true;
    }

    @Override
    public String toString() {
        return "pl.cp.first.SudokuVerify{"
                + "list=" + list + '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        SudokuElement sudokuElement = (SudokuElement) o;
        return new EqualsBuilder()
                .append(list, sudokuElement.list)
                .isEquals();
    }

    @Override
    public int hashCode() {
        return new HashCodeBuilder(17, 37)
                .append(list)
                .toHashCode();
    }
}
