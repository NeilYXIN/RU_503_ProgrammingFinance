// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Inclass 5
// Submitting date: Oct/21/2017

// SetTest.cpp
// Driver program for class IntegerSet.

#include <iostream>
using namespace std;

#include "IntegerSet.h" // IntegerSet class definition

int main()
{
	IntegerSet a;
	IntegerSet b;
	IntegerSet c;
	IntegerSet d;

	cout << "Enter set A:\n";
	a.inputSet();
	cout << "\nSet A is : \n";
	a.printSet();

	cout << "\nEnter set B:\n";
	b.inputSet();
	cout << "\nSet B is : \n";
	b.printSet();

	/* Write call to unionOfSets for object a, passing b as argument and assigning the result to c */
	c = a.UnionOfSets(b);
	cout << "\nUnion of A and B is:\n";
	c.printSet();

	/* Write call to intersectionOfSets for object a, passing b as argument and assigning the result to d */
	d = a.InterSectionOfSets(b);
	cout << "\nIntersection of A and B is:\n";
	d.printSet();

	system("pause");
	return 0;
}
