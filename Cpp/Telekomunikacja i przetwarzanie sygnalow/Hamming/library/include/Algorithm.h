#ifndef TELE1_ALGORITHM_H
#define TELE1_ALGORITHM_H
#define BYTE 8 // byte = 8 bits

#include <iostream>
#include "FileController.h"

class Algorithm {
private:
    // Hamming matrix
    int H[8][16] = {
     {1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
     {1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
     {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
     {1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
     {1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
     {0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0},
     {1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1}
    };

public:

    Algorithm();

    void encode(const FileController_ptr& input, const FileController_ptr& output); // encodes what is in input file and saves it to output file

    void decode(const FileController_ptr& input, const FileController_ptr& output); // decodes what is in input file and saves it to output file

    bool areFilesSame(const FileController_ptr& input, const FileController_ptr& output); // checks if given files are identical and returns result

    virtual ~Algorithm();

};
typedef std::shared_ptr<Algorithm> Algorithm_ptr;
#endif //TELE1_ALGORITHM_H
