#include <iostream>
#include "Template.h"
#include "budynek.h"
#include "biuro.h"
#include "mieszkanie.h"
#include "lokal.h"

#include <vector>

using namespace std;

int main() {
    cout << "Lokale" << endl;

    Budynek_ptr budynek(new Budynek());

    Mieszkanie_ptr m1(new Mieszkanie(60,15.0));
    Mieszkanie_ptr m2(new Mieszkanie(90,14.0));
    Mieszkanie_ptr m3(new Mieszkanie(40,10.0));
    Biuro_ptr b1(new Biuro(20,20.0,140.0));
    Biuro_ptr b2(new Biuro(90,30.0,200.0));

    budynek->dodaj_lokal(m1);
    budynek->dodaj_lokal(m2);
    budynek->dodaj_lokal(m3);
    budynek->dodaj_lokal(b1);
    budynek->dodaj_lokal(b2);

    cout<<m1->toString()<<endl;
    cout<<m2->toString()<<endl;
    cout<<m3->toString()<<endl;
    cout<<b1->toString()<<endl;
    cout<<b2->toString()<<endl;



    return 0;
}
