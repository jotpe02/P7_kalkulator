#include "logika1.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void zapiszWyrazenieDo(string nazwaPliku, wyrazenie* glowa)
{
    ofstream wyjscie;
    wyjscie.open(nazwaPliku);
    if(wyjscie.is_open())
    {
        while(glowa != NULL)
        {
            wyjscie << glowa->dane << '\t';
            glowa = glowa->next;
        }
        wyjscie << endl;
    }
    wyjscie.close();
    /*void wydrukuj(Liczby* w)
{
    while(w != NULL)
    {
        cout << w->wartosc << '\t';
        w = w->nasst;
    }
    cout << endl;
} */
}

wyrazenie* odczytajWyrazenieZ(string nazwaPliku)
{
    wyrazenie* glowa = NULL;
    wyrazenie* ogon = NULL;
    ifstream wejscie;
    string x;
    wejscie.open(nazwaPliku);
    if(wejscie.is_open())
    {
        do
        {
            getline(wejscie, glowa->dane );
        }
        while(!wejscie.eof());
        {
            wyrazenie* nowy = new wyrazenie;
            nowy->dane = x;
            nowy->next = NULL;
            if(glowa == NULL)
                glowa = nowy;
            else
            {
                ogon->next = nowy;
            }
            ogon = nowy;
        }
        getline(wejscie,glowa->dane);
    }
    return glowa;
    wejscie.close();
}

void definiujZmienne(double x, string a, stale*& lista)
{
    if(lista == NULL)
        return;
    stale* nowy = new stale;
    nowy->wartosc = x;
    nowy->nazwa = a;
    nowy->next = lista->next;
    lista->next = nowy;
}

void usunZPrzoduStala(stale*& glowa)
{
    stale* p;
    p = glowa;
    if(p)
    {
        glowa = p->next;
        delete p;
    }
}

void usunZmienna(string nazwa_stalej, stale*& glowa)
{
    stale* p;
    stale* e;
    if(glowa->nazwa == nazwa_stalej)
        usunZPrzoduStala(glowa);
    else
    {
        p = glowa;
        while(p->next->nazwa != nazwa_stalej ) p = p->next;
        e = p->next;
        p->next = e->next;
        delete e;
    }
}

stale* znajdzStala(int id, string stala)
{

}

void wstawNaKoncu(wyrazenie*& ogon, string x)
{
    if(ogon == NULL)
        return;
    wyrazenie* nowy = new wyrazenie;
    nowy->dane = x;
    nowy->next = ogon->next;
    ogon->next = nowy;
}

wyrazenie* znajdzOgon(wyrazenie* glowa)
{
    if(glowa == NULL)
        return 0;
    wyrazenie* ogon = NULL;
    while(glowa->next != NULL)
    {
        glowa = glowa->next;
        ogon = glowa;
    }
    return ogon;
}

int nadajID(wyrazenie* w)
{
    int c = 0;
    while(w)
    {
        c++;
        w = w->next;
        c = w->id;
    }
    /* unsigned l_size ( slistEl * p )
    {
      unsigned c = 0; // zerujemy licznik

      while( p )
      {
        c++;     // zwiększamy licznik o 1
        p = p->next;
      }

      return c;
    } */
    return c;
}

wyrazenie* znajdzWyrazenie(int id, wyrazenie* glowa)
{
    wyrazenie* p = glowa;
    while(p && p->id != id)
        p = p->next;
    return p;
}

void usunZPrzoduWyrazenie(wyrazenie*& glowa)
{
    wyrazenie* p;
    p = glowa;
    if(p)
    {
        glowa = p->next;
        delete p;
    }
}

void usunWybraneWyrazenie(wyrazenie*& glowa, wyrazenie* e)
{
    wyrazenie* p;
    if(e == glowa)
        usunZPrzoduWyrazenie(glowa);
    else
    {
        p = glowa;
        while(e != glowa)
        {
            p = p->next;
        }
        e = p->next;
        p->next = e->next;
        delete e;
    }
}
