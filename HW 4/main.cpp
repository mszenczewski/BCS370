//****************************************************
// File: main.cpp
//
// Purpose: Provides unit testing for StockStack and StockQueue classes
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************

#include <iostream>
#include <iomanip>
#include "stock_stack_test.h"
#include "stock_queue_test.h"

using namespace std;

//****************************************************
// Function: main
//
// Purpose: Provides unit testing for StockStack and StockQueue classes
//
//****************************************************
int main()
{
	cout << setfill('.');

	testStockStackPushTop();
	testStockStackPop();
	testStockStackClear();
	testStockStackMaxStorage();
	testStockStackSize();
	testStockStackConstructorDefault();
	testStockStackConstructorParameter();
	testStockStackConstructorCopy();
	testStockStackOverloadInsertionExtraction();
	testStockStackOverloadAssignment();
	
	testStockQueueEnqueueDequeue();
	testStockQueueSize();
	testStockQueueClear();
	testStockQueueConstructorDefault();
	testStockQueueConstructorCopy();
	testStockQueueOverloadAssignment();
	testStockQueueOverloadInsertionExtraction();

	return 0;
}