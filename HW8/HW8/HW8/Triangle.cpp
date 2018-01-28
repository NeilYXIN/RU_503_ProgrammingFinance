#include "Triangle.h"
#include <iostream>
#include <math.h>
using namespace std;

Triangle::Triangle(double xValue, double yValue, double edgeValue) : TwoDimensionalShape(xValue, yValue)
{
	setedge(edgeValue);
}

void Triangle::setedge(double edgeValue)
{
	edge = edgeValue;
}

double Triangle::getedge()
{
	return edge;
}

double Triangle::getarea()
{
	return edge * edge * sqrt(3) / 4.0;
}

void Triangle::print()
{
	cout << "The triangle with edge length " << getedge() << " that is located at (" << getx() << "," << gety() << ") has:" << endl;
	cout << "An area of " << getarea() << endl;
}