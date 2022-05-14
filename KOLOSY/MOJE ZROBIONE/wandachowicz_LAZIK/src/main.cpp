#include <iostream>
#include "Template.h"
#include <iostream>
#include "RakietaKosmiczna.h"
#include "Satelita.h"
#include "LazikMarsjanski.h"

using namespace std;

int main() {
    RakietaKosmiczna_ptr rakieta(new RakietaKosmiczna(30));
    Element_ptr satelita(new Satelita(10 , "Wojtyla"));
    Element_ptr lazik(new LazikMarsjanski(10 , "LAZIKUS" , "DiKarpio"));
    rakieta->zaladuj(satelita);
    rakieta->zaladuj(lazik);
    cout<<rakieta->toString();
    return 0;
}
