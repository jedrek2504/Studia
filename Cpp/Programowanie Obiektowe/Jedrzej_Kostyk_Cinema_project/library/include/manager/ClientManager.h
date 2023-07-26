#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "model/typedefs.h"
#include <string>

class ClientManager {

    ClientRepository_ptr clientRepository;

public:
    explicit ClientManager(const ClientRepository_ptr &clientRepository);

    virtual ~ClientManager();

    // Tworzy objekt client i zwraca na niego wskaźnik. Jeśli client jest już stworzony zamienia jego pole isArchive na false.
    Client_ptr registerClient(const std::string &firstName, const std::string &lastName, const int &age,
                   const std::string &emailAddress);

    // ustawia pole isArchive obiektu na true
    void unregisterClient(const Client_ptr &client);

    // zwraca wskaznik klienta o odpowiadajacym adresie email
    Client_ptr getClient(const std::string &emailAddress) const;

    //wywoule metode getInfo() wszystkich klientow w repozytorium.
    std::string getAllClientsReport() const;
};

#endif //CLIENTMANAGER_H
