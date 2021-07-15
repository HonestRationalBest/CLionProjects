#include <iostream>
#include "Piosenka.h"

using namespace std;
int main() {

    int wybor, wybor1;

    cout << "To jest składanka na rok 2021" << endl;
    cout << "Czy chcesz posłuchaćskładanki ?" << endl;
    cout << "1 - tak, 0 - nie" << endl;
    cin>>wybor;

    Piosenka p1;
    if(wybor == 1){
        p1.PokazPiesenkiTytuly();
        cout << "Czy chcesz posłuchaćjakiejśinnej piosenki ?" << endl;
        cout << "1 - tak, 0 - nie" << endl;
        cin>>wybor;
        if(wybor == 1){
            wybor1 =1;
            while(wybor1 >= 0){
                cout << "Wybierz utwórod 1 do 10 lub wpisz 0 i wylosuj dowolny utwór, lub 11 żeby skonczyć" << endl;
                cin>>wybor1;
                if(wybor1 == 0){
                    wybor1 =  rand() % 10;
                }
                switch(wybor1){
                    case 1:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 2:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 3:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 4:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 5:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 6:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 7:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 8:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 9:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 10:
                        p1.Wyswietl_pozycje(wybor1-1);
                        break;
                    case 11:
                        return 0;
                    default:
                        cout << "Niepoprawne dane" << endl;
                        return 0;
                }
            }
        }else{
            return 0;
        }
    }
    return 0;
}
