//****************************************************
// File: main.cpp
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
#include <iomanip>
#include <iostream>

using namespace std;

//****************************************************
// Function: main
//
// Purpose: Provides unit testing for StockList class
//
//****************************************************
int main()
{
	cout << setfill('.');

	testStockListLength();
	testStockListAddFind();
	testStockListConstructorList();
	testStockListClear();
	testStockListAddList();
	testStockListDelete();
	testStockListOverloadAssignment();
	testStockListOverloadInsertionExtraction();
	testStockListOverloadEquality();

	return 0;
}
