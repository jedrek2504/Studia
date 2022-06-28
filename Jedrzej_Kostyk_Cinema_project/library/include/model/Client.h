#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>

class Client{

    std::string firstName;
    std::string lastName;
    int age;
    std::string emailAddress;
    bool archive;

public:

    Client(const std::string &firstName, const std::string &lastName, const int &age,
           const std::string &emailAddress);

    virtual ~Client();

    //getters
    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const int &getAge() const;

    const std::string &getEmailAddress() const;

    bool isArchive() const;

    //setters
    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setAge(const int &age);

    void setEmailAddress(const std::string &emailAddress);

    void setArchive(bool archive);

    //other methods

    std::string getInfo() const; //zwraca lancuch zawierajacy informacje o kliencie

};
#endif //CLIENT_H
