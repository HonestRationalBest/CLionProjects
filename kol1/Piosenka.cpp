//
// Created by pavel on 26.04.2021.
//
#include <iostream>
#include "Piosenka.h"
using namespace std;

void Piosenka::PokazPiesenkiTytuly(){
    for(int i =0; i<10; i++){
        cout<<arrayPiosenekTytuly[i]<<endl;
    }
}

void Piosenka::Wyswietl_pozycje(int wybor){
    cout<<arrayPiosenek[wybor]<<endl;
}
