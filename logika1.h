#ifndef LOGIKA1_H
#define LOGIKA1_H
#include <string>

using namespace std;

struct stale
{
    string nazwa;
    double wartosc;
    stale* next;
};
struct wyrazenie
{
    int id;
    string dane;
    stale* stale_lista;
    wyrazenie* next;
};

void zapiszWyrazenieDo(string nazwaPliku, wyrazenie* w); // x

wyrazenie* odczytajWyrazenieZ(string nazwaPliku); // x

void definiujZmienne(double x, string a, stale*& lista); // x

void usunZmienna(string nazwa_stalej); // x

stale* znajdzStala(int id, string stala); // tego nie umiem

void wstawNaKoncu(wyrazenie*& glowa, string x); // x

void usunWybraneWyrazenie(wyrazenie*& glowa, wyrazenie* e); //x

wyrazenie* znajdzWyrazenie(int id); // x

int nadajID(wyrazenie* w); // x

#endif // LOGIKA1_H
