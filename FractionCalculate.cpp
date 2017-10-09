#include"stdafx.h"
#include"FractionCalculate.h"


FractionCalculate::FractionCalculate()
{

}

int FractionCalculate::gcd(int a, int b)//Maximum common divisor
{
	int temp, r;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

Fraction FractionCalculate::FractionAdd(Fraction f1, Fraction f2)//Addition
{
	Fraction f3;
	f3.deno = f1.deno * f2.deno;
	f3.numer = f1.numer * f2.deno + f1.deno * f2.numer;
	return Fractionsim(f3);
}

Fraction FractionCalculate::Fractionsub(Fraction f1, Fraction f2)//Subtraction
{
	Fraction f3;
	f3.deno = f1.deno * f2.deno;
	f3.numer = f1.numer * f2.deno - f1.deno * f2.numer;
	return Fractionsim(f3);
}

Fraction FractionCalculate::Fractionmul(Fraction f1, Fraction f2)//Multiplication
{
	Fraction f3;
	f3.deno = f1.deno * f2.deno;
	f3.numer = f1.numer * f2.numer;
	return Fractionsim(f3);
}

Fraction FractionCalculate::Fractiondiv(Fraction f1, Fraction f2)//Division
{
	Fraction f3;
	f3.numer = f1.numer * f2.deno;
	f3.deno = f1.deno * f2.numer;
	return Fractionsim(f3);
}

Fraction FractionCalculate::Fractionsim(Fraction f1)//Fractional simplification
{
	int temp = gcd(f1.deno, f1.numer);
	f1.deno /= temp;
	f1.numer /= temp;
	return f1;
}
