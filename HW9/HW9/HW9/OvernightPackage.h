// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 9
// Submitting date: Nov/5/2017
#pragma once
#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include "Package.h"
class OvernightPackage: public Package
{
public:
	//constructor
	OvernightPackage(char *snamevalue, char *saddressvalue, char *scityvalue, char* sstatevalue, char* szipvalue, char *rnamevalue, char *raddressvalue, char *rcityvalue, char* rstatevalue, char* rzipvalue, double weightvalue, double basiccostvalue, double flatfeevalue);
	virtual double calculatecost();//redefine calculatecost function
	void setflatfee(double flatfeevalue);
	double getflatfee();
private:
	double flatfee;
	char* deliverytype = "Overnight Delivery";
};
#endif // !OVERNIGHTPACKAGE_H
