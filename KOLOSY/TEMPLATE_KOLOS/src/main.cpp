#include <iostream>
#include "BoatRental.h"
#include "RowBoat.h"
#include "SailBoat.h"

using namespace std;

int main() {

    BoatRental_ptr boatrental(new BoatRental(100));
    Boat_ptr zeglowka(new Sailboat(1 , "fafik1" , NULL , 6));
    Boat_ptr lodka(new Rowboat(2 , "fafik2" , NULL , 201));

    cout<<zeglowka->calculateRentalPrice()<<endl;
    cout<<boatrental->getAccount()<<endl;
    boatrental->addBoat(zeglowka);
    boatrental->addBoat(lodka);
    boatrental->rentBoat(1);
    boatrental->returnBoat(1);
    cout<<boatrental->getAccount()<<endl;

    return EXIT_SUCCESS;

}