#include "logika.h"

void dodajElement(wyrazenie*& element, wyrazenie* nowy)
{
    if (element == NULL)
    {
        element = nowy;
        element->next = NULL;
        element->previous = NULL;
    }
    else
    {
        wyrazenie* glowa = element;
        while (element->next)
        {
            element = element->next;
        }
        nowy->previous = element;
        nowy->next = NULL;
        element->next = nowy;
        element = glowa;
    }
}

void dodajElement(zmienna*& element, zmienna* nowy)
{
    if (element == NULL)
    {
        element = nowy;
        element->next = NULL;
        element->previous = NULL;
    }
    else
    {
        zmienna* glowa = element;
        while (element->next)
        {
            element = element->next;
        }
        nowy->previous = element;
        nowy->next = NULL;
        element->next = nowy;
        element = glowa;
    }
}


//template<typename T>
//void dodajElement(T*& element, T* nowy)
//{
//    if (element == NULL)
//    {
//        element = nowy;
//        element->next = NULL;
//        element->previous = NULL;
//    }
//    else
//    {
//        T* glowa = element;
//        while (element->next)
//        {
//            element = element->next;
//        }
//        nowy->previous = element;
//        nowy->next = NULL;
//        element->next = nowy;
//        element = glowa;
//    }
//}

wyrazenie* znajdzWyrazenie(wyrazenie* wyrazenia, long id)
{
    while (wyrazenia && wyrazenia->id != id)
    {
        wyrazenia = wyrazenia->next;
    }

    return wyrazenia;
}

zmienna* znajdzZmienna(zmienna* zmienne, string nazwa)
{
    while (zmienne && zmienne->nazwa != nazwa)
    {
        zmienne = zmienne->next;
    }

    return zmienne;
}

int zamknijProgram()
{
    exit(0);
}

void obliczWyrazenia(wyrazenie* wyrazenia, string info)
{
    Parser* mp = new Parser();
    while (wyrazenia)
    {
        wyrazenia->wynik = mp->Parsuj(wyrazenia->dane);
        wyrazenia = wyrazenia->next;
    }

    delete mp;
}
