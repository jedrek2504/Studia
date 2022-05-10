#include <iostream>
#include "Pociag.h"
#include "Pasazerski.h"
#include "Towarowy.h"

using namespace std;

int main() {
    Wagon_ptr towarowy(new Towarowy(100,30));
    Wagon_ptr pasazerski (new Pasazerski(20, 60));
    Pociag_ptr pociag(new Pociag(200));
    pociag->dodajWagon(towarowy);
    pociag->dodajWagon(pasazerski);
    std::cout << pociag->toString();
//    std::cout <<"                                         ______\n"
//                "                                          .-\"\"\"\".._'.       _,##\n"
//                "                                   _..__ |.-\"\"\"-.|  |   _,##'`-._\n"
//                "                                  (_____)||_____||  |_,##'`-._,##'`\n"
//                "                                  _|   |.;-\"\"-.  |  |#'`-._,##'`\n"
//                "                               _.;_ `--' `\\    \\ |.'`\\._,##'`\n"
//                "                              /.-.\\ `\\     |.-\";.`_, |##'`\n"
//                "                              |\\__/   | _..;__  |'-' /\n"
//                "                              '.____.'_.-`)\\--' /'-'`\n"
//                "                               //||\\\\(_.-'_,'-'`\n"
//                "                             (`-...-')_,##'`\n"
//                "                           _,##`-..,-;##`\n"
//                "                       _,##'`-._,##'`\n"
//                "                    _,##'`-._,##'`\n"
//                "                      `-._,##'`";
    return EXIT_SUCCESS;
}