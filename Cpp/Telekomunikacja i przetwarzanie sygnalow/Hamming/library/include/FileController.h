#ifndef TELE1_FILECONTROLLER_H
#define TELE1_FILECONTROLLER_H

#include <iostream>
#include <fstream>
#include <memory>

class FileController {
private:

    std::string path; // path to a file

    std::fstream file; // fstream variable

public:

    explicit FileController(std::string path);

    bool openRead(); // open file for reading and informs if successful

    bool openWrite(); //opens file for writing and informs if successful

    bool erase(); // erases what is in the file and informs if successful

    bool write(const std::string &data); // writes to a file and informs if successful; takes string as an argument

    std::string read(); // reads from a file ; returns a string

    bool close(); // closes a file and informs if successful

    virtual ~FileController();
};
typedef std::shared_ptr<FileController> FileController_ptr;

#endif //TELE1_FILECONTROLLER_H
