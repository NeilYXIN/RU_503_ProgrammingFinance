#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape
{
public:
	Circle(double = 0, double = 0, double = 0);
	void setradius(double radiusValue);
	double getradius();
	double getarea();
	void print();

private:
	double radius;
};
#endif // !CIRCLE_H

