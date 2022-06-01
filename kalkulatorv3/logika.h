#ifndef LOGIKA_H
#define LOGIKA_H

#include <iostream>
#include <fstream>
#include <string>

#include "parser.h"

using namespace std;

static long id;

struct zmienna
{
    string nazwa;
    double wartosc;
    zmienna* next;
    zmienna* previous;
};

struct wyrazenie
{
    long id;
    string dane;
    wyrazenie* next;
    wyrazenie* previous;
    double wynik;
};

//template<typename T>
//void dodajElement(T*& element, T* nowy);
void dodajElement(wyrazenie*& element, wyrazenie* nowy);
void dodajElement(zmienna*& element, zmienna* nowy);
wyrazenie* znajdzWyrazenie(wyrazenie* wyrazenia, long id);
zmienna* znajdzZmienna(zmienna* zmienne, string nazwa);
int zamknijProgram();
void obliczWyrazenia(wyrazenie* wyrazenia, string info="Wyrażenia");


#endif // LOGIKA_H
