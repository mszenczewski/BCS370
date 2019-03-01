//****************************************************
// File: main.cpp
//
// Purpose: Provides unit testing of Stock and Portfolio classes
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
// 
//****************************************************

#include <iostream>
#include "stock.h"
#include "portfolio.h"
#include "unit_test.h"

using namespace std;

//****************************************************
// Function: main
//
// Purpose: Provides unit testing of Stock and Portfolio classes
//
//****************************************************
int main()
{
	//Run unit tests
	testStockSetGetName();
	testStockSetGetPrice();
	testStockSetGetShares();
	testPortfolioSetGet();
	testPortfolioPriceRangeCount();
	testPortfolioMostShares();
	testPortfolioFindByName();
	testPortfolioTotalValue();
	
	return 0;
}