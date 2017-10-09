#include"stdafx.h"
#include"Calculate.h"
#include"FractionCalculate.h"

Calculate::Calculate()
{

}

bool Calculate::isBracket(char c)//Determine whether it is brackets
{
	if (c == '(' || c == ')')
		return true;
	else
		return false;
}

int Calculate::getPri(char c)//Get the priority of the symbol
{
	switch (c)
	{
	case '+':
	case '-':
		return 0;   //If it is addition and subtraction, return 0
		break;
	case '*':
	case '/':
		return 1;   //If it is multiplied and division, returns 1
		break;
	case '(':
	case ')':
		return -1;  //Set brackets to the lowest priority
		break;
	default:
		break;
	}
}

int Calculate::checkzero(Fraction op1)//Check whether the divisor is zero
{
	if (op1.numer == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Calculate::check(Fraction c, std::stack<Fraction> &space2, std::deque<Fraction> &space3)//Determine the priority of the symbol
{
	if (space2.empty())
	{
		space2.push(c);
		return;
	}

	if (isBracket(c.symbol))
	{
		if (c.symbol == '(')
			space2.push(c);
		else
		{
			while (space2.top().symbol != '(') //Pop all elements until the left parenthesis is encountered
			{
				Fraction ch = space2.top();
				space3.push_back(ch);
				space2.pop();
			}

			space2.pop();
		}
	}
	else
	{
		Fraction sym = space2.top();

		if (getPri(c.symbol) <= getPri(sym.symbol)) //Compare the priority of two symbols
		{
			//If c's priority is smaller than or equal to the top of the stack, the stack top element is popped
			space2.pop();
			//push it into space3 (suffix expression)
			space3.push_back(sym);
			check(c, space2, space3);
		}
		else
		{
			//If c is greater than the top of the stack, it will push c into space2 (operator stack)
			space2.push(c);
		}
	}
}

//Remove the element from space1 and assign the element to space2 and space3
void Calculate::allocate(std::deque<Fraction> &space1, std::stack<Fraction> &space2, std::deque<Fraction> &space3)
{
	while (!space1.empty())
	{
		Fraction c = space1.front();
		space1.pop_front();

		if (c.symbol == '|')
		{
			space3.push_back(c);
		}
		else
		{
			check(c, space2, space3);
		}

	}

	//If the input ends, the space2 element will pop up and join the suffix expression
	while (!space2.empty())
	{
		Fraction c = space2.top();
		space3.push_back(c);
		space2.pop();
	}
}

//Calculate the suffix expression
Fraction Calculate::calculateExpression(deque<Fraction> &space1)
{
	stack<Fraction> space2;
	deque<Fraction> space3;
	stack<Fraction> space4;
	allocate(space1, space2, space3);
	while (!space3.empty())
	{
		Fraction c = space3.front();
		space3.pop_front();

		//If it is an operand, press it into the space4 stack
		if (c.symbol == '|')
		{
			space4.push(c);
		}
		else     //If it is an operator, pop up the elements from the stack to calculate
		{
			Fraction op1 = space4.top();
			space4.pop();
			Fraction op2 = space4.top();
			space4.pop();
			FractionCalculate fc;
			if (c.symbol == '+')
			{
				space4.push(fc.FractionAdd(op2, op1));
			}
			else if (c.symbol == '-')
			{
				space4.push(fc.Fractionsub(op2, op1));
			}
			else if (c.symbol == '*')
			{
				space4.push(fc.Fractionmul(op2, op1));
			}
			else
			{
				if (c.symbol == '/')
				{
					int t = checkzero(op1);
					if (t == 0)
					{
						space4.push(fc.Fractiondiv(op2, op1));
					}
					else
					{
						Fraction fg;
						fg.deno = 0;
						fg.numer = 1;
						fg.symbol = '|';
						return fg;
					}
				}
			}
		}
	}
	return space4.top();
}