#include <iostream>
using namespace std;

void print(int &number2){
    cout<<number2<<endl;
    number2*=2;
    cout<<number2<<endl;
}


int main(){
    int number1=7;
    cout<<number1<<endl;
    print(number1);
    cout<<number1<<endl;
    return 1;
}