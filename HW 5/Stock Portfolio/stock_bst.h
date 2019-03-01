//****************************************************
// File: stock_bst.h
//
// Purpose: Defines a binary search tree of Stock data 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
//
//****************************************************

#ifndef STOCK_BST_H
#define STOCK_BST_H

#include "stock.h"

class StockBST
{
private:
	struct StockBSTNode
	{
		Stock stock;
		StockBSTNode* left;
		StockBSTNode* right;
	};

	StockBSTNode* root;

	void Add(Stock s, StockBSTNode* &tree);
	void Clear(StockBSTNode* &tree);
	int Size(const StockBSTNode* tree) const;
	void Copy(StockBSTNode* &copy, const StockBSTNode* original);
	void Preorder(StockBSTNode* tree) const;
	void Inorder(StockBSTNode* tree) const;
	void Postorder(StockBSTNode* tree) const;
	bool GetShares(StockBSTNode* tree, std::string name, double &shares) const;

public:
	//constructor
	StockBST();
	StockBST(const StockBST& rhs);

	//destructor
	~StockBST();

	//methods
	void Clear();
	void Add(Stock s);
	int Size();
	void Preorder();
	void Inorder();
	void Postorder();
	bool GetShares(std::string name, double &shares);

	//operator overload
	StockBST& operator=(const StockBST &rhs);
	friend std::ostream &operator<<(std::ostream &os, StockBST &rhs);
	friend std::ostream &operator<<(std::ostream &os, StockBST::StockBSTNode* tree);
};

std::ostream &operator<<(std::ostream &os, StockBST &rhs);
std::ostream &operator<<(std::ostream &os, StockBST::StockBSTNode* tree);

#endif

