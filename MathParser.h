#ifndef MATHPARSER_H
#define MATHPARSER_H
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

typedef enum
{
   left,
   right
} direction;


class math_parser
{
   private:
      struct oper
      {
         string name;
         int priority;
         direction dir;
         float (*func)(float, float);
      };

      vector <oper> ops;
      int op_count;
      bool err;

      bool IsOperator(string ch, oper * op);
      vector <string> ConvertToONP(string exp);
   public:
      math_parser();
      ~math_parser();
      bool AddOperator(string name, int priority, direction dir, float (*func)(float, float));
      int Parse(string exp);
};

math_parser::math_parser()
{
   err = false;
   op_count = 0;
}

math_parser::~math_parser()
{
   //
}



bool math_parser::AddOperator(string name, int priority, direction dir, float (*func)(float, float))
{
   oper op;
   op.name = name;
   op.priority = priority;
   op.dir = dir;
   op.func = func;
   ops.push_back(op);
   op_count++;
   return true;
}

bool math_parser::IsOperator(string ch, oper * op)
{
   oper tmp = {"", -1, (direction)-1, 0};
   *op = tmp;
   bool IsOperator = false;
   for(int i = 0; i < op_count; i++)
   {
      if(ops[i].name == ch)
      {
         IsOperator = true;
         *op = ops[i];
         break;
      }
   }
   return IsOperator;
}

vector<string> math_parser::ConvertToONP(string exp)
{
   vector<string> out;
   vector<string> stack;
   int length = exp.size();
   string ch;
   string ch2;
   for(int i = 0; i < length; i++)
   {
      ch = exp[i];
      if(atoi(ch.c_str()) <= 9 && (atoi(ch.c_str()) > 0 || ch == "0"))
      {
         // Symbol jest cyfr�
         ch2 = exp[++i];
         string c = ch;
         while(atoi(ch2.c_str()) <= 9 && (atoi(ch2.c_str()) > 0 || ch2 == "0" || ch2 == "."))
         {
            c += ch2;
            ch2 = exp[++i];
            continue;
         }
         i--;
         out.push_back(c);
      }
      else if(atoi(ch.c_str()) <= 'z' && atoi(ch.c_str()) >= 'a')
      {
         // Symbol jest zmienn�, albo funkcj�
      }
      else if(ch == ",")
      {
         // Symbol jest znakiem oddzielaj�cym argumenty funkcji
         while(stack[stack.size()-1] != "(")
         {
            out.push_back(stack[stack.size()-1]);
            stack.pop_back();
         }
      }
      else if(ch == "(")
      {
          stack.push_back(ch);
      }
      else if(ch == ")")
      {
         while(stack[stack.size()-1] != "(")
         {
            out.push_back(stack[stack.size()-1]);
            stack.pop_back();
         }
         stack.pop_back();
      }
      else
      {
         // Symbol jest operatorem
         oper cur;
         IsOperator(ch, &cur); // Pobranie aktualnego operatora do zmiennej cur

         if(stack.size() <= 0)
         {
            // Nie ma �adnych operator�w na stosie
            stack.push_back(ch);
            continue;
         }

         oper op;
         while(IsOperator(stack[stack.size()-1], &op) == true) // Dop�ki na stosie znajduje si� odpowiedni operator
         {
            if((cur.dir == (direction)0 && cur.priority <= op.priority) || (cur.dir == (direction)1 && cur.priority < op.priority))
            {
               out.push_back(stack[stack.size()-1]);
               stack.pop_back();
            }
            else
               break;
            if(stack.size() <= 0)
            {
               break;
            }
         }
         stack.push_back(ch);
      }
   }
   while(stack.size() > 0)
   {
      // Dodanie wszystkiego do wyj�cia
      out.push_back(stack[stack.size()-1]);
      stack.pop_back();
   }

   return out;
}

int math_parser::Parse(string exp)
{
   vector <string> symbols = ConvertToONP(exp);
   vector <string> stack;

   for(int i = 0; i < (int)symbols.size(); i++)
   {
      string sym = symbols[i];
      oper op;
      if(atoi(sym.c_str()) > 0 || sym == "0")
      {
         stack.push_back(sym);
      }
      else if(IsOperator(sym, &op))
      {
         string a = stack[stack.size()-1];
         stack.pop_back();
         string b = stack[stack.size()-1];
         stack.pop_back();
         float ret = (*op.func)(atof(b.c_str()), atof(a.c_str()));
         char buf[10];
         gcvt(ret, 3,buf);
         stack.push_back(buf);
      }

   }
   string ret = "";
   ret = stack[0];
   return atoi(ret.c_str());
}


#endif // MATHPARSER_H
