//
// Created by pavel on 19.04.2021.
//

#ifndef LAB07_STR_OSOBNIKI_H
#define LAB07_STR_OSOBNIKI_H

#include "Mieszakniec.h"
#include "Organizm.h"


class Glon: protected Organizm, public Mieszkaniec {
public:
    Glon();
    virtual RodzajMieszkanca kimJestes() final;
    virtual ZamiarMieszkanca
    wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec * dajPotomka();
    virtual void przyjmijZdobycz
            (Mieszkaniec * mieszkaniec);
};

class Grzyb: protected Organizm, public Mieszkaniec {
public:
    Grzyb();
    virtual RodzajMieszkanca kimJestes() final;
    virtual ZamiarMieszkanca
    wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec * dajPotomka();
    virtual void przyjmijZdobycz
            (Mieszkaniec * mieszkaniec);
};

class Bakteria: protected Organizm, public Mieszkaniec {
public:
    Bakteria();
    virtual RodzajMieszkanca kimJestes() final;
    virtual ZamiarMieszkanca
    wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec * dajPotomka();s
    virtual void przyjmijZdobycz
            (Mieszkaniec * mieszkaniec);
};


#endif //LAB07_STR_OSOBNIKI_H
