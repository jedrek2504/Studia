#include <iostream>
#include "Rowboat.h"
#include "Sailboat.h"
#include "BoatRental.h"

using namespace std;

int main()
{
    BoatRental_ptr boatrental(new BoatRental(50));
    Boat_ptr myRB(new Rowboat(1, "R15", true, 250));
    Boat_ptr mySB(new Sailboat(2, "S15", true, 6));
    boatrental->addBoat(myRB);
    boatrental->addBoat(mySB);
    boatrental->rentBoat(1);
    cout<<boatrental->showAvailableBoats();
    cout<<boatrental->showRentedBoats();

    return 0;
}
