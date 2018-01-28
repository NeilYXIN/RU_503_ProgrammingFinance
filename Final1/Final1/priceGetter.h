#include <iostream>
#include <fstream>  
#include <string>   
#include <string.h>
#include <vector>
#include <time.h>
#include <map>
#pragma once
#ifndef PRICEGETTER_H
#define PRICEGETTER_H

using namespace std;
class PriceGetter
{
public:
	PriceGetter();
	~PriceGetter();
	void cacheResultFile();
	float getRandompPrice(string stocknamevalue);
private:
	map<string, string> result1;
	map<string, string> result2;
};


#endif // !PRICEGETTER_H