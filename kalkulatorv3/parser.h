#ifndef PARSER_H
#define PARSER_H

#include<string>
#include<vector>

#include "funkcje.h"

struct oper
{
    std::string nazwa;
    int priorytet;
    double (*funkcja)(double, double);
};


class Parser
{
private:
    std::vector <oper> operatory;
    int liczba_operatorow;

    bool IsOperator(std::string znak, oper* op);
    void DodajOperator(std::string nazwa, int priorytet, double (*funkcja)(double, double));
    std::vector <std::string> KonwertujDoONP(std::string exp);

public:
    Parser();
    double Parsuj(std::string wyrazenie);
};

#endif // PARSER_H
