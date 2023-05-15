/**
 * This implementation provides the Advanced Encryption Standard (AES) algorithm, which is a widely used symmetric key encryption algorithm.
 * The AES algorithm takes a block of plaintext and a key as inputs and outputs a block of ciphertext. This implementation supports 128-bit, 192-bit, 256-bit key size and operates on 16-byte blocks.
 * The algorithm consists of several rounds of substitution, permutation, and XOR operations, which provide a high degree of security and resistance to attacks.
 */

package model;

public class AES {


    static class AESKeyException extends Exception {
        public AESKeyException(String msg) {
            super(msg);
        }

    }

    static class AESException extends Exception {
        public AESException(String msg) {
            super(msg);
        }

    }

    // Set the block size to 4 (number of columns in state matrix)
    private final int Nb = 4;

    // Number of 32-bit words in the key
    private int Nk = 0;

    // Number of rounds
    private int Nr = 0;

    // The main key used for encryption/decryption called key schedule
    byte[][] keySchedule;

    // The state matrix used in encryption/decryption
    private byte[][] state;

    public AES() {
        state = new byte[4][4];
    }

    // 256-element table that replaces each byte of the input with a corresponding byte from the S-box.
    private final int[] sbox = {0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F,
            0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76, 0xCA, 0x82,
            0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C,
            0xA4, 0x72, 0xC0, 0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC,
            0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15, 0x04, 0xC7, 0x23,
            0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27,
            0xB2, 0x75, 0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52,
            0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84, 0x53, 0xD1, 0x00, 0xED,
            0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58,
            0xCF, 0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9,
            0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8, 0x51, 0xA3, 0x40, 0x8F, 0x92,
            0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
            0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E,
            0x3D, 0x64, 0x5D, 0x19, 0x73, 0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A,
            0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB, 0xE0,
            0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62,
            0x91, 0x95, 0xE4, 0x79, 0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E,
            0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08, 0xBA, 0x78,
            0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B,
            0xBD, 0x8B, 0x8A, 0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E,
            0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E, 0xE1, 0xF8, 0x98,
            0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55,
            0x28, 0xDF, 0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41,
            0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16};

    // Used in the decryption process to reverse the substitution performed by the S-box.
    private final int[] invSbox = {0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5,
            0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB, 0x7C, 0xE3,
            0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4,
            0xDE, 0xE9, 0xCB, 0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D,
            0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E, 0x08, 0x2E, 0xA1,
            0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B,
            0xD1, 0x25, 0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4,
            0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92, 0x6C, 0x70, 0x48, 0x50,
            0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D,
            0x84, 0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4,
            0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06, 0xD0, 0x2C, 0x1E, 0x8F, 0xCA,
            0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
            0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF,
            0xCE, 0xF0, 0xB4, 0xE6, 0x73, 0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD,
            0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E, 0x47,
            0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E,
            0xAA, 0x18, 0xBE, 0x1B, 0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79,
            0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4, 0x1F, 0xDD,
            0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27,
            0x80, 0xEC, 0x5F, 0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D,
            0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF, 0xA0, 0xE0, 0x3B,
            0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53,
            0x99, 0x61, 0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1,
            0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D};

    // Array of constants used in AES key expansion
    private static final int[] rcon = {
            0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
            0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,
            0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,
            0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
            0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
            0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,
            0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,
            0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
            0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
            0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
            0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
            0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
            0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
            0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
            0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
            0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb
    };

    // multiplies two bytes
    public byte multiplyBytes(byte a, byte b) {
        byte byte1 = a, byte2 = b, resultByte = 0, t; // initialize variables for input bytes and result byte

        while (byte1 != 0) // iterate through the bits of the first input byte
        {
            if ((byte1 & 1) != 0) // check if the current bit is 1
                resultByte = (byte) (resultByte ^ byte2); // if yes, XOR the result byte with the second input byte

            t = (byte) (byte2 & 0x20); // store the 6th bit of the second input byte in a temporary variable

            byte2 = (byte) (byte2 << 1); // shift the second input byte left by 1 bit

            if (t != 0) // if the 6th bit was 1
                byte2 = (byte) (byte2 ^ 0x1b); // XOR the second input byte with 0x1b

            byte1 = (byte) ((byte1 & 0xff) >> 1); // shift the bits of the first input byte to the right by 1 bit
        }

        return resultByte; // return the result byte
    }

