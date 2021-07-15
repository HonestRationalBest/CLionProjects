#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};

struct tablica_studentow
{
    student* sts;
    int count;

    tablica_studentow(student* sts, const int count)
    {
        this->count = count;
        this->sts = sts;
    }
};

tablica_studentow wczytacStudentow(string sciezka)
{
    string linia;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    sciezka="studenci.csv";
    plik.open(sciezka);
    plik >> liczbaStudentow;

    auto students = new student[liczbaStudentow];


    for (int i = 0; i < 2; i++)
        plik >> sredniki;

    for (int i = 0; i < liczbaStudentow; i++)
    {
        plik >> linia;

        istringstream ss(linia);
        string pomoc;

        getline(ss, students[i].imie, ';');
        getline(ss, students[i].nazwisko, ';');
        getline(ss, pomoc);

        students[i].punkty = atoi(pomoc.c_str());
    }

    plik.close();

    return tablica_studentow(students, liczbaStudentow);
}

void QS(student* tab, int left, int right, int tryb)
{
    int i = left, j = right;

    const student piwot = tab[(left + right) / 2];

    while (i <= j)
    {
        while (tryb != 0 ? tab[i].punkty < piwot.punkty : tab[i].punkty > piwot.punkty)
            i++;

        while (tryb != 0 ? tab[j].punkty > piwot.punkty : tab[j].punkty < piwot.punkty)
            j--;

        if (i <= j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        QS(tab, left, j, tryb);
    if (i < right)
        QS(tab, i, right, tryb);
}
void wyswetlStudentow(student* students, int count)
{
    for (int i = 0; i < count; i++)
        cout << students[i].imie << " " << students[i].nazwisko << " " << students[i].punkty << endl;
}

int flagaPolska(student* students, int n, int limit)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        while (students[i].punkty <= limit && i < j)
            i++;
        while (students[j].punkty > limit && i < j)
            j--;
        if (i < j)
        {
            swap(students[i], students[j]);
            i++;
            j--;
        }
    }
    if (students[i].punkty <= limit)
        return i + 1;

    return i;
}
pair<int ,int> flagaFrancuzka(student* students, int n, int limit1, int limit2)
{
    int i = -1, j = 0, k = n;

    while(j < k)
    {
        if(students[j].punkty % 3 <= limit1)
        {
            i++;
            swap(students[i], students[j]);
            j++;
        }
        else
        {
            if (students[j].punkty % 3 > limit2)
            {
                k--;
                swap(students[k], students[j]);
            }
            else
            {
                j++;
            }
        }
    }

    return { i, k };
}

void zadanie41()
{
    auto students = wczytacStudentow("studenci.csv");

    wyswetlStudentow(students.sts, students.count);
}
void zadanie42()
{
    tablica_studentow students = wczytacStudentow("studenci.csv");

    cout << "Przed podzialem: " << endl;
    wyswetlStudentow(students.sts, students.count);
    cout << endl;

    const int first_greater_then_10_index = flagaPolska(students.sts, students.count, 10);

    cout << "Studenci, ktorzy otrzymali <=10 punktow:" << endl;
    wyswetlStudentow(students.sts, first_greater_then_10_index);
    cout << endl;

    cout << endl << "Studenci, ktorzy otrzymali >10 punktow: " << endl;
    wyswetlStudentow(students.sts + first_greater_then_10_index, students.count - first_greater_then_10_index);
    cout << endl;
}
void zadanie43()
{
    tablica_studentow students = wczytacStudentow("studenci.csv");

    cout << "Przed podzialem: " << endl;
    wyswetlStudentow(students.sts, students.count);
    cout << endl;

    auto [i1, i2] = flagaFrancuzka(students.sts, students.count, 0, 1);

    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3: " << endl;
    wyswetlStudentow(students.sts, i1 + 1);

    cout << endl << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 1: " << endl;
    wyswetlStudentow(students.sts + i1 + 1, i2 - i1 - 1);

    cout << endl << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 2: " << endl;
    wyswetlStudentow(students.sts + i2, students.count - i2);
}

int main()
{
    while (true)
    {
        int n = 0;
        cout << "Zad 4.1 " << endl;
        cout << "Zad 4.2 " << endl;
        cout << "Zad 4.3 " << endl;
        cout << "Wyjscie " << endl;
        cout << "Wprowadz numer: ";
        cin >> n;
        cout << endl;

        switch (n)
        {
            case 1:
                zadanie41();
                break;
            case 2:
                zadanie42();
                break;
            case 3:
                zadanie43();
                break;
            case 4:
                return 0;
            default:
                cout << "Niepoprawna wartosc" << endl;
                break;
        }
    }
}
