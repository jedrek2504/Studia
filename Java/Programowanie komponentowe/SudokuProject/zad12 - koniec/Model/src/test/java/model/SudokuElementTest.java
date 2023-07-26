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

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class SudokuElementTest {
    List<SudokuField> testSudokuFields;
    SudokuElement testSudokuElement;

    @BeforeEach
    public void sudokuSet() {
        testSudokuFields = new ArrayList<>(9);
        for (int i = 0; i < 9; i++) {
            testSudokuFields.add(new SudokuField());
        }
        testSudokuElement = new SudokuElement();
        for (int i = 0; i < 9; i++) {
            testSudokuElement.getSudokuElement().get(i).setFieldValue(i + 1);
        }
    }

    @Test
    public void testGetSudokuElement() {
        for (int i = 0;i < 9;i++) {
            assertEquals(testSudokuElement.getSudokuElement().get(i).getFieldValue(), i + 1);
        }
    }

    @Test
    public void testSetSudokuElement() {
        for (int i = 0;i < 9;i++) {
            testSudokuFields.get(i).setFieldValue((i + 1) * 10);
        }
        testSudokuElement.setSudokuElement(testSudokuFields);
        for (int i = 0;i < 9;i++) {
            assertEquals(testSudokuElement.getSudokuElement().get(i).getFieldValue(),
                    testSudokuFields.get(i).getFieldValue());
        }
    }

    @Test
    public void testElementNumberOutOfRange() {
        for (int i = 0;i < 9;i++) {
            testSudokuFields.get(i).setFieldValue((i + 1) * 100);
        }
        testSudokuElement.setSudokuElement(testSudokuFields);
        assertFalse(testSudokuElement.verify());
    }

    @Test
    public void testElementNumberRepeats() {
        for (int i = 0;i < 9;i++) {
            testSudokuFields.get(i).setFieldValue(1);
        }
        testSudokuElement.setSudokuElement(testSudokuFields);
        assertFalse(testSudokuElement.verify());
    }

    @Test
    public void testElementPositive() {
        for (int i = 0;i < 9;i++) {
            testSudokuFields.get(i).setFieldValue(i + 1);
        }
        testSudokuElement.setSudokuElement(testSudokuFields);
        assertTrue(testSudokuElement.verify());
    }

    @Test
    void testToString() {
        SudokuElement testSudokuElement1 = new SudokuElement();
        assertFalse(testSudokuElement1.toString().isEmpty());
    }

    @Test
    void testEqualsSameObjects() {
        SudokuElement testSudokuElement1 = testSudokuElement;
        assertEquals(testSudokuElement, testSudokuElement1);
    }

    @Test
    void testEqualsNULLValue() {
        SudokuElement testSudokuElement1 = null;
        assertFalse(testSudokuElement.equals(testSudokuElement1));

    }

    @Test
    public void testEqualsDifferentClasses() {
        SudokuBoard testSudokuBoard = new SudokuBoard(new BacktrackingSudokuSolver());
        assertFalse(testSudokuElement.equals(testSudokuBoard));
    }

    @Test
    void testEqualsBuilder() {
        SudokuElement testSudokuElement1 = new SudokuElement();
        SudokuElement testSudokuElement2 = new SudokuElement();
        assertEquals(testSudokuElement1, testSudokuElement2);
    }

    @Test
    void testHashCode() {
        SudokuElement testSudokuElement1 = new SudokuElement();
        SudokuElement testSudokuElement2 = new SudokuElement();
        assertEquals(testSudokuElement2.hashCode(),testSudokuElement1.hashCode());
        testSudokuElement1.getSudokuElement().set(0, new SudokuField(5));
        assertNotEquals(testSudokuElement2.hashCode(),testSudokuElement1.hashCode());
    }
}