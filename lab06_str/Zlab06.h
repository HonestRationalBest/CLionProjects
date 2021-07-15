#ifndef LAB06_STR_ZLAB06_H
#define LAB06_STR_ZLAB06_H
#include <string>
#include <iostream>
#include "Zlab03.h"

using namespace std;

class Obliczenia {
protected:
    const double pi = 3.14;
public:
    virtual double promienKolaWgPola() = 0;
    virtual double promenOkreguWgObwodu() = 0;
    virtual ~Obliczenia();
};

class Kwadrat: public Prostokat, public Obliczenia
{
public:
    Kwadrat(string nazwa = "?", double bok =0)
            :Prostokat(nazwa,bok,bok){}
    ~Kwadrat()
    {
        cout << "Kwadrat: " << nazwa
             <<" kończy działanie" << endl;
    }
    virtual std::string doTekstu();
    double promienKolaWgPola();
    double promenOkreguWgObwodu() ;
};


#endif //LAB06_STR_ZLAB06_H
