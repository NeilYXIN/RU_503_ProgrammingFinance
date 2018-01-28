#include "priceGetter.h"

using namespace std;

PriceGetter::PriceGetter()
{
	cacheResultFile();
}

PriceGetter::~PriceGetter()
{

}


void PriceGetter::cacheResultFile()
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
			result1[tempname]= tempprice;
			//Token = strtok_s(NULL, delimiter, &nextToken);
			count++;
		}
	}
	else // no rsult_1 exist
	{
		cout << "no file result_1" << endl;
	}
	
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
}

float PriceGetter::getRandompPrice(string stocknamevalue)
{
	float price = -1.0;
	srand(time(0));
	int filerand = rand() % 2;
	switch (filerand)
	{
	default: // don't have enough files
		cout << "random number error!" << endl;
		break;
	case 0: // get price from result_1
	{
		if (result1.find(stocknamevalue)!=result1.end())
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
