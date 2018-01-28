#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "Account.h"
class BankAccount : public Account
{
public:
	BankAccount();
	~BankAccount();
	void bankHistoryInitializer();
	void deposit(double moneyvalue, double *balance);
	void withdraw(double moneyvalue, double *balance);
	void printHistory();
private:

};


#endif // !BANKACCOUNT_H

