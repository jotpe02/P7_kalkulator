#ifndef GRAFIKA_H
#define GRAFIKA_H
#include "logika.h"
//#include <iostream>
//#include <fstream>
//#include <string>

//using namespace std;

wyrazenie* odczytajWyrazeniaZPliku();
void zdefiniujWyrazenie(wyrazenie*& wyrazenia);
void edytujWyrazenie(wyrazenie*& wyrazenia);
void usunWyrazenie(wyrazenie* wyrazenia);
void zdefiniujZmienna(zmienna*& zmienne);
void edytujZmienna(zmienna*& zmienne);
void usunZmienna(zmienna* zmienne);
void zapiszWyrazeniaDoPliku(wyrazenie* wyrazenia);
void wyswietlWyrazenia(wyrazenie* wyrazenia, string info = "Wyrazenia:", bool pokazWynik=false);
void wyswietlZmienne(zmienna* zmienne);
void wyswietlMenu();
void wyczyscKonsole();

#endif // GRAFIKA_H
