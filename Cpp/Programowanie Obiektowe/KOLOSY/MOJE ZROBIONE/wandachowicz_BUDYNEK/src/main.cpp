#include <iostream>
#include "Template.h"
#include "Budynek.h"
#include "Mieszkanie.h"
#include "Biuro.h"

using namespace std;

int main() {

    Budynek_ptr budynek(new Budynek());
    Lokal_ptr Mieszkanie1(new Mieszkanie(60 , 15));
    Lokal_ptr Mieszkanie2(new Mieszkanie(90 , 14));
    Lokal_ptr Mieszkanie3(new Mieszkanie(40 , 10));

    Lokal_ptr Biuro1(new Biuro(20 , 20 , 140));
    Lokal_ptr Biuro2(new Biuro(90 , 30 , 200));

    budynek->dodaj_lokal(Mieszkanie1);
    budynek->dodaj_lokal(Mieszkanie2);
    budynek->dodaj_lokal(Mieszkanie3);
    budynek->dodaj_lokal(Biuro1);
    budynek->dodaj_lokal(Biuro2);

    cout<<budynek->toString();

    return 0;
}
