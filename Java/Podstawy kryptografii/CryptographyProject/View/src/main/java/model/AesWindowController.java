package model;

import com.gluonhq.charm.glisten.control.ToggleButtonGroup;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.HexFormat;

public class AesWindowController {

    public Button generateKeyButton;
    public TextArea inputTextArea;
    public TextArea outputTextArea;
    public ToggleButtonGroup toggleButtonsGroup;
    public ToggleButton toggleButtonWindow;
    public ToggleButton toggleButtonFile;
    public Button encodeButton;
    public Button decodeButton;
    public Button chooseFileButton1;
    public Text chooseFile1PathText;
    public Button loadKeyButton;
    public Button saveKeyButton;
    public Text saveFilePath;
    public Text saveCipherFilePath;
    public Text chooseFile2PathText;
    public Button chooseFileButton2;
    public Button saveTextFileButton;
    public Button saveCipherFileButton;
    public TextField generatedKeyText;

    private byte[] inputArea;
    private byte[] outputArea;

    private final AES aes;
    private final RandomGenerator rg;

    public AesWindowController() {
        rg = new RandomGenerator();
        aes = new AES();
    }

    private String bytesToHexString(byte[] bytes) {
        return HexFormat.of().formatHex(bytes);
    }

    private byte[] hexStringToBytes(String data) {
        return HexFormat.of().parseHex(data);
    }

    @FXML
    public void initialize() {
        // Set the default state of the toggle buttons
        toggleButtonWindow.setSelected(true);
        toggleButtonFile.setSelected(false);
        hideFileNodes();
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
    public void toggleButtonAction(ActionEvent event) {
        // Handle toggle button events
        if (event.getSource() == toggleButtonWindow) {
            hideFileNodes();
        } else if (event.getSource() == toggleButtonFile) {
            showFileNodes();
        }
    }

    @FXML
    private void generateKeyButtonAction() {
        byte[] key = rg.generateAESKey();
        generatedKeyText.setText(bytesToHexString(key));
    }

    @FXML
    private void encodeButtonAction() {
        // Get the encryption key from keyTextField
        String keyString = generatedKeyText.getText();

        byte[] key = hexStringToBytes(keyString);
        if (inputArea == null) {
            // Get the input message from inputTextArea
            String message = inputTextArea.getText();

            try {
                // Convert the input message to bytes
                byte[] messageBytes = message.getBytes();

                // Encrypt the message using AES
                outputArea = aes.encrypt(messageBytes, key);

                // Convert the encrypted message to a hex string
                String encryptedMessageHex = bytesToHexString(outputArea);

                // Set the outputTextArea to the encrypted message
                outputTextArea.setText(encryptedMessageHex);
            } catch (AES.AESException | AES.AESKeyException e) {
                // If an exception occurs during encryption, display the error message
                outputTextArea.setText(e.getMessage());
            }
        } else { // it means that the file was loaded already
            try {
                outputArea = aes.encrypt(inputArea, key);
                String encryptedMessageHex;
                if(outputArea.length >= 3000) {
                    byte[] tmpArray = new byte[3000];

                    // copy the first 5000 bytes from the original array to the tmp array
                    System.arraycopy(outputArea, 0, tmpArray, 0, 3000);

                    // Convert the encrypted message to a hex string
                    encryptedMessageHex = bytesToHexString(tmpArray);

                    // Set the outputTextArea to the encrypted message
                    outputTextArea.setText(encryptedMessageHex);
                } else {
                    encryptedMessageHex = bytesToHexString(inputArea);

                    // Set the outputTextArea to the encrypted message
                    outputTextArea.setText(encryptedMessageHex);
                }

            } catch (AES.AESException | AES.AESKeyException e) {
                // If an exception occurs during encryption, display the error message
                outputTextArea.setText(e.getMessage());
            }
        }

    }


    @FXML
    private void decodeButtonAction() {
        // Get the decryption key from keyTextField
        String keyString = generatedKeyText.getText();
        byte[] key = hexStringToBytes(keyString);

        if (outputArea == null) {
            // Get the encrypted message from inputTextArea
            String encryptedMessageHex = outputTextArea.getText();

            try {
                // Convert the encrypted message from hex to bytes
                byte[] encryptedMessage = hexStringToBytes(encryptedMessageHex);

                // Decrypt the message using AES
                inputArea = aes.decrypt(encryptedMessage, key);

                // Convert the decrypted message to a string
                String decryptedMessageString = new String(inputArea);

                // Set the outputTextArea to the decrypted message
                inputTextArea.setText(decryptedMessageString);
            } catch (AES.AESException | AES.AESKeyException e) {
                // If an exception occurs during decryption, display the error message
                inputTextArea.setText(e.getMessage());
            }
        } else {
            try {
                // Decrypt the message using AES
                inputArea = aes.decrypt(outputArea, key);
                String decryptedMessageString;
                if(inputArea.length >= 3000) {
                    byte[] tmpArray = new byte[3000];
                    // copy the first 5000 bytes from the original array to the tmp array
                    System.arraycopy(inputArea, 0, tmpArray, 0, 3000);
                    // Convert the decrypted message to a string
                    decryptedMessageString = new String(tmpArray);
                    // Set the outputTextArea to the decrypted message
                    inputTextArea.setText(decryptedMessageString);

                } else {
                    decryptedMessageString = new String(inputArea);

                    // Set the outputTextArea to the decrypted message
                    inputTextArea.setText(decryptedMessageString);
                }



            } catch (AES.AESException | AES.AESKeyException e) {
                // If an exception occurs during decryption, display the error message
                inputTextArea.setText(e.getMessage());
            }
        }

    }


    @FXML
    public void chooseFileButtonAction(ActionEvent event) {
        FileChooser fileChooser = new FileChooser();

        // Set the initial directory for the FileChooser
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));

