#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;
BankAccount::BankAccount()
{
	bankHistoryInitializer();
}

BankAccount::~BankAccount()
{
}

void BankAccount::bankHistoryInitializer()
{
	//add flag to determine first run or not
	ifstream ifile("BankTransactionHistory.txt");

	string buf;
	int BankTransactionHistoryflag = 0;
	// balance file doesn't exist
	if (!ifile.is_open())
	{
		ifile.close();
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, "BankTransactionHistory.txt", "w+"); // create file
		if (err == 0) // no error
		{
			fclose(fp); // close created file
		}
	}
	ifstream ifile1("BankTransactionHistory.txt");
	if (ifile1.is_open()) // file successfully opened
	{
		while (true)
		{
			getline(ifile1, buf); // get data by line
			// not first open, do nothing
			if (!strcmp(buf.c_str(), "BankTransactionHistory"))
			{
				//cout << "Balance else" << endl; // test
				ifile1.close(); // close file
				break;
			}
			// first open or file format error, initialize
			else
			{
				//cout << buf << endl; // test
				ofstream ofile("BankTransactionHistory.txt");
				ofile << "BankTransactionHistory" << endl;
				ofile.close();
				ifile1.close();
				break;
			}
		}
	}
	// unexpected error
	else
	{
		cout << "error open BankTransactionHistory file" << endl;
	}
}

void BankAccount::deposit(double moneyvalue, double *balance)
{
	// update bank balance
	*balance += moneyvalue;
	struct tm t;  // tm struct pointer
	time_t now; // declare time_t variable
	time(&now); // get system time
	localtime_s(&t, &now); // get local time
	// update bank transaction history
	ofstream ofile("BankTransactionHistory.txt", ios:: app);
	ofile << "Deposit" << " " << moneyvalue << " " << t.tm_year+1900 <<"/"<< t.tm_mon << "/" << t.tm_mday << " " << *balance << endl;
	ofile.close();	
}

void BankAccount::withdraw(double moneyvalue, double *balance)
{
	// balance not enough 
	if (*balance<moneyvalue)
	{
		cout << endl << "No sufficient money in your account!" << endl;
	}
	// balance enough, do withdrawal
	else
	{
		// update bank balance
		*balance -= moneyvalue;
		struct tm t;  // tm struct pointer
		time_t now; // declare time_t variable
		time(&now); // get system time
		localtime_s(&t, &now); // get local time
		// update bank transaction history
		ofstream ofile("BankTransactionHistory.txt", ios::app);
		ofile << "Withdrawal" << " " << moneyvalue << " " << t.tm_year + 1900 << "/" << t.tm_mon << "/" << t.tm_mday << " " << *balance << endl;
		ofile.close();
	}
}

void BankAccount::printHistory() //template design pattern
{
	cout.setf(ios::left); // left align
	cout << setw(15) << "Amount" << setw(15) << "Date" << setw(15) << "Balance" << endl; // print title in format
	ifstream ifile("BankTransactionHistory.txt");
	if (ifile.is_open())
	{
		char* delimiter = " ";
		char* nextToken = NULL;
		char * Token = NULL;
		string line;
		while (true)
		{
			// have content
			if (getline(ifile, line))
			{
				if (!strcmp(line.c_str(), "BankTransactionHistory")) // first line
				{
					continue; // jump first line
				}
				// get each word
				nextToken = NULL;
				Token = NULL;
				Token = strtok_s(const_cast<char*>(line.c_str()), delimiter, &nextToken); // get event
				string event = Token;
				Token = strtok_s(NULL, delimiter, &nextToken); // get amount
				string amount = Token;
				Token = strtok_s(NULL, delimiter, &nextToken); // get date
				string date = Token;
				Token = strtok_s(NULL, delimiter, &nextToken); // get balance
				string balance = Token;
				cout << setw(15) << event << setw(15) << amount << setw(15) << date << setw(15) << balance << endl; // print in foramt
			}
			// end file
			else
			{
				ifile.close(); // close file
				break;
			}
		}		
	}
	else
	{
		cout << "open bank transaction history file error!" << endl;
	}
}