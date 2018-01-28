// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 7
// Submitting date: Oct/23/2017

#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>
using namespace std;

class Polynomial
{
private:
	int coefficient[12];
	int terms;

public:
	Polynomial();//constructor
	void setterms();//set term number
	int getterms();//get term number
	void setconex(int);//set coefficient and exponent

	const Polynomial operator+(const Polynomial & poly);//overload +
	const Polynomial operator-(const Polynomial & poly);//overload -
	const Polynomial operator*(const Polynomial & poly);//overload *
	const Polynomial &operator+=(const Polynomial & poly);//overload +=
	const Polynomial &operator-=(const Polynomial & poly);//overload-=
	const Polynomial &operator*=(const Polynomial & poly);//overload *=

	friend ostream& operator<<(ostream&, const Polynomial &);//overload <<

};

#endif POLYNOMIAL_H
