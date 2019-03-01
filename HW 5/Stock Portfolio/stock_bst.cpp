//****************************************************
// File: stock_bst.cpp
//
// Purpose: Defines a binary search tree of Stock data
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************

#include "stock_bst.h"

using namespace std;

//****************************************************
// Function: StockBST
//
// Purpose: Default constructor
//
// Runtime: O(1)
//
//****************************************************
StockBST::StockBST()
{
	root = NULL;
}

//****************************************************
// Function: StockBST
//
// Purpose: Copy constructor
//
// Runtime: O(n)
//
//****************************************************
StockBST::StockBST(const StockBST &rhs)
{
	Copy(root, rhs.root);
}

//****************************************************
// Function: ~StockBST
//
// Purpose: destructor
//
// Runtime: O(n)
//
//****************************************************
StockBST::~StockBST()
{
	Clear();
}

//****************************************************
// Function: Clear
//
// Purpose: Empties the tree
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Clear()
{
	Clear(root);
	root = NULL;
}

//****************************************************
// Function: Add
//
// Purpose: inserts Stock into the tree
//
// Runtime: O(log n)
//
//****************************************************
void StockBST::Add(Stock s)
{
	Add(s, root);
}

//****************************************************
// Function: Size
//
// Purpose: returns the size of the tree
//
// Runtime: O(n)
//
//****************************************************
int StockBST::Size()
{
	return Size(root);
}

//****************************************************
// Function: Preorder
//
// Purpose: Prints tree using preorder traversal
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Preorder()
{
	Preorder(root);
}

//****************************************************
// Function: Inorder
//
// Purpose: Prints tree using inorder traversal
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Inorder()
{
	Inorder(root);
}

//****************************************************
// Function: Postorder
//
// Purpose: Prints tree using postorder traversal
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Postorder()
{
	Postorder(root);
}

//****************************************************
// Function: GetShares
//
// Purpose: Finds and returns shares of a given stock
//
// Runtime: O(log n)
//
//****************************************************
bool StockBST::GetShares(std::string name, double &shares)
{
	return GetShares(root, name, shares);
}

//****************************************************
// Function: GetShares
//
// Purpose: Finds and returns shares of a given stock
//
// Runtime: O(log n)
//
//****************************************************
bool StockBST::GetShares(StockBSTNode* tree, std::string name, double &shares) const
{
	if (tree == NULL)
	{
		return false;
	}
	else if (tree->stock.GetName() == name)
	{
		shares = tree->stock.GetShares();
		return true;
	}
	else if (name < tree->stock.GetName())
	{
		return GetShares(tree->left, name, shares);
	}
	else if (name > tree->stock.GetName())
	{
		return GetShares(tree->right, name, shares);
	}
}

//****************************************************
// Function: Copy
//
// Purpose: Copies one tree into another
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Copy(StockBSTNode* &copy, const StockBSTNode* original)
{
	if (original == NULL)
	{
		copy = NULL;
	}
	else
	{
		copy = new StockBSTNode;
		copy->stock = original->stock;
		Copy(copy->left, original->left);
		Copy(copy->right, original->right);
	}
}

//****************************************************
// Function: Add
//
// Purpose: Inserts new item into the tree
//
// Runtime: O(log n)
//
//****************************************************
void StockBST::Add(Stock s, StockBSTNode* &tree)
{
	if (tree == NULL)
	{
		tree = new StockBSTNode;
		tree->stock = s;
		tree->right = NULL;
		tree->left = NULL;
	}
	else
	{
		if (s < tree->stock)
		{
			Add(s, tree->left);
		}
		if (s > tree->stock)
		{
			Add(s, tree->right);
		}
	}
}

//****************************************************
// Function: Clear
//
// Purpose: Empties the tree
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Clear(StockBSTNode* &tree)
{
	if (tree != NULL)
	{
		Clear(tree->left);
		Clear(tree->right);
		delete tree;
	}
}

//****************************************************
// Function: Size
//
// Purpose: returns the size of the tree
//
// Runtime: O(n)
//
//****************************************************
int StockBST::Size(const StockBSTNode* tree) const
{
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + Size(tree->left) + Size(tree->right);
	}
}

//****************************************************
// Function: Preorder
//
// Purpose: Prints the tree using preorder traversal
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Preorder(StockBSTNode* tree) const
{
	if (tree != NULL)
	{
		cout << tree->stock.GetName() << endl;
		Preorder(tree->left);
		Preorder(tree->right);
	}
}

//****************************************************
// Function: Inorder
//
// Purpose: Prints tree using inorder traversal
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Inorder(StockBSTNode* tree) const
{
	if (tree != NULL)
	{
		Inorder(tree->left);
		cout << tree->stock.GetName() << endl;
		Inorder(tree->right);
	}
}

//****************************************************
// Function: Postorder
//
// Purpose: Prints tree using postorder traversal
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Postorder(StockBSTNode* tree) const
{
	if (tree != NULL)
	{
		Postorder(tree->left);
		Postorder(tree->right);
		cout << tree->stock.GetName() << endl;
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
StockBST &StockBST::operator=(const StockBST &rhs)
{
	Copy(root, rhs.root);
	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: overloads insertion operator
//
// Runtime: O(n)
//
//****************************************************
std::ostream &operator<<(std::ostream &os, StockBST::StockBSTNode* tree)
{
	if (tree != NULL)
	{
		&operator<<(os, tree->left);
		os << tree->stock;
		&operator<<(os, tree->right);
	}
	return os;
}

//****************************************************
// Function: operator<<
//
// Purpose: overloads insertion operator
//
// Runtime: O(n)
//
//****************************************************
std::ostream &operator<<(std::ostream &os, StockBST &rhs)
{
	os << rhs.root;
	return os;
}
