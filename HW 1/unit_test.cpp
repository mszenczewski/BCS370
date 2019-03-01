//****************************************************
// File: unit_test.cpp
//
// Purpose: Provides unit testing for Stock and Portfolio classes 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
// 
//****************************************************

#include "unit_test.h"
#include "stock.h"
#include "portfolio.h"
#include <iostream>
#include <string>

using namespace std;

//****************************************************
// Function: testStockSetGetName
//
// Purpose: Provides unit testing for Stock class SetName and GetName 
//
//****************************************************
void testStockSetGetName()
{
	const string testString = "testString";
	Stock s;

	//create test data
	s.SetName(testString);

	//test function
	if (s.GetName() == testString)
	{
		cout << "Stock Set/Get Name: Pass" << endl;
	}
	else
	{
		cout << "Stock Set/Get Name: Fail" << endl;
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
		cout << "Stock Set/Get Price: Pass" << endl;
	}
	else
	{
		cout << "Stock Set/Get Price: Fail" << endl;
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
		cout << "Stock Set/Get Shares: Pass" << endl;
	}
	else
	{
		cout << "Stock Set/Get Shares: Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioSetGet
//
// Purpose: Provides unit testing for Portfolio class Set and Get 
//
//****************************************************
void testPortfolioSetGet()
{
	Portfolio p;
	Stock s;
	bool getSetPassed = true;

	//create test stock
	s.SetName("testName");
	s.SetPrice(12);
	s.SetShares(11);

	p.Initialize();

	//test each index
	for (int i = 0; i < p.Size(); i++)
	{
		//set data to index
		p.Set(i, s);

		//test each member variable
		if (p.Get(i).GetName() != s.GetName() ||
			p.Get(i).GetPrice() != s.GetPrice() ||
			p.Get(i).GetShares() != s.GetShares())
		{
			getSetPassed = false;
		}
	}

	//print results
	if (getSetPassed == true)
	{
		cout << "Portfolio Set/Get: Pass" << endl;
	}
	else
	{
		cout << "Portfolio Set/Get: Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioPriceRangeCount
//
// Purpose: Provides unit testing for Portfolio class PriceRangeCount 
//
//****************************************************
void testPortfolioPriceRangeCount()
{
	const int testLowerBound = 20;
	const int testUpperBound = 30;
	const int rangeCount = 3;
	Stock a;
	Stock b;
	Stock c;
	Stock d;
	Stock e;
	Stock f;
	Portfolio p;

	//create test stocks
	a.SetPrice(10);
	b.SetPrice(20);
	c.SetPrice(15);
	d.SetPrice(25);
	e.SetPrice(30);
	f.SetPrice(40);

	//set test stocks to p
	p.Initialize();
	p.Set(0, a);
	p.Set(1, b);
	p.Set(2, c);
	p.Set(3, d);
	p.Set(4, e);
	p.Set(5, f);

	//test function
	if (p.PriceRangeCount(testLowerBound, testUpperBound) == rangeCount)
	{
		cout << "Portfolio PriceRangeCount: Pass" << endl;
	}
	else
	{
		cout << "Portfolio PriceRangeCount: Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioMostShares
//
// Purpose: Provides unit testing for Portfolio class MostShares
//
//****************************************************
void testPortfolioMostShares()
{
	Stock a;
	Stock b;
	Stock c;
	Stock d;
	Stock e;
	Stock f;
	Portfolio p;

	//create test stocks
	a.SetShares(12);
	b.SetShares(22);
	c.SetShares(34);
	d.SetShares(41);
	e.SetShares(16);
	f.SetShares(9);

	//set test stocks to p
	p.Initialize();
	p.Set(0, a);
	p.Set(1, b);
	p.Set(2, c);
	p.Set(3, d);
	p.Set(4, e);
	p.Set(5, f);

	//test function
	if (p.MostShares().GetShares() == d.GetShares())
	{
		cout << "Portfolio MostShares: Pass" << endl;
	}
	else
	{
		cout << "Portfolio MostShares: Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioFindByName
//
// Purpose: Provides unit testing for Stock class FindByName
//
//****************************************************
void testPortfolioFindByName()
{
	const string testName = "delta";
	Stock a;
	Stock b;
	Stock c;
	Stock d;
	Stock e;
	Stock f;
	Stock s;
	Portfolio p;

	//create test stocks
	a.SetName("alpha");
	b.SetName("beta");
	c.SetName("gamma");
	d.SetName("delta");
	e.SetName("eta");
	f.SetName("theta");

	//set test stocks to p
	p.Initialize();
	p.Set(0, a);
	p.Set(1, b);
	p.Set(2, c);
	p.Set(3, d);
	p.Set(4, e);
	p.Set(5, f);

	//test function
	p.FindByName(testName, s);

	if (p.FindByName(testName, s) == true && s.GetName() == d.GetName())
	{
		cout << "Portfolio FindByName: Pass" << endl;
	}
	else
	{
		cout << "Portfolio FindByName: Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioTotalValue
//
// Purpose: Provides unit testing for Portfolio class TotalValue
//
//****************************************************
void testPortfolioTotalValue()
{
	const double totalValue = 1021;
	Stock a;
	Stock b;
	Stock c;
	Stock d;
	Stock e;
	Stock f;
	Portfolio p;

	//create test stocks
	a.SetPrice(12);
	a.SetShares(6);

	b.SetPrice(24);
	b.SetShares(0);

	c.SetPrice(11);
	c.SetShares(19);

	d.SetPrice(9);
	d.SetShares(31);

	e.SetPrice(13);
	e.SetShares(14);

	f.SetPrice(31);
	f.SetShares(9);

	//set test stocks to p
	p.Initialize();
	p.Set(0, a);
	p.Set(1, b);
	p.Set(2, c);
	p.Set(3, d);
	p.Set(4, e);
	p.Set(5, f);

	//test function
	if (p.TotalValue() == totalValue)
	{
		cout << "Portfolio TotalValue: Pass" << endl;
	}
	else
	{
		cout << "Portfolio TotalValue: Pass" << endl;
	}
}