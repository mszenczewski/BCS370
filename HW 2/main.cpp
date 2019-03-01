//****************************************************
// File: main.cpp
//
// Purpose: Provides unit testing for Stock class 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
// 
//****************************************************

#include <iostream>
#include <iomanip>
#include "stock.h"
#include "portfolio.h"
#include "test_stock.h"
#include "test_portfolio.h"

using namespace std;

//****************************************************
// Function: main
//
// Purpose: Provides unit testing for Portfolio and Stock classes
//
//****************************************************
int main()
{
	cout << setfill('.');

	//run Stock tests
	testStockSetGetName();
	testStockSetGetPrice();
	testStockSetGetShares();
	testStockConstructorDefault();
	testStockConstructorParameters();
	testStockConstructorCopy();
	testStockCalculateValue();
	testStockOperatorAssignment();
	testStockOperatorInsertionExtraction();

	//run Portfolio tests
	testPortfolioSetGet();
	testPortfolioSize();
	testPortfolioInitialize();
	testPortfolioConstructorDefault();
	testPortfolioConstructorParameters();
	testPortfolioConstructorCopy();
	testPortfolioOperatorAssignment();
	testPortfolioOperatorInsertionExtraction();
	testPortfolioPriceRangeCount();
	testPortfolioMostShares();
	testPortfolioFindByName();
	testPortfolioTotalValue();
	testPortfolioResizeGrow();
	testPortfolioResizeShrink();
	testPortfolioResizeSame();
	testPortfolioClone();

	return 0;
}