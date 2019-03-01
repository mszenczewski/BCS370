//****************************************************
// File: test_stock_list.cpp
//
// Purpose: Provides unit testing for StockList class  
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************
#include "test_stock_list.h"
#include "stock_list.h"
#include "stock.h"
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

const int column_width = 40;

//****************************************************
// Function: testStockListLength
//
// Purpose: Provides unit testing for StockList Length
//
//****************************************************
void testStockListLength()
{
	StockList list;

	if (list.Length() == 0)
	{
		cout << setw(column_width) << left << "Stock List Length" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock List Length" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockListAddFind
//
// Purpose: Provides unit testing for StockList Add and FindByName 
//
//****************************************************
void testStockListAddFind()
{
	bool found;
	int errors = 0;
	Stock s1("Apple", 11.10, 34);
	Stock s2("Banana", 9.53, 37);
	Stock s3("Orange", 121.04, 11);
	Stock test;
	string testName[] = { s1.GetName(), s2.GetName(), s3.GetName(), "Potato", "Broccoli", "Corn" };

	StockList list;

	list.Add(s1);
	list.Add(s2);
	list.Add(s3);

	//test valid data
	for (int i = 0; i < 3; i++)
	{
		found = list.FindByName(testName[i], test);

		if (found == false || test.GetName() != testName[i])
		{
			errors++;
		}
	}

	//test invalid data
	for (int i = 3; i < 6; i++)
	{
		found = list.FindByName(testName[i], test);

		if (found == true || test.GetName() == testName[i])
		{
			errors++;
		}
	}
	
	//print results
	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock List Add/Find" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock List Add/Find" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockListConstructorList
//
// Purpose: Provides unit testing for StockList constructor which takes a StockList parameter
//
//****************************************************
void testStockListConstructorList()
{
	Stock s1("Apple", 11.10, 34);
	Stock s2("Banana", 9.53, 37);
	Stock s3("Orange", 121.04, 11);

	Stock s4, s5, s6;

	StockList list1;

	list1.Add(s1);
	list1.Add(s2);
	list1.Add(s3);

	StockList list2(list1); //list will be backwards and fail comparison
	StockList list3(list2); //reverses list
	
	if (list1 == list3)
	{
		cout << setw(column_width) << left << "Stock List Constructor" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock List Constructor" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockListClear
//
// Purpose: Provides unit testing for StockList Clear
//
//****************************************************
void testStockListClear()
{
	bool found;
	int errors = 0;
	Stock s1("Apple", 11.10, 34);
	Stock s2("Banana", 9.53, 37);
	Stock s3("Orange", 121.04, 11);
	Stock test;
	string testName[] = { s1.GetName(), s2.GetName(), s3.GetName()};

	StockList list;

	list.Add(s1);
	list.Add(s2);
	list.Add(s3);

	list.Clear();

	for (int i = 0; i < 3; i++)
	{
		found = list.FindByName(testName[i], test);

		if (found)
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock List Clear" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock List Clear" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockListAddList
//
// Purpose: Provides unit testing for StockList Add which adds one list into another
//
//****************************************************
void testStockListAddList()
{
	Stock s1("Apple", 11.10, 34);
	Stock s2("Banana", 9.53, 37);
	Stock s3("Orange", 121.04, 11);
	Stock s4("Corn", 98.53, 12);

	StockList list1;
	StockList list2;
	StockList list3;

	list1.Add(s1);
	list1.Add(s2);

	list2.Add(s3);
	list2.Add(s4);

	list1.Add(list2);

	list3.Add(s1);
	list3.Add(s2);
	list3.Add(s4); //list added in reverse
	list3.Add(s3); 

	if (list1 == list3)
	{
		cout << setw(column_width) << left << "Stock List Add List" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock List Add List" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockListDelete
//
// Purpose: Provides unit testing for StockList Delete
//
//****************************************************
void testStockListDelete()
{
	Stock s1("Apple", 11.10, 34);
	Stock s2("Banana", 9.53, 37);
	Stock s3("Orange", 121.04, 11);
	Stock s4("Corn", 98.53, 12);
	Stock s5("Broccoli", 111.20, 69);
	Stock s6("Potato", 123.2, 19);

	int errors = 0;
	bool found;
	string testName[] = { s1.GetName(), s3.GetName(), s6.GetName() };

	Stock test;
	StockList list;

	list.Add(s1);
	list.Add(s2);
	list.Add(s3);
	list.Add(s4);
	list.Add(s5);
	list.Add(s6);

	list.Delete(s1.GetName());
	list.Delete(s3.GetName());
	list.Delete(s6.GetName());

	//look for deleted data
	for (int i = 0; i < 3; i++)
	{
		found = list.FindByName(testName[i], test);

		if (found)
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock List Delete" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock List Delete" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockListOverloadAssignment
//
// Purpose: Provides unit testing for StockList assignment operator overload
//
//****************************************************
void testStockListOverloadAssignment()
{
	Stock s1("Apple", 11.10, 34);
	Stock s2("Banana", 9.53, 37);
	Stock s3("Orange", 121.04, 11);
	Stock s4("Corn", 98.53, 12);
	Stock s5("Broccoli", 111.20, 69);
	Stock s6("Potato", 123.2, 19);

	StockList list1;
	StockList list2;
	StockList list3;

	list1.Add(s1);
	list1.Add(s2);
	list1.Add(s3);

	list2.Add(s4);
	list2.Add(s5);
	list2.Add(s6);

	list1 = list2; //list will be backwards and fail comparison
	list3 = list2; //reverse list

	if (list1 == list3)
	{
		cout << setw(column_width) << left << "Stock List Assignment" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock List Assignment" << right << "Fail" << endl;
	}

}

//****************************************************
// Function: testStockListOverloadInsertionExtraction
//
// Purpose: Provides unit testing for StockList insertion and extraction operator overloads
//
//****************************************************
void testStockListOverloadInsertionExtraction()
{
	Stock s1("Apple", 11.10, 34);
	Stock s2("Banana", 9.53, 37);
	Stock s3("Orange", 121.04, 11);
	Stock s4("Corn", 98.53, 12);
	StockList list;
	StockList list2;
	StockList list3;
	ifstream inputFile;
	ofstream outputFile;

	list.Add(s1);
	list.Add(s2);
	list.Add(s3);
	list.Add(s4);

	inputFile.open("test_stocklist.txt");
	outputFile.open("test_stocklist.txt");

	outputFile << list;

	inputFile >> list2; //list will be backwards and fail comparison

	list3.Add(list2); //reverses list

	if (list == list3)
	{
		cout << setw(column_width) << left << "Stock List Insertion/Extraction" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock List Insertion/Extraction" << right << "Fail" << endl;
	}

	inputFile.close(); 
	outputFile.close(); 
}

//****************************************************
// Function: testStockListOverloadComparison
//
// Purpose: Provides unit testing for StockList equality operator overloads
//
//****************************************************
void testStockListOverloadEquality()
{
	int errors = 0;
	Stock s1("Apple", 11.10, 34);
	Stock s2("Banana", 9.53, 37);
	Stock s3("Orange", 121.04, 11);
	Stock s4("Corn", 98.53, 12);
	Stock s5("Potato", 45.2, 123);
	StockList list1;
	StockList list2;

	//compare if the same
	list1.Add(s1);
	list1.Add(s2);
	list1.Add(s3);

	list2.Add(s1);
	list2.Add(s2);
	list2.Add(s3);

	if (!(list1 == list2))
	{
		errors++;
	}

	//compare if different, same size
	list1.Clear();
	list2.Clear();

	list1.Add(s1);
	list1.Add(s2);

	list2.Add(s1);
	list2.Add(s4);

	if (list1 == list2)
	{
		errors++;
	}

	//compare if different, second is shorter
	list1.Clear();
	list2.Clear();

	list1.Add(s1);
	list1.Add(s2);
	list1.Add(s3);
	list1.Add(s4);

	list2.Add(s1);
	list2.Add(s2);

	if (list1 == list2)
	{
		errors++;
	}

	//compare if different, first is shorter
	list1.Clear();
	list2.Clear();

	list1.Add(s1);
	list1.Add(s2);

	list2.Add(s1);
	list2.Add(s2);
	list1.Add(s3);
	list1.Add(s4);

	if (list1 == list2)
	{
		errors++;
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock List Comparison" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock List Comparison" << right << "Fail" << endl;
	}
}