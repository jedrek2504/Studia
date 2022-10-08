//DZIALA ALE TESTY SA JAKIES POJEBANE NIE CHCE SIE ZBUDOWAC PROGRAM ZA ABRDZO XDDDDD

#include <iostream>
#include "Magazyn.h"
#include "Beczka.h"
#include "Skrzynia.h"

using namespace std;

int main(int argc, char *argv[])
{
    Magazyn_ptr m(new Magazyn(1234));
    OpakowaniePtr b(new Beczka(1234, "13" , 3));
    OpakowaniePtr s(new Skrzynia(1234, 13 , 3, 4));

    m->wstaw(b);
    m->wstaw(s);

    cout<<m->opis();


    return 0;
}