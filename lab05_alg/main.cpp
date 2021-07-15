#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


void wczytanieDanych(string & text, string & wzorzec);
void algorytmNaiwny(string text, string wzorzec);
void KMP( string wzorzec, string text);
void computeLPSArray(string wzorzec, int M, int* lps);
void BM( string txt, string pat);

int main()
{
    string text;
    string wzorzec;
    int n = 0;

    while (true)
    {



        cout << "1. Wczytanie danych" << endl;
        cout << "2. Algorytm niwny" << endl;
        cout << "3. Algorytm Knutha-Morrisa-Pratta" << endl;
        cout << "4. Algorytm Boyer’a-Moore’a" << endl;
        cout << "5. Wyjscie" << endl;
        cout << "Wprowadz numer: ";
        cin >> n;
        cout << endl;

        switch (n)
        {
            case 1:
                wczytanieDanych(text,wzorzec);
                break;
            case 2:
                algorytmNaiwny(text, wzorzec);
                break;
            case 3:
                KMP(text, wzorzec);
                break;
            case 4:
                BM(text, wzorzec);
                break;
            case 5:
                return 0;
            default:
                cout << "Niepoprawna wartosc" << endl;
                break;
        }
    }
}

void wczytanieDanych(string & text, string & wzorzec)
{
    cin.ignore();
    cout<<"Tekst: "<< endl;
    getline(cin, text);
    cout<<"Wzorzec: "<< endl;
    getline(cin, wzorzec);
    cout << text << endl << wzorzec << endl;
}

    void algorytmNaiwny(string text, string wzorzec){


        int M= wzorzec.length();
        int N= text.length();
        int ok=0;
        for (int i = 0; i <= N - M; i++) {
            int j;

            for (j = 0; j < M; j++)
                if (text[i + j] != wzorzec[j])
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

void KMP(string text, string wzorzec)
{
    int M= wzorzec.length();
    int N= text.length();

    int lps[M];

    computeLPSArray(wzorzec, M, lps);

    int i = 0;
    int j = 0;
    int ok=0;
    while (i < N) {
        if (wzorzec[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            ok++;
            cout << "Wzorzec jest od pozycji: " <<  i - j << endl;
            j = lps[j - 1];
        }

        else if (i < N && wzorzec[j] != text[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    if(ok == 0){
        cout << "Brak wyników "<< endl;
    }
}


void computeLPSArray(string wzorzec, int M, int* lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (wzorzec[i] == wzorzec[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];

            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void badCharHeuristic( string str, int size,int badchar[256])
{
    int i;

    for (i = 0; i < 256; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}


void BM( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int ok=0;
    int badchar[256];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;
        while(j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            ok++;
            cout << "Wzorzec jest od pozycji: " <<  s << endl;
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
        }
        else
            s += max(1, j - badchar[txt[s + j]]);
    }
    if(ok == 0){
        cout << "Brak wyników "<< endl;
    }
}