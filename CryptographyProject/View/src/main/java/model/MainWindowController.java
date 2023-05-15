package model;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;

import java.util.Locale;
import java.util.Objects;
import java.util.ResourceBundle;


public class MainWindowController {
    @FXML
    private ComboBox<String> comboBoxAlgorithm;
    @FXML
    private ComboBox<String> comboBoxLanguage;

    private static String algorithmChoice;
    private final ResourceBundle resourceBundle = ResourceBundle.getBundle("lang");


    @FXML
    private void initialize() {
        comboBoxLanguage.getItems().addAll(resourceBundle.getString("comboBoxPolish"), resourceBundle.getString("comboBoxEnglish"));

        comboBoxAlgorithm.getItems().addAll(resourceBundle.getString("comboBoxAES"), resourceBundle.getString("comboBoxDSA"));

        comboBoxAlgorithm.setValue(resourceBundle.getString("comboBoxAES")); // Set comboBoxAES as default value

        algorithmChoice = resourceBundle.getString("comboBoxAES");
    }

    @FXML
    public void startButtonAction() {
        if (!comboBoxAlgorithm.getSelectionModel().isEmpty()) {
            if (Objects.equals(algorithmChoice, resourceBundle.getString("comboBoxAES"))) {
                // load AES algorithm window
                FxmlStageSetup.buildStage("/AesWindow.fxml");

            } else if (Objects.equals(algorithmChoice, resourceBundle.getString("comboBoxDSA"))) {

                FxmlStageSetup.buildStage("/DsaWindow.fxml");

            } else {
                System.out.println("Nie ma takiej opcji :C");
            }
        }
    }



    @FXML
    private void confirmLanguageButtonAction() {
        if (!comboBoxLanguage.getSelectionModel().isEmpty()) {
            String language = comboBoxLanguage.getSelectionModel().getSelectedItem();

            if (language.equals(resourceBundle.getString("comboBoxPolish"))) {
                Locale.setDefault(new Locale("pl"));
            } else if (language.equals(resourceBundle.getString("comboBoxEnglish"))) {
                Locale.setDefault(new Locale("en"));
            }

            FxmlStageSetup.buildStage("/window.fxml");
        }
    }


    @FXML
    private void getAuthorButtonAction() {
        ResourceBundle listBundle = ResourceBundle.getBundle("model.Author");
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        String author1 = listBundle.getObject("1").toString();
        String author2 = listBundle.getObject("2").toString();
        alert.setContentText(author1 + "\n" + author2 + "\n");
        alert.showAndWait();
    }


    @FXML
    private void confirmAlgorithmButtonAction() {
        if (!comboBoxAlgorithm.getSelectionModel().isEmpty()) {
            algorithmChoice = comboBoxAlgorithm.getSelectionModel().getSelectedItem();
        }
    }


}