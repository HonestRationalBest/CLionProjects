#include <iostream>
using namespace std;

struct Elem{
    int data;
    struct Elem* next;
    struct Elem* prev;
};

int isEmpty(struct Elem* list){
    if(list->next == NULL && list->prev == NULL){
        return 1;
    }else{
        return 0;
    }
}

int insertEnd(struct Elem* list)
{
    if (list == NULL)
    {
        Elem* elem = new struct Elem;
        elem->data = rand() % 50 +1;
        elem->next = elem->prev = elem;
        list = elem;
        return list->data;
    }
    Elem *last = list->prev;
    struct Elem* new_node = new Elem;
    new_node->data = rand() % 50 +1;
    new_node->next = list;
    list->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
    return list->data;
}

int main() {
    struct Elem *elem;
    elem= new struct Elem;
    elem->next= NULL;
    elem->prev= NULL;
    int result;
    while (true)
    {
        cout << endl;
        cout << "Sprawdzenie czy lista jest pusta - 1" << endl;
        cout << "Dodanie elementu na koniec listy - 2" << endl;
        cout << "Dodanie elementu na początek listy - 3" << endl;
        cout << "Usunięcie elementu z końca listy - 4" << endl;
        cout << "Usunięcie elementu z początku listy - 5" << endl;
        cout << "Usunięcie elementu bieżącego - 6" << endl;
        cout << "Wyświetlenie elementów  - 7" << endl;
        cout << "Usunięcie całej listy wraz ze zwolnieniem pamięci - 8" << endl;
        cout << "Wyjście z programu - 9" << endl;
        cout << "Wprowadz numer: ";

        int choise = 0;
        cin >> choise;

        switch (choise)
        {
            case 1:
                if(isEmpty(elem)){
                    cout<<"Lista pusta"<<endl;
                }else{
                    cout<<"Lista nie pusta"<<endl;
                }
                break;
            case 2:
                result = insertEnd(elem);
                cout<<"Dodano za element bieżący: "<<result<<endl;
            case 3:

            case 4:

            case 5:

            case 6:

            case 7:
                break;
            case 8:
                break;
            case 9:
                return 0;
            default:
                cout << "Niepoprawny numer" << endl;
        }
    }
}