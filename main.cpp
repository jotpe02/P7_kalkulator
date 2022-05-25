#include <iostream>
#include "logika1.h"
#include "grafika1.h"
#include "MathParser.h"

using namespace std;

float _dodawanie(float arg1, float arg2)
{
   return arg1 + arg2;
}

float _odejmowanie(float arg1, float arg2)
{
   return arg1 - arg2;
}

float _mnozenie(float arg1, float arg2)
{
   return arg1 * arg2;
}

float _dzielenie(float arg1, float arg2)
{
   return arg1 / arg2;
}

int main()
{
    wyswietlMenu();
    stale *glowa1;
    wyrazenie *glowa2;

    string wejscie;
    int opcja;
    cin >> opcja;

    if(opcja == 1)
    {
        cout << "Podaj nazwe pliku wejsciowego " << endl;
        cin >> wejscie;
        odczytajWyrazenieZ(wejscie);
     }
    if(opcja == 2 )
    {
        wczytajWyrazenie();
    }
    if(opcja == 3 )
    {
        double wartoscZmiennej;
        cout << "Podaj wartosc zmiennej " << endl;
        cin >> wartoscZmiennej;
        cout << "Podaj nazwe zmiennej " << endl;
        string nazwaZmiennej;
        cin >> nazwaZmiennej;
        definiujZmienne(wartoscZmiennej,nazwaZmiennej,glowa1);
    }
    if(opcja == 4 )
    {
        string nazwaZmiennejDoUsuniecia;
        cout << "Podaj nazwe zmiennej do usuniecia " << endl;
        cin >> nazwaZmiennejDoUsuniecia;
        usunZmienna(nazwaZmiennejDoUsuniecia);
    }
    if(opcja == 5 )
    {
        cout << "Podaj wyrazenie ktore ma byc wstawione na koniec " << endl;
        string wyrazenieNaKoniec;
        cin >> wyrazenieNaKoniec;
        wstawNaKoncu(glowa2, wyrazenieNaKoniec);
    }
    if(opcja == 6 )
    {
        wyrazenie *e;
        int IDDoUsuniecia;
        cout << "Podaj wyrazenie ktore ma byc usuniete " << endl;
        cin >> IDDoUsuniecia;
        e->id = IDDoUsuniecia;
        usunWybraneWyrazenie(glowa2, e);
    }
    if(opcja == 7)
    {
        int ID;
        cout << "Podaj ID wyrazenia ktore chcesz znalezc " << endl;
        cin >> ID;
        wyrazenie *rozwiazanie;
        rozwiazanie = znajdzWyrazenie(ID);
    }
    if(opcja == 8)
    {
        nadajID(glowa2);
    }

/*
    string x;
    cin >> x;
    math_parser mp;
    mp.AddOperator("+", 1, (direction)0, _dodawanie);
    mp.AddOperator("-", 1, (direction)0, _odejmowanie);
    mp.AddOperator("*", 2, (direction)0, _mnozenie);
    mp.AddOperator("/", 2, (direction)0, _dzielenie);
    int nazwa = mp.Parse(x);
    cout << nazwa << endl;
*/


    return 0;
}
