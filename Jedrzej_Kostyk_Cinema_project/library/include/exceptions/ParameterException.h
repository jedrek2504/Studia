//
// Created by student on 12.06.2022.
//

#ifndef CARRENTAL_PARAMETEREXCEPTION_H
#define CARRENTAL_PARAMETEREXCEPTION_H

#include <string>
#include <stdexcept>

// Wyjątki, gdy przekazywany argument jest niewłaściwy

class ParameterException : public std::logic_error {
public:
    explicit ParameterException(const std::string& what_arg) : std::logic_error(what_arg) {}
};

#endif //CARRENTAL_PARAMETEREXCEPTION_H
