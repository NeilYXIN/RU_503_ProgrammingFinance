// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 9
// Submitting date: Nov/5/2017
#pragma once
#ifndef PACKAGE_H
#define PACKAGR_H
class Package
{
public:
	//constructor
	Package(char *snamevalue, char *saddressvalue, char* scityvalue, char* sstatevalue, char* szipvalue, char *rnamevalue, char *raddressvalue, char* rcityvalue, char* rstatevalue, char* rzipvalue, double weightvalue, double basiccostvalue);
	//setters
	void setsname(char *namevalue);
	void setsaddress(char *addressvalue);
	void setscity(char* cityvalue);
	void setsstate(char* statevalue);
	void setszip(char* zipvalue);
	void setrname(char *addressvalue);
	void setraddress(char *addressvalue);
	void setrcity(char *cityvalue);
	void setrstate(char *statevalue);
	void setrzip(char *zipvalue);
	void setweight(double weightvalue);
	void setbasiccost(double costvalue);
	//getters
	char* getsname();
	char* getsaddress();
	char* getscity();
	char* getsstate();
	char* getszip();
	char* getrname();
	char* getraddress();
	char* getrcity();
	char* getrstate();
	char* getrzip();
	double getweight();
	double getbasiccost();
	//calculate funtion
	virtual double calculatecost();
	//deliver type
	char * getdeliverytype();

private:
	char *sname;
	char *saddress;
	char *scity;
	char *sstate;
	char *szip;
	char *rname;
	char *raddress;
	char *rcity;
	char *rstate;
	char *rzip;
	double weight;
	double basiccost;
	char* deliverytype = "Regular Delivery";
};
#endif // !PACKAGE_H
