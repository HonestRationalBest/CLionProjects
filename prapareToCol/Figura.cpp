//
// Created by pavel on 23.04.2021.
//

#include "Figura.h"
#include <string>
#include <math.h>
#include <iostream>
using namespace std;


Operacje::~Operacje()
{
}

void Figura::liczPole()
{
    pole =  value*value*3.14;
}

double Figura::podajPole()
{
    return pole;
}

Kolo::Kolo(string f, int v):figura(f){
    value = v;
    liczPole();
}

Kolo::~Kolo()
{
    std::cout << "Kolo znika" << std::endl;
}

Figura::Figura(string f, int v):figura(f){
    value = v;
    liczPole();
}

Figura::~Figura()
{
    std::cout << "Kolo znika" << std::endl;
}

double Figura::Dodaj(double p1, double p2){
    return p1+p2;
}

double Figura::Odejmuj(double p1, double p2){
    return p1+p2;
}
double Figura::Zamien(double p1, double p2){
    return p1+p2;
}