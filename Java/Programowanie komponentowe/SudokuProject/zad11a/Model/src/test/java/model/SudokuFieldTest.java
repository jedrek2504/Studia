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

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class SudokuFieldTest {
    SudokuField testSudokuField;

    @BeforeEach
    public void sudokuSet() {
        testSudokuField = new SudokuField();
    }

    @Test
    public void testDefaultValue() {
        assertEquals(testSudokuField.getFieldValue(), 0);
    }

    @Test
    public void testSetGetSudokuField() {
        testSudokuField.setFieldValue(1);
        assertEquals(testSudokuField.getFieldValue(), 1);
    }

    @Test
    void testToString() {
        SudokuField testSudokuField1 = new SudokuField(1);
        int value = testSudokuField1.getFieldValue();
        assertEquals(testSudokuField1.toString(), "model.SudokuField{value=" + value + "}");
    }


    @Test
    void testEqualsSameObjects() {
        SudokuField testSudokuField1 = testSudokuField;
        assertTrue(testSudokuField.equals(testSudokuField1));
    }

    @Test
    void testEqualsNULLValue() {
        SudokuField testSudokuField1 = null;
        assertFalse(testSudokuField.equals(testSudokuField1));
    }

    @Test
    void testEqualsNotGood() {
        SudokuElement testSudokuElement = new SudokuElement();
        assertFalse(testSudokuField.equals(testSudokuElement));
    }

    @Test
    void testGetClass() {
        SudokuField testSudokuField1 = new SudokuField();
        assertEquals(testSudokuField.getClass(), testSudokuField1.getClass());
    }

    @Test
    public void testHashCodeAndEqualsCoherentGood() {
        SudokuField testSudokuField1 = testSudokuField;
        assertTrue(testSudokuField1.hashCode() == testSudokuField.hashCode());
        assertTrue(testSudokuField1.equals(testSudokuField));
    }

    @Test
    public void compareToTest() {
        SudokuField sudokuField = new SudokuField(5);
        SudokuField sudokuField2 = new SudokuField(5);

        assertEquals(sudokuField.compareTo(sudokuField2), 0);

        sudokuField.setFieldValue(8);
        assertEquals(sudokuField.compareTo(sudokuField2), 1);

        sudokuField.setFieldValue(2);
        assertEquals(sudokuField.compareTo(sudokuField2), -1);
        assertThrows(NullPointerException.class, () -> sudokuField.compareTo(null));
    }

}