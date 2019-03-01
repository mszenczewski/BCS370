//****************************************************
// File: test_stock.cpp
//
// Purpose: Provides unit testing for Stock class 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
// 
//****************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "stock.h"
#include "test_stock.h"

using namespace std;

const int column_width = 44;

//****************************************************
// Function: testStockSetGetName
//
// Purpose: Provides unit testing for Stock class SetName and GetName 
//
//****************************************************
void testStockSetGetName()
{
	const string testName = "testName";
	Stock s;

	//create test data
	s.SetName(testName);

	//test function
	if (s.GetName() == testName)
	{
		cout << setw(column_width) << left << "Stock Set/Get Name" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Set/Get Name" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockSetGetPrice
//
// Purpose: Provides unit testing for Stock class SetPrice and GetPrice 
//
//****************************************************
void testStockSetGetPrice()
{
	const double testDouble = 25.0;
	Stock s;

	//create test data
	s.SetPrice(testDouble);

	//test function
	if (s.GetPrice() == testDouble)
	{
		cout << setw(column_width) << left << "Stock Set/Get Price" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Set/Get Price" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockSetGetShares
//
// Purpose: Provides unit testing for Stock class SetPrice and GetPrice 
//
//****************************************************
void testStockSetGetShares()
{
	const double testDouble = 25.0;
	Stock s;

	//create test data
	s.SetShares(testDouble);

	//test function
	if (s.GetShares() == testDouble)
	{
		cout << setw(column_width) << left << "Stock Set/Get Shares" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Set/Get Shares" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockConstructorDefault
//
// Purpose: Provides unit testing for Stock class default constructor
//
//****************************************************
void testStockConstructorDefault()
{
	const string testName = "";
	const double testPrice = 0;
	const double testShares = 0;

	//create test data
	Stock s;

	//test function
	if (s.GetName() == testName &&
		s.GetPrice() == testPrice &&
		s.GetShares() == testShares)
	{
		cout << setw(column_width) << left << "Stock Default Constructor" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Default Constructor" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockConstructorParameters
//
// Purpose: Provides unit testing for Stock class parameterized constructor
//
//****************************************************
void testStockConstructorParameters()
{
	const string testName = "Apple";
	const double testPrice = 12.4;
	const double testShares = 43;

	//create test data
	Stock s(testName, testPrice, testShares);

	//test function
	if (s.GetName() == testName &&
		s.GetPrice() == testPrice &&
		s.GetShares() == testShares)
	{
		cout << setw(column_width) << left << "Stock Parameterized Constructor" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Parameterized Constructor" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockConstructorCopy
//
// Purpose: Provides unit testing for Stock class copy constructor
//
//****************************************************
void testStockConstructorCopy()
{
	const string testName = "Apple";
	const double testPrice = 12.4;
	const double testShares = 43;

	//create test data
	Stock s(testName, testPrice, testShares);
	Stock s2(s);

	//test function
	if (s2.GetName() == testName &&
		s2.GetPrice() == testPrice &&
		s2.GetShares() == testShares)
	{
		cout << setw(column_width) << left << "Stock Copy Constructor" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Copy Constructor" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockCalculateValue
//
// Purpose: Provides unit testing for Stock class CalculateValue
//
//****************************************************
void testStockCalculateValue()
{
	const double testPrice = 12.4;
	const double testShares = 43;
	const double testValue = 533.2;

	//create test data
	Stock s("test", testPrice, testShares);

	//test function
	if (s.CalculateValue() == testValue)
	{
		cout << setw(column_width) << left << "Stock CalculateValue" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock CalculateValue" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockOperatorAssignment
//
// Purpose: Provides unit testing for Stock class assignment operator overload
//
//****************************************************
void testStockOperatorAssignment()
{
	const string testName = "Apple";
	const double testPrice = 12.4;
	const double testShares = 43;

	//create test data
	Stock s(testName, testPrice, testShares);
	Stock s2;

	s2 = s;

	//test function
	if (s.GetName() == testName &&
		s.GetPrice() == testPrice &&
		s.GetShares() == testShares)
	{
		cout << setw(column_width) << left << "Stock Assignment Overload" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Assignment Overload" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockOperatorInsertionExtraction
//
// Purpose: Provides unit testing for Stock class assignment operator overload
//
//****************************************************
void testStockOperatorInsertionExtraction()
{
	const string testName = "Apple";
	const double testPrice = 12.4;
	const double testShares = 43;

	ofstream outputFile;
	ifstream inputFile;

	//create test data
	Stock s(testName, testPrice, testShares);

	outputFile.open("test_stock.txt");
	inputFile.open("test_stock.txt");

	//write data to file
	outputFile << s;

	//input data from file
	inputFile >> s;

	inputFile.close();
	outputFile.close();

	//test function
	if (s.GetName() == testName &&
		s.GetPrice() == testPrice &&
		s.GetShares() == testShares)
	{
		cout << setw(column_width) << left << "Stock Insertion/Extraction Overload" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Insertion/Extraction Overload" << right << "Fail" << endl;
	}

}

