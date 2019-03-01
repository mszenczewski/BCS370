//****************************************************
// File: stock_stack.cpp
//
// Purpose: Defines a StockStack class to hold a stack of stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************

#include "stock_stack.h"

using namespace std;

//****************************************************
// Function: StockStack
//
// Purpose: default constructor
//
// Runtime: O(1)
//
//****************************************************
StockStack::StockStack()
{
	top = -1;
	max = 10;
	stockArray = new Stock[max];
}

//****************************************************
// Function: StockStack
//
// Purpose: consructor with one parameter
//
// Runtime: O(1)
//
//****************************************************
StockStack::StockStack(int max)
{
	top = -1;
	this->max = max;
	stockArray = new Stock[max];
}

//****************************************************
// Function: StockStack
//
// Purpose: copy constructor
//
// Runtime: O(n)
//
//****************************************************
StockStack::StockStack(const StockStack &rhs)
{
	top = rhs.top;
	max = rhs.max;
	stockArray = new Stock[max];

	for (int i = 0; i < max; i++)
	{
		stockArray[i] = rhs.stockArray[i];
	}
}

//****************************************************
// Function: ~StockStack
//
// Purpose: destructor
//
// Runtime: O(1)
//
//****************************************************
StockStack::~StockStack()
{
	delete[] stockArray;
}

//****************************************************
// Function: Clear
//
// Purpose: empties stack
//
// Runtime: O(1)
//
//****************************************************
void StockStack::Clear()
{
	top = -1;
}

//****************************************************
// Function: Size
//
// Purpose: Returns logical size of stack
//
// Runtime: O(1)
//
//****************************************************
int StockStack::Size()
{
	return top + 1;
}

//****************************************************
// Function: MaxStorage
//
// Purpose: Returns size of stack
//
// Runtime: O(1)
//
//****************************************************
int StockStack::MaxStorage()
{
	return max;
}

//****************************************************
// Function: Push
//
// Purpose: Adds item to stack
//
// Runtime: O(1)
//
//****************************************************
bool StockStack::Push(Stock s)
{
	if (max == top + 1)
	{
		return false;
	}
	else
	{
		stockArray[++top] = s;
		return true;
	}
}

//****************************************************
// Function: Pop
//
// Purpose: Removes item from stack
//
// Runtime: O(1)
//
//****************************************************
bool StockStack::Pop()
{
	if (top == -1)
	{
		return false;
	}
	else
	{
		top--;
		return true;
	}
}

//****************************************************
// Function: Top
//
// Purpose: Copies top item from stack
//
// Runtime: O(1)
//
//****************************************************
bool StockStack::Top(Stock &returnedStock)
{
	if (top == -1)
	{
		return false;
	}
	else
	{
		returnedStock = stockArray[top];
		return true;
	}
}

//****************************************************
// Function: operator=
//
// Purpose: overload assignment operator
//
// Runtime: O(n)
//
//****************************************************
StockStack &StockStack::operator=(StockStack &rhs)
{
	delete[] stockArray;

	top = rhs.top;
	max = rhs.max;
	stockArray = new Stock[max];

	for (int i = 0; i < max; i++)
	{
		stockArray[i] = rhs.stockArray[i];
	}

	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: overload insertion operator
//
// Runtime: O(n)
//
//****************************************************
std::ostream &operator<<(std::ostream &output, StockStack &rhs)
{
	output << rhs.max << endl;
	output << rhs.top << endl;

	for (int i = 0; i < rhs.max; i++)
	{
		output << rhs.stockArray[i];
	}

	return output;
}

//****************************************************
// Function: operator>>
//
// Purpose: overload extraction operator
//
// Runtime: O(n)
//
//****************************************************
std::istream &operator>>(std::istream &is, StockStack &input)
{
	input.Clear();

	is >> input.max;

	input.stockArray = new Stock[input.max];

	is >> input.top;

	for (int i = 0; i < input.max; i++)
	{
		is >> input.stockArray[i];
	}

	return is;
}
