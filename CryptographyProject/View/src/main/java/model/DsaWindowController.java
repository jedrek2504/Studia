package model;

import com.gluonhq.charm.glisten.control.ToggleButtonGroup;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.text.Text;

import java.math.BigInteger;
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
    public Button saveSignatureButton;
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

    BigInteger[] signature;
    private byte[] message;

    private String bytesToHexString(byte[] bytes) {
        return HexFormat.of().formatHex(bytes);
    }

    private byte[] hexStringToBytes(String data) {
        return HexFormat.of().parseHex(data);
    }

    public byte[] concatByteArrays(byte[] a, byte[] b) {
        byte[] result = new byte[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    public DsaWindowController() {
        dsa = new DSA();
    }

    public void generateKeysButtonAction(ActionEvent actionEvent) {
        dsa.generateKey();
        DsaGeneratedKeyField.setText(dsa.q.toString(16) + " " + dsa.g.toString(16));
        DsaGeneratedKeyField2.setText(dsa.y.toString(16));
        DsaGeneratedKeyField3.setText(dsa.x.toString(16));
        DsaGeneratedKeyField4.setText(dsa.p.toString(16));
    }

    @FXML
    private void signButtonAction(ActionEvent event) {
        BigInteger[] signature = dsa.sign(DsaInputTextArea.getText().getBytes());
        String pom=bytesToHexString(signature[0].toByteArray());
        pom+="\n";
        pom+=bytesToHexString(signature[1].toByteArray());

        DsaOutputTextArea.setText(pom);
    }


    @FXML
    public void verifyButtonAction(ActionEvent actionEvent) {
        String plaintext = DsaInputTextArea.getText();
        byte[] message = plaintext.getBytes();
        String signatureString = DsaOutputTextArea.getText();
        String[] tab =signatureString.split("\n");
        BigInteger[] signature = new BigInteger[2];
        signature[0] = new BigInteger(1,hexStringToBytes(tab[0]));
        signature[1] = new BigInteger(1,hexStringToBytes(tab[1]));

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

    public void toggleButtonAction(ActionEvent actionEvent) {
        // Handle toggle button events
        if (actionEvent.getSource() == toggleButtonWindow) {
            hideFileNodes();
        } else if (actionEvent.getSource() == toggleButtonFile) {
            showFileNodes();
        }
    }


    public void chooseFileButtonAction(ActionEvent actionEvent) {
        
    }

    public void loadKeysFromFile(ActionEvent actionEvent) {

    }


    public void saveKeysToFile() {

    }


    public void saveSignatureButtonAction(ActionEvent actionEvent) {
    }

    public void saveSignedTextButtonAction(ActionEvent actionEvent) {
    }
}
