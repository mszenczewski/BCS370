//****************************************************
// File: test_portfolio.cpp
//
// Purpose: Provides unit testing for Portfolio class 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
// 
//****************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "stock.h"
#include "portfolio.h"
#include "test_portfolio.h"

using namespace std;

const int column_width = 44;

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
		cout << setw(column_width) << left << "Portfolio Set/Get" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Set/Get" << right << "Fail" << endl;
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
		cout << setw(column_width) << left << "Portfolio PriceRangeCount" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio PriceRangeCount" << right << "Fail" << endl;
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
		cout << setw(column_width) << left << "Portfolio MostShares" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio MostShares" << right << "Fail" << endl;
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
		cout << setw(column_width) << left << "Portfolio FindByName" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio FindByName" << right << "Fail" << endl;
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
		cout << setw(column_width) << left << "Portfolio TotalValue" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio TotalValue" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioSize
//
// Purpose: Provides unit testing for Portfolio class Size
//
//****************************************************
void testPortfolioSize()
{
	Portfolio p;

	if (p.Size() == 10)
	{
		cout << setw(column_width) << left << "Portfolio Size" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Size" << right << "Fail" << endl;
	}

}

//****************************************************
// Function: testPortfolioConstructorDefault
//
// Purpose: Provides unit testing for Portfolio default constructor 
//
//****************************************************
void testPortfolioConstructorDefault()
{
	bool passed = true;
	Portfolio p;

	for (int i = 0; i < p.Size(); i++)
	{
		if (p.Size() != 10 ||
			p.Get(i).GetName() != "" ||
			p.Get(i).GetPrice() != 0 ||
			p.Get(i).GetShares() != 0
			)
		{
			bool passed = false;
		}
	}

	if (passed)
	{
		cout << setw(column_width) << left << "Portfolio Default Constructor" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Default Constructor" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioInitialize
//
// Purpose: Provides unit testing for Portfolio class Initialize 
//
//****************************************************
void testPortfolioInitialize()
{
	bool passed = true;
	Portfolio p;

	//create test data
	Stock s("test", 43, 3);
	Stock s2("test2", 12, 34);

	p.Set(0, s);
	p.Set(1, s2);

	//test function
	for (int i = 0; i < p.Size(); i++)
	{
		if (p.Get(i).GetName() != "" ||
			p.Get(i).GetPrice() != 0 ||
			p.Get(i).GetShares() != 0
			)
		{
			bool passed = false;
		}
	}

	if (passed)
	{
		cout << setw(column_width) << left << "Portfolio Initialize" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Initialize" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioConstructorParameters
//
// Purpose: Provides unit testing for Portfolio constructor which takes parameters
//
//****************************************************
void testPortfolioConstructorParameters()
{
	const int testSize = 12;

	//create test data
	Portfolio p(testSize);

	//test function
	if (p.Size() == testSize)
	{
		cout << setw(column_width) << left << "Portfolio Parameterized Constructor" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Parameterized Constructor" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioConstructorCopy
//
// Purpose: Provides unit testing for Portfolio copy constructor 
//
//****************************************************
void testPortfolioConstructorCopy()
{
	const string testName[] = { "Alpha", "Beta", "Gamma" };
	const double testPrice[] = { 14, 37.4, 99 };
	const double testShares[] = { 7, 88, 36 };

	bool passed = true;

	//create test data
	Stock s0(testName[0], testPrice[0], testShares[0]);
	Stock s1(testName[1], testPrice[1], testShares[1]);
	Stock s2(testName[2], testPrice[2], testShares[2]);

	Portfolio p;

	p.Set(0, s0);
	p.Set(1, s1);
	p.Set(2, s2);

	Portfolio p2(p);

	//test function
	for (int i = 0; i < 3; i++)
	{
		if (p2.Get(i).GetName() != testName[i] ||
			p2.Get(i).GetPrice() != testPrice[i] ||
			p2.Get(i).GetShares() != testShares[i])
		{
			passed = false;
		}
	}

	if (passed)
	{
		cout << setw(column_width) << left << "Portfolio Copy Constructor" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Copy Constructor" << right << "Fail" << endl;
	}
	
}

//****************************************************
// Function: testPortfolioOperatorAssignment
//
// Purpose: Provides unit testing for Portfolio assignment operator overload 
//
//****************************************************
void testPortfolioOperatorAssignment()
{
	const string testName[] = { "Alpha", "Beta", "Gamma" };
	const double testPrice[] = { 14, 37.4, 99 };
	const double testShares[] = { 7, 88, 36 };

	bool passed = true;

	//create test data
	Stock s0(testName[0], testPrice[0], testShares[0]);
	Stock s1(testName[1], testPrice[1], testShares[1]);
	Stock s2(testName[2], testPrice[2], testShares[2]);

	Portfolio p;
	Portfolio p2;

	p.Set(0, s0);
	p.Set(1, s1);
	p.Set(2, s2);

	//test function
	p2 = p;

	//verify new array has data
	for (int i = 0; i < 3; i++)
	{
		if (p2.Get(i).GetName() != testName[i] ||
			p2.Get(i).GetPrice() != testPrice[i] ||
			p2.Get(i).GetShares() != testShares[i])
		{
			passed = false;
		}
	}

	//verify old array retained data
	for (int i = 0; i < 3; i++)
	{
		if (p.Get(i).GetName() != testName[i] ||
			p.Get(i).GetPrice() != testPrice[i] ||
			p.Get(i).GetShares() != testShares[i])
		{
			passed = false;
		}
	}

	if (passed)
	{
		cout << setw(column_width) << left << "Portfolio Assignment Overload" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Assignment Overload" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioOperatorAssignment
//
// Purpose: Provides unit testing for Portfolio insertion and extraction operator overload 
//
//****************************************************
void testPortfolioOperatorInsertionExtraction()
{
	bool passed = true;

	Stock testStock[] = 
	{ 
		Stock("Apple", 12.3, 4), 
		Stock("Microsoft", 4, 16),
		Stock("Google", 7.4, 11)
	};

	ofstream outputFile;
	ifstream inputFile;

	outputFile.open("test_portfolio.txt");
	inputFile.open("test_portfolio.txt");

	//create test data
	Portfolio p;

	for (int i = 0; i < 3; i++)
	{
		p.Set(i, testStock[i]);
	}	
	
	//write data to file
	outputFile << p;

	//input data from file
	inputFile >> p;

	inputFile.close();
	outputFile.close();

	//verify results
	for (int i = 0; i < 3; i++)
	{
		if (p.Get(i).GetName() != testStock[i].GetName() ||
			p.Get(i).GetPrice() != testStock[i].GetPrice() ||
			p.Get(i).GetShares() != testStock[i].GetShares())
		{
			passed = false;
		}
	}

	//print results
	if (passed)
	{
		cout << setw(column_width) << left << "Portfolio Insertion/Extraction Overload" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Insertion/Extraction Overload" << right << "Fail" << endl;
	}

}

//****************************************************
// Function: testPortfolioResizeGrow
//
// Purpose: Provides unit testing for Portfolio class Resize when new array is larger
//
//****************************************************
void testPortfolioResizeGrow()
{
	const int testOldSize = 3;
	const int testNewSize = 5;
	int end;
	bool passed = true;

	//create test data
	Stock testStock[] =
	{
		Stock("Apple", 12.3, 4),
		Stock("Microsoft", 4, 16),
		Stock("Google", 7.4, 11)
	};

	Portfolio p(testOldSize);

	for (int i = 0; i < 3; i++)
	{
		p.Set(i, testStock[i]);
	}

	//test function
	p.Resize(testNewSize);

	//set loop end to lower index
	if (testNewSize < testOldSize)
	{
		end = testNewSize;
	}
	else
	{
		end = testOldSize;
	}

	//verify results
	for (int i = 0; i < end; i++)
	{
		if (p.Get(i).GetName() != testStock[i].GetName() ||
			p.Get(i).GetPrice() != testStock[i].GetPrice() ||
			p.Get(i).GetShares() != testStock[i].GetShares() ||
			p.Size() != testNewSize
			)
		{
			passed = false;
		}
	}

	//print results
	if (passed)
	{
		cout << setw(column_width) << left << "Portfolio Resize (Grow)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Resize (Grow)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioResizeShrink
//
// Purpose: Provides unit testing for Portfolio class Resize when new array is smaller
//
//****************************************************
void testPortfolioResizeShrink()
{
	const int testOldSize = 3;
	const int testNewSize = 2;
	int end;
	bool passed = true;

	//create test data
	Stock testStock[] =
	{
		Stock("Apple", 12.3, 4),
		Stock("Microsoft", 4, 16),
		Stock("Google", 7.4, 11)
	};

	Portfolio p(testOldSize);

	for (int i = 0; i < 3; i++)
	{
		p.Set(i, testStock[i]);
	}

	//test function
	p.Resize(testNewSize);

	//set loop end to lower index
	if (testNewSize < testOldSize)
	{
		end = testNewSize;
	}
	else
	{
		end = testOldSize;
	}

	//verify results
	for (int i = 0; i < end; i++)
	{
		if (p.Get(i).GetName() != testStock[i].GetName() ||
			p.Get(i).GetPrice() != testStock[i].GetPrice() ||
			p.Get(i).GetShares() != testStock[i].GetShares() ||
			p.Size() != testNewSize
			)
		{
			passed = false;
		}
	}

	//print results
	if (passed)
	{
		cout << setw(column_width) << left << "Portfolio Resize (Shrink)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Resize (Shrink)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioResizeSame
//
// Purpose: Provides unit testing for Portfolio class Resize when new array is smaller
//
//****************************************************
void testPortfolioResizeSame()
{
	const int testOldSize = 3;
	const int testNewSize = 3;
	int end;
	bool passed = true;

	//create test data
	Stock testStock[] =
	{
		Stock("Apple", 12.3, 4),
		Stock("Microsoft", 4, 16),
		Stock("Google", 7.4, 11)
	};

	Portfolio p(testOldSize);

	for (int i = 0; i < 3; i++)
	{
		p.Set(i, testStock[i]);
	}

	//test function
	p.Resize(testNewSize);

	//set loop end to lower index
	if (testNewSize < testOldSize)
	{
		end = testNewSize;
	}
	else
	{
		end = testOldSize;
	}

	//verify results
	for (int i = 0; i < end; i++)
	{
		if (p.Get(i).GetName() != testStock[i].GetName() ||
			p.Get(i).GetPrice() != testStock[i].GetPrice() ||
			p.Get(i).GetShares() != testStock[i].GetShares() ||
			p.Size() != testNewSize
			)
		{
			passed = false;
		}
	}

	//print results
	if (passed)
	{
		cout << setw(column_width) << left << "Portfolio Resize (Same)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Resize (Same)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testPortfolioClone
//
// Purpose: Provides unit testing for Portfolio class Clone
//
//****************************************************
void testPortfolioClone()
{
	bool passed = true;

	Stock testStock[] =
	{
		Stock("Apple", 12.3, 4),
		Stock("Microsoft", 4, 16),
		Stock("Google", 7.4, 11)
	};

	Portfolio p;
	Portfolio *testP;

	//create test data
	for (int i = 0; i < 3; i++)
	{
		p.Set(i, testStock[i]);
	}

	//test function
	testP = p.Clone();


	//verify results
	for (int i = 0; i < 3; i++)
	{
		if (testP->Get(i).GetName() != testStock[i].GetName() ||
			testP->Get(i).GetPrice() != testStock[i].GetPrice() ||
			testP->Get(i).GetShares() != testStock[i].GetShares() )
		{
			passed = false;
		}
	}

	delete testP; //memory leak without this

	//print results
	if (passed)
	{
		cout << setw(column_width) << left << "Portfolio Clone" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Portfolio Clone" << right << "Fail" << endl;
	}
}