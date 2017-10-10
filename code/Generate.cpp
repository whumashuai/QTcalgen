#include"stdafx.h"
#include"Generate.h"
#include"FractionCalculate.h"
#include"memory.h"
#include"Calculate.h"
#include<iostream>
#include<windows.h>
using namespace std;

int temp = 0;
deque<string> C_expression;
deque<string> C_result;

Generate::Generate()
{

}

void Generate::del()
{
    space.clear(); //Initialization
    line.clear();
}

void Generate::Generateoperators()//Generate the operation symbol
{
    int num = rand() % 4 + 1;
    Fraction fc;
    switch (num)
    {
    case 1:   //Addition
        fc.deno = 1;
        fc.numer = 0;
        fc.symbol = '+';
        space.push_back(fc);
        line.push_back(fc);
        break;
    case 2: //Subtraction
        fc.deno = 1;
        fc.numer = 0;
        fc.symbol = '-';
        space.push_back(fc);
        line.push_back(fc);
        break;
    case 3: //Multiplication
        fc.deno = 1;
        fc.numer = 0;
        fc.symbol = '*';
        space.push_back(fc);
        line.push_back(fc);
        break;
    case 4: //Division
        fc.deno = 1;
        fc.numer = 0;
        fc.symbol = '/';
        space.push_back(fc);
        line.push_back(fc);
        break;
    default:
        break;
    }
}

void Generate::GenerateFraction()//Generate Fraction
{
    Fraction a;
    FractionCalculate fc;
    a.numer = rand() % 10 + 1;
    a.deno = rand() % 10 + 1;
    while (a.numer >= a.deno) //To ensure that numerator are less than denominator
    {
        a.numer = rand() % 10 + 1;
        a.deno = rand() % 10 + 1;
    }
    a.symbol = '|'; //"/" means division,"|" means fraction
    a = fc.Fractionsim(a);
    space.push_back(a);
    line.push_back(a);
}

void Generate::Generateinteger() //Generate the integer
{
    int a = (rand() % 10) + 1;
    Fraction fc;
    fc.numer = a;
    fc.deno = 1;
    fc.symbol = '|';
    space.push_back(fc);
    line.push_back(fc);
}

void Generate::random() //Automatically generate integers and fractions
{
    int t = rand() % 2;
    if (t == 0)
    {
        GenerateFraction();
    }
    else
    {
        Generateinteger();
    }
}

void Generate::GenerateExpression(int n)
{
    for (int i = 1;i <= n;i++)
    {
        Sleep(1000);
        srand((unsigned)time(0));
        int operatorsnum = rand() % 8 + 3;//Generate the number of operands
        int bracketsid = rand() % 2;
        int bracketnum = 0; //The pair of brackets
        if (bracketsid == 0)//Generate left bracks
        {
            Fraction fc;
            fc.deno = 1;
            fc.numer = 0;
            fc.symbol = '(';
            space.push_back(fc);
            line.push_back(fc);
            bracketnum++;
        }

        random();

        for (int j = 0;j < operatorsnum;j++)
        {
            Generateoperators();

            bracketsid = rand() % 2;
            if (bracketsid == 0 && j<operatorsnum - 1)
            {
                Fraction fc;
                fc.deno = 1;
                fc.numer = 0;
                fc.symbol = '(';
                space.push_back(fc);
                line.push_back(fc);
                bracketnum++;
                random();
            }
            else
            {
                random();
                if (bracketnum > 0 && bracketsid == 1)
                {
                    Fraction fc;
                    fc.deno = 1;
                    fc.numer = 0;
                    fc.symbol = ')';
                    space.push_back(fc);
                    line.push_back(fc);
                    bracketnum--;
                }
            }
        }
        while (bracketnum > 0)
        {
            Fraction fc;
            fc.deno = 1;
            fc.numer = 0;
            fc.symbol = ')';
            space.push_back(fc);
            line.push_back(fc);
            bracketnum--;
        }
        Answer();
        if (temp == 1)
        {
            i = i - 1;
            temp = 0;
        }
    }
}

string Generate::IntToString(int n)//int converted to string
{
    stringstream newstr;
    newstr << n;
    return newstr.str();
}

string Generate::charToString(char n)//char converted to string
{
    stringstream newstr;
    newstr << n;
    return newstr.str();
}

void Generate::Answer()
{
    string n;
    string re;
    string exp;

    Fraction ans;
    Calculate cal;
    ans = cal.calculateExpression(space);
    if (ans.numer < 0 || ans.deno <= 0 || ans.numer > 100 || ans.deno > 100)//Control the final result is not negative, the numerator and denominator of the score are less than 100
    {
        temp = 1;
    }
    else
    {
        while (!line.empty())
        {
            Fraction fcc = line.front();
            if (fcc.symbol == '(' || fcc.symbol == ')')
            {
                exp = exp + charToString(fcc.symbol);
            }
            else if (fcc.symbol == '+' || fcc.symbol == '-')
            {
                exp = exp + charToString(fcc.symbol);
            }
            else if (fcc.symbol == '*')
            {
                const char* c_s = "×";
                string tmp(c_s);
                exp = exp + tmp;
            }
            else if (fcc.symbol == '/')
            {
                const char* c_s = "÷";
                string tmp(c_s);
                exp = exp + tmp;
            }
            else
            {
                if (fcc.symbol == '|')
                {
                    if (fcc.deno == 1)
                    {
                        exp = exp + IntToString(fcc.numer);
                    }
                    else
                    {
                        exp = exp + IntToString(fcc.numer);
                        exp = exp + "/";
                        exp = exp + IntToString(fcc.deno);
                    }
                }
            }
            line.pop_front();
        }
        C_expression.push_back(exp);
        string tmp;
        if (ans.deno == 1) //Convert the result to a string type
        {
            stringstream ss;
            ss << ans.numer;
            ss >> re;
            tmp = re;
        }
        else
        {
            string a, b;
            stringstream ss;
            ss << ans.numer;
            ss >> a;

            string c = "/";
            string re = a + c;
            stringstream sss;
            sss << ans.deno;
            sss >> b;
            re.append(b);
            tmp = re;
        }
        C_result.push_back(tmp);
    }

    space.clear(); //Initialization
    line.clear();
}

