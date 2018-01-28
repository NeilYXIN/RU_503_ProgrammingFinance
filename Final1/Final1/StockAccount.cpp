#include "StockAccount.h"
#include <iostream>
#include <iomanip>
#include "LinkedList.h"
using namespace std;
StockAccount::StockAccount()
{
	list = new LinkedList();
	cacheResultFile();
	stockHistoryInitializer();
	initializePortfolio();
	
	// initialize linkedlist
	//get portfolio info
}

StockAccount::~StockAccount()
{

}

void StockAccount::cacheResultFile()
{
	ifstream infile1("Result_1.txt");
	ifstream infile2("Result_2.txt");
	string line;
	char* delimiter = " \t";
	char* nextToken = NULL;
	char * Token = NULL;

	//store result_1 txt into result1 vector
	if (infile1) // file exist
	{
		int count = 0;
		while (getline(infile1, line))
		{
			nextToken = NULL;
			Token = NULL;
			Token = strtok_s(const_cast<char*>(line.c_str()), delimiter, &nextToken);
			string tempname = Token;
			Token = strtok_s(NULL, delimiter, &nextToken);
			string tempprice = Token;
			result1[tempname] = tempprice;
			//Token = strtok_s(NULL, delimiter, &nextToken);
			count++;
		}
	}
	else // no rsult_1 exist
	{
		cout << "no file result_1" << endl;
	}
	infile1.close();
	//store result_2 txt into result2 vector
	if (infile2) // file exist
	{
		int count = 0;
		while (getline(infile2, line))
		{
			nextToken = NULL;
			Token = NULL;
			Token = strtok_s(const_cast<char*>(line.c_str()), delimiter, &nextToken);
			string tempname = Token;
			Token = strtok_s(NULL, delimiter, &nextToken);
			string tempprice = Token;
			result2[tempname] = tempprice;
			//Token = strtok_s(NULL, delimiter, &nextToken);
			count++;
		}
	}
	else // no result_2 exist
	{
		cout << "no file result_2" << endl;
	}
	infile2.close();
}

double StockAccount::getRandompPrice(string stocknamevalue)
{
	double price = -1.0;
	srand(time(0));
	int filerand = rand() % 2;
	switch (filerand)
	{
	default: // don't have enough files
		cout << "random number error!" << endl;
		break;
	case 0: // get price from result_1
	{
		if (result1.find(stocknamevalue) != result1.end())
		{
			price = atof(result1[stocknamevalue].c_str());
		}
		else
		{
			cout << "No such stock name" << endl;
		}
		break;
	}
	case 1: // get price from result_2
	{
		if (result2.find(stocknamevalue) != result2.end())
		{
			price = atof(result2[stocknamevalue].c_str());
		}
		else
		{
			cout << "No such stock name" << endl;
		}
		break;
	}
	}
	return price;
}

void StockAccount::stockHistoryInitializer()
{
	//add flag to determine first run or not
	ifstream ifile("StockTransactionHistory.txt");

	string buf;
	int BankTransactionHistoryflag = 0;
	// balance file doesn't exist
	if (!ifile.is_open())
	{
		ifile.close();
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, "StockTransactionHistory.txt", "w+"); // create file
		if (err == 0) // no error
		{
			fclose(fp); // close created file
		}
	}
	ifstream ifile1("StockTransactionHistory.txt");
	if (ifile1.is_open()) // file successfully opened
	{
		while (true)
		{
			getline(ifile1, buf); // get data by line
								  // not first open, do nothing
			if (!strcmp(buf.c_str(), "StockTransactionHistory"))
			{
				//cout << "Balance else" << endl; // test
				ifile1.close(); // close file
				break;
			}
			// first open or file format error, initialize
			else
			{
				//cout << buf << endl; // test
				ofstream ofile("StockTransactionHistory.txt");
				ofile << "StockTransactionHistory" << endl;
				ofile.close();
				ifile1.close();
				break;
			}
		}
	}
	// unexpected error
	else
	{
		cout << "error open StockTransactionHistory file" << endl;
	}
}

void StockAccount::buyStock(string stockname, int stocknum, double price)
{


	// when already exist
	if (bought(stockname))
	{
		// find existed node and update num
		Node * temp = list->root;
		while (temp->next != list->end)
		{
			temp = temp->next;
			if (temp->stockname == stockname)
			{
				temp->stocknum += stocknum;
				cout << "You have purchased " << stocknum << " shares of " << temp->stockname << " at $" << price << " each for a total of $" << price*stocknum << "." << endl;
				sortStock();
			}
		}

	}
	// no record found
	else
	{
		Node * newnode = new Node(stockname, stocknum);
		list->insertEnd(newnode);
		//double price = getRandompPrice(newnode->stockname;
		cout << "You have purchased " << newnode->stocknum << " shares of " << newnode->stockname << " at $" << price << " each for a total of $" << price*newnode->stocknum << "." << endl;
		//return price;
	}

}


void StockAccount::sellStock(string stockname, int stocknum, double price)
{
	// when exist
	if (bought(stockname))
	{
		// find existed node and update num
		Node * temp = list->root;
		while (temp->next != list->end)
		{
			temp = temp->next;
			if (temp->stockname == stockname)
			{
				temp->stocknum -= stocknum;
				cout << "You have sold " << stocknum << " shares of " << temp->stockname << " at $" << price << " each for a total of $" << price*stocknum << ".";
				// if sold out delete this from list
				if (temp->stocknum == 0)
				{
					list->erase(temp);
					
				}
				sortStock();
				break;
			}
		}

	}
	// no record found
	else
	{
		cout << "sellStock: Error! Stockname not found!" << endl;
		//return price;
	}
}

bool StockAccount::bought(string namevalue)
{
	return list->nameExist(namevalue);
}

