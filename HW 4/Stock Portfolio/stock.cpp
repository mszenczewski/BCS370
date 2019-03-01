//****************************************************
// File: stock.cpp
//
// Purpose: Defines a Stock class to hold stock data 
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
// Name: Michael Szenczewski
// Date: 10/29/2017
// Description: Updated to overload comparison operator
// 
//****************************************************

#include "stock.h"
#include <string>
#include <iostream>

using namespace std;

//****************************************************
// Function: Stock
//
// Purpose: Default constructor
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
Stock::Stock()
{
	name = new string;
	price = new double;
	shares = new double;

	*name = "NO_NAME";
	*price = 0;
	*shares = 0;
}

//****************************************************
// Function: Stock
//
// Purpose: Constructor with input data to initialize
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
Stock::Stock(std::string name, double price, double shares)
{
	this->name = new string;
	this->price = new double;
	this->shares = new double;

	*this->name = name;
	*this->price = price;
	*this->shares = shares;
}

//****************************************************
// Function: Stock
//
// Purpose: Copy constructor
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
Stock::Stock(const Stock &rhs)
{
	name = new string;
	price = new double;
	shares = new double;

	*name = *rhs.name;
	*price = *rhs.price;
	*shares = *rhs.shares;
}

//****************************************************
// Function: ~Stock
//
// Purpose: Destructor
//
//****************************************************
Stock::~Stock()
{
	delete name;
	delete price;
	delete shares;
}

//****************************************************
// Function: SetName
//
// Purpose: Setter for name
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
void Stock::SetName(std::string name)
{
	*this->name = name;
}

//****************************************************
// Function: SetPrice
//
// Purpose: Setter for price
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
void Stock::SetPrice(double price)
{
	*this->price = price;
}

//****************************************************
// Function: SetShares
//
// Purpose: Setter for shares
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
void Stock::SetShares(double shares)
{
	*this->shares = shares;
}

//****************************************************
// Function: GetName
//
// Purpose: Getter for name
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
std::string Stock::GetName()
{
	return *name;
}

//****************************************************
// Function: GetPrice
//
// Purpose: Getter for price
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
double Stock::GetPrice()
{
	return *price;
}

//****************************************************
// Function: GetShares
//
// Purpose: Getter for shares
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
double Stock::GetShares()
{
	return *shares;
}

//****************************************************
// Function: CalculateValue
//
// Purpose: Returns the total value of the stock
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
double Stock::CalculateValue()
{
	return *price * *shares;
}

//****************************************************
// Function: operator=
//
// Purpose: Overloading = operator to copy data
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
Stock& Stock::operator=(const Stock& rhs)
{
	*name = *rhs.name;
	*price = *rhs.price;
	*shares = *rhs.shares;

	return *this;
}


//****************************************************
// Function: operator==
//
// Purpose: Overloading comparison operator
//
//****************************************************
bool operator==(const Stock &lhs, const Stock &rhs)
{
	if (*lhs.name == *rhs.name &&
		*lhs.price == *rhs.price &&
		*lhs.shares == *rhs.shares)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//****************************************************
// Function: operator!=
//
// Purpose: Overloading comparison operator
//
//****************************************************
bool operator!=(const Stock &lhs, const Stock &rhs)
{
	if (*lhs.name != *rhs.name ||
		*lhs.price != *rhs.price ||
		*lhs.shares != *rhs.shares)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//****************************************************
// Function: operator<<
//
// Purpose: Overloading << operator to print data
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
std::ostream& operator<<(std::ostream& output, Stock &rhs)
{
	output <<
		*rhs.name << endl <<
		*rhs.price << endl <<
		*rhs.shares << endl;

	return output;
}

//****************************************************
// Function: operator>>
//
// Purpose: Overloading >> operator to input data
//
// Update Information
// ------------------
//
// Name: Michael Szenczewski
// Date: 10/8/2017
// Description: Updated to use pointers
//
//****************************************************
std::istream& operator>>(std::istream& is, Stock &input)
{
	is >>
		*input.name >>
		*input.price >>
		*input.shares;

	return is;
}