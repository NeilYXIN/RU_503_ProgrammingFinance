#include "Account.h"
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;
Account::Account()//initialize cash balance
{
}


Account::~Account()
{
}



void Account::execute()
{
	cout << endl;
	cout.setf(ios::left);
	cout << setw(15) << "Event";
	printHistory();
}



void Account::accountInitializer(double * balance, double * portfolio)
{
	//add flag to determine first run or not
	ifstream ifile("AccountInfo.txt");

	double initial = 10000;
	string buf;
	int Balanceflag = 0;
	// balance file doesn't exist
	if (!ifile.is_open())
	{
		ifile.close();
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, "AccountInfo.txt", "w+"); // create file
		if (err == 0) // no error
		{
			fclose(fp); // close created file
		}
		ofstream ofile("AccountInfo.txt");
		time_t seconds;
		seconds = time(NULL);

		ofile << "AccountInfo" << endl
			<< initial << " "
			<< 0 << " "
			<< seconds
			<< endl;
		ofile.close();
		ifile.close();
	}
	ifstream ifile1("AccountInfo.txt");
	char* delimiter = " ";
	char* nextToken = NULL;
	char * Token = NULL;
	if (ifile1.is_open()) // file successfully opened
	{
		int count = 0;
		
		while (true)
		{
			count++;
			if (getline(ifile1, buf)) // has content
			{
				// first line
		
				//not first line
				if (count > 1)
				{

					nextToken = NULL;
					Token = NULL;
					Token = strtok_s(const_cast<char*>(buf.c_str()), delimiter, &nextToken); // get balance
					string tempbalance = Token;
					Token = strtok_s(NULL, delimiter, &nextToken); // get portfolio
					string tempportfolio = Token;
					
					*balance = atof(tempbalance.c_str());
					*portfolio = atof(tempportfolio.c_str());// delete portfolio, not necessary
				}
			}
			else
			{
			//	cout << "initialize balance is: " << *balance << endl;
			//	cout << "initialize portfolio is: " << *portfolio << endl;
				// delete portfolio, not necessary
				ifile1.close();
				break;
			}

		}
	}
	// unexpected error
	else
	{
		cout << "error open AccountInfo file" << endl;
	}


}



