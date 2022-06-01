#include "parser.h"


Parser::Parser()
{
    liczba_operatorow = 0;
    DodajOperator("+", 1, dodawanie);
    DodajOperator("-", 1, odejmowanie);
    DodajOperator("*", 2, mnozenie);
    DodajOperator("/", 2, dzielenie);
}

void Parser::DodajOperator(std::string nazwa, int priorytet, double (*funkcja)(double, double))
{
    oper op;
    op.nazwa = nazwa;
    op.priorytet = priorytet;
    op.funkcja = funkcja;
    operatory.push_back(op);
    liczba_operatorow++;
}

bool Parser::IsOperator(std::string znak, oper* op)
{
    oper tmp = { "", -1, 0 };
    *op = tmp;
    bool IsOperator = false;
    for (int i = 0; i < liczba_operatorow; i++)
    {
        if (operatory[i].nazwa == znak)
        {
            IsOperator = true;
            *op = operatory[i];
            break;
        }
    }
    return IsOperator;
}

std::vector<std::string> Parser::KonwertujDoONP(std::string wyrazenie)
{
    std::vector<std::string> wyjscie;
    std::vector<std::string> stos;
    std::string znak;
    std::string znak2;
    for (int i = 0; i < wyrazenie.size(); i++)
    {
        znak = wyrazenie[i];
        if (atoi(znak.c_str()) <= 9 && (atoi(znak.c_str()) > 0 || znak == "0"))
        {
            // Symbol jest cyfr�
            znak2 = wyrazenie[++i];
            std::string c = znak;
            while (atoi(znak2.c_str()) <= 9 && (atoi(znak2.c_str()) > 0 || znak2 == "0" || znak2 == "."))
            {
                c += znak2;
                znak2 = wyrazenie[++i];
                continue;
            }
            i--;
            wyjscie.push_back(c);
        }
        else if (atoi(znak.c_str()) <= 'z' && atoi(znak.c_str()) >= 'a')
        {
            // Symbol jest zmienn�, albo funkcj�
        }
        else if (znak == ",")
        {
            // Symbol jest znakiem oddzielaj�cym argumenty funkcji
            while (stos[stos.size() - 1] != "(")
            {
                wyjscie.push_back(stos[stos.size() - 1]);
                stos.pop_back();
            }
        }
        else if (znak == "(")
        {
            stos.push_back(znak);
        }
        else if (znak == ")")
        {
            while (stos[stos.size() - 1] != "(")
            {
                wyjscie.push_back(stos[stos.size() - 1]);
                stos.pop_back();
            }
            stos.pop_back();
        }
        else
        {
            // Symbol jest operatorem
            oper cur;
            IsOperator(znak, &cur); // Pobranie aktualnego operatora do zmiennej cur

            if (stos.size() <= 0)
            {
                // Nie ma �adnych operator�w na stosie
                stos.push_back(znak);
                continue;
            }

            oper op;
            while (IsOperator(stos[stos.size() - 1], &op) == true) // Dop�ki na stosie znajduje si� odpowiedni operator
            {
                if (cur.priorytet <= op.priorytet)
                {
                    wyjscie.push_back(stos[stos.size() - 1]);
                    stos.pop_back();
                }
                else
                    break;
                if (stos.size() <= 0)
                {
                    break;
                }
            }
            stos.push_back(znak);
        }
    }
    while (stos.size() > 0)
    {
        // Dodanie wszystkiego do wyj�cia
        wyjscie.push_back(stos[stos.size() - 1]);
        stos.pop_back();
    }

    return wyjscie;
}

double Parser::Parsuj(std::string exp)
{
    std::vector <std::string> symbole = KonwertujDoONP(exp);
    std::vector <std::string> stos;

    for (int i = 0; i < (int)symbole.size(); i++)
    {
        std::string sym = symbole[i];
        oper op;
        if (atof(sym.c_str()) > 0 || sym == "0")
        {
            stos.push_back(sym);
        }
        else if (IsOperator(sym, &op))
        {
            std::string a = stos[stos.size() - 1];
            stos.pop_back();
            std::string b = stos[stos.size() - 1];
            stos.pop_back();
            double ret = (*op.funkcja)(atof(b.c_str()), atof(a.c_str()));
            char buf[10];
            snprintf(buf, sizeof(buf), "%g", ret);
            //gcvt(ret, 3, buf);
            stos.push_back(buf);
        }

    }
    std::string ret = "";
    ret = stos[0];
    return atof(ret.c_str());
}