    /**
     * Expand the input key into an array of round keys for the AES encryption algorithm using the Rijndael key schedule.
     *
     * @param key the input key as a byte array
     * @return a new 2D byte array representing the expanded round keys
     * @throws AESKeyException if the input key has an invalid length
     */
    public byte[][] expandKey(byte[] key) throws AESKeyException {
        Nk = key.length / 4; // calculate the number of columns in the key matrix
        if (Nk != 4 && Nk != 6 && Nk != 8) { // validate that the key length is valid for AES-128, AES-192, or AES-256
            throw new AESKeyException("Invalid key length (must be 128, 192, or 256 bits)");
        }
        Nr = Nk + 6; // calculate the number of rounds based on the key length
        byte[][] tmpMainKey = new byte[4][(Nr + 1) * 4]; // initialize a temporary array for the expanded key

        // copy the key bytes into the mainKey array
        for (int i = 0; i < key.length; i++) {
            tmpMainKey[i % 4][i / 4] = key[i];
        }

        byte[] temp = new byte[4];
        for (int i = Nk; i < (Nr + 1) * 4; i++) {
            for (int j = 0; j < 4; j++) {
                temp[j] = tmpMainKey[j][i - 1]; // initialize the temporary array with the previous word in the expanded key
            }
            if (i % Nk == 0) {
                // perform key schedule operation on every Nk-th word
                byte t = temp[0];
                temp[0] = (byte) (sbox[temp[1] & 0xFF] ^ rcon[i / Nk]);
                temp[1] = (byte) (sbox[temp[2] & 0xFF]);
                temp[2] = (byte) (sbox[temp[3] & 0xFF]);
                temp[3] = (byte) (sbox[t & 0xFF]);
            }
            for (int j = 0; j < 4; j++) {
                tmpMainKey[j][i] = (byte) (tmpMainKey[j][i - Nk] ^ temp[j]); // calculate the next word in the expanded key
            }
        }
        return tmpMainKey; // return the expanded key as a matrix of bytes
    }

    /**
     * Combines the current state with a portion of the key schedule based on the current round number.
     *
     * @param state       the current state matrix
     * @param keySchedule the entire key schedule matrix
     * @param round       the current round number
     * @return the resulting matrix after adding the round key
     * @throws AESException if the provided round number is out of range
     */
    public byte[][] addRoundKey(byte[][] state, byte[][] keySchedule, int round) throws AESException {
        // Check if the provided round number is valid based on the length of the key schedule
        if (round >= keySchedule[0].length / 4) {
            throw new AESException("Invalid round number");
        }

        // Create a temporary matrix to store the output
        byte[][] result = new byte[4][4];

        // Iterate over each element of the state matrix
        for (int c = 0; c < 4; c++) {
            for (int r = 0; r < 4; r++) {
                // Perform an XOR operation between the state element and the corresponding element
                // of the key schedule based on the current round number, and store the result in the
                // corresponding element of the result matrix
                result[r][c] = (byte) (state[r][c] ^ keySchedule[r][round * 4 + c]);
            }
        }

        // Return the resulting matrix
        return result;
    }


