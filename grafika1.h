#ifndef GRAFIKA1_H
#define GRAFIKA1_H
#include <string>
#include "logika1.h"

using namespace std;

/*
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
*/
bool czyEdytuj(wyrazenie *& x);

wyrazenie* wczytajWyrazenie();

void wyswietlMenu();

#endif // GRAFIKA1_H
