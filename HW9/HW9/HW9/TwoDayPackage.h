// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 9
// Submitting date: Nov/5/2017
#pragma once
#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "Package.h"

class TwoDayPackage : public Package
{
public:
	//constructor
	TwoDayPackage(char *snamevalue, char* saddressvalue, char* scityvalue, char *sstatevalue, char* szipvalue, char* rnamevalue, char* raddressvalue, char* rcityvalue, char* rstatevalue, char *rzipvalue, double weightvalue, double basiccostvalue, double flatfeevalue);
	//redefine calculate cost function
	virtual double calculatecost();
	//setter and getter for flat fee
	void setflatfee(double flatfeevalue);
	double getflatfee();

private:
	double flatfee;
	char* deliverytype = "Two Day Delivery";
};
#endif // !TWODAYPACKAGE_H
