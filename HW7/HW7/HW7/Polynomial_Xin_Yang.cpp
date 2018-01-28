// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 7
// Submitting date: Oct/23/2017

#include "Polynomial_Xin_Yang.h"
//constructor
Polynomial::Polynomial()
{
	for (int i = 0; i < 12; i++)
	{
		coefficient[i] = 0;//set all coefficient to 0
	}
	terms = 0;//set term to 0
}

void Polynomial::setterms()
{
	int t;
	cin >> t;
	terms = t;//set terms
}

int Polynomial::getterms()
{
	return terms;//get terms
}

void Polynomial::setconex(int i)
{
	cout << "Enter coefficient and exponent: ";
	int co = 0, ex = 0;
	cin >> co >> ex;//get coefficient and exponent
	coefficient[ex] = co;//set polynomial
}

ostream& operator<<(ostream& output, const Polynomial &poly)//overload <<
{
	int flag = 0;//determine output +
	for (int i = 0; i < 12; i++)
	{
		if (poly.coefficient[i] != 0)//output when coefficient is not 0
		{
			if (flag != 0)
			{
				output << " + ";//output + when not fisrt
			}
			if (i == 1)//omit exponent when is 1
			{
				output << poly.coefficient[i] << "x";
			}
			else //output all information
			{
				output << poly.coefficient[i] << "x^" << i;
			}
			flag = 1;//first time don't output +
		}
	}
	output << endl;//seperate
	return output;
}

const Polynomial Polynomial::operator+(const Polynomial & poly)//overload +
{
	Polynomial polyadd;//new polynomial as result
	for (int i = 0; i < 6; i++)
	{
		polyadd.coefficient[i] = coefficient[i] + poly.coefficient[i];//calculate sum
	}
	return polyadd;

}

const Polynomial Polynomial::operator-(const Polynomial & poly)//overload -
{
	Polynomial polysub;//new polynomial as result
	for (int i = 0; i < 6; i++)
	{
		polysub.coefficient[i] = coefficient[i] - poly.coefficient[i];//minus 
	}
	return polysub;
}

const Polynomial Polynomial::operator*(const Polynomial & poly)//overload *
{
	Polynomial polymul;//new polynomial as result
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			polymul.coefficient[i + j] += coefficient[i] * poly.coefficient[j];//do multiplication
		}
	}
	return polymul;
}

const Polynomial &Polynomial::operator+=(const Polynomial & poly)//overload +=
{
	for (int i = 0; i < 6; i++)
	{
		coefficient[i] += poly.coefficient[i];
	}
	return *this;
}

const Polynomial &Polynomial::operator-=(const Polynomial & poly)//overload -=
{
	for (int i = 0; i < 6; i++)
	{
		coefficient[i] -= poly.coefficient[i];
	}
	return *this;
}

const Polynomial &Polynomial::operator*=(const Polynomial & poly)//overload *=
{
	Polynomial temp = *this;//save poly 1
	for (int i = 0; i < 12; i++)//set poly 1 to 0
	{
		coefficient[i] = 0;
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			coefficient[i + j] += temp.coefficient[i] * poly.coefficient[j];//do multiplication
		}
	}
	return *this;
}