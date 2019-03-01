//****************************************************
// File: portfolio.cpp
//
// Purpose: Defines a Portfolio class to hold an array of stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
// 
//****************************************************

#include "portfolio.h"
#include "stock.h"
#include <iostream>
#include <string>

using namespace std;

//****************************************************
// Function: Portfolio
//
// Purpose: Default constructor
//
//****************************************************
Portfolio::Portfolio()
{
	Initialize();
}

//****************************************************
// Function: Set
//
// Purpose: Puts stock class into the array
//
//****************************************************
void Portfolio::Set(int index, Stock s)
{
	if (index >= 0 && index < Size())
	{
		stockArray[index] = s;
	}
	else
	{
		cout << "invalid index";
	}
}

//****************************************************
// Function: Get
//
// Purpose: Returns stock class from given index
//
//****************************************************
Stock Portfolio::Get(int index)
{
	return stockArray[index];
}

//****************************************************
// Function: PriceRangeCount
//
// Purpose: Returns amount of stocks whose price is within given bounds
//
//****************************************************
int Portfolio::PriceRangeCount(double lowerBound, double upperBound)
{
	int count = 0;

	//traverse array
	for (int i = 0; i < Size(); i++)
	{
		//if value is in range, add to count
		if (stockArray[i].GetPrice() >= lowerBound && stockArray[i].GetPrice() <= upperBound)
		{
			count++;
		}
	}
	return count;
}

//****************************************************
// Function: MostShares
//
// Purpose: Returns stock class with the most shares
//
//****************************************************
Stock Portfolio::MostShares()
{
	Stock most("error", -1, -1);

	//traverse array
	for (int i = 0; i < Size(); i++)
	{
		//If stock has more shares, replace "most"
		if (stockArray[i].GetShares() > most.GetShares())
		{
			most = stockArray[i];
		}
	}
	return most;
}

//****************************************************
// Function: FindByName
//
// Purpose: Determines if given stock name is within the array
//
//****************************************************
bool Portfolio::FindByName(string name, Stock & v)
{
	//traverse array
	for (int i = 0; i < Size(); i++)
	{
		//check if stock is in array
		if (stockArray[i].GetName() == name)
		{
			v = stockArray[i];
			return true;
		}
	}
	return false;
}

//****************************************************
// Function: TotalValue
//
// Purpose: Returns the total value of all stock in the array
//
//****************************************************
double Portfolio::TotalValue()
{
	double total = 0;

	//traverse array
	for (int i = 0; i < Size(); i++)
	{
		total += stockArray[i].CalculateValue();
	}

	return total;
}

//****************************************************
// Function: Size
//
// Purpose: Returns the size of the array
//
//****************************************************
int Portfolio::Size()
{
	return 10;
}

//****************************************************
// Function: Initialize
//
// Purpose: Initializes all members of the array to defaults
//
//****************************************************
void Portfolio::Initialize()
{
	//create each element of the array
	for (int i = 0; i < Size(); i++)
	{
		stockArray[i] = Stock("", 0, 0);
	}
}

//****************************************************
// Function: GetAuthor
//
// Purpose: Returns name of the author
//
//****************************************************
std::string Portfolio::GetAuthor()
{
	return "Michael Szenczewski";
}
