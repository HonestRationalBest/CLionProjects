#ifndef LAB06_STR_ZLAB06_H
#define LAB06_STR_ZLAB06_H
#include <string>
#include <iostream>
#include "ZLab03.h"

using namespace std;

class Kwadrat: public Prostokat
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
};


#endif //LAB06_STR_ZLAB06_H
