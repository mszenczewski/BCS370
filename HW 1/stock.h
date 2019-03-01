//****************************************************
// File: stock.h
//
// Purpose: Defines a Stock class to hold stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
// 
//****************************************************

#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>

class Stock
{
private:
	std::string name;
	double price;
	double shares;
public:
	//Constructors
	Stock();
	Stock(std::string name, double price, double shares);
	Stock(const Stock &rhs);

	//Setters
	void SetName(std::string name);
	void SetPrice(double price);
	void SetShares(double shares);

	//Getters
	std::string GetName();
	double GetPrice();
	double GetShares();

	//Functions
	double CalculateValue();

	//Operator Overload
	Stock& operator=(const Stock& rhs);
	friend std::ostream& operator<<(std::ostream& output, Stock &rhs);
};

std::ostream& operator<<(std::ostream& output, Stock &rhs);

#endif 
