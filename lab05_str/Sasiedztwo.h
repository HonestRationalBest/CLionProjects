//
// Created by pavel on 29.03.2021.
//

#ifndef LAB_05_STR_SASIEDZTWO_H
#define LAB_05_STR_SASIEDZTWO_H

enum RodzajMieszkanca {GLON,GRZYB,BAKTERIA,PUSTKA, SCIANA,
        TRUP, NIEZNANE};
enum AkcjaMieszkanca {POTOMEK, POLOWANIE, ROZKLAD, NIC};
enum Polozenie {P=0, PG=1, G=2, LG=3, L=4, LD=5, D=6, PD=7,
        NIGDZIE=8 };

class Sasiedztwo{

private:

    RodzajMieszkanca sasiad[3][3];


    RodzajMieszkanca * elementWewnetrzny(Polozenie polozenie);


    static Polozenie losujPolozenie();

public:
    Sasiedztwo(RodzajMieszkanca rodzaj = NIEZNANE);


    void okreslSasiada(Polozenie polozenie, RodzajMieszkanca rodzaj);

    RodzajMieszkanca ktoJestSasiadem(Polozenie polozenie);

    unsigned short ile(RodzajMieszkanca rodzaj) const;

    Polozenie losujSasiada(RodzajMieszkanca rodzaj);

    static void zmienIdeksyWgPolozenia(Polozenie polozenie,long & wiersz, long & kolumna);

    static void zmienIdeksyWgPolozenia(Polozenie polozenie, unsigned int & wiersz,unsigned int & kolumna);

    };

#endif //LAB_05_STR_SASIEDZTWO_H
