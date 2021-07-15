#include <iostream>

using namespace std;

struct el_listy_1k{
    int dane;
    struct el_listy_1k* nast;
};
struct Lista_1K{
    struct el_listy_1k * head;
    struct el_listy_1k * tail;
    int counter;
};

int isEmpty(struct Lista_1K* lista){
    if(lista->head == NULL && lista->tail == NULL){
        return 1;
    }else{
        return 0;
    }
}

el_listy_1k* pushTail(struct Lista_1K* lista){

    el_listy_1k* temp = new struct el_listy_1k;
    temp->dane = rand() % 50 +1;
    temp->nast = nullptr;
    if (lista->head == nullptr && lista->tail == nullptr) {
        lista->head = temp;
        lista->tail = temp;
    }
    else {
        lista->tail->nast = temp;
        lista->tail = temp;
    }
    lista->counter++;
    return temp;
}


el_listy_1k* pushHead(struct Lista_1K* list) {
    el_listy_1k* temp = new struct el_listy_1k;
    temp->dane = rand() % 50 +1;
    temp->nast = nullptr;
    if (list->head == nullptr && list->tail == nullptr) {
        list->head = temp;
        list->tail = temp;
    }
    else {
        temp->nast = list->head;
        list->head = temp;
    }
    list->counter++;
    return temp;
}

el_listy_1k* pushInPos(struct Lista_1K* list, int position){
    el_listy_1k* temp = new struct el_listy_1k;
    el_listy_1k* p = list->head;
    temp->dane = rand() % 50 +1;
    temp->nast = nullptr;
    if (position < 0 || position > list->counter) {
        cout << "Pozicja musi być od 0 do " << list->counter << endl;
    }
    else if (position == 0 || position == 1) {
        return pushHead(list);
    }
    else if (position == list->counter) {
        return pushTail(list);
    }
    else {
        for (int i = 0; i < position - 2; i++) {
            p = p->nast;
        }
        temp->nast = p->nast;
        p->nast = temp;
        list->counter++;
        return temp;
    }
}


int popTail(struct Lista_1K* list) {
    if (list->head == nullptr && list->tail == nullptr) {
        cout << "Linked List is empty!" << endl;
    }
    else if (list->head == list->tail) {
        int x = list->tail->dane;
        el_listy_1k* temp = list->head;
        list->head = list->tail = nullptr;
        delete temp;
        list->counter--;
        return x;
    }
    else {
        int x = list->tail->dane;
        el_listy_1k* p = list->head;
        while (p->nast != list->tail) {
            p = p->nast;
        }
        p->nast = nullptr;
        delete list->tail;
        list->tail = p;
        return x;
    }

}

int popHead(struct Lista_1K* list) {

    if (list->head == nullptr && list->tail == nullptr) {
        cout << "Linked List is empty!" << endl;
    }
    else if (list->head == list->tail) {
        int x = list->head->dane;
        el_listy_1k* temp = list->head;
        list->head = list->tail = nullptr;
        delete temp;
        list->counter--;
        return x;
    }
    else {
        int x = list->head->dane;
        el_listy_1k* temp = list->head->nast;
        list->head->nast = nullptr;
        delete list->head;
        list->head = temp;
        list->counter--;
        return x;
    }
}

int popInPos(struct Lista_1K* list, int position) {
    if (position < 0 || position > list->counter) {
        cout << "Position shold be between 0 and " << list->counter << endl;

    }
    else if (position == 0 || position == 1) {
        return popHead(list);
    }
    else if (position == list->counter) {
        return popTail(list);
    }
    else {
        el_listy_1k* p = list->head;
        el_listy_1k* p1 = list->head;
        for (int i = 0; i < position - 2; i++) {
            p = p->nast;
            p1 = p1->nast;
        }
        p1 = p1->nast;
        int x = p1->dane;
        p->nast = p1->nast;
        p1->nast = nullptr;
        list->counter--;
        delete p1;
        return x;
    }
}


int getFirstElement(struct Lista_1K* list)
{
    if (list->head == nullptr && list->tail == nullptr) {
        cout << "List is empty!" << endl;
    }
    else {
        return list->head->dane;
    }
}
int getLastElement(struct Lista_1K* list)
{
    if (list->head == nullptr && list->tail == nullptr) {
        cout << "List is empty!" << endl;
    }
    else {
        return list->tail->dane;
    }
}

