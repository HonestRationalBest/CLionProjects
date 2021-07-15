#include <iostream>
#include "Figura.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Kolo kolo1("kolo", 5);
    Kolo kolo2;
    Figura newFigura;
    double p1 = kolo1.podajPole();
    double p2 = kolo2.podajPole();
    std::cout << newFigura.Dodaj(p1, p2);
    std::cout << newFigura.Odejmuj(p1, p2);
    std::cout << newFigura.Zamien(p1, p2);
    return 0;
}
