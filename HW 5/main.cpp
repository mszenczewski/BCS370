//****************************************************
// File: main.cpp
//
// Purpose: Provides unit testing for StockBST class 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************

#include <iostream>
#include <iomanip>
#include "stock_bst_test.h"

using namespace std;

//****************************************************
// Function: main
//
// Purpose: Run unit tests for StockBST class
//
//****************************************************
int main()
{
	cout << setfill('.');

	testStockBSTAddGetShares();
	testStockBSTSize();
	testStockBSTClear();
	testStockBSTInorder();
	testStockBSTPreorder();
	testStockBSTPostorder();
	testStockBSTConstructorCopy();
	testStockBSTOperatorOverloadAssignment();
	testStockBSTOperatorOverloadExtraction();
	return 0;
}