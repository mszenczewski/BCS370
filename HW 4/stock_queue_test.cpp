//****************************************************
// File: stock_queue_test.cpp
//
// Purpose: Provides unit testing for StockQueue class 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************
#include "stock_queue_test.h"
#include "stock_queue.h"
#include "stock.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int column_width = 48;

//****************************************************
// Function: testStockQueueEnqueueDequeue
//
// Purpose: test StockStack class Enqueue and Dequeue
//
//****************************************************
void testStockQueueEnqueueDequeue()
{
	StockQueue queue;
	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);
	Stock s4;
	Stock s5;
	Stock s6;
	Stock x;
	bool testDequeue = false;
	bool testDequeueEmpty = true;

	queue.Enqueue(s1);
	queue.Enqueue(s2);
	queue.Enqueue(s3);

	testDequeue = queue.Dequeue(s4);
	queue.Dequeue(s5);
	queue.Dequeue(s6);

	testDequeueEmpty = queue.Dequeue(x); // empty queue

	if (s1 == s4 &&
		s2 == s5 &&
		s3 == s6 &&
		testDequeue &&
		testDequeueEmpty == false)
	{
		cout << setw(column_width) << left << "Stock Queue Enqueue/Dequeue" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Queue Enqueue/Dequeue" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockQueueSize
//
// Purpose: test StockStack class Size
//
//****************************************************
void testStockQueueSize()
{
	StockQueue queue;

	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);

	queue.Enqueue(s1);
	queue.Enqueue(s2);
	queue.Enqueue(s3);

	if (queue.Size() == 3)
	{
		cout << setw(column_width) << left << "Stock Queue Size" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Queue Size" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockQueueClear
//
// Purpose: test StockStack class Clear
//
//****************************************************
void testStockQueueClear()
{
	StockQueue queue;
	Stock x;
	Stock y;

	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);

	queue.Clear();

	queue.Dequeue(x); 

	if (queue.Size() == 0 && x == y)
	{
		cout << setw(column_width) << left << "Stock Queue Clear" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Queue Clear" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockQueueConstructorDefault
//
// Purpose: test StockStack class default constructor
//
//****************************************************
void testStockQueueConstructorDefault()
{
	StockQueue queue;
	Stock x;
	Stock y;
	bool notEmpty = queue.Dequeue(x);

	if (!notEmpty && x == y)
	{
		cout << setw(column_width) << left << "Stock Queue Constructor (Default)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Queue Constructor (Default)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockQueueConstructorCopy
//
// Purpose: test StockStack class copy constructor
//
//****************************************************
void testStockQueueConstructorCopy()
{
	StockQueue q1;

	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);
	Stock x;
	Stock y;
	int errors = 0;

	q1.Enqueue(s1);
	q1.Enqueue(s2);
	q1.Enqueue(s3);

	StockQueue q2(q1);

	for (int i = 0; i < 3; i++)
	{
		q1.Dequeue(x);
		q2.Dequeue(y);

		if (x != y)
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock Queue Constructor (Copy)" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Queue Constructor (Copy)" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockQueueOverloadAssignment
//
// Purpose: test StockStack class assignment operator overload
//
//****************************************************
void testStockQueueOverloadAssignment()
{
	StockQueue q1;
	StockQueue q2;

	Stock s1("Apple", 11.0, 14);
	Stock s2("Banana", 14.43, 7);
	Stock s3("Orange", 9.6, 2);
	Stock x;
	Stock y;
	int errors = 0;

	q1.Enqueue(s1);
	q1.Enqueue(s2);
	q1.Enqueue(s3);

	q2 = q1;

	for (int i = 0; i < 3; i++)
	{
		q1.Dequeue(x);
		q2.Dequeue(y);

		if (x != y)
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock Queue Overload Assignment" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Queue Overload Assignment" << right << "Fail" << endl;
	}
}

//****************************************************
// Function: testStockQueueOverloadInsertionExtraction
//
// Purpose: test StockStack class overloard of insertion and extraction operators 
//
//****************************************************
void testStockQueueOverloadInsertionExtraction()
{
	string fileName = "stock_queue_test.txt";
	ofstream outputFile;
	ifstream inputFile;
	int errors = 0;

	Stock stockArray[] =
	{
		Stock("Apple", 11.0, 14),
		Stock("Banana", 14.43, 7),
		Stock("Orange", 9.6, 2)
	};
	Stock x;

	StockQueue q;

	for (int i = 0; i < 3; i++)
	{
		q.Enqueue(stockArray[i]);
	}

	inputFile.open(fileName);
	outputFile.open(fileName);

	outputFile << q;
	inputFile >> q;

	for (int i = 0; i < 3; i++)
	{
		q.Dequeue(x);

		if (x != stockArray[i])
		{
			errors++;
		}
	}

	if (errors == 0)
	{
		cout << setw(column_width) << left << "Stock Queue Overload Insertion/Extraction" << right << "Pass" << endl;
	}
	else
	{
		cout << setw(column_width) << left << "Stock Queue Overload Insertion/Extraction" << right << "Fail" << endl;
	}
}