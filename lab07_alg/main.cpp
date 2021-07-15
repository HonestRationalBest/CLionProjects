#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct student
{
    string name;
    string surname;
    int punkts = 0;

};

void sortowanieQuickSort(student* tab, int left, int right, int tryb)
{
    int i = left, j = right;

    const student piwot = tab[(left + right) / 2];

    while (i <= j)
    {
        while (tryb != 0 ? tab[i].punkts < piwot.punkts : tab[i].punkts > piwot.punkts)
            i++;

        while (tryb != 0 ? tab[j].punkts > piwot.punkts : tab[j].punkts < piwot.punkts)
            j--;

        if (i <= j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        sortowanieQuickSort(tab, left, j, tryb);
    if (i < right)
        sortowanieQuickSort(tab, i, right, tryb);
}
void readStudentsFromFile(student*& tab, int& n, string path)
{
    string linia;
    int students_count;
    ifstream plik;
    char srednik;

    plik.open(path);
    plik >> students_count;

    tab = new student[students_count];
    n = students_count;

    for (int i = 0; i < 2; i++)
        plik >> srednik;

    for (int i = 0; i < students_count; i++)
    {
        plik >> linia;

        istringstream ss(linia);
        string punkts;

        getline(ss, tab[i].name, ';');
        getline(ss, tab[i].surname, ';');
        getline(ss, punkts);

        tab[i].punkts = atoi(punkts.c_str());
    }

    plik.close();
}
void printStudents(student* tab, int n)
{
    for (int i = 0; i < n; i++)
        cout << tab[i].name << " " << tab[i].surname << " " << tab[i].punkts << endl;
}
void deleteAllStudents(student*& tab)
{
    delete[] tab;
    tab = nullptr;
}

bool linearSearch(student* x, int n, int liczba_punktow)
{
    int i = 0;
    bool flag = false;

    while (i < n)
    {
        if (x[i].punkts == liczba_punktow)
        {
            flag = true;
            cout << x[i].name << " " << x[i].surname << endl;
        }

        i = i + 1;
    }

    return flag;
}
bool binarySearch(student* x, int n, int liczba_punktow)
{
    int lewy = 0;
    int prawy = n - 1;
    bool flag = false;

    ofstream fout("wyniki.csv");

    while (lewy <= prawy)
    {
        int srodek = (int)(lewy + prawy) / 2;

        if (x[srodek].punkts == liczba_punktow)
        {
            int szukane_punkty = x[srodek].punkts;

            int index_from;

            if (x[0].punkts == szukane_punkty)
            {
                index_from = 0;
            }
            else
            {
                int i = srodek;
                for (; i > 0; i--)
                {
                    if (x[i].punkts != szukane_punkty)
                    {
                        break;
                    }
                }
                index_from = i + 1;
            }

            for (int i = index_from; i < n; i++)
            {
                if (x[i].punkts == szukane_punkty)
                {
                    cout << x[i].name << ";" << x[i].surname << ";" << x[i].punkts << endl;
                    fout << x[i].name << ";" << x[i].surname << ";" << x[i].punkts << endl;
                }
                else
                {
                    break;
                }
            }

            flag = true;
            break;
        }
        else
        {
            if (liczba_punktow < x[srodek].punkts)
            {
                prawy = srodek - 1;
            }
            else
            {
                lewy = srodek + 1;
            }
        }
    }

    fout.close();

    return flag;
}

void zadanie1(student*& students, int& n)
{
    if (students != nullptr)
    {
        deleteAllStudents(students);
    }

    readStudentsFromFile(students, n, "studenci.csv");

    printStudents(students, n);
}
void zadanie2(student*& students, int& n)
{
    int liczba_punktow = 0;
    cout << "Wprowadz liczbe punktow: "; cin >> liczba_punktow;

    if (linearSearch(students, n, liczba_punktow) == false)
    {
        cout << "Nie ma studentow z taka liczba punktow" << endl;
    }
}
void zadanie3(student*& students, int& n)
{
    int liczba_punktow = 0;
    cout << "Wprowadz liczbe punktow: "; cin >> liczba_punktow;

    sortowanieQuickSort(students, 0, n - 1, true);
    cout << "---------------SORTED---------------" << endl;
    printStudents(students, n);
    cout << "------------------------------------" << endl;

    if (binarySearch(students, n, liczba_punktow) == false)
    {
        cout << "Nie ma studentow z taka liczba punktow" << endl;
    }
}

int main()
{
    student* students = nullptr;
    int n = 0;

    while (true)
    {
        cout << "ZADANIE 1 - 1" << endl;
        cout << "ZADANIE 2 - 2" << endl;
        cout << "ZADANIE 3 - 3" << endl;
        cout << "Wprowadz numer: ";

        int wyb = 0;
        cin >> wyb;

        switch (wyb)
        {
            case 1:
                zadanie1(students, n);
                break;
            case 2:
                if (students == nullptr) zadanie1(students, n);
                zadanie2(students, n);
                break;
            case 3:
                if (students == nullptr) zadanie1(students, n);
                zadanie3(students, n);
                break;
            default:
                cout << "Niepoprawny numer" << endl;
                break;
        }
        cout << "------------------------------------" << endl;

    }

    return 0;
}