    /**
     * Applies the substitution box (S-box) to each element of the state matrix.
     *
     * @param state the current state matrix
     * @return the resulting matrix after applying the S-box
     */
    public byte[][] subBytes(byte[][] state) {
        // Create a temporary matrix to store the output
        byte[][] result = new byte[4][4];

        // Iterate over each element of the state matrix
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // Extract the row and column indices from the current state element
                int row = (state[i][j] >> 4) & 0x0f;
                int col = state[i][j] & 0x0f;

                // Look up the value from the S-box using the extracted row and column indices,
                // and store the result in the corresponding element of the result matrix
                result[i][j] = (byte) sbox[row * 16 + col];
            }
        }

        // Return the resulting matrix
        return result;
    }


    /**
     * Shifts the rows of the state matrix according to a fixed pattern.
     *
     * @param state the current state matrix
     * @return the resulting matrix after shifting the rows
     */
    public byte[][] shiftRows(byte[][] state) {
        // Create a temporary matrix to store the output
        byte[][] result = new byte[4][Nb];

        // Iterate over each row of the state matrix
        for (int r = 0; r < 4; r++) {
            // Iterate over each column of the state matrix
            for (int c = 0; c < Nb; c++) {
                // Shift the current element of the row by a fixed number of positions based on the
                // row index, and store the result in the corresponding element of the result matrix
                result[r][c] = state[r][(c + r) % Nb];
            }
        }

        // Return the resulting matrix
        return result;
    }


    /**
     * Applies the MixColumns operation to the state matrix.
     *
     * @param state the current state matrix
     * @return the resulting matrix after applying the MixColumns operation
     */
    byte[][] mixColumns(byte[][] state) {
        // Create an array to store intermediate calculations
        int[] tmp = new int[4];

        // Define constants used in the MixColumns operation
        byte b02 = (byte) 0x02, b03 = (byte) 0x03;

        // Iterate over each column of the state matrix
        for (int c = 0; c < 4; c++) {
            // Compute the new value of each element in the current column
            tmp[0] = multiplyBytes(b02, state[0][c]) ^ multiplyBytes(b03, state[1][c]) ^ state[2][c] ^ state[3][c];
            tmp[1] = state[0][c] ^ multiplyBytes(b02, state[1][c]) ^ multiplyBytes(b03, state[2][c]) ^ state[3][c];
            tmp[2] = state[0][c] ^ state[1][c] ^ multiplyBytes(b02, state[2][c]) ^ multiplyBytes(b03, state[3][c]);
            tmp[3] = multiplyBytes(b03, state[0][c]) ^ state[1][c] ^ state[2][c] ^ multiplyBytes(b02, state[3][c]);

            // Copy the intermediate values back into the state matrix
            for (int i = 0; i < 4; i++) {
                state[i][c] = (byte) (tmp[i]);
            }
        }

        // Return the resulting matrix
        return state;
    }

    // Ciphers 16-byte block of code
    public byte[] cipher(byte[] in) throws AESException {
        // Create a new byte array to hold the result
        byte[] result = new byte[in.length];

        // Populate the state array with input bytes
        for (int i = 0; i < in.length; i++) {
            state[i / 4][i % 4] = in[i]; // Store each byte of input in the 4x4 state array
        }

        // Apply the initial round key
        state = addRoundKey(state, keySchedule, 0); // Add the first round key to the state

        // Apply the main encryption rounds
        for (int round = 1; round < Nr; round++) {
            state = subBytes(state); // Substitute each byte in the state using S-box table
            state = shiftRows(state); // Shift rows in the state cyclically
            state = mixColumns(state); // Mix the columns in the state
            state = addRoundKey(state, keySchedule, round); // Add the current round key to the state
        }

        // Apply the final round
        state = subBytes(state); // Substitute each byte in the state using S-box table
        state = shiftRows(state); // Shift rows in the state cyclically
        state = addRoundKey(state, keySchedule, Nr); // Add the last round key to the state

        // Copy the state back to the result array
        for (int i = 0; i < result.length; i++) {
            result[i] = state[i / 4][i % 4]; // Store each byte of the final state in the result array
        }

        // Return the result
        return result;
    }


    // Takes in a message and a key and returns an encrypted byte array using the AES encryption algorithm
    public byte[] encrypt(byte[] message, byte[] key) throws AESException, AESKeyException {
        // Set the number of columns of the key
        Nk = key.length / 4;

        // Set the number of rounds for AES encryption
        Nr = Nk + 6;

        // Throw an exception if the input message is empty
        if (message.length == 0) {
            throw new AESException("Input message cannot be empty");
        }

        // Determine the length of the padded message
        int len;
        int pom = message.length / 16;
        if (pom == 0) {
            len = 16;
        } else if ((message.length % 16) != 0) {
            len = (pom + 1) * 16;
        } else {
            len = pom * 16;
        }

        // Create a new byte array with the length of the message padded to 16-byte blocks
        byte[] result = new byte[len];
        byte[] temp = new byte[len];
        byte[] block = new byte[16];

        // Generate the main key
        keySchedule = expandKey(key);

        // Pad the input message with zeros if necessary
        for (int i = 0; i < len; i++) {
            if (i < message.length) {
                temp[i] = message[i];
            } else {
                temp[i] = 0;
            }
        }

        // Encrypt the padded message using AES
        for (int i = 0; i < len; i += 16) {
            // Copy 16 bytes from the padded message into the block
            System.arraycopy(temp, i + 0, block, 0, 16);

            // Apply AES encryption to the block using the main key
            block = cipher(block);

            // Copy the encrypted block into the result array
            System.arraycopy(block, 0, result, i + 0, 16);
        }

        // Return the encrypted byte array
        return result;

    }

    /**
     * Applies the inverse S-box substitution to the state matrix.
     *
     * @param state the state matrix to be transformed
     * @return the transformed state matrix
     */
    public byte[][] invSubBytes(byte[][] state) {
        byte[][] result = new byte[4][4];
        // Iterate over the rows and columns of the state matrix
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // Compute the row and column values from the current byte
                int row = (state[i][j] >> 4) & 0x0f;
                int col = state[i][j] & 0x0f;
                // Lookup the corresponding inverse S-box value and store it in the result matrix
                result[i][j] = (byte) invSbox[row * 16 + col];
            }
        }
        return result;
    }


    /**
     * Performs the inverse shift rows operation on a given 4x4 byte state matrix.
     *
     * @param state The state matrix to be transformed
     * @return The transformed state matrix
     */
    public byte[][] invShiftRows(byte[][] state) {
        // Create a new 4xNb byte array to store the transformed state matrix
        byte[][] result = new byte[4][Nb];

        // For each row in the state matrix
        for (int r = 0; r < 4; r++) {
            // For each column in the state matrix
            for (int c = 0; c < Nb; c++) {
                // Calculate the new column index based on the current row index and column index
                int newCol = (c + r) % Nb;

                // Copy the byte from the original state matrix to the corresponding position in the transformed matrix
                result[r][newCol] = state[r][c];
            }
        }

        // Return the transformed state matrix
        return result;
    }


    /**
     * Performs the inverse MixColumns operation on a 4x4 byte matrix.
     *
     * @param state the input 4x4 byte matrix
     * @return the result of the inverse MixColumns operation on the input matrix
     */
    byte[][] invMixColumns(byte[][] state) {
        // Initialize array to hold temporary values
        int[] tmp = new int[4];

        // Define the necessary byte values for the MixColumns operation
        byte b02 = (byte) 0x0e, b03 = (byte) 0x0b, b04 = (byte) 0x0d, b05 = (byte) 0x09;

        // Perform the inverse MixColumns operation on each column of the input matrix
        for (int c = 0; c < 4; c++) {
            // Compute the values for each row of the output column
            tmp[0] = multiplyBytes(b02, state[0][c]) ^ multiplyBytes(b03, state[1][c]) ^ multiplyBytes(b04, state[2][c]) ^ multiplyBytes(b05, state[3][c]);
            tmp[1] = multiplyBytes(b05, state[0][c]) ^ multiplyBytes(b02, state[1][c]) ^ multiplyBytes(b03, state[2][c]) ^ multiplyBytes(b04, state[3][c]);
            tmp[2] = multiplyBytes(b04, state[0][c]) ^ multiplyBytes(b05, state[1][c]) ^ multiplyBytes(b02, state[2][c]) ^ multiplyBytes(b03, state[3][c]);
            tmp[3] = multiplyBytes(b03, state[0][c]) ^ multiplyBytes(b04, state[1][c]) ^ multiplyBytes(b05, state[2][c]) ^ multiplyBytes(b02, state[3][c]);
            // Update the values of the output column with the computed values
            for (int i = 0; i < 4; i++) {
                state[i][c] = (byte) (tmp[i]);
            }

        }

        // Return the resulting 4x4 byte matrix
        return state;
    }

    // Deciphers 16-byte block of code
    public byte[] decipher(byte[] in) throws AESException {
        // Create a new byte array to hold the result
        byte[] result = new byte[in.length];

        // Populate the state array with input bytes
        for (int i = 0; i < in.length; i++) {
            state[i / 4][i % 4] = in[i];
        }

        // Apply the initial round key
        state = addRoundKey(state, keySchedule, Nr);

        // Apply the main decryption rounds in reverse order
        for (int round = Nr - 1; round >= 1; round--) {
            state = invShiftRows(state);
            state = invSubBytes(state);
            state = addRoundKey(state, keySchedule, round);
            state = invMixColumns(state);
        }

        // Apply the final round
        state = invShiftRows(state);
        state = invSubBytes(state);
        state = addRoundKey(state, keySchedule, 0);

        // Copy the state back to the result array
        for (int i = 0; i < result.length; i++) {
            result[i] = state[i / 4][i % 4];
        }

        // Return the result
        return result;
    }


    // Takes in a message and a key and returns a decrypted byte array using the AES encryption algorithm
    public byte[] decrypt(byte[] message, byte[] key) throws AESException, AESKeyException {
        // Set the number of columns of the key
        Nk = key.length / 4;

        // Set the number of rounds for AES decryption
        Nr = Nk + 6;

        // Throw an exception if the input message is empty
        if (message.length == 0) {
            throw new AESException("Input message cannot be empty");
        }

        // Create a new byte array to hold the decrypted message
        byte[] result = new byte[message.length];
        byte[] block = new byte[16];

        // Generate the main key
        keySchedule = expandKey(key);

        // Decrypt the message by processing each 16-byte block using AES
        for (int i = 0; i + 16 <= message.length; i += 16) {
            // Copy 16 bytes from the message into the block
            System.arraycopy(message, i, block, 0, 16);

            // Decrypt the block using AES
            block = decipher(block);

            // Copy the decrypted block into the result array
            System.arraycopy(block, 0, result, i, 16);
        }


        return result;
    }

}
