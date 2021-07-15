//
// Created by pavel on 23.04.2021.
//

#ifndef PRAPARETOCOL_FIGURA_H
#define PRAPARETOCOL_FIGURA_H
#include <string>
using namespace std;

class Operacje{
public:
    virtual double Dodaj(double p1, double p2);
    virtual double Odejmuj(double p1, double p2);
    virtual double Zamien(double p1, double p2);
    virtual ~Operacje();
};

class Figura: public Operacje{
public:
    int value;
    double pole;
    string figura;
    double podajPole();
    void liczPole();
    double Dodaj(double p1, double p2);
    double Odejmuj(double p1, double p2);
    double Zamien(double p1, double p2);
    Figura(string figura = "Kolo", int value = 1);
    ~Figura();
};


class Kolo: public Figura{
public:
    string figura;
    double liczPoleKola();
    Kolo(string figura = "Kolo", int value = 1);
    ~Kolo();
};

#endif //PRAPARETOCOL_FIGURA_H
