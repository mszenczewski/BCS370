//****************************************************
// File: portfolio.h
//
// Purpose: Defines a Portfolio class to hold an array of stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
// 
//****************************************************

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "stock.h"
#include <iostream>
#include <string>

class Portfolio 
{
private:
	Stock stockArray[10];
public:
	//Constructor
	Portfolio();

	//Setter
	void Set(int index, Stock s);

	//Getter
	Stock Get(int index);

	//Functions
	void Initialize();
	int PriceRangeCount(double lowerBound, double upperBound);
	int Size();
	double TotalValue();
	bool FindByName(std::string name, Stock &v);
	std::string GetAuthor();
	Stock MostShares();
};

#endif