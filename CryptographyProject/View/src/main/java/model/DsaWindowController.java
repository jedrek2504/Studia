package model;

import com.gluonhq.charm.glisten.control.ToggleButtonGroup;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;

import javax.swing.text.Utilities;
import java.io.*;
import java.math.BigInteger;
import java.nio.Buffer;
import java.util.HexFormat;

public class DsaWindowController {
    public Button generateKeysButton;
    public TextArea DsaInputTextArea;
    public TextArea DsaOutputTextArea;
    public ToggleButtonGroup toggleButtonsGroup;
    public ToggleButton toggleButtonWindow;
    public ToggleButton toggleButtonFile;
    public Button signButton;
    public Button verifyButton;
    public Text chooseFile1PathText;
    public Button chooseFileButton1;
    public Text loadKeyPath;
    public Text saveKeysPath;
    public Button loadKeysButton;
    public Button saveKeysButton;
    public Text saveSignaturePath;
    public Text saveSignedTextPath;
    public Text chooseFile2PathText;
    public Button chooseFileButton2;
    public Button saveTextButton;
    public Button saveSignedTextButton;
    public TextField DsaGeneratedKeyField;
    public TextField DsaGeneratedKeyField2;
    public TextField DsaGeneratedKeyField3;
    public TextField DsaGeneratedKeyField4;
    public Text DsaKeyText1;
    public Text DsaKeyText2;
    public Text DsaKeyText3;
    public Text DsaKeyText4;

    DSA dsa;

    BigInteger [] signature = new BigInteger[2];
    private byte[] message;
    boolean isWindow = false;

    @FXML
    public void initialize() {
        dsa = new DSA();
        // Set the default state of the toggle buttons
        toggleButtonWindow.setSelected(true);
        toggleButtonFile.setSelected(false);
        hideFileNodes();
        isWindow = true;
    }

    public void generateKeysButtonAction(ActionEvent actionEvent) {
        dsa.generateKey();
        DsaGeneratedKeyField.setText(dsa.q.toString(16) + dsa.g.toString(16));
        DsaGeneratedKeyField2.setText(dsa.y.toString(16));
        DsaGeneratedKeyField3.setText(dsa.x.toString(16));
        DsaGeneratedKeyField4.setText(dsa.p.toString(16));
    }

    @FXML
    private void signButtonAction(ActionEvent event) {
        if(message == null) {
            message = DsaInputTextArea.getText().getBytes();
        }
        signature = dsa.sign(message);
        DsaOutputTextArea.setText(signature[0].toString(16) + "\n" + signature[1].toString(16));
    }


