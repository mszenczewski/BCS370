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
	int size;
	Stock *stockArray;
public:
	//Constructor
	Portfolio();
	Portfolio(int size);
	Portfolio(const Portfolio &rhs);

	//Destructor
	~Portfolio();

	//Mutators
	void Set(int index, Stock s);

	//Accessors
	Stock Get(int index);

	//Functions
	void Initialize();
	void Resize(int newSize);
	int PriceRangeCount(double lowerBound, double upperBound);
	int Size();
	double TotalValue();
	bool FindByName(std::string name, Stock &v);
	std::string GetAuthor();
	Stock MostShares();
	Portfolio *Clone();


	//Operator overload
	Portfolio& operator=(const Portfolio &rhs);
	friend std::ostream& operator<<(std::ostream& output, Portfolio &rhs);
	friend std::istream& operator>>(std::istream& is, Portfolio &input);

};

std::ostream& operator<<(std::ostream& output, Portfolio &rhs);
std::istream& operator>>(std::istream& is, Portfolio &input);


#endif