//
// Created by student on 12.06.2022.
//

#ifndef CARRENTAL_LOGICEXCEPTION_H
#define CARRENTAL_LOGICEXCEPTION_H

#include <string>
#include <stdexcept>

class LogicException : public std::logic_error {
public:
    explicit LogicException(const std::string& what_arg) : std::logic_error(what_arg) {}
};

#endif //CARRENTAL_LOGICEXCEPTION_H
