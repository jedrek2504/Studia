#include "../include/FileController.h"
#include <sstream>
#include <utility>

FileController::FileController(std::string path) : path(std::move(path)) {}

bool FileController::openRead() {
    file.open(path, std::ios::in);
    if (file.is_open()) {
        return true;
    }
    return false;
}

bool FileController::openWrite() {
    file.open(path, std::ios::out | std::ios::app);
    if (file.is_open()) {
        return true;
    }
    return false;
}

bool FileController::write(const std::string &data) {
    if (this->openWrite()) {
        file << data; // write data to file
        this->close();
        return true;
    } else {
        std::cout << "FileController::write() | Given path does not exist" << std::endl;
        return false;
    }
}

bool FileController::erase() {
    file.close(); // close file before erasing
    file.open(path, std::ios::out | std::ios::trunc);
    file.close();

    if (file.is_open()) {
        std::cout << "FileController::erase() | File has not been closed properly!" << std::endl;
        return false;
    }
    return true;
}

FileController::~FileController() {
    if (file.is_open()) {
        file.close(); // close file
    }
}

std::string FileController::read() {
    if (this->openRead()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        this->close();
        return buffer.str();
    } else {
        std::cout << "FileController::read() | Given path does not exist!" << std::endl;
        return "";
    }
}

bool FileController::close() {
    file.close();
    if (!file.is_open()) {
        return false;
    }
    return true;
}




