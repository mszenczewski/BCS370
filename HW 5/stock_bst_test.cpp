//****************************************************
// File: stock_bst_test.cpp
//
// Purpose: Provides unit testing for StockBST class 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************

#include "stock_bst_test.h"
#include "stock_bst.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int column_width = 38;

//****************************************************
// Function: testStockBSTAddGetShares
//
// Purpose: provides unit testing for StockBST class Add and GetShares functions
//
//****************************************************
void testStockBSTAddGetShares()
{
	int errors = 0;
	StockBST bst;

	Stock a("Orange", 12.5, 32);
	Stock b("Banana", 14.3, 21);
	Stock c("Apple", 41.2, 17);
	Stock d("Potato", 52.9, 11);
	Stock e("Corn", 14.2, 124);

	string stockNames[] = { "Orange", "Banana", "Apple", "Potato", "Corn" };
	double stockShares[] = { 32, 21, 17, 11, 124 };

	bst.Add(a);
	bst.Add(b);
	bst.Add(c);
	bst.Add(d);
	bst.Add(e);

	//test valid lookup
	for (int i = 0; i < 5; i++)
	{
		double x;
		bst.GetShares(stockNames[i], x);
		
		if (x != stockShares[i])
		{
			errors++;
		}
	}

	//test invalid lookup
	double y = -1;
	bst.GetShares("NotAStock", y);
	if (y != -1)
	{
		errors++;
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock BST Add/GetShares" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock BST Add/GetShares" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockBSTSize
//
// Purpose: provides unit testing for StockBST class Size function
//
//****************************************************
void testStockBSTSize()
{
	StockBST bst;

	Stock a("Orange", 12.5, 32);
	Stock b("Banana", 14.3, 21);
	Stock c("Apple", 41.2, 17);
	Stock d("Potato", 52.9, 11);
	Stock e("Corn", 14.2, 124);

	bst.Add(a);
	bst.Add(b);
	bst.Add(c);
	bst.Add(d);
	bst.Add(e);

	if (bst.Size() == 5)
	{
		cout << setw(column_width) << left << "Stock BST Size" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock BST Size" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockBSTClear
//
// Purpose: provides unit testing for StockBST class Clear function
//
//****************************************************
void testStockBSTClear()
{
	int errors = 0;

	StockBST bst;

	Stock a("Orange", 12.5, 32);
	Stock b("Banana", 14.3, 21);
	Stock c("Apple", 41.2, 17);
	Stock d("Potato", 52.9, 11);
	Stock e("Corn", 14.2, 124);

	string stockNames[] = { "Orange", "Banana", "Apple", "Potato", "Corn" };
	double stockShares[] = { 32, 21, 17, 11, 124 };

	bst.Add(a);
	bst.Add(b);
	bst.Add(c);
	bst.Add(d);
	bst.Add(e);

	bst.Clear();

	if (bst.Size() != 0)
	{
		errors++;
	}

	for (int i = 0; i < 5; i++)
	{
		double x = -1;
		bst.GetShares(stockNames[i], x);

		if (x != -1)
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock BST Clear" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock BST Clear" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockBSTInorder
//
// Purpose: provides unit testing for StockBST class Inorder function
//
//****************************************************
void testStockBSTInorder()
{
	StockBST bst;

	Stock a("Orange", 12.5, 32);
	Stock b("Banana", 14.3, 21);
	Stock c("Apple", 41.2, 17);
	Stock d("Potato", 52.9, 11);
	Stock e("Corn", 14.2, 124);

	stringstream stream;
	string inorder = "";

	inorder += "Apple\n";
	inorder += "Banana\n";
	inorder += "Corn\n";
	inorder += "Orange\n";
	inorder += "Potato\n";

	bst.Add(a);
	bst.Add(b);
	bst.Add(c);
	bst.Add(d);
	bst.Add(e);

	auto original = cout.rdbuf(); //save original stream

	cout.rdbuf(stream.rdbuf()); //redirect stream

	bst.Inorder();

	cout.rdbuf(original); //return original stream

	if (stream.str() == inorder)
	{
		cout << setw(column_width) << left << "Stock BST Inorder" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock BST Inorder" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockBSTPreorder
//
// Purpose: provides unit testing for StockBST class Preoder function
//
//****************************************************
void testStockBSTPreorder()
{
	stringstream stream;
	StockBST bst;

	Stock a("Orange", 12.5, 32);
	Stock b("Banana", 14.3, 21);
	Stock c("Apple", 41.2, 17);
	Stock d("Potato", 52.9, 11);
	Stock e("Corn", 14.2, 124);

	string preorder = "";

	preorder += "Orange\n";
	preorder += "Banana\n";
	preorder += "Apple\n";
	preorder += "Corn\n";
	preorder += "Potato\n";

	bst.Add(a);
	bst.Add(b);
	bst.Add(c);
	bst.Add(d);
	bst.Add(e);

	auto original = cout.rdbuf(); //save original stream

	cout.rdbuf(stream.rdbuf()); //redirect stream

	bst.Preorder();

	cout.rdbuf(original); //return original stream

	if (stream.str() == preorder)
	{
		cout << setw(column_width) << left << "Stock BST Preorder" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock BST Preorder" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockBSTPostorder
//
// Purpose: provides unit testing for StockBST class Postorder function
//
//****************************************************
void testStockBSTPostorder()
{
	stringstream stream;
	StockBST bst;

	Stock a("Orange", 12.5, 32);
	Stock b("Banana", 14.3, 21);
	Stock c("Apple", 41.2, 17);
	Stock d("Potato", 52.9, 11);
	Stock e("Corn", 14.2, 124);

	string postorder = "";

	postorder += "Apple\n";
	postorder += "Corn\n";
	postorder += "Banana\n";
	postorder += "Potato\n";
	postorder += "Orange\n";

	bst.Add(a);
	bst.Add(b);
	bst.Add(c);
	bst.Add(d);
	bst.Add(e);

	auto original = cout.rdbuf(); //save original stream

	cout.rdbuf(stream.rdbuf()); //redirect stream

	bst.Postorder();

	cout.rdbuf(original); //return original stream

	if (stream.str() == postorder)
	{
		cout << setw(column_width) << left << "Stock BST Postorder" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock BST Postorder" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockBSTConstructorCopy
//
// Purpose: provides unit testing for StockBST class copy constructor
//
//****************************************************
void testStockBSTConstructorCopy()
{
	int errors = 0;

	StockBST bst;

	Stock a("Orange", 12.5, 32);
	Stock b("Banana", 14.3, 21);
	Stock c("Apple", 41.2, 17);
	Stock d("Potato", 52.9, 11);
	Stock e("Corn", 14.2, 124);

	string stockNames[] = { "Orange", "Banana", "Apple", "Potato", "Corn" };
	double stockShares[] = { 32, 21, 17, 11, 124 };

	bst.Add(a);
	bst.Add(b);
	bst.Add(c);
	bst.Add(d);
	bst.Add(e);

	StockBST bst2(bst);

	if (bst2.Size() != bst.Size())
	{
		errors++;
	}

	for (int i = 0; i < 5; i++)
	{
		double x = -1;
		bst2.GetShares(stockNames[i], x);

		if (x != stockShares[i])
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock BST Constructor (Copy)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock BST Constructor (Copy)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockBSTOperatorOverloadAssignment
//
// Purpose: provides unit testing for StockBST assignment operator overload
//
//****************************************************
void testStockBSTOperatorOverloadAssignment()
{
	int errors = 0;

	StockBST bst;
	StockBST bst2;

	Stock a("Orange", 12.5, 32);
	Stock b("Banana", 14.3, 21);
	Stock c("Apple", 41.2, 17);
	Stock d("Potato", 52.9, 11);
	Stock e("Corn", 14.2, 124);

	string stockNames[] = { "Orange", "Banana", "Apple", "Potato", "Corn" };
	double stockShares[] = { 32, 21, 17, 11, 124 };

	bst.Add(a);
	bst.Add(b);
	bst.Add(c);
	bst.Add(d);
	bst.Add(e);

	bst2 = bst;

	if (bst2.Size() != bst.Size())
	{
		errors++;
	}

	for (int i = 0; i < 5; i++)
	{
		double x = -1;
		bst2.GetShares(stockNames[i], x);

		if (x != stockShares[i])
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock BST Overload (Assignment)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock BST Overload (Assignment)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockBSTOperatorOverloadExtraction
//
// Purpose: provide unit testing for StockBST extraction operator overload
//
//****************************************************
void testStockBSTOperatorOverloadExtraction()
{
	stringstream stream;
	stringstream print;

	StockBST bst;

	Stock a("Orange", 12.5, 32);
	Stock b("Banana", 14.3, 21);
	Stock c("Apple", 41.2, 17);
	Stock d("Potato", 52.9, 11);
	Stock e("Corn", 14.2, 124);

	bst.Add(a);
	bst.Add(b);
	bst.Add(c);
	bst.Add(d);
	bst.Add(e);

	auto original = cout.rdbuf(); //save original stream

	cout.rdbuf(print.rdbuf()); //redirect stream

	cout << c; //Apple
	cout << b; //Banana
	cout << e; //Corn
	cout << a; //Orange
	cout << d; //Potato

	cout.rdbuf(stream.rdbuf()); //redirect stream

	cout << bst;

	cout.rdbuf(original); //return original stream

	if (stream.str() == print.str())
	{
		cout << setw(column_width) << left << "Stock BST Overload (Extraction)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock BST Overload (Extraction)" << right << "Fail" << endl;
	}
}
