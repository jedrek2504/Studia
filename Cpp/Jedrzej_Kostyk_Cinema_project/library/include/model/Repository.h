#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <functional>
#include <vector>
#include <string>

template<class T>
class Repository {
private:

    std::vector<T> elements;

public:

    Repository();

    virtual ~Repository();

    T get(unsigned int id) const;

    void add(T element);

    T find(const std::function<bool(T)> &predicate) const;

    std::vector<T> findAll(const std::function<bool(T)> &predicate) const; //zwraca vector zawierajacy obiekty tozsame z predykatem

    std::string report() const; // Wypisuje informacje każdego elemntu w wektorze

    int size() const;

    void remove(T element);
};

#endif //REPOSITORY_H
