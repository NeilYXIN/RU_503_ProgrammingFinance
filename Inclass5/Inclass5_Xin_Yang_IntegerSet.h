// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Inclass 5
// Submitting date: Oct/21/2017

#pragma once
// IntegerSet.h
// Header file for class IntegerSet

#ifndef INTEGER_SET_H
#define INTEGER_SET_H

class IntegerSet
{
public:
	IntegerSet(); // constructor

	/* Write a member funcion prototype for UnionOfSets */
	IntegerSet UnionOfSets(IntegerSet b);			  
	/* Write a member funcion prototype for InterSectionOfSets */
	IntegerSet InterSectionOfSets(IntegerSet b);

	void inputSet(); // read values from user

	void printSet() const;

private:
	int set[101]; // range of 0 - 100

				  // determines a valid entry to the set
	int validEntry(int x) const
	{
		return (x >= 0 && x <= 100);
	} // end function validEntry
};
#endif INTEGER_SET_H