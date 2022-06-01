#include "grafika.h"


wyrazenie* odczytajWyrazeniaZPliku()
{
    wyrazenie* glowa = NULL;
    wyrazenie* ogon = NULL;
    ifstream strumien;
    string dane, nazwaPliku;

    wyczyscKonsole();
    cout << "Podaj nazwe pliku wejsciowego: ";
    cin >> nazwaPliku;
    strumien.open(nazwaPliku);

    if (strumien.is_open())
    {
        while (getline(strumien, dane))
        {
            if (glowa == NULL)
            {
                glowa = new wyrazenie();
                glowa->id = ++::id;
                glowa->dane = dane;
                glowa->next = NULL;
                ogon = glowa;
            }
            else
            {
                wyrazenie* nowy = new wyrazenie();
                nowy->id = ++::id;
                nowy->dane = dane;
                ogon->next = nowy;
                ogon = ogon->next;
            }
        }
    }
    return glowa;
    strumien.close();
}

void zdefiniujWyrazenie(wyrazenie*& wyrazenia)
{
    string dane;

    wyczyscKonsole();
    cout << "Wprowadz wyrazenie: ";
    cin >> dane;

    wyrazenie* nowe = new wyrazenie();
    nowe->id = ++::id;
    nowe->dane = dane;

    dodajElement(wyrazenia, nowe);
}

void edytujWyrazenie(wyrazenie*& wyrazenia)
{
    long id;
    string dane, odpowiedz;

    wyczyscKonsole();
    cout << "Podaj identyfikator wyrazenia: ";
    cin >> id;
    cout << "Wprowadz wyrazenie: ";
    cin >> dane;

    wyrazenie* szukane = znajdzWyrazenie(wyrazenia, id);
    if (szukane == NULL)
    {
        cout << "Wyrazenie o podanym identyfikatorze nie istnieje. Czy chcesz je stworzyc? (T/N)";
        cin >> odpowiedz;
        if (odpowiedz == "T" || odpowiedz == "t")
        {
            wyrazenie* nowe = new wyrazenie();
            nowe->id = ++::id;
            nowe->dane = dane;

            dodajElement(wyrazenia, nowe);
        }
        else
        {
            return;
        }
    }
    else
    {
        szukane->dane = dane;
    }
}

void usunWyrazenie(wyrazenie* wyrazenia)
{
    long id;

    wyczyscKonsole();
    cout << "Podaj identyfikator wyrazenia: ";
    cin >> id;

    wyrazenie* szukane = znajdzWyrazenie(wyrazenia, id);
    if (szukane != NULL)
    {
        if (szukane->previous != NULL)
        {
            szukane->previous->next = szukane->next;
        }
        delete szukane;
    }
}

void zdefiniujZmienna(zmienna*& zmienne)
{
    string nazwa, odpowiedz;
    double wartosc;

    wyczyscKonsole();
    cout << "Podaj nazwe zmiennej: ";
    cin >> nazwa;
    cout << "Podaj wartosc zmiennej: ";
    cin >> wartosc;

    zmienna* szukana = znajdzZmienna(zmienne, nazwa);
    if (szukana != NULL)
    {
        cout << "Zmienna o podanej nazwie juz istnieje. Czy chcesz ja nadpisac? (T/N)";
        cin >> odpowiedz;
        if (odpowiedz == "T" || odpowiedz == "t")
        {
            szukana->wartosc = wartosc;
        }
        else
        {
            return;
        }
    }

    zmienna* nowa = new zmienna();
    nowa->nazwa = nazwa;
    nowa->wartosc = wartosc;

    dodajElement(zmienne, nowa);
}

void edytujZmienna(zmienna*& zmienne)
{
    string nazwa, odpowiedz;
    double wartosc;

    wyczyscKonsole();
    cout << "Podaj nazwe zmiennej: ";
    cin >> nazwa;
    cout << "Podaj wartosc zmiennej: ";
    cin >> wartosc;

    zmienna* szukana = znajdzZmienna(zmienne, nazwa);
    if (szukana == NULL)
    {
        cout << "Zmienna o podanej nazwie nie istnieje. Czy chcesz ja stworzyc? (T/N)";
        cin >> odpowiedz;
        if (odpowiedz == "T" || odpowiedz == "t")
        {
            zmienna* nowa = new zmienna();
            nowa->nazwa = nazwa;
            nowa->wartosc = wartosc;

            dodajElement(zmienne, nowa);
        }
        else
        {
            return;
        }
    }
    else
    {
        szukana->wartosc = wartosc;
    }
}

void usunZmienna(zmienna* zmienne)
{
    string nazwa;

    wyczyscKonsole();
    cout << "Podaj nazwe zmiennej: ";
    cin >> nazwa;

    zmienna* szukana = znajdzZmienna(zmienne, nazwa);
    if (szukana != NULL)
    {
        if (szukana->previous != NULL)
        {
            szukana->previous->next = szukana->next;
        }
        delete szukana;
    }
}

void zapiszWyrazeniaDoPliku(wyrazenie* wyrazenia)
{
    string nazwaPliku;
    ofstream strumien;

    wyczyscKonsole();
    cout << "Podaj nazwe pliku wyjsciowego: ";
    cin >> nazwaPliku;
    strumien.open(nazwaPliku);

    if (strumien.is_open())
    {
        while (wyrazenia)
        {
            strumien << wyrazenia->dane << endl;
            wyrazenia = wyrazenia->next;
        }
    }

    strumien.close();
}



void wyswietlWyrazenia(wyrazenie* wyrazenia, string info, bool pokazWynik)
{
    cout << info << endl;

    if (wyrazenia == NULL)
    {
        cout << "Brak wyrazen" << endl << endl;
        return;
    }

    while (wyrazenia)
    {
        cout << "id: " << wyrazenia->id << ", dane: " << wyrazenia->dane;
        if(pokazWynik)
            cout << " = " << wyrazenia->wynik;

        wyrazenia = wyrazenia->next;
        cout << endl;
    }
    cout << endl;
}

void wyswietlZmienne(zmienna* zmienne)
{
    cout << "Zmienne:" << endl;

    if (zmienne == NULL)
    {
        cout << "Brak zmiennych" << endl << endl;
        return;
    }

    while (zmienne)
    {
        cout << "nazwa: " << zmienne->nazwa << ", wartosc: " << zmienne->wartosc << endl;
        zmienne = zmienne->next;
    }
    cout << endl;
}

void wyswietlMenu()
{
    cout << "Co chcesz zrobic? Wybierz odpowiednia opcje." << endl;
    cout << endl;
    cout << "1. Wczytaj wyrazenia z pliku" << endl;
    cout << "2. Zdefiniuj nowe wyrazenie" << endl;
    cout << "3. Edytuj wyrazenie" << endl;
    cout << "4. Usun wyrazenie" << endl;
    cout << "5. Zdefiniuj zmienna" << endl;
    cout << "6. Edytuj zmienna" << endl;
    cout << "7. Usun zmienna" << endl;
    cout << "8. Pokaz wszystkie wyrazenia i zmienne" << endl;
    cout << "9. Zapisz wyrazenia z klawiatury do pliku" << endl;
    cout << "10. Oblicz wyrazenia" << endl;
    cout << "11. Wyjdz z programu" << endl;
    cout << endl;
    cout << "Twoja opcja to: ";
}

void wyczyscKonsole()
{
    system("cls");
}
