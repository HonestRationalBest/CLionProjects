//
// Created by pavel on 26.04.2021.
//

#ifndef KOL1_PIOSENKA_H
#define KOL1_PIOSENKA_H
#include <iostream>
#include <string>
using namespace std;


class Piosenka {
public:
    string arrayPiosenekTytuly[10]={"Piosenka_1","Piosenka_2","Piosenka_3","Piosenka_4","Piosenka_5","Piosenka_6","Piosenka_7","Piosenka_8","Piosenka_9","Piosenka_10"};
    string arrayPiosenek[10]={"Piosenka_1, Wykonawca:Piosenkarz_1;Tekst: To jest tekst do piosenkinr.1",
                              "Piosenka_2, Wykonawca:Piosenkarz_2;Tekst: To jest tekst do piosenkinr.1",
                              "Piosenka_3, Wykonawca:Piosenkarz_3;Tekst: To jest tekst do piosenkinr.1",
                              "Piosenka_4, Wykonawca:Piosenkarz_4;Tekst: To jest tekst do piosenkinr.1",
                              "Piosenka_5, Wykonawca:Piosenkarz_5;Tekst: To jest tekst do piosenkinr.1",
                              "Piosenka_6, Wykonawca:Piosenkarz_6;Tekst: To jest tekst do piosenkinr.1",
                              "Piosenka_7, Wykonawca:Piosenkarz_7;Tekst: To jest tekst do piosenkinr.1",
                              "Piosenka_8, Wykonawca:Piosenkarz_8;Tekst: To jest tekst do piosenkinr.1",
                              "Piosenka_9, Wykonawca:Piosenkarz_9;Tekst: To jest tekst do piosenkinr.1",
                              "Piosenka_10, Wykonawca:Piosenkarz_10;Tekst: To jest tekst do piosenkinr.1"};
    void PokazPiesenkiTytuly();
    void Wyswietl_pozycje(int wybor);

};


#endif //KOL1_PIOSENKA_H
