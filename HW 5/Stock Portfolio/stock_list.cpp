//****************************************************
// File: stock_list.cpp
//
// Purpose: Defines a StockList class to hold linked list of Stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************
#include "stock_list.h"

using namespace std;

//****************************************************
// Function: StockList
//
// Purpose: Default constructor
//
// Runtime: O(1)
//
//****************************************************
StockList::StockList()
{
	length = 0;
	list = NULL;
}

//****************************************************
// Function: StockList
//
// Purpose: Constructor which takes one parameter
//
// Runtime: O(n)
//
//****************************************************
StockList::StockList(const StockList &otherList)
{
	StockListNode *location;

	location = otherList.list;

	//if otherList is empty
	if (location == NULL)
	{
		list = NULL;
		length = 0;
	}
	else
	{
		//add data
		while (location != NULL)
		{
			Add(location->stock);
			location = location->next;
		}

		length = otherList.length;
	}
}

//****************************************************
// Function: ~StockList
//
// Purpose: Destructor
//
// Runtime: O(n)
//
//****************************************************
StockList::~StockList()
{
	Clear();
}

//****************************************************
// Function: Clear
//
// Purpose: Deletes all members of the list
//
// Runtime: O(n)
//
//****************************************************
void StockList::Clear()
{
	StockListNode *temp;

	for (int i = 0; i < length; i++)
	{
		temp = list;
		list = list->next;
		delete temp;
	}
	
	length = 0;
	list = NULL;
}

//****************************************************
// Function: Length
//
// Purpose: Returns the size of the list
//
// Runtime: O(1)
//
//****************************************************
int StockList::Length()
{
	return length;
}

//****************************************************
// Function: Add
//
// Purpose: Inserts item into the list
//
// Runtime: O(1)
//
//****************************************************
void StockList::Add(const Stock s)
{
	StockListNode *temp;

	//create new node
	temp = new StockListNode;

	//put data in node
	temp->stock = s;
	temp->next = list;

	//move list pointer
	list = temp;

	length++;
}

//****************************************************
// Function: FindByName
//
// Purpose: Finds if item is in list and returns true/false. If found, passes data into Stock object
//
// Runtime: O(n)
//
//****************************************************
bool StockList::FindByName(std::string name, Stock &result) const
{
	if (length == 0)
	{
		return false;
	}

	StockListNode *location = list;
	
	//find item
	while (location->stock.GetName() != name && location->next != NULL)
	{
		location = location->next;
	}

	if (location->next == NULL && location->stock.GetName() != name)
	{
		return false;
	}
	else 
	{
		result = location->stock;
		return true;
	}
}

//****************************************************
// Function: Delete
//
// Purpose: Removes item from list
//
// Runtime: O(n)
//
//****************************************************
void StockList::Delete(std::string name)
{
	StockListNode *location = list;
	StockListNode *temp;

	//if at start of list
	if (location->stock.GetName() == name)
	{
		//save address for cleanup
		temp = list;

		//logically remove item
		list = list->next;
	}
	else
	{
		//find item
		while (location->next->stock.GetName() != name && location->next != NULL)
		{
			location = location->next;
		}

		//save address for cleanup
		temp = location->next;

		//logically remove item
		location->next = (location->next)->next;
	}

	//release item
	delete temp;

	length--;
}

//****************************************************
// Function: Add
//
// Purpose: Adds item from one list into another
//
// Runtime: O(n)
//
//****************************************************
void StockList::Add(const StockList &otherList)
{
	StockListNode *location;

	location = otherList.list;

	while (location != NULL)
	{
		Add(location->stock);
		location = location->next;
	}
}

//****************************************************
// Function: operator=
//
// Purpose: Overloads assignment operator
//
// Runtime: O(n)
//
//****************************************************
StockList &StockList::operator=(const StockList &rhs)
{
	StockListNode *location;

	Clear();

	location = rhs.list;

	while (location != NULL)
	{
		Add(location->stock);
		location = location->next;
	}

	length = rhs.length;

	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: Overloads insertion operator
//
// Runtime: O(n)
//
//****************************************************
std::ostream &operator<<(std::ostream &os, StockList &rhs)
{
	StockList::StockListNode *temp = rhs.list;

	while (temp != NULL)
	{
		os << temp->stock;
		temp = temp->next;
	}

	return os;
}

//****************************************************
// Function: operator>>
//
// Purpose: Overloads extraction operator
//
// Runtime: O(n)
//
//****************************************************
std::istream &operator>>(std::istream &is, StockList &rhs)
{
	while (true)
	{
		string name;
		double price;
		double shares;

		is >> name;

		//exit if blank line is found
		if (name == "")
		{
			break;
		}

		is >> price;
		is >> shares;

		Stock s(name, price, shares);

		rhs.Add(s);
	}
	
	return is;
}

//****************************************************
// Function: operator==
//
// Purpose: Overloads equality operator
//
// Runtime: O(n)
//
//****************************************************
bool operator==(const StockList &lhs, const StockList &rhs)
{
	int errors = 0;
	StockList::StockListNode *lhsPtr;
	StockList::StockListNode *rhsPtr;

	lhsPtr = lhs.list;
	rhsPtr = rhs.list;

	while (lhsPtr != NULL && rhsPtr != NULL)
	{
		if (lhs.list->stock != rhs.list->stock)
		{
			errors++;
		}

		lhsPtr = lhsPtr->next;
		rhsPtr = rhsPtr->next;
	}

	if (errors == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

