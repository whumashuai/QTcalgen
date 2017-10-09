#pragma once
#include<string>
#include"Fraction.h"
#include<deque>
#include<stack>
#include<string>
#include<sstream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;
class Generate
{
public:
	Generate();

	void Generateoperators(); //Generate the operation symbol

	void GenerateFraction(); //Generate Fraction

	void Generateinteger(); //Generate the integer

	void random(); //Automatically generate integers and fractions

	void GenerateExpression();//Generate Expression

	string IntToString(int n);//int converted to string
	string charToString(char n);//char converted to string

	string printExpression();//Output the expression

	Fraction printAnswer();//Output the answer

private:
	deque <Fraction> space;
	deque <Fraction> line; //Store the formula
};