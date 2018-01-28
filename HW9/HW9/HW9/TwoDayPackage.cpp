// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 9
// Submitting date: Nov/5/2017
#include "TwoDayPackage.h"
#include <iostream>
using namespace std;
//constructor function
TwoDayPackage::TwoDayPackage(char* snamevalue, char* saddressvalue, char* scityvalue, char* sstatevalue, char* szipvalue, char* rnamevalue, char* raddressvalue, char* rcityvalue, char* rstatevalue, char* rzipvalue, double weightvalue, double basiccostvalue, double flatfeevalue) 
	: Package(snamevalue, saddressvalue, scityvalue, sstatevalue, szipvalue, rnamevalue, raddressvalue, rcityvalue, rstatevalue, rzipvalue, weightvalue, basiccostvalue)
{
	setflatfee(flatfeevalue);
}
//set flat fee and determine if it's positive
void TwoDayPackage::setflatfee(double flatfeevalue)
{
	if (flatfeevalue > 0)
	{
		flatfee = flatfeevalue;
	}
	else
	{
		cout << "Flat Fee Must Be Posistive!" << endl;
	}
}
//get flat fee
double TwoDayPackage::getflatfee()
{
	return flatfee;
}
//new calculation funtion with flat fee added
double TwoDayPackage::calculatecost()
{
	return (getflatfee() + getbasiccost())*getweight();
}