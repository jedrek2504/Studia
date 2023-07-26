package model;

import java.util.ListResourceBundle;

public class Author extends ListResourceBundle {

    @Override
    protected Object[][] getContents() {
        return new Object[][]{
                {"1", "Jędrzej Kostyk"},
                {"2", "Grzegorz Bednarek"}
        };
    }
}
