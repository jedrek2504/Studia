#include "../include/Algorithm.h"
#include <cmath>
#include <string>
#include <algorithm>

Algorithm::Algorithm() = default;

Algorithm::~Algorithm() = default;

void Algorithm::encode(const FileController_ptr& input, const FileController_ptr& output) {
    int letter_bin[BYTE]{0};        // encoded letter (first 8 bits of message)
    int parity[BYTE]{0};            // parity bits (last 8 bits of message)
    int message[2 * BYTE]{};        // final encoded message
    output->erase();                 // erase file
    std::string msg = input->read(); // assign to 'msg' what is in input file

    for (unsigned char c: msg) {                // iterate through every letter in a given message
        int letter_int = static_cast<int>(c);   // getting integer representation of ascii_int char "c"
        for (int i = BYTE - 1; i >= 0; i--) {   // loop encodes a letter and stores final code in a 8 element array:
            letter_bin[i] = letter_int % 2;     //   - firstly it applies either 1 or 0 to ith bit
            letter_int /= 2;                    //   - then it switches to the next bit (to the right)
        }

        // push encoded letter to the first 8 positions of final message array
        for (int i = 0; i < BYTE; i++) {
            message[i] = letter_bin[i];
        }

        // compute each of the 8 parity bits using matrix equation
        for (int i = 0; i < BYTE; i++) {
            parity[i] = 0;
            for (int j = 0; j < BYTE; j++) {
                parity[i] += letter_bin[j] * H[i][j];
            }
            parity[i] %= 2;
        }

        // push encoded letter to the last 8 positions of final message array
        for (int i = 0; i < BYTE; i++) {
            message[i + 8] = parity[i];
        }

        // write the encoded 16 bit message to output file
        for (int i : message) {
            output->write(std::to_string(i));
        }
    }
}

void Algorithm::decode(const FileController_ptr& input, const FileController_ptr& output) {
    int code_tab[BYTE]{};
    int encoded[BYTE * 2]{};
    bool isOneError;                     // flag that checks if there is AT LEAST 1 error
    bool isTwoError;                     // flag that checks if there are 2 errors
    output->erase();                     // erase output file
    std::string code = input->read();    // assign to 'code' what is in input file

    for (int i = 0; i < code.length(); i += 16) {
        int iter = 0;
        int ascii_int = 0;
        int pow = BYTE - 1; // 7
        char ascii_letter;
        isOneError = false;

        // iterate through every 16-bit encoded letter in binary code stored in input
        for (int j = i; j < i + 16; j++) {
            // Convert string to binary and store each digit in the encoded array
            encoded[iter] = code[j] - '0'; // '0'=48 in decimal and this way we get number representation of a string
            iter++;
        }

        for (int j = 0; j < BYTE; j++) {
            code_tab[j] = 0;
            for (int k = 0; k < BYTE * 2; k++) {
                code_tab[j] += encoded[k] * H[j][k];     // Mul of matrixes T and H  -> if T*H!=0 then there is min 1 error
            }                                            //                          -> if T*H==0 then there is no error
            code_tab[j] %= 2;                            // make result either a 1 or 0
            if (code_tab[j] == 1) {                      // if any element is 1 then the whole result is not a 0
                isOneError = true;                       // it means that there is at least 1 error
            }
        }

        // If there is at least one error:
        if (isOneError) {
            for (int j = 0; j < BYTE * 2; j++) {
                for (int k = j + 1; k < BYTE * 2; k++) {
                    isTwoError = true; // flag is set to true unless proven otherwise
                    // doing xor on every pair of columns in H matrix
                    for (int g = 0; g < BYTE; g++) {
                        if (code_tab[g] != (H[g][j] ^ H[g][k])) {
                            isTwoError = false;       // proved that there is no mistake in this pair of columns
                            break;                    // exit this loop
                        }
                    }
                    // if the flag has not been set to false it means that in this pair of columns there are two mistakes
                    if (isTwoError) {
                        // fixing invalid bits which are located on j-th and k-th position of encoded message
                        encoded[j] = !encoded[j];
                        encoded[k] = !encoded[k];
                        break; // exit the whole loop
                    }
                }
            }

            for (int j = 0; j < (BYTE * 2); j++) {
                // searching for a column that is equal to code_tab
                for (int k = 0; k < BYTE; k++) {
                    if (H[k][j] != code_tab[k]) {
                        break;
                    }
                    if (k == 7) { //if the loop has not been broken it means that this column is the one that has error in it
                        encoded[j] = !encoded[j]; // fix invalid bit, which is located on j-th position of encoded message
                    }
                }
            }
        }
        // if no error is detected calculate ascii number
        for (int j = 0; j < BYTE; j++) {
            ascii_int += encoded[j] * std::pow(2, pow);
            pow--;
        }
        ascii_letter = static_cast<char>(ascii_int);    // cast ascii number back to char
        std::string str(1, ascii_letter);         // convert char to string
        output->write(str);                        // write result in output file
    }
}

bool Algorithm::areFilesSame(const FileController_ptr& input, const FileController_ptr& output) {
    std::string msg1 = input->read();
    std::string msg2 = output->read();
    if(msg1 == msg2) {
        return true;
    }
    return false;
}
