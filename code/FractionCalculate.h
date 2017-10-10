#ifndef FRACTIONCALCULATE_H
#define FRACTIONCALCULATE_H
#include"Fraction.h"
using namespace std;

class FractionCalculate
{
public:
    FractionCalculate();

    int gcd(int a, int b);//Maximum common divisor

    Fraction FractionAdd(Fraction f1, Fraction f2);//Addition

    Fraction Fractionsub(Fraction f1, Fraction f2);//Subtraction

    Fraction Fractionmul(Fraction f1, Fraction f2);//Multiplication

    Fraction Fractiondiv(Fraction f1, Fraction f2);//Division

    Fraction Fractionsim(Fraction f1);//Fractional simplification
};

#endif // FRACTIONCALCULATE_H
