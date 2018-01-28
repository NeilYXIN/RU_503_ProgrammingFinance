#pragma once
#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H
#include "Account.h"
#include <iostream>
#include <fstream>  
#include <string>   
#include <string.h>
#include <vector>
#include <time.h>
#include <map>
#include "LinkedList.h"
using namespace std;
class StockAccount : public Account
{
	friend class LinkedList;
public:
	StockAccount();
	~StockAccount();
	void cacheResultFile(); // load stock price info
	void stockHistoryInitializer(); // create stock history file
	double getRandompPrice(string stocknamevalue); // get random price by stock name

	void buyStock(string stockname, int stocknum, double price);
	void sellStock(string stockname, int stocknum, double price);

	bool bought(string namevalue); // if this stock is already bought before
	double getStockNum(string namevalue);

	void initializePortfolio(); // create file and load portfolio detail from file
	void savePortfolio(); // save detail portfolio to txt
	double getPortfolio(); // return total price of portfolio
	void savePortfolioHistory(double balance, double portfolio); //save total amount and balance to account info file

	void addStockHistory(string event, string name, int num, double price);
	void printHistory();
	void printPortfolio();

	void sortStock();

private:
	map<string, string> result1;
	map<string, string> result2;
	double portfoliovalue;
	LinkedList *list;
};


#endif // !STOCKACCOUNT_H
