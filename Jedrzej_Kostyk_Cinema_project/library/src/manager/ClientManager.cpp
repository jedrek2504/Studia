#include "manager/ClientManager.h"
#include "model/Repository.h"
#include "model/Client.h"
#include "exceptions/ParameterException.h"

ClientManager::ClientManager(const ClientRepository_ptr &clientRepository)  : clientRepository(clientRepository) {
    if (clientRepository == nullptr) { throw ParameterException("Cannot create clientManager without repository!"); }
}

ClientManager::~ClientManager() {

}

Client_ptr ClientManager::registerClient(const std::string &firstName, const std::string &lastName, const int &age,
                                         const std::string &emailAddress) {
    Client_ptr clientCheck = getClient(emailAddress);  //sprawdzamy czy istnieje client w repozytorium: jesli clientCheck = nullptr to go nie ma
                                                       //a jezeli jest to upewniamy sie ze dokona sie dearchiwizacja.
    if (clientCheck == nullptr) {
        Client_ptr newClient = std::make_shared<Client>(firstName, lastName, age, emailAddress);
        clientRepository->add(newClient);
        return newClient;
    } else {
        clientCheck->setArchive(false);      // gdy klient był zarchiwizowany dokonuje się dearchiwizacja

        // ustawione zostają nowe dane klienta
        clientCheck->setFirstName(firstName);
        clientCheck->setLastName(lastName);
        clientCheck->setAge(age);

        return clientCheck;
    }
}

void ClientManager::unregisterClient(const Client_ptr &client) {

    if (client == nullptr) {
        throw ParameterException("Invalid Client_ptr!");
    }
    client->setArchive(true);
}

Client_ptr ClientManager::getClient(const std::string &emailAddress) const {
    ClientPredicate predicate = [emailAddress](const Client_ptr& ptr) {
        return ptr->getEmailAddress() == emailAddress;
    };
    return clientRepository->find(predicate);
}

std::string ClientManager::getAllClientsReport() const {
    return clientRepository->report();
}
