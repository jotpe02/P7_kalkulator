#include "grafika1.h"
#include <iostream>
#include <string>

using namespace std;

wyrazenie* wczytajWyrazenie()
{
    wyrazenie* glowa = NULL;
    wyrazenie* ogon = NULL;
    string x;
    cin >>x;
    while(x.size() !=0)
    {
        wyrazenie *nowy = new wyrazenie;
        nowy->dane = x;
        nowy->next = NULL;
        if(glowa == NULL)
            glowa = nowy;
        else
        {
            ogon->next = nowy;
        }
        ogon = nowy;
        cin >> x;
    }
    return glowa;
}

void wyswietlMenu()
{
    cout << "Co chcesz zrobic? " << endl;
    cout << endl;
    cout << "1. Wczytaj wyrazenia z pliku " << endl;
    cout << "2. Wczytaj wyrazenia z klawiatury " << endl;
    cout << "3. Definiuj zmienne " << endl;
    cout << "4. Usun zmienne " << endl;
    cout << "5. Dodaj wyrazenie na koniec listy " << endl;
    cout << "6. Usun wybrane wyrazenie " << endl;
    cout << "7. Znajdz wybrane wyrazenie " << endl;
    cout << "8. Nadaj ID " << endl;
    cout << "9. Wyjdz z programu " << endl;
}