    @FXML
    public void verifyButtonAction(ActionEvent actionEvent) {
        if(isWindow) {
            message = DsaInputTextArea.getText().getBytes();
        }
        boolean isVerified = dsa.verify(message, signature);
        if (isVerified) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Verification Result");
            alert.setHeaderText("Signature is Valid");
            alert.setContentText("The signature is verified successfully!");
            alert.showAndWait();
        } else {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Verification Result");
            alert.setHeaderText("Signature is Invalid");
            alert.setContentText("The signature could not be verified!");
            alert.showAndWait();
        }
    }

    private void hideFileNodes() {
        // Hide the file-related nodes
        chooseFile1PathText.setVisible(false);
        chooseFileButton1.setVisible(false);
        chooseFile2PathText.setVisible(false);
        chooseFileButton2.setVisible(false);
    }

    private void showFileNodes() {
        // Show the file-related nodes
        chooseFile1PathText.setVisible(true);
        chooseFileButton1.setVisible(true);
        chooseFile2PathText.setVisible(true);
        chooseFileButton2.setVisible(true);
    }

    @FXML
    public void toggleButtonAction(ActionEvent actionEvent) {
        // Handle toggle button events
        if (actionEvent.getSource() == toggleButtonWindow) {
            hideFileNodes();
            isWindow = true;
        } else if (actionEvent.getSource() == toggleButtonFile) {
            showFileNodes();
            isWindow = false;
        }
    }


    public void chooseFileButtonAction(ActionEvent actionEvent) {
        FileChooser fileChooser = new FileChooser();

        // Set the initial directory for the FileChooser
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));

        File selectedFile = fileChooser.showOpenDialog(null);

        if (selectedFile != null) {
            String filePath = selectedFile.getAbsolutePath();
            if (actionEvent.getSource().equals(chooseFileButton1)) {
                try {
                    FileInputStream inputStream = new FileInputStream(selectedFile);
                    chooseFile1PathText.setText(filePath);
                    message = inputStream.readAllBytes();
                    inputStream.close();

                    byte[] tmpArray = new byte[1000];

                    if (message != null) {
                        // copy the first 3000 bytes from the original array to the tmp array
                        System.arraycopy(message, 0, tmpArray, 0, 1000);
                        DsaInputTextArea.setText(new String(tmpArray));
                    }

                    // Display a success message
                    Alert alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("File loaded");
                    alert.setHeaderText(null);
                    alert.setContentText("The file has been loaded.");
                } catch (IOException e) { // If there was an error loading the file
                    e.printStackTrace();

                    // Display an error message
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error");
                    alert.setHeaderText("Error loading file");
                    alert.setContentText("There was an error loading the file.");
                    alert.showAndWait();
                }
            } else if (actionEvent.getSource().equals(chooseFileButton2)) {

                try {
                    FileInputStream inputStream = new FileInputStream(selectedFile);
                    BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
                    String rString = reader.readLine();
                    String sString = reader.readLine();
                    BigInteger r = new BigInteger(rString);
                    BigInteger s = new BigInteger(sString);
                    signature[0] = r;
                    signature[1] = s;
                    reader.close();
                    inputStream.close();
                    DsaOutputTextArea.setText(signature[0].toString(16)+"\n"+signature[1].toString(16));

                    // Display a success message
                    Alert alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("File loaded");
                    alert.setHeaderText(null);
                    alert.setContentText("The file has been loaded.");
                } catch (IOException e) { // If there was an error loading the file
                    e.printStackTrace();

                    // Display an error message
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error");
                    alert.setHeaderText("Error loading signature");
                    alert.setContentText("There was an error loading the signature.");
                    alert.showAndWait();
                }
            }
        }
    }

    public void loadKeysFromFile(ActionEvent actionEvent) {
        // Create a new FileChooser
        FileChooser fileChooser = new FileChooser();

        // Set the initial directory for the FileChooser
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));

        // Set the extension filter for the FileChooser
        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("MyKey files (*.key)", "*.key");
        fileChooser.getExtensionFilters().add(extFilter);

        // Show the Open dialog and get the selected file
        File file = fileChooser.showOpenDialog(null);

        if (file != null) { // If a file was selected
            try {
                FileInputStream inputStream = new FileInputStream(file);
                BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
                String qStr = reader.readLine();
                String gStr = reader.readLine();
                String yStr = reader.readLine();
                String xStr = reader.readLine();
                String pStr = reader.readLine();

                dsa.q = new BigInteger(qStr);
                dsa.g = new BigInteger(gStr);
                dsa.y = new BigInteger(yStr);
                dsa.x = new BigInteger(xStr);
                dsa.p = new BigInteger(pStr);

                DsaGeneratedKeyField.setText(dsa.q.toString(16) + dsa.g.toString(16));
                DsaGeneratedKeyField2.setText(dsa.y.toString(16));
                DsaGeneratedKeyField3.setText(dsa.x.toString(16));
                DsaGeneratedKeyField4.setText(dsa.p.toString(16));

                // Display a success message
                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("Key loaded");
                alert.setHeaderText(null);
                alert.setContentText("The key has been loaded.");
                alert.showAndWait();
            } catch (IOException e) { // If there was an error loading the file
                e.printStackTrace();

                // Display an error message
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error");
                alert.setHeaderText("Error loading key");
                alert.setContentText("There was an error loading the key.");
                alert.showAndWait();
            }
        }
    }


    public void saveKeysToFile() {
        // Create a new instance of FileChooser
        FileChooser fileChooser = new FileChooser();

        // Set the initial directory for the FileChooser
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));

        // Set the title for the FileChooser window
        fileChooser.setTitle("Save Key File");

        // Set the extension filter for the FileChooser
        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("Key files (*.key)", "*.key");
        fileChooser.getExtensionFilters().add(extFilter);

        // Show the Save File Dialog
        File file = fileChooser.showSaveDialog(saveKeysButton.getScene().getWindow());

        if (file != null) {
            try {
                FileOutputStream outputStream = new FileOutputStream(file);
                DataOutputStream dataOutput = new DataOutputStream(outputStream);
                dataOutput.writeBytes(dsa.q.toString() + "\n" + dsa.g.toString() + "\n" + dsa.y.toString() + "\n" + dsa.x.toString() + "\n" + dsa.p.toString()+ "\n");
                dataOutput.close();
                outputStream.close();

                // Display a success message
                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("Key saved");
                alert.setHeaderText(null);
                alert.setContentText("The key has been saved.");
                alert.showAndWait();
            } catch (IOException e) { // If there was an error saving the file
                e.printStackTrace();

                // Display an error message
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error");
                alert.setHeaderText("Error saving key");
                alert.setContentText("There was an error saving the key.");
                alert.showAndWait();
            }
        }
    }

    @FXML
    public void saveTextButtonAction(ActionEvent actionEvent) {
        // Create a new instance of FileChooser
        FileChooser fileChooser = new FileChooser();

        // Set the initial directory for the FileChooser
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));

        // Set the title for the FileChooser window
        fileChooser.setTitle("Save Input Text File");

        // Show the Save File Dialog
        File file = fileChooser.showSaveDialog(saveTextButton.getScene().getWindow());

        if (file != null) {
            try {
                FileOutputStream outputStream = new FileOutputStream(file);
                outputStream.write(message);
                outputStream.close();

                // Display the path to the saved file in the saveCipherFilePath label
                saveSignaturePath.setText(file.getAbsolutePath());

                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("File saved");
                alert.setHeaderText(null);
                alert.setContentText("The file has been saved.");
                alert.showAndWait();
            } catch (IOException e) {
                e.printStackTrace();
                // Display an error message if there was a problem saving the file
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error");
                alert.setHeaderText("Error saving file");
                alert.setContentText("There was an error saving the file.");
                alert.showAndWait();
            }
        }
    }
    @FXML
    public void saveSignedTextButtonAction(ActionEvent actionEvent) {
        // Create a new instance of FileChooser
        FileChooser fileChooser = new FileChooser();

        // Set the initial directory for the FileChooser
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));

        // Set the title for the FileChooser window
        fileChooser.setTitle("Save Input Text File");

        // Show the Save File Dialog
        File file = fileChooser.showSaveDialog(saveTextButton.getScene().getWindow());

        if (file != null) {
            try {
                FileOutputStream outputStream = new FileOutputStream(file);
                DataOutputStream dataOutput = new DataOutputStream(outputStream);

                dataOutput.writeBytes(signature[0].toString() + "\n" + signature[1].toString() + "\n");

                dataOutput.close();
                outputStream.close();

                // Display the path to the saved file in the saveCipherFilePath label
                saveSignaturePath.setText(file.getAbsolutePath());

                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("File saved");
                alert.setHeaderText(null);
                alert.setContentText("The file has been saved.");
                alert.showAndWait();
            } catch (IOException e) {
                e.printStackTrace();
                // Display an error message if there was a problem saving the file
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error");
                alert.setHeaderText("Error saving file");
                alert.setContentText("There was an error saving the file.");
                alert.showAndWait();
            }
        }
    }
}
