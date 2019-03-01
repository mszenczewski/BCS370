//****************************************************
// File: stock_queue.h
//
// Purpose: Defines a StockQueue class to hold a queue of stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************

#ifndef STOCK_QUEUE_H
#define STOCK_QUEUE_H

#include "stock.h"

class StockQueue
{
private:
	struct NodeStock
	{
		Stock stock;
		NodeStock *next;
	};
	NodeStock *front;
	NodeStock *rear;
	int size;
public:
	StockQueue();
	StockQueue(const StockQueue &rhs);

	~StockQueue();

	void Clear();
	int Size();
	void Enqueue(Stock s);
	bool Dequeue(Stock &returnedStock);

	StockQueue &operator=(const StockQueue &rhs);
	friend std::ostream& operator<<(std::ostream& output, StockQueue &rhs);
	friend std::istream& operator>>(std::istream& is, StockQueue &input);
};

std::ostream& operator<<(std::ostream& output, StockQueue &rhs);
std::istream& operator>>(std::istream& is, StockQueue &input);

#endif
