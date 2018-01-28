// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 7
// Submitting date: Oct/23/2017

#include "Polynomial_Xin_Yang.h"

int main()
{
	Polynomial poly1;//first polynomial
	Polynomial poly2;//second polynomial
	Polynomial polytemp;//to restore polynomial 1

	cout << "Enter the number of polynomial terms: ";
	poly1.setterms();//call set function to set polynomial 1
	for (int i = 0; i < poly1.getterms(); i++)
	{
		poly1.setconex(i);//set coefficient and exponent
	}
	cout << endl;
	cout << "First Polynomial is: ";
	cout << poly1;//overload << output poly1

				  //repeat to input polynomial 2
	cout << "Enter the number of polynomial terms: ";
	poly2.setterms();
	for (int i = 0; i < poly2.getterms(); i++)
	{
		poly2.setconex(i);
	}
	cout << endl;
	cout << "Second Polynomial is: ";
	cout << poly2;
	cout << endl;

	polytemp = poly1;//store poly 1 incase += -= *= change the value of poly1

	cout << "Adding polynomial yields: ";
	cout << poly1 + poly2;//overload + & <<
	cout << endl;

	cout << "+= the polynomial yields: ";
	cout << (poly1 += poly2);//overload += & <<
	cout << endl;

	poly1 = polytemp;

	cout << "Subtracting the polynomial yields: ";
	cout << poly1 - poly2;//overload << & -
	cout << endl;

	cout << "-= the polynomials yields: ";
	cout << (poly1 -= poly2);//overload -= & <<
	cout << endl;

	poly1 = polytemp;
	cout << "Multiplying the polynomials yields: ";
	cout << poly1 * poly2;//overload * & <<
	cout << endl;

	cout << "*= the polynomial yields: ";
	cout << (poly1 *= poly2);//overload *= & <<
	cout << endl;

	system("pause");
	return 0;
}