// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 9
// Submitting date: Nov/5/2017
#include <iostream>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <vector>
#include <iomanip>
using namespace std;
//loop to print information
void vectorprint(Package *);
//main funtion
int main()
{
	//initialize price per ounce
	double regular = 0.5;
	double twoday = 2.0;
	double overnight = 5.0;
	double total = 0.0;
	//print price information
	cout << "Package delivery services program" << endl;
	cout << "Cost per ounce for a package : $" << fixed << setprecision(2) << regular << " / ounce" << endl;
	cout << "Additional cost for two day delivery : $" << fixed << setprecision(2) << twoday << " / ounce" << endl;
	cout << "Additional cost for overnight delivery : $" << fixed << setprecision(2) << overnight << " / ounce" << endl;
	//create three packages for test
	Package package1("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854", "Tom Smith", "2 Davidson Road", "Piscataway", "NJ", "08854", 10.0, regular);
	TwoDayPackage package2("Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854", "Jennifer Smith", "4 Davidson Road", "Piscataway", "NJ", "08854", 5.0, regular, twoday);
	OvernightPackage package3("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854", "Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854", 2.0, regular, overnight);
	//vector of Package pointers
	vector<Package *>packagevector(3);
	packagevector[0] = &package1;//point to regular package
	packagevector[1] = &package2;//point to two day package
	packagevector[2] = &package3;//point to overnight package
	//for every package, print package order information
	for (int i = 0; i < packagevector.size(); i++)
	{
		cout << "Package " << i + 1 << endl << endl;//print package name
		vectorprint(packagevector[i]);//call print information function
		total += packagevector[i]->calculatecost();//meanwhile add total cost
	}
	cout << "Total cost of all the packages: $" << fixed << setprecision(2) << total << endl;//print total cost

	system("pause");
}
//function to show package order details
void vectorprint(Package *packv)
{
	//Sender information
	cout << "Sender:" << endl;
	cout << packv->getsname() << endl;//show sender name
	//show sender address
	cout << packv->getsaddress() << endl;
	cout << packv->getscity() << ", " << packv->getsstate() << " " << endl << endl;
	//Recipient information
	cout << "Recipient:" << endl;
	cout << packv->getrname() << endl;//show recipient name
	//show recipient address
	cout << packv->getraddress() << endl;
	cout << packv->getrcity() << ", " << packv->getrstate() << " " << endl << endl;
	//package information
	cout << "Weight of package : " << fixed << setprecision(2) << packv->getweight() << " ounces" << endl;//package weight
	cout << "Type of delivery : " << packv->getdeliverytype() << endl;//delivery type
	cout << "Cost of Package : $" << fixed << setprecision(2) << packv->calculatecost() << endl << endl;//package price
}