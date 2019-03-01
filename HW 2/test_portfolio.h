//****************************************************
// File: test_portfolio.h
//
// Purpose: Provides unit testing for Portfolio class 
//
// Written By: Michael Szenczewski
//
// Compiler: Visual C++ 2015
// 
//****************************************************

#ifndef TEST_PORTFOLIO_H
#define TEST_PORTFOLIO_H

void testPortfolioSetGet();
void testPortfolioSize();
void testPortfolioInitialize();
void testPortfolioConstructorDefault();
void testPortfolioConstructorParameters();
void testPortfolioConstructorCopy();
void testPortfolioOperatorAssignment();
void testPortfolioOperatorInsertionExtraction();
void testPortfolioPriceRangeCount();
void testPortfolioMostShares();
void testPortfolioFindByName();
void testPortfolioTotalValue();
void testPortfolioResizeGrow();
void testPortfolioResizeShrink();
void testPortfolioResizeSame();
void testPortfolioClone();

#endif 