        File selectedFile = fileChooser.showOpenDialog(null);

        if (selectedFile != null) {
            String filePath = selectedFile.getAbsolutePath();
            if (event.getSource().equals(chooseFileButton1)) {
                chooseFile1PathText.setText(filePath);
                inputArea = readFile(selectedFile);
                byte[] tmpArray = new byte[3000];

                if (inputArea != null) {
                    // copy the first 5000 bytes from the original array to the tmp array
                    System.arraycopy(inputArea, 0, tmpArray, 0, 3000);
                    inputTextArea.setText(new String(tmpArray));
                }

                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("File loaded");
                alert.setHeaderText(null);
                alert.setContentText("The file has been loaded.");
                alert.showAndWait();
            } else if (event.getSource().equals(chooseFileButton2)) {

                chooseFile2PathText.setText(filePath);
                outputArea = readFile(selectedFile);
                byte[] tmpArray = new byte[3000];
                if (outputArea != null) {
                    // copy the first 5000 bytes from the original array to the tmp array
                    System.arraycopy(outputArea, 0, tmpArray, 0, 3000);
                    outputTextArea.setText(bytesToHexString(tmpArray));
                }

                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("File loaded");
                alert.setHeaderText(null);
                alert.setContentText("The file has been loaded.");
                alert.showAndWait();
            }
        }
    }

    private byte[] readFile(File file) {
        try {
            FileInputStream fis = new FileInputStream(file);
            byte[] bytes = fis.readAllBytes();
            fis.close();
            return bytes;
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }


    @FXML
    public void loadKeyFromFile() {
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
                // Read the key from the selected file
                FileInputStream fis = new FileInputStream(file);
                byte[] keyBytes = fis.readAllBytes();
                fis.close();

                // Convert the key bytes to a hex string
                String keyHex = bytesToHexString(keyBytes);
                // Update the generatedKeyText field with the loaded key
                generatedKeyText.setText(keyHex);

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


    @FXML
    public void saveKeyToFile() {
        // Get the generated key from the generatedKeyText field
        String keyHex = generatedKeyText.getText();

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
        File file = fileChooser.showSaveDialog(saveKeyButton.getScene().getWindow());

        if (file != null) {
            try {
                // Convert the key hex string to a byte array
                byte[] keyBytes = hexStringToBytes(keyHex);

                // Open a new output stream to the selected file
                FileOutputStream fos = new FileOutputStream(file);

                // Write the key bytes to the file
                fos.write(keyBytes);

                // Close the output stream
                fos.close();

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
    private void saveTextFileButtonAction() {
        // Create a new instance of FileChooser
        FileChooser fileChooser = new FileChooser();

        // Set the initial directory for the FileChooser
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));

        // Set the title for the FileChooser window
        fileChooser.setTitle("Save Input Text File");

        // Show the Save File Dialog
        File file = fileChooser.showSaveDialog(saveTextFileButton.getScene().getWindow());

        if (file != null) {
            try {
                // Open a new output stream to the selected file
                FileOutputStream fileOutputStream = new FileOutputStream(file);

                // Convert the cipher text to bytes
                byte[] inputBytes = inputArea;

                // Write the bytes to the file
                fileOutputStream.write(inputBytes);

                // Close the output stream
                fileOutputStream.close();

                // Display the path to the saved file in the saveCipherFilePath label
                saveFilePath.setText(file.getAbsolutePath());

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
    public void saveCipherFileButtonAction() {
        // Create a new instance of FileChooser
        FileChooser fileChooser = new FileChooser();

        // Set the initial directory for the FileChooser
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));

        // Set the title for the FileChooser window
        fileChooser.setTitle("Save Cipher Text File");

        // Show the Save File Dialog
        File file = fileChooser.showSaveDialog(saveCipherFileButton.getScene().getWindow());

        if (file != null) {
            try {
                // Open a new output stream to the selected file
                FileOutputStream fileOutputStream = new FileOutputStream(file);

                // Convert the cipher text to bytes
                byte[] cipherBytes = outputArea;

                // Write the bytes to the file
                fileOutputStream.write(cipherBytes);

                // Close the output stream
                fileOutputStream.close();

                // Display the path to the saved file in the saveCipherFilePath label
                saveCipherFilePath.setText(file.getAbsolutePath());

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