void printList(struct Lista_1K *lista){
    struct el_listy_1k*r;
    if(lista->head==NULL){
        cout<<"Lista jest pusta";
    }else{
        r=lista->head;
        cout<<"Lista: ";
        while(r!=NULL){
            cout<<r->dane<<",";
            r=r->nast;
        }
    }
}

double getAverage(struct Lista_1K *lista)
{
    el_listy_1k* p = lista->head;
    double sum = 0;
    while (p != lista->tail)
    {
        sum = sum + p->dane;
        p = p->nast;
    }
    sum = sum + p->dane;
    return sum / lista->counter;
}

void getMaxElement(struct Lista_1K *lista)
{
    int max = lista->head->dane;
    int index = 1;
    int k = 1;
    el_listy_1k* p = lista->head->nast;
    while (p != nullptr) {
        index++;
        if (max < p->dane) {
            max = p->dane;
            k = index;
        }
        p = p->nast;
    }
    cout << "The max element is: " << max << " under index " << k << endl;
}

void deleteAll(struct Lista_1K *lista) {
    while (true) {
        if (lista->head == lista->tail) {
            break;
        }
        else {
            popHead(lista);
        }
    }
    popHead(lista);

}


int main() {
    struct Lista_1K*naszalista;
    struct el_listy_1k*el;
    naszalista= new struct Lista_1K;
    naszalista->head= NULL;
    naszalista->tail= NULL;
    int result;
    while (true)
    {
        cout << endl;
        cout << "Sprawdzenie czy lista jest pusta - 1" << endl;
        cout << "Dodanie elementu na koniec listy - 2" << endl;
        cout << "Dodanie elementu na początek listy - 3" << endl;
        cout << "Dodanie elementu na określoną pozycję - 4" << endl;
        cout << "Usunięcie elementu na końcu listy - 5" << endl;
        cout << "Usunięcie elementu na początku listy - 6" << endl;
        cout << "Usunięcie elementu  znajdującego się na określonej pozycji - 7" << endl;
        cout << "Pobranie  pierwszego  elementu  z  listy - 8" << endl;
        cout << "Pobranie ostatniego elementu z listy - 9" << endl;
        cout << "Policzenie  średniej  arytmetycznej  elementów  w  liście - 10" << endl;
        cout << "Znalezienie elementu maksymalnego w liście - 11" << endl;
        cout << "Wyświetlenie całej listy - 12" << endl;
        cout << "Usunięcie całej listy wraz ze zwolnieniem pamięci - 13" << endl;
        cout << "Wyjście z programu - 14" << endl;
        cout << "Wprowadz numer: ";

        int wyb = 0;
        cin >> wyb;

        switch (wyb)
        {
            case 1:
                result = isEmpty(naszalista);
                if(result == 1){
                    cout<<"Lista pusta"<<endl;
                }else{
                    cout<<"Lista nie pusta"<<endl;
                }
                break;
            case 2:
                el = pushTail(naszalista);
                cout<<"Dodano na koniec: "<<el->dane<<endl;
                break;
            case 3:
                el = pushHead(naszalista);
                cout<<"Dodano na początek: "<<el->dane<<endl;
                break;
            case 4:
                cout<<"Proszę podać pozycję: "<<endl;
                cin>>result;
                el = pushInPos(naszalista, result);
                cout<<"Dodano na pozycje dane: "<<el->dane<<endl;
                break;
            case 5:
                result = popTail(naszalista);
                cout<<"Usunięte z początku: "<<result<<endl;
                break;
            case 6:
                result = popHead(naszalista);
                cout<<"Usunięte z początku: "<<result<<endl;
                break;
            case 7:
                cout<<"Proszę podać pozycję: "<<endl;
                cin>>result;
                result = popInPos(naszalista, result);
                cout<<"Dodano na pozycje dane: "<<result<<endl;
                break;
            case 8:
                cout<<getFirstElement(naszalista)<<endl;
                break;
            case 9:
                cout<<getLastElement(naszalista)<<endl;
                break;
            case 10:
                cout<<getAverage(naszalista)<<endl;
                break;
            case 11:
                getMaxElement(naszalista);
                break;
            case 12:
                printList(naszalista);
                break;
            case 13:
                deleteAll(naszalista);
                break;
            case 14:
                return 0;
            default:
                cout << "Niepoprawny numer" << endl;
        }
    }
}



