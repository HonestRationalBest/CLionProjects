#include <iostream>
using namespace std;

struct elemStosu{
    int dane;
    struct elemStosu* nast;
};

int isEmpty(elemStosu*w){
    if(w == nullptr){
        return 0;
    }else{
        return 1;
    }
}

void lastPrint(elemStosu*w){
    cout<<w->dane;
}


elemStosu* push(elemStosu*w, int * x){
    elemStosu*nowy=new elemStosu;

    nowy->dane = *x;
    nowy->nast=w;
    return nowy;
}

elemStosu* pop(elemStosu*w, int*x){
    if(isEmpty(w) == 1){
        elemStosu*temp=w;
        w=w->nast;
        *x=temp->dane;
        delete temp;
    }
    return w;
}

void deleteAll(elemStosu*&w){
    int*x;
    while(isEmpty(w) == 1){
        w = pop(w, x);
    }
}


int main() {
    elemStosu* stos = nullptr;
    int *x = nullptr;
    int result;
    while (true)
    {
        cout << endl;
        cout << "Sprawdzenie czy stos jest pusty - 1" << endl;
        cout << "Dodanie elementu na stos - 2" << endl;
        cout << "Usunięcie elementu ze stosu - 3" << endl;
        cout << "Pobranie elementu ze stosu - 4" << endl;
        cout << "Usunięcie wszystkich elementów ze stosu - 5" << endl;
        cout << "Wyjście z programu - 6" << endl;
        cout << "Wprowadz numer: ";

        int wyb = 0;
        cin >> wyb;

        switch (wyb)
        {
            case 1:
                result = isEmpty(stos);
                if(result == 0){
                    cout<<"Pusty"<<endl;
                }else{
                    cout<<"Niepusty"<<endl;
                }
                break;
            case 2:
                *x = rand() % 10+1;
                stos = push(stos, x);
                cout<<"Dodano: "<<*x;
                break;
            case 3:
                stos = pop(stos, x);
                cout<<"Usuniente: "<<*x;
                break;
            case 4:
                lastPrint(stos);
                break;
            case 5:
                deleteAll(stos);
                break;
            case 6:
                return 0;
            default:
                cout << "Niepoprawny numer" << endl;
        }
    }
}






