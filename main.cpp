#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include "MathParser.hpp" // Zawiera definicj� klasy i jej metod

using namespace std;

float _dodawanie(float arg1, float arg2)
{
   return arg1 + arg2;
}

float _odejmowanie(float arg1, float arg2)
{
   return arg1 - arg2;
}

float _mnozenie(float arg1, float arg2)
{
   return arg1 * arg2;
}

float _dzielenie(float arg1, float arg2)
{
   return arg1 / arg2;
}

int main(int argc, char *argv[])
{
   string exp = "2.5*2";
   math_parser mp;
   mp.AddOperator("+", 1, (direction)0, _dodawanie);
   mp.AddOperator("-", 1, (direction)0, _odejmowanie);
   mp.AddOperator("*", 2, (direction)0, _mnozenie);
   mp.AddOperator("/", 2, (direction)0, _dzielenie);
   float ret = mp.Parse(exp);
   cout << ret << endl;
   cout <<"Aby kontynuowa" << (char)134 << ", naci" << (char)152 << "nij dowolny klawisz . . .";
   getch();
   return EXIT_SUCCESS;
}

