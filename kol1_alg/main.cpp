#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//Pavel Korshun 11

/* Zadanie 11Pobieramy od użytkownikadane  o ksamochodach.
 * Są to: rocznik, marka  oraz cena (liczba całkowita dodatnia).
 * a.Posortować samochodyna te o cenie nie wyższej niż 30 000, a następnie pozostałe.
 * b.Uporządkować malejąco algorytmem sortowania  przez  wybieraniewedług rocznikasamochody o cenie powyżej 30 000.
 * c.Wyznaczyć, ile samochodów o cenie nie wyższej niż 30000 jest marki o podanej przez użytkownika nazwie.
 * d.Wyznaczyć trzy (różne)liczby oznaczające roczniki najtańszych samochodów.U
 * WAGI:
 * 1.Informacje o jednym samochodzienależy przechowywać w strukturze.
 * 2.Każdy podpunkt należy zrealizować jako oddzielną funkcję, która wszystkie niezbędne informacje dostaje jako parametry wejściowe, a wyniki zwraca jako wynik lub jako parametry wynikowe.
 * 3.W programie nie wolno używać zmiennych globalnych.
 * 4.Wszystko  należy  zrealizować  w  jednej  tablicy   z   danymi –nie  należy  używać dodatkowych tablic.
 * 5.Wyżej  punktowane  będą  optymalne  algorytmy  pod  względem  czasowym ipamięciowym.
 * 6.Po każdym podpunkcie należy wyświetlić całą tablicę z  danymi –do  tego  celu zdefiniować odpowiednią funkcję.
 * 7.W programie głównym algorytmy mają być zrealizowane w podanej w zadaniu kolejności.  W  kolejnych  podpunktach  powinno  się  wykorzystywać  informacje otrzymane w poprzednich podpunktach i brać pod uwagę stan tablicy.
*/


struct car
{
    string marka;
    int rocznik;
    int cena;
};

int pobranie(car *&tab)
{
    int n;
    cout << "Wpisz liczbe samochodów:" << endl;
    cin >> n;
    tab = new car[n];
    cout << "Wpish dane" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> tab[i].marka;
        cin >> tab[i].rocznik;
        cin >> tab[i].cena;
        cout << endl;
    }
    cout << endl;
    return n;
}

void pokaz(car *&tab, int n)
{
    for (int i = 0; i < n; i++)
        cout << tab[i].marka <<tab[i].rocznik << tab[i].cena << endl;
    cout << endl;
}

int flaga_polska(car *&lista_danych, int n,int &granicznik)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        while (lista_danych[i].cena <= 30000 && i < j)
            i++;
        while (lista_danych[j].cena > 30000 && i < j)
            j--;
        if (i < j)
        {
            swap(lista_danych[i], lista_danych[j]);
            i++;
            j--;
        }
    }
    if (lista_danych[i].cena <= 30000)
        return i + 1;

    return i;
}

void selectionSort(car *arr, int nowailosc, int n)
{
    int i, j, min_idx, temp;

        for (i = nowailosc; i < n; ++i)
        {
            min_idx = i;
            for (j = i+1; j < n; j++)
                if (arr[j].rocznik > arr[min_idx].rocznik)
                    min_idx = j;

            temp = arr[i].rocznik;
            arr[i] = arr[min_idx];
            arr[min_idx].rocznik = temp;
        }

}

void algorytmNaiwny(string wzorzec, int nowailosc, car *arr){

    for(int i = 0; i< nowailosc;i++){
        int M= wzorzec.length();
        int N= arr[i].marka.length();
        int ok=0;
        for (int i = 0; i <= N - M; i++) {
            int j;

            for (j = 0; j < M; j++)
                if (arr[i].marka[i + j] != wzorzec[j])
                    break;

            if (j == M){
                cout << "Wzorzec jest na pozycji "
                     << i << endl;
                ok++;
            }


        }
        if(ok == 0){
            cout << "Brak wyników "<< endl;
        }
    }


}

int main()
{
    car *tab;
    int n, granicznik;
    string wzorzec;
    cout << "Pobranie" << endl;
    n = pobranie(tab);
    pokaz(tab, n);

    int nowailosc = flaga_polska(tab, n, granicznik);
    pokaz(tab, n);

    selectionSort(tab, nowailosc, n);
    pokaz(tab, n);
    cout<<"Prosze podac wzorzec"<<endl;
    cin.ignore();
    cout<<"Wzorzec: "<< endl;
    getline(cin, wzorzec);

    algorytmNaiwny(wzorzec, nowailosc, tab);
    pokaz(tab, n);
    return 0;
}