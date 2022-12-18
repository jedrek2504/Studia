package model;

import java.util.ListResourceBundle;

public class Author extends ListResourceBundle {

    @Override
    protected Object[][] getContents() {
        return new Object[][] {
                {"--> ", "Jędrzej Kostyk"}
        };
    }
}
