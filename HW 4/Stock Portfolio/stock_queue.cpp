//****************************************************
// File: stock_queue.cpp
//
// Purpose: Defines a StockQueue class to hold a queue of stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************

#include "stock_queue.h"

using namespace std;

//****************************************************
// Function: StockQueue
//
// Purpose: default constructor
//
// Runtime: O(1)
//
//****************************************************
StockQueue::StockQueue()
{
	front = NULL;
	rear = NULL;
	size = 0;
}

//****************************************************
// Function: StockQueue
//
// Purpose: copy constructor
//
// Runtime: O(n)
//
//****************************************************
StockQueue::StockQueue(const StockQueue &rhs)
{
	Clear();
	size = rhs.size;

	NodeStock *location = rhs.front;
	NodeStock *temp;

	temp = new NodeStock;
	temp->stock = rhs.front->stock;
	front = temp;
	rear = temp;
	location = location->next;

	while (location != NULL)
	{
		temp = new NodeStock;
		temp->stock = location->stock;
		rear->next = temp;

		rear = temp;

		location = location->next;
	}

	rear->next = NULL;
}

//****************************************************
// Function: ~StockQueue
//
// Purpose: destructor
//
// Runtime: O(n)
//
//****************************************************
StockQueue::~StockQueue()
{
	Clear();
}

//****************************************************
// Function: Clear
//
// Purpose: empty queue
//
// Runtime: O(n)
//
//****************************************************
void StockQueue::Clear()
{
	NodeStock *temp;

	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}

	rear = NULL;

	size = 0;
}

//****************************************************
// Function: Size
//
// Purpose: returns size of queue
//
// Runtime: O(1)
//
//****************************************************
int StockQueue::Size()
{
	return size;
}

//****************************************************
// Function: Enqueue
//
// Purpose: adds stock to queue
//
// Runtime: O(1)
//
//****************************************************
void StockQueue::Enqueue(Stock s)
{
	NodeStock *temp = new NodeStock;
	
	temp->stock = s;
	temp->next = NULL;

	if (rear == NULL)
	{
		front = temp;
	}
	else
	{
		rear->next = temp;
	}

	rear = temp;

	size++;
}

//****************************************************
// Function: Dequeue
//
// Purpose: Removes stock from queue
//
// Runtime: O(1)
//
//****************************************************
bool StockQueue::Dequeue(Stock &returnedStock)
{
	if (front == NULL)
	{
		return false;
	}
	else
	{
		returnedStock = front->stock;

		NodeStock *temp;

		temp = front;

		front = front->next;

		delete temp;

		size--;

		return true;
	}
}

//****************************************************
// Function: operator=
//
// Purpose: overload assignment operator
//
// Runtime: O(n)
//
//****************************************************
StockQueue &StockQueue::operator=(const StockQueue &rhs)
{
	Clear();
	size = rhs.size;

	NodeStock *location = rhs.front;
	NodeStock *temp;

	temp = new NodeStock;
	temp->stock = rhs.front->stock;
	front = temp;
	rear = temp;
	location = location->next;

	while (location != NULL)
	{
		temp = new NodeStock;
		temp->stock = location->stock;
		rear->next = temp;

		rear = temp;

		location = location->next;
	}

	rear->next = NULL;

	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: overload insertion operator
//
// Runtime: O(n)
//
//****************************************************
std::ostream &operator<<(std::ostream &output, StockQueue &rhs)
{
	output << rhs.size << endl;

	StockQueue::NodeStock *location = rhs.front;

	while (location != NULL)
	{
		output << location->stock;
		location = location->next;
	}
	
	return output;
}

//****************************************************
// Function: operator>>
//
// Purpose: overload extraction operator 
//
// Runtime: O(n)
//
//****************************************************
std::istream& operator>>(std::istream& is, StockQueue &input)
{
	Stock s;
	int numRecords;

	input.Clear();

	is >> numRecords;

	for (int i = 0; i < numRecords; i++)
	{
		is >> s;
		input.Enqueue(s);
	}

	return is;
}
