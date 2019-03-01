//****************************************************
// File: stock_stack_test.cpp
//
// Purpose: Provides unit testing for StockStack class 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************
#include "stock_stack_test.h"
#include "stock_stack.h"
#include "stock.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int column_width = 48;

//****************************************************
// Function: testStockStackClear
//
// Purpose: Test StockStack class Clear
//
//****************************************************
void testStockStackClear()
{
	StockStack stack;

	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);
	Stock x;
	Stock y;
	bool test = true;

	stack.Push(s1);
	stack.Push(s2);
	stack.Push(s3);

	stack.Clear();

	stack.Top(x);

	if (x == y)
	{
		cout << setw(column_width) << left << "Stock Stack Clear" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Clear" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockStackPushTop
//
// Purpose: test StockStack Push and Top
//
//****************************************************
void testStockStackPushTop()
{
	StockStack stack;

	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);
	Stock x;
	bool testPush = false;
	bool testTop = false;

	testPush = stack.Push(s1);
	stack.Push(s2);
	stack.Push(s3);

	testTop = stack.Top(x);

	if (x == s3 && testPush && testTop)
	{
		cout << setw(column_width) << left << "Stock Stack Push/Top" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Push/Top" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockStackMaxStorage
//
// Purpose: test StockStack MaxStorage
//
//****************************************************
void testStockStackMaxStorage()
{
	int testNum = 14;
	StockStack stack(testNum);
	
	if (stack.MaxStorage() == testNum)
	{
		cout << setw(column_width) << left << "Stock Stack Max Storage" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Max Storage" << right << "Fail" << endl;
	}

}

//****************************************************
// Function: testStockStackSize
//
// Purpose: test StockStack Size
//
//****************************************************
void testStockStackSize()
{
	StockStack stack;
	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);

	stack.Push(s1);
	stack.Push(s2);
	stack.Push(s3);

	if (stack.Size() == 3)
	{
		cout << setw(column_width) << left << "Stock Stack Size" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Size" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockStackPop
//
// Purpose: test StockStack Pop
//
//****************************************************
void testStockStackPop()
{
	StockStack stack;
	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);
	Stock s4("Potato", 19.6, 24);
	Stock x;
	bool testPop = false;

	stack.Push(s1);
	stack.Push(s2);
	stack.Push(s3);
	stack.Push(s4);

	testPop = stack.Pop();
	stack.Pop();

	stack.Top(x);

	if (x == s2 && testPop)
	{
		cout << setw(column_width) << left << "Stock Stack Pop" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Pop" << right << "Fail" << endl;
	}

}

//****************************************************
// Function: testStockStackConstructorDefault
//
// Purpose: test StockStack default constructor
//
//****************************************************
void testStockStackConstructorDefault()
{
	StockStack stack;

	if (stack.Size() == 0 &&
		stack.MaxStorage() == 10)
	{
		cout << setw(column_width) << left << "Stock Stack Constructor (Default)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Constructor (Default)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockStackConstructorParameter
//
// Purpose: test StockStack constructor with one parameter
//
//****************************************************
void testStockStackConstructorParameter()
{
	int testNum = 14;
	StockStack stack(testNum);

	if (stack.Size() == 0 &&
		stack.MaxStorage() == testNum)
	{
		cout << setw(column_width) << left << "Stock Stack Constructor (One Parameter)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Constructor (One Parameter)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockStackConstructorCopy
//
// Purpose: test StackStock copy constructor
//
//****************************************************
void testStockStackConstructorCopy()
{
	int length = 3;
	int errors = 0;

	StockStack stack1(length);

	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);
	Stock x;
	Stock y;

	stack1.Push(s1);
	stack1.Push(s2);
	stack1.Push(s3);

	StockStack stack2(stack1);

	for (int i = 0; i < length; i++)
	{
		stack1.Top(x);
		stack2.Top(y);

		stack1.Pop();
		stack2.Pop();

		if (x != y)
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock Stack Constructor (Copy)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Constructor (Copy)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockStackOverloadInsertionExtraction
//
// Purpose: test StockStack overload of insertion and extraction operators
//
//****************************************************
void testStockStackOverloadInsertionExtraction()
{
	string fileName = "stock_stack_test.txt";
	ofstream outputFile;
	ifstream inputFile;
	int errors = 0;
	StockStack stack;
	Stock stockArray[] =
	{
		Stock("Apple", 11.0, 14),
		Stock("Banana", 14.43, 7),
		Stock("Orange", 9.6, 2)
	};
	Stock x;

	//input data in reverse order to pass comparison
	for (int i = 2; i >= 0; i--)
	{
		stack.Push(stockArray[i]);
	}

	inputFile.open(fileName);
	outputFile.open(fileName);

	outputFile << stack;
	inputFile >> stack;

	//test if data is the same
	for (int i = 0; i < stack.Size(); i++)
	{
		stack.Top(x);
		stack.Pop();
		if (x != stockArray[i])
		{
			errors++;
		}
	}

	inputFile.close();
	outputFile.close();

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock Stack Overload (Insertion/Extraction)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Overload (Insertion/Extraction)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockStackOverloadAssignment
//
// Purpose: test StockStack overload of assignment operator
//
//****************************************************
void testStockStackOverloadAssignment()
{
	int errors = 0;

	StockStack stack1;
	StockStack stack2;

	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);
	Stock x;
	Stock y;

	stack1.Push(s1);
	stack1.Push(s2);
	stack1.Push(s3);

	stack2 = stack1;

	for (int i = 0; i < stack1.Size(); i++)
	{
		stack1.Top(x);
		stack2.Top(y);

		stack1.Pop();
		stack2.Pop();

		if (x != y)
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock Stack Overload (Assignment)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Stack Overload (Assignment)" << right << "Fail" << endl;
	}
}

