#include <time.h>
#include <iostream>
using namespace std;
struct Node {
    char value;
    Node* next;

};
struct body {
    Node* head;
    Node* tail;
};
typedef struct Node node;
typedef struct body Body;
node* Q = new (node);
Body* body = new (Body);



void Enqueue(char val) {
    node* temp = new node;
    temp->value = val;
    if (body->head == NULL && body->tail == NULL) {
        body->head = temp;
        body->tail = temp;
        temp->next = NULL;
    }
    else {
        body->tail->next = temp;
        body->tail = temp;
        temp->next = NULL;
    }

}
void PrintQueue() {
    node* i = body->head;
    if (body->head != NULL && body->tail != NULL) {
        while (i->next != NULL) {
            cout << i->value<< " ";
            i = i->next;
        }
        cout << i->value;
    }
    else {
        cout << "Queue is empty, nothing to print!" << endl;
    }
}

void IsEmpty() {
    if (body->head == NULL && body->tail == NULL) {
        cout << "Queue is empty";
    }
    else {
        cout << "Queue is not empty";
    }

}
void Dequeue() {
    if (body->head == NULL && body->tail == NULL) {
        cout << "Queue empty, nothing to dequeue";
    }
    else if (body->head == body->tail) {
        node* ToDelete = body->head;
        node* temp = body->head;
        temp = temp->next;
        body->head = NULL;
        ToDelete->next = NULL;
        body->head = temp;
        body->tail = temp;
        delete ToDelete;
    }
    else {
        node* ToDelete = body->head;
        node* temp = body->head;
        temp = temp->next;
        body->head = NULL;
        ToDelete->next = NULL;
        body->head = temp;
        delete ToDelete;
    }


}
void GetFirst() {
    if (body->head == NULL && body->tail == NULL) {
        cout << "Queue empty! Can't get the first element";
    }
    else {
        cout << "The first element of the queue is:" << body->head->value;
    }

}
void DeleteQueue() {
    if (body->head == NULL && body->tail == NULL) {
        cout << "Queue is already empty, nothing to delete";
    }
    else if (body->head == body->tail) {
        Dequeue();
    }
    else {

        while (true) {
            if (body->head == body->tail) {
                Dequeue();
                break;
            }
            else {
                Dequeue();
            }
        }
    }
}
int main()
{

    body->head = NULL;
    body->tail = NULL;
    int input;
    cout << "*********************************************************" << endl;
    cout << "   1. Is Empty" << endl;
    cout << "   2. Enqueue" << endl;
    cout << "   3. Dequeue" << endl;
    cout << "   4. Get First" << endl;
    cout << "   5. Delete All" << endl;
    cout << "   6. Load From File" << endl;
    cout << "   7. Exit" << endl;
    cout << "*********************************************************" << endl;
    while (true) {
        cout << "Choose function: ";
        cin >> input;
        cout << endl;
        switch (input)
        {
            case 1:
                IsEmpty();
                break;
            case 2:
                int i;
                srand(time(NULL));
                for (int b = 0; b < 20; b++) {
                    i = 97 + rand() % 26;
                    Enqueue((char)i);

                }
                break;
            case 3:
                Dequeue();
                break;
            case 4:
                GetFirst();
                break;
            case 5:
                DeleteQueue();
                break;
            case 6:
                DeleteQueue();
                cout << "Loading form file...";
                return 0;
            case 7:
                DeleteQueue();
                cout << "Bye"; return 0;
            default:
                cout << "Wrong input!"; return 0;
        }
    }
    DeleteQueue();
    delete Q;
    delete body;

}

//Zad1.1
int sum(FIFO* kolejka){
    int sum = 0;
    if(isEmpty(kolejka)){
        return 0;
    }
    temp = kolejka->head;
    while(true){
        sum+=temp->value;
        if(temp->next == nullptr){
            cout<<"Suma: "<<sum<<endl;
            return 1;
        }
        temp = temp->next;
    }
}
//Zad1.2
int main(){
    FIFO* kolejka = new struct Fifo;
    int x;
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    cout<<"Prosze podać element: "<<x;
    attach(kolejka, x);
    x = sum(kolejka);
    if(x==1){
        cout<<"Kolejka nie pusta"<<endl;
    }else{
        cout<<"Kolejka pusta"<<endl;
    }
}
//Zad2