// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 9
// Submitting date: Nov/5/2017
#include "Package.h"
#include<iostream>
using namespace std;
//constructor
Package::Package(char *snamevalue, char* saddressvalue, char *scityvalue, char *sstatevalue, char *szipvalue, char* rnamevalue, char *raddressvalue, char *rcityvalue, char *rstatevalue, char* rzipvalue, double weightvalue, double basiccostvalue)
	:sname(snamevalue),saddress(saddressvalue),scity(scityvalue),sstate(sstatevalue),szip(szipvalue),rname(rnamevalue),raddress(raddressvalue),rcity(rcityvalue),rstate(rstatevalue),rzip(rzipvalue),weight(weightvalue),basiccost(basiccostvalue)
{

}
//setter functions
void Package::setsname(char* namevalue)
{
	sname = namevalue;
}

void Package::setsaddress(char *addressvalue)
{
	saddress = addressvalue;
}

void Package::setscity(char *cityvalue)
{
	scity = cityvalue;
}

void Package::setsstate(char *statevalue)
{
	sstate = statevalue;
}

void Package::setszip(char *zipvalue)
{
	szip = zipvalue;
}

void Package::setrname(char *namevalue)
{
	rname = namevalue;
}

void Package::setraddress(char *addressvalue)
{
	raddress = addressvalue;
}

void Package::setrcity(char *cityvalue)
{
	rcity = cityvalue;
}

void Package::setrstate(char *statevalue)
{
	rstate = statevalue;
}

void Package::setrzip(char* zipvalue)
{
	rzip = zipvalue;
}
//determine if weight is positive
void Package::setweight(double weightvalue)
{
	if (weightvalue > 0)
	{
		weight = weightvalue;
	}
	else
	{
		cout << "Weight Must Be Positive!" << endl;
	}
}
//determine if price is positive
void Package::setbasiccost(double basiccostvalue)
{
	if (basiccostvalue > 0)
	{
		basiccost = basiccostvalue;
	}
	else
	{
		cout << "Regular Price per Ounce Must Be Positive!" << endl;
	}
}

//getter funtions
char* Package::getsname()
{
	return sname;
}

char* Package::getsaddress()
{
	return saddress;
}

char* Package::getscity()
{
	return scity;
}

char* Package::getsstate()
{
	return sstate;
}

char* Package::getszip()
{
	return szip;
}

char* Package::getrname()
{
	return rname;
}

char* Package::getraddress()
{
	return raddress;
}

char* Package::getrcity()
{
	return rcity;
}

char* Package::getrstate()
{
	return rstate;
}

char* Package::getrzip()
{
	return rzip;
}

double Package::getweight()
{
	return weight;
}

double Package::getbasiccost()
{
	return basiccost;
}

//regular price calculation
double Package::calculatecost()
{
	return getweight()*getbasiccost();
}
//get delivery type
char* Package::getdeliverytype()
{
	return deliverytype;
}