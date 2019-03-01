//****************************************************
// File: portfolio.cpp
//
// Purpose: Defines a Portfolio class to hold an array of stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
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
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use dynamic array
//
//****************************************************
Portfolio::Portfolio()
{
	size = 10;

	stockArray = new Stock[size];

	Initialize();
}

//****************************************************
// Function: Portfolio
//
// Purpose: Constructor which takes one parameter
//
//****************************************************
Portfolio::Portfolio(int size)
{
	this->size = size;

	stockArray = new Stock[size];

	Initialize();
}

//****************************************************
// Function: Portfolio
//
// Purpose: Copy constructor 
//
//****************************************************
Portfolio::Portfolio(const Portfolio &rhs)
{
	size = rhs.size;

	stockArray = new Stock[size];

	for (int i = 0; i < size; i++)
	{
		stockArray[i] = rhs.stockArray[i];
	}
}

//****************************************************
// Function: ~Portfolio
//
// Purpose: Destructor
//
//****************************************************

Portfolio::~Portfolio()
{
	delete[] stockArray;
}

//****************************************************
// Function: Set
//
// Purpose: Puts stock class into the array
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use dynamic array
//
//****************************************************
void Portfolio::Set(int index, Stock s)
{
	if (index >= 0 && index < size)
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
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use dynamic array
//
//****************************************************
int Portfolio::PriceRangeCount(double lowerBound, double upperBound)
{
	int count = 0;

	//traverse array
	for (int i = 0; i < size; i++)
	{
		//if value is in range, add to count
		if (stockArray[i].GetPrice() >= lowerBound && 
			stockArray[i].GetPrice() <= upperBound)
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
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use dynamic array
//
//****************************************************
Stock Portfolio::MostShares()
{
	Stock most("error", -1, -1);

	//traverse array
	for (int i = 0; i < size; i++)
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
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use dynamic array
//
//****************************************************
bool Portfolio::FindByName(string name, Stock & v)
{
	//traverse array
	for (int i = 0; i < size; i++)
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
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use dynamic array
//
//****************************************************
double Portfolio::TotalValue()
{
	double total = 0;

	//traverse array
	for (int i = 0; i < size; i++)
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
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use dynamic array
//
//****************************************************
int Portfolio::Size()
{
	return size;
}

//****************************************************
// Function: Initialize
//
// Purpose: Initializes all members of the array to defaults
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use dynamic array
//
//****************************************************
void Portfolio::Initialize()
{
	//create each element of the array
	for (int i = 0; i < size; i++)
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


//****************************************************
// Function: operator=
//
// Purpose: Overload of assignment operator
//
//****************************************************
Portfolio& Portfolio::operator=(const Portfolio &rhs)
{
	//release old array
	delete[] stockArray;
	stockArray = NULL;

	size = rhs.size;

	//create new array
	stockArray = new Stock[size];

	//populate array
	for (int i = 0; i < size; i++)
	{
		stockArray[i] = rhs.stockArray[i];
	}

	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: Overloading << operator to print data
//
//****************************************************
std::ostream& operator<<(std::ostream& output, Portfolio &rhs)
{
	for (int i = 0; i < rhs.size; i++)
	{
		output <<
			rhs.Get(i).GetName() << endl <<
			rhs.Get(i).GetPrice() << endl <<
			rhs.Get(i).GetShares() << endl;
	}

	return output;
}

//****************************************************
// Function: operator>>
//
// Purpose: Overloading >> operator to input data
//
//****************************************************
std::istream& operator >> (std::istream& is, Portfolio &input)
{
	for (int i = 0; i < input.size; i++)
	{
		is >> input.Get(i);
	}

	return is;
}

//****************************************************
// Function: Resize
//
// Purpose: Resizes existing array while maintaining data. If the new size is smaller, data will be lost.
//
//****************************************************
void Portfolio::Resize(int newSize)
{
	if (size == newSize)
	{
		//array does not need resizing
	}
	else
	{
		const int oldSize = size;
		int end;

		//create holding tank
		Stock *tempArray = new Stock[oldSize];

		//copy existing data to holding tank
		for (int i = 0; i < oldSize; i++)
		{
			tempArray[i] = stockArray[i];
		}

		//release old array
		delete[] stockArray;
		stockArray = NULL;

		//create new array
		size = newSize;
		stockArray = new Stock[size];

		//set loop end to lower index
		if (newSize < oldSize)
		{
			end = newSize;
		}
		else
		{
			end = oldSize;
		}

		//copy old data into new array
		for (int i = 0; i < end; i++)
		{
			stockArray[i] = tempArray[i];
		}

		//release holding tank
		delete[] tempArray;
	}	
}

//****************************************************
// Function: Clone
//
// Purpose: Creates a new dynamic instance of Portfolio, copies the data in, and returns the address
//
//****************************************************
Portfolio* Portfolio::Clone()
{
	return new Portfolio(*this);

	/*
	Portfolio *p;

	//create new class
	p = new Portfolio(size);

	//copy data
	*p = *this;

	return p;
	*/
}