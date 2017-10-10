#ifndef CALCULATE_H
#define CALCULATE_H
#include"Fraction.h"
#include<stack>
#include<deque>
using namespace std;

class Calculate
{
public:
    Calculate();

    bool isBracket(char c);//Determine whether it is brackets

    int getPri(char c);//Get the priority of the symbol

    int checkzero(Fraction op1); //Check whether the divisor is zero

    void check(Fraction c, stack<Fraction>& space2, deque<Fraction>& space3);//Determine the priority of the symbol

                                                                                           //Remove the element from space1 and assign the element to space2 and space3
    void allocate(deque<Fraction>& space1, stack<Fraction>& space2, deque<Fraction>& space3);

    //Calculate the suffix expression
    Fraction calculateExpression(deque<Fraction> &space1);
};

#endif // CALCULATE_H
