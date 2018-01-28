#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(double xValue, double yValue, double radiusValue) : TwoDimensionalShape(xValue, yValue)
{
	setradius(radiusValue);
}

void Circle::setradius(double radiusValue)
{
	radius = radiusValue;
}

double Circle::getradius()
{
	return radius;
}

double Circle::getarea()
{
	return 3.14 * radius * radius;
}

void Circle::print()
{
	cout << "The circle with radius " << getradius() << " that is located at (" << getx() << "," << gety() << ") has:" << endl;
	cout << "An area of " << getarea() << endl;
}