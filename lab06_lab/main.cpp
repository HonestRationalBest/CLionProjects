#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

int make_hash(int hash, char s, int off, int p, int exp)
{
    return hash + (int(s) - off) * pow(p, exp);
}
int update_hash(int hash, char s_preview, char s_next, int off, int p, int exp)
{
    int u_hash = hash - (int(s_preview) - off) * pow(p, exp);
    u_hash *= p;
    u_hash += int(s_next) - off;

    return u_hash;
}
void kr(string text, string pattern, int p, int off)
{
    int hashP = 0, hashT = 0;

    for (int i = 0; i < pattern.size(); i++)
    {
        hashP = make_hash(hashP, pattern[i], off, p, pattern.size() - i - 1);
        hashT = make_hash(hashT, text[i], off, p, pattern.size() - i - 1);
    }

    for (int i = pattern.size(), j = 0; i <= text.size(); i++, j++)
    {
        if (hashP == hashT)
        {
            int index = 0;
            while (index < pattern.size() && pattern[index] == text[j + index])
                index++;

            if (index == pattern.size())
                cout << j << " ";
        }

        if (i < text.size())
            hashT = update_hash(hashT, text[j], text[i], off, p, pattern.size() - 1);
    }
}

int main()
{
    string wzorzec;
    string tekst;

    fstream plik("tekst1.txt");
    getline(plik, wzorzec);

    for (int i = 2; !plik.eof(); i++)
    {
        getline(plik, tekst);
        cout << "Linijka " << i << ": ";
        kr(tekst, wzorzec, 3, 65);
        cout << endl;
    }


    return 0;
}
