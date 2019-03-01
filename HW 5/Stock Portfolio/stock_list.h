//****************************************************
// File: stock_list.h
//
// Purpose: Defines a StockList class to hold linked list of Stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************
#ifndef STOCK_LIST_H
#define STOCK_LIST_H

#include "stock.h"

class StockList
{
private:
	struct StockListNode 
	{
		Stock stock;
		StockListNode *next;
	};
	int length;
	StockListNode *list;
public:
	//constructors
	StockList();
	StockList(const StockList &otherList);

	//destructor
	~StockList();

	//methods
	void Clear();
	int Length();
	void Add(const Stock s);
	void Add(const StockList &otherList);
	bool FindByName(std::string name, Stock &result) const;
	void Delete(std::string name);

	//operator overload
	StockList &operator=(const StockList &rhs);
	friend std::ostream &operator<<(std::ostream &os, StockList &rhs);
	friend std::istream &operator>>(std::istream &is, StockList &rhs);
	friend bool operator==(const StockList &lhs, const StockList &rhs);
};

std::ostream &operator<<(std::ostream &os, StockList &rhs);
std::istream &operator>>(std::istream &is, StockList &rhs);
bool operator==(const StockList &lhs, const StockList &rhs);

#endif 
