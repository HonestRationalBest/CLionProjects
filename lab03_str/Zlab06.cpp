//
// Created by pavel on 12.04.2021.
//
#include "Zlab06.h"

string Kwadrat::doTekstu()
{
    string napis ="";
    napis = "Kwadrat o nazwie: " + nazwa
            + " bok=" + to_string(bok1);
    if(poprawny) napis += " obwod=" + to_string(obwod)
                          + " pole=" + to_string(pole);
    else napis +=" !Figura niepoprawna.";
    return napis;
}