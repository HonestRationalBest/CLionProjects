#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};

void sortowanieQuickSort(student* tab, int left, int right, int mode)
{
    int i = left, j = right;

    const student piwot = tab[(left + right) / 2];

    while (i <= j)
    {
        while (mode != 0 ? tab[i].punkty < piwot.punkty : tab[i].punkty > piwot.punkty)
            i++;

        while (mode != 0 ? tab[j].punkty > piwot.punkty : tab[j].punkty < piwot.punkty)
            j--;

        if (i <= j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        sortowanieQuickSort(tab, left, j, mode);
    if (i < right)
        sortowanieQuickSort(tab, i, right, mode);
}

void wyswietlStudentow(student* tab, int n)
{
    for (int i = 0; i < n; i++)
        cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
}

void usunTabliceStudentow(student*& tab)
{
    delete[] tab;
}

void wczytajStudentow(student*& tab, int& n, string path)
{
    string linia;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;

    plik.open(path);
    plik >> liczbaStudentow;

    tab = new student[liczbaStudentow];
    n = liczbaStudentow;

    for (int i = 0; i < 2; i++)
        plik >> sredniki;

    for (int i = 0; i < liczbaStudentow; i++)
    {
        plik >> linia;

        istringstream ss(linia);
        string pomoc;

        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);

        tab[i].punkty = atoi(pomoc.c_str());
    }

    plik.close();
}

int main()
{
    student* tab;
    int size,mode;
    string path = "studenci.csv";

    cout << "Podaj tryb:" << endl;
    cout << "0 -> malejaco" << endl;
    cout << "1 -> rosnaco" << endl;
    cin >> mode;

    wczytajStudentow(tab, size, path);

    cout << "Wszystkie studenci: " << endl;
    wyswietlStudentow(tab, size);
    cout << endl;

    sortowanieQuickSort(tab, 0, size - 1, mode);

    cout << endl << "Wszystkie studenci po wykonaniu sortowania : " << endl;
    wyswietlStudentow(tab, size);

    usunTabliceStudentow(tab);
}
