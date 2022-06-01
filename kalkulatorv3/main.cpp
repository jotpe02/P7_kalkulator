//#include <iostream>
//#include "logika.h"
#include "grafika.h"
//#include "parser.h"

using namespace std;

int main()
{
    string opcja;
    wyrazenie* listaWyrazenZPliku = NULL;
    wyrazenie* listaWyrazen = NULL;
    zmienna* listaZmiennych = NULL;

    while (true)
    {
        wyswietlMenu();
        cin >> opcja;

        if(opcja == "1")
        {
            listaWyrazenZPliku = odczytajWyrazeniaZPliku();
            wyczyscKonsole();
        }
        else if(opcja == "2")
        {

            zdefiniujWyrazenie(listaWyrazen);
            wyczyscKonsole();
        }
        else if(opcja == "3")
        {
            edytujWyrazenie(listaWyrazen);
            wyczyscKonsole();
        }
        else if(opcja == "4")
        {
            usunWyrazenie(listaWyrazen);
            wyczyscKonsole();
        }
        else if(opcja == "5")
        {
            zdefiniujZmienna(listaZmiennych);
            wyczyscKonsole();
        }
        else if(opcja == "6")
        {
            edytujZmienna(listaZmiennych);
            wyczyscKonsole();
        }
        else if(opcja == "7")
        {
            usunZmienna(listaZmiennych);
            wyczyscKonsole();
        }
        else if(opcja == "8")
        {
            wyczyscKonsole();
            wyswietlWyrazenia(listaWyrazenZPliku, "Wyrazenia z pliku:");
            wyswietlWyrazenia(listaWyrazen, "Wyrazenia z klawiatury:");
            wyswietlZmienne(listaZmiennych);
        }
        else if(opcja == "9")
        {
            zapiszWyrazeniaDoPliku(listaWyrazen);
        }
        else if(opcja == "10")
        {
            wyczyscKonsole();
            obliczWyrazenia(listaWyrazenZPliku);
            obliczWyrazenia(listaWyrazen);
            wyswietlWyrazenia(listaWyrazenZPliku, "Wyrazenia z pliku: ", true);
            wyswietlWyrazenia(listaWyrazen, "Wyrazenia z klawiatury:", true);
        }
        else if(opcja == "11")
        {
            zamknijProgram();
        }

    }
    return 0;
}