void StockAccount::initializePortfolio()
{
	//add flag to determine first run or not
	ifstream ifile("PortfolioDetails.txt");
	//double initial = 10000;
	string buf;
	//int Balanceflag = 0;
	// portfolio detail file doesn't exist
	if (!ifile.is_open())
	{
		ifile.close();
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, "PortfolioDetails.txt", "w+"); // create file
		if (err == 0) // no error
		{
			fclose(fp); // close created file
		}
		ofstream ofile("PortfolioDetails.txt");
		ofile << "PortfolioDetails" << endl;
		ofile.close();
		ifile.close();
	}
	ifstream ifile1("PortfolioDetails.txt");
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
					string tempname = Token;
					Token = strtok_s(NULL, delimiter, &nextToken); // get portfolio
					int tempnum = atoi(Token);
					Node * newnode = new Node(tempname, tempnum);
					list->insertEnd(newnode);
				}
			}
			else
			{
				ifile1.close();
				//cout << "get detail from txt: " << endl;
				//list->traversalPrint();

				break;
			}





		}
	}
	// unexpected error
	else
	{
		cout << "error open PortfolioDetails file" << endl;
	}
}

void StockAccount::savePortfolio()
{
	sortStock();
	ofstream ofile("PortfolioDetails.txt");
	ofile << "PortfolioDetails" << endl;
	ofile.close();
	Node * temp = list->root;
	ofstream ofile1("PortfolioDetails.txt", ios::app);
	while (temp->next != list->end)
	{
		temp = temp->next;
		
		ofile1 << temp->stockname << " " << temp->stocknum << endl;
	}
	ofile1.close();



}

double StockAccount::getPortfolio()
{
	double sum = 0.0;
	Node * count = list->root;
	while (true)
	{
		if (count->next != list->end)
		{
			count = count->next;
			sum += getRandompPrice(count->stockname)*count->stocknum;
		}
		else
		{
			return sum;
		}
	}
}

void StockAccount::savePortfolioHistory(double balance, double portfolio)
{
	ofstream ofile("AccountInfo.txt", ios::app);
	struct tm t;  // tm struct pointer
	time_t now; // declare time_t variable
	time(&now); // get system time
	localtime_s(&t, &now); // get local time
    portfolio = getPortfolio();

	time_t seconds;
	seconds = time(NULL);

	tm * timeinfo;
	timeinfo = localtime(&seconds);
	
	ofile << balance << " "
		<< portfolio << " "
		<< seconds
		<< endl;
	ofile.close();
}

void StockAccount::addStockHistory(string event, string name, int num, double price)
{
	struct tm t;  // tm struct pointer
	time_t now; // declare time_t variable
	time(&now); // get system time
	localtime_s(&t, &now); // get local time
	ofstream ofile("StockTransactionHistory.txt", ios::app); // append mode
	ofile << event << " " << name << " " << num << " " << price << " " << price*num << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << endl;
	ofile.close();

}

double StockAccount::getStockNum(string namevalue)
{
	return list->getNode(namevalue)->stocknum;
}

void StockAccount::printHistory() // template design
{
	
	cout.setf(ios::left); // left align
	cout << setw(15) << "Company Symbol" << setw(15) << "Number" << setw(15) << "Price per share" << setw(15) << "Total value" << setw(15) << "Time" << endl; // print title in format
	ifstream ifile("StockTransactionHistory.txt");
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
				if (!strcmp(line.c_str(), "StockTransactionHistory")) // first line
				{
					continue; // jump first line
				}
				// get each word
				nextToken = NULL;
				Token = NULL;
				Token = strtok_s(const_cast<char*>(line.c_str()), delimiter, &nextToken); // get event
				string event = Token;
				Token = strtok_s(NULL, delimiter, &nextToken); // get amount
				string compsymbol = Token;
				Token = strtok_s(NULL, delimiter, &nextToken); // get date
				string number = Token;
				Token = strtok_s(NULL, delimiter, &nextToken); // get balance
				string price = Token;
				Token = strtok_s(NULL, delimiter, &nextToken); // get balance
				string total = Token;
				Token = strtok_s(NULL, delimiter, &nextToken); // get balance
				string time = Token;
				cout << setw(15) << event << setw(15) << compsymbol << setw(15) << number << setw(15) << price << setw(15) << total << setw(15) << time << endl; // print in foramt
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
void StockAccount::printPortfolio()
{
	sortStock();
	cout << endl;
	cout.setf(ios::left); // left align
	cout << setw(15) << "CompSymbol" << setw(15) << "Number" << setw(15) << "Price per share" << setw(15) << "Total value" << endl; // print title in format
	ifstream ifile("PortfolioDetails.txt");
	if (ifile.is_open())
	{
		char* delimiter = " ";
		char* nextToken = NULL;
		char * Token = NULL;
		string line;
		double total = 0.0;
		Node * count = list->root;
		while (count->next != list->end)
		{
		
			count = count->next;
			//double price = getRandompPrice(count->stockname);
			total += count->tempprice*count->stocknum;
			cout << setw(15) << count->stockname << setw(15) << count->stocknum << setw(15) << count->tempprice << setw(15) << count->tempprice*count->stocknum << endl; // print in foramt
		}
		cout << endl << "Total portfolio value : $" << total << "." << endl;
		ifile.close(); // close file

	}
	else
	{
		cout << "open bank transaction history file error!" << endl;
	}
}

void StockAccount::sortStock()
{
	Node * temp = list->root;
	while (temp->next != list->end)
	{
		temp = temp->next;
		temp->tempprice = getRandompPrice(temp->stockname);
	}
	if (list->root->next != list->end && list->root->next->next != list->end)
	{
		list->sort();
	}
	

	
}