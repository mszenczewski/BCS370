//****************************************************
// File: stock_stack.h
//
// Purpose: Defines a StockStack class to hold a stack of stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************

#ifndef STOCK_STACK_H
#define STOCK_STACK_H

#include "stock.h"

class StockStack
{
private:
	int top;
	int max;
	Stock *stockArray;
public:
	StockStack();
	StockStack(int max);
	StockStack(const StockStack &rhs);

	~StockStack();

	void Clear();
	int Size();
	int MaxStorage();
	bool Push(Stock s);
	bool Pop();
	bool Top(Stock &returnedStock);

	StockStack &operator=(StockStack& rhs);
	friend std::ostream& operator<<(std::ostream& output, StockStack &rhs);
	friend std::istream& operator>>(std::istream& is, StockStack &input);
};

std::ostream& operator<<(std::ostream& output, StockStack &rhs);
std::istream& operator>>(std::istream& is, StockStack &input);


#endif
