//****************************************************
// File: stock.cpp
//
// Purpose: Defines a Stock class to hold stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
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
//****************************************************
Stock::Stock()
{
	name = "no name";
	price = 0;
	shares = 0;
}

//****************************************************
// Function: Stock
//
// Purpose: Constructor with input data to initialize
//
//****************************************************
Stock::Stock(std::string name, double price, double shares)
{
	this->name = name;
	this->price = price;
	this->shares = shares;
}

//****************************************************
// Function: Stock
//
// Purpose: Copy constructor
//
//****************************************************
Stock::Stock(const Stock &rhs)
{
	name = rhs.name;
	price = rhs.price;
	shares = rhs.shares;
}

//****************************************************
// Function: SetName
//
// Purpose: Setter for name
//
//****************************************************
void Stock::SetName(std::string name)
{
	this->name = name;
}

//****************************************************
// Function: SetPrice
//
// Purpose: Setter for price
//
//****************************************************
void Stock::SetPrice(double price)
{
	this->price = price;
}

//****************************************************
// Function: SetShares
//
// Purpose: Setter for shares
//
//****************************************************
void Stock::SetShares(double shares)
{
	this->shares = shares;
}

//****************************************************
// Function: GetName
//
// Purpose: Getter for name
//
//****************************************************
std::string Stock::GetName()
{
	return name;
}

//****************************************************
// Function: GetPrice
//
// Purpose: Getter for price
//
//****************************************************
double Stock::GetPrice()
{
	return price;
}

//****************************************************
// Function: GetShares
//
// Purpose: Getter for shares
//
//****************************************************
double Stock::GetShares()
{
	return shares;
}

//****************************************************
// Function: CalculateValue
//
// Purpose: Returns the total value of the stock
//
//****************************************************
double Stock::CalculateValue()
{
	return price * shares;
}

//****************************************************
// Function: operator=
//
// Purpose: Overloading = operator to copy data
//
//****************************************************
Stock& Stock::operator=(const Stock& rhs)
{
	name = rhs.name;
	price = rhs.price;
	shares = rhs.shares;

	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: Overloading << operator to print data
//
//****************************************************
std::ostream& operator<<(std::ostream& output, Stock &rhs)
{
	output <<
		"Name: " << rhs.name << endl <<
		"Price: " << rhs.price << endl <<
		"Shares: " << rhs.shares << endl;

	return output;
}
