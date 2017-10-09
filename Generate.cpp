#include"stdafx.h"
#include"Generate.h"
#include"FractionCalculate.h"
#include"Calculate.h"

Generate::Generate()
{

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

void Generate::GenerateExpression()
{
	srand((unsigned)time(0));
	int operatorsnum = rand() % 12 + 3;//Generate the number of operands
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

string Generate::printExpression()//Output the expression
{
	string re;
	while (!line.empty())
	{
		Fraction fcc = line.front();
		if (fcc.symbol == '(' || fcc.symbol == ')')
		{
			re = re + charToString(fcc.symbol);
		}
		else if (fcc.symbol == '+' || fcc.symbol == '-')
		{
			re = re + charToString(fcc.symbol);
		}
		else if (fcc.symbol == '*')
		{
			string tmp = "¡Á";
			re = re + tmp;
		}
		else if (fcc.symbol == '/')
		{
			string tmp = "¡Â";
			re = re + tmp;
		}
		else
		{
			if (fcc.symbol == '|')
			{
				if (fcc.deno == 1)
				{
					re = re + IntToString(fcc.deno);
				}
				else
				{
					re = re + IntToString(fcc.numer);
					re = re + charToString(fcc.symbol);
					re = re + IntToString(fcc.deno);
				}
			}
		}
	}
	return re;
}

Fraction Generate::printAnswer()//Output the answer
{
	Calculate cal;
	return cal.calculateExpression(space);
}