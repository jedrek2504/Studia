#include <iostream>
#include "manager/ClientManager.h"
#include "manager/TicketManager.h"
#include "manager/MovieManager.h"
#include "model/typedefs.h"
#include "model/Repository.h"
#include "model/Room.h"

using namespace std;

int main()
{
    //PRZYKLAD FUNKCJONALNOSCI:
    //W ponizszym kodzie sprawdze dzialanie funkcji TicketManager::getAllTicketsRaport() dla przykladowych
    //klientow, filmow, etc. Pokaze rowniez dzialanie niektorych metod wystepujacych w moim projekcie:
    //##################################################################################################################

    //Towrzymy wszystkich managerow oraz repozytoria
    ClientRepository_ptr clientRepo = std::make_shared<Repository<Client_ptr>>();
    ClientManager_ptr clientManager = std::make_shared<ClientManager>(clientRepo);
    MovieRepository_ptr movieRepo = std::make_shared<Repository<Movie_ptr>>();
    MovieManager_ptr movieManager = std::make_shared<MovieManager>(movieRepo);
    TicketRepository_ptr ticketRepo = std::make_shared<Repository<Ticket_ptr>>();
    TicketManager_ptr ticketManager = std::make_shared<TicketManager>(ticketRepo);

    //tworzymy 2 sale kinowe
    Room_ptr room1(new Room(1, 40));
    Room_ptr room2(new Room(2, 2));

    //tworzymy 5 klientow
    Client_ptr client1 = clientManager->registerClient("Jan" , "Kowalski" , 17 , "email1@mail.com"); // normalny
    Client_ptr client2 = clientManager->registerClient("Adam" , "Nowak" , 6 , "email2@mail.com"); //dzieciecy
    Client_ptr client3 = clientManager->registerClient("Jedrzej" , "Kostyk" , 20 , "email3@mail.com"); //studencki
    Client_ptr client4 = clientManager->registerClient("Karol" , "Wojtyla" , 64 , "email4@mail.com"); //rencista
    Client_ptr client5 = clientManager->registerClient("Jakub" , "Lysiuk" , 17 , "email5@mail.com"); //normalny

    //tworzymy 2 filmy
    Movie_ptr movie1 = movieManager->registerMovie(1 , "Piraci z Karaibow: Na krańcu świata" , "Akcja");
    Movie_ptr movie2 = movieManager->registerMovie(2 , "Hobbit: Niezwykła podróż" , "Przygodowy");

    //sprawdzamy ilosc dostepnych miejsc w poszczegolnych salach PRZED zakupem biletow
    cout<<"Ilosc dostepnych miejsc w sali 1 przed zakupem biletow: "<<room1->getNoOfAvailableSeats()<<endl; //40
    cout<<"Ilosc dostepnych miejsc w sali 2 przed zakupem biletow: "<<room2->getNoOfAvailableSeats()<<endl; //2

    //tworzymy bilety dla 5 klientow
    ticketManager->registerTicket(100.0 , client1 , movie1 , room1);
    ticketManager->registerTicket(100.0 , client2 , movie1 , room1);
    ticketManager->registerTicket(100.0 , client3 , movie1 , room1);
    ticketManager->registerTicket(100.0 , client4 , movie2 , room2);
    ticketManager->registerTicket(100.0 , clientManager->getClient("email5@mail.com") , movieManager->getMovie(2) , room2);

    //Wypiszemy: klientow , filmy, bilety
    cout<<"KLIENCI"<<endl;
    cout<<clientManager->getAllClientsReport()<<endl;
    cout<<"FILMY"<<endl;
    cout<<movieManager->getAllMoviesReport()<<endl;
    cout<<"BILETY"<<endl;
    cout<<"============================================================================================================"<<endl;
    cout<<ticketManager->getAllTicketsReport();
    cout<<"============================================================================================================"<<endl;

    //sprawdzamy ilosc dostepnych miejsc w poszczegolnych salach PO zakupem biletow
    cout<<"Ilosc dostepnych miejsc w sali 1 po zakupie biletow: "<<room1->getNoOfAvailableSeats()<<endl; //47
    cout<<"Ilosc dostepnych miejsc w sali 2 po zakupie biletow: "<<room2->getNoOfAvailableSeats()<<endl; //0

    //korzystamy teraz z metody konczacej film 2
    ticketManager->endFilm(movie2);

    //sprawdzamy co sie zmienilo po wywolaniu metody TicketManager::getAllTicketsRaport():
    //bilety na movie2 trafiaja do archiwum
    //film zostaje przerwany
    //siedzenia w sali, w ktorej byl odtwarzany movie2 (room2) zostaja zwolnione.
    cout<<"BILETY PO WYWOLANIU METODY endFilm()"<<endl;
    cout<<"============================================================================================================"<<endl;
    cout<<ticketManager->getAllTicketsReport();
    cout<<"============================================================================================================"<<endl;

    //sprawdzamy ilosc dostepnych miejsc w poszczegolnych salach PO zakonczeniu filmu
    cout<<"Ilosc dostepnych miejsc w sali 1 po zakonczeniu filmu: "<<room1->getNoOfAvailableSeats()<<endl; //47
    cout<<"Ilosc dostepnych miejsc w sali 2 po zakonczeniu filmu: "<<room2->getNoOfAvailableSeats()<<endl; //2

    //Jedrzej Kostyk 242430 IS 2021/2022
    //
    //##################################################################################################################

    return 0;
}
