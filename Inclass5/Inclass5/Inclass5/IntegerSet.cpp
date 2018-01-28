// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Inclass 5
// Submitting date: Oct/21/2017

// IntegerSet.cpp
// Member-function definitions for class IntegerSet.

#include <iostream>
#include <iomanip>
using namespace std;

/* Write include directive for IntegerSet.h here */
#include "IntegerSet.h"

// constructor
IntegerSet::IntegerSet()
{
	for (int i = 0; i < 101; i++) set[i] = 0;
} // end IntegerSet constructor

  // input a set from the user
void IntegerSet::inputSet()
{
	int number;

	do
	{
		cout << "Enter an element (-1 to end): ";
		cin >> number;

		if (validEntry(number))
			set[number] = 1;
		else if (number != -1)
			cout << "Invalid Element\n";
	} while (number != -1); // end do...while

	cout << "Entry complete\n";
} // end function inputSet

  // prints the set to the output stream
void IntegerSet::printSet() const
{
	cout << "{ ";

	for (int u = 0; u < 101; u++)
		if (set[u]) cout << u << " ";

	cout << "}" << endl;
	} // end function printSet

/* Write definition for unionOfSets */
IntegerSet IntegerSet::UnionOfSets(IntegerSet b)
{
	IntegerSet c;
	for (int i = 0; i < 101; i++)
	{
		c.set[i] = set[i] || b.set[i];
	}
	return c;
}

/* Write definition for intersectionOfSets */
IntegerSet IntegerSet::InterSectionOfSets(IntegerSet b)
{
	IntegerSet d;
	for (int i = 0; i < 101; i++)
	{
		d.set[i] = set[i] && b.set[i];
	}
	return d;
}