#include"Model.h"
#include<QApplication>
#include"Sterowanie.h"
#include"Wyswietlanie.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Model model;
    Sterowanie sterowanie;
    Wyswietlanie wyswietlanie;
//Podłączanie obiektów
    wyswietlanie.podlaczModel(&model);
    QObject::connect (sterowanie.przycisk(), //źródło
                      SIGNAL (clicked()), //sygnał źródła
                      &app, //odbiorca
                      SLOT(quit ()) //akcja odbiorcy
    );
    QObject::connect (sterowanie.slidera(), //źródło
                      SIGNAL (valueChanged (int)), //sygnał źródła
                      &wyswietlanie, //odbiorca
                      SLOT(przerysuj(int)) //akcja odbiorcy
    );
    wyswietlanie.show();
    sterowanie.show();
    return app.exec();
}