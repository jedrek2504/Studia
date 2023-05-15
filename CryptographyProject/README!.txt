Following commends must be added to Run>Edit Configuration>Main>VM Options for JavaFX to work correctly.

--module-path C:\DevTools\javafx-sdk-19\lib
--add-modules javafx.controls,javafx.fxml
--add-exports javafx.graphics/com.sun.javafx.sg.prism=ALL-UNNAMED

module-path has to be a path to javafx-sdk-19