#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Node.h"
class Account
{
public:
	Account();
	~Account();
	void accountInitializer(double *balance, double *portfolio); // create file and load balance and total portfolio 
	virtual void printHistory() = 0; // template design pattern
	void execute(); // template design pattern
private:
	
};
#endif // !ACCOUNT_H
