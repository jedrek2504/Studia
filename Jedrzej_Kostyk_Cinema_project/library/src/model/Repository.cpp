#include "model/Repository.h"
#include "model/Client.h"
#include "model/Ticket.h"
#include "model/Movie.h"
#include "exceptions/LogicException.h"


template<class T>
Repository<T>::Repository() = default;

template<class T>
Repository<T>::~Repository() = default;

template<class T>
T Repository<T>::get(unsigned int id) const {
    if (id < size()) {
        return elements[id];
    }
    throw LogicException("Wrong index of vector!");
}

template<class T>
void Repository<T>::add(T element) {
    if (element == nullptr) {
        throw LogicException("Cannot add nullptr!");
    }
    elements.push_back(element);
}

template<class T>
T Repository<T>::find(const std::function<bool(T)> &predicate) const {
    for (int i = 0; i < size(); i++) {
        T element = get(i);
        if (predicate(element)) {
            return element;
        }
    }
    return nullptr;
}

template<class T>
std::vector<T> Repository<T>::findAll(const std::function<bool(T)> &predicate) const {
    std::vector<T> result;
    for (int i = 0; i < size(); ++i) {
        T element = get(i);
        if (predicate(element)) {
            result.push_back(element);
        }
    }
    return result;
}

template<class T>
std::string Repository<T>::report() const {
    std::string chain;
    for (int i = 0; i < size(); i++) {
        chain += (get(i)->getInfo() + " \n");
    }
    return chain;
}

template<class T>
int Repository<T>::size() const {
    return elements.size();
}

template<class T>
void Repository<T>::remove(T element) {
    for (int i = 0; i < size(); ++i) {
        if (element == get(i)) {
            elements.erase(elements.begin() + i);
        }
    }
}

template
class Repository<Client_ptr>;

template
class Repository<Ticket_ptr>;

template
class Repository<Movie_ptr>;
