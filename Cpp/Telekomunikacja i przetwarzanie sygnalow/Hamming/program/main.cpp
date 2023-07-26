#include <iostream>
#include "../library/include/Algorithm.h"

/*  HOW DOES THIS CODE WORK?
/   1. write something in input.txt file
/   2. encode it using option 1
/   3. introduce errors in encoded.txt file (max 2 errors for every 16 bits)
/   4. decode the message using option 2
/   5. program will inform you if these files are identical
/   6. enjoy.
*/

int main() {

    // create FileController objects for input/output files
    FileController_ptr input(new FileController("files/input.txt"));
    FileController_ptr encoded(new FileController("files/encoded.txt"));
    FileController_ptr output(new FileController("files/output.txt"));
    Algorithm_ptr algo(new Algorithm());

    int option{1};

    while (option != 0) {
        std::cout << "Choose option:\n"
                  << "[1] - Encode message from file input.txt\n"
                  << "[2] - Decode message to file output.txt\n"
                  << "[0] - Exit program\n"
                  << "Answer: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                system("clear");
                algo->encode(input, encoded); // encoding
                std::cout << "encoded!" << std::endl;
                break;

            }
            case 2: {
                system("clear");
                algo->decode(encoded, output); // decoding
                std::cout << "decoded!" << std::endl;
                if (algo->areFilesSame(input, output)) {
                    std::cout << "Result: Files are identical!" << std::endl;
                } else {
                    std::cout << "Result: Files are NOT identical!" << std::endl;
                }
                break;
            }
            default: { // exit program
                system("clear");
                option = 0;
                std::cout << "exiting..." << std::endl;
                break;
            }
        }
    }

    return 0;
}