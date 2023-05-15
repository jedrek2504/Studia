package model;

import java.math.BigInteger;

public class ModelMain {
    public static void main(String[] args) {

        // Prepare the message and signature as byte[] arrays
        byte[] messageBytes = {1, 2, 3, 4, 5};
        byte[] messageBytes2 = {1, 2, 3, 4, 5, 6};

        DSA dsa = new DSA();
        BigInteger[] signature = dsa.sign(messageBytes);
        BigInteger[] signature2 = dsa.sign(messageBytes2);

        System.out.println(dsa.verify(messageBytes, signature));
        System.out.println(dsa.verify(messageBytes, signature2));

    }
}
