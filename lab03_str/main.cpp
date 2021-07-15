#include <iostream>
using namespace std;
#include "Nisza.h"
#include "Osobniki.h"
#include "Sasiedztwo.h"

#include <fstream>

int main() {
    Srodowisko ekoSystem
            =Srodowisko::czytajZPliku("start.txt");
    ofstream plikWynikowy("symulacja.txt");
    if(!plikWynikowy.is_open()) return 1;
    string stanSymulacji;
    unsigned long i = 0;
    do{
        system("clear");
        cout << "Krok symulacji: " << i << endl;
        plikWynikowy << "Krok symulacji: " << i << endl;
        stanSymulacji = ekoSystem.doTekstu();
        cout << endl << stanSymulacji << endl;
        plikWynikowy << stanSymulacji << endl;
        cin.ignore(1);
        ekoSystem++;
        i++;
    } while(i < 200 && !ekoSystem);
    cout << endl;
    plikWynikowy.close();
    return 0;
}
