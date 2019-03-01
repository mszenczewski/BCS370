//****************************************************
// File: stock.h
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
//****************************************************

#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>

class Stock
{
private:
	std::string *name;
	double *price;
	double *shares;
public:
	//Constructors
	Stock();
	Stock(std::string name, double price, double shares);
	Stock(const Stock &rhs);

	//Destructor
	~Stock();

	//Mutators
	void SetName(std::string name);
	void SetPrice(double price);
	void SetShares(double shares);

	//Accessors
	std::string GetName();
	double GetPrice();
	double GetShares();

	//Functions
	double CalculateValue();

	//Operator Overload
	Stock& operator=(const Stock& rhs);
	friend std::ostream& operator<<(std::ostream& output, Stock &rhs);
	friend std::istream& operator>>(std::istream& is, Stock &input);
};

std::ostream& operator<<(std::ostream& output, Stock &rhs);
std::istream& operator>>(std::istream& is, Stock &input);


#endif 
