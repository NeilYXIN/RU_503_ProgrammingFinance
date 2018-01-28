#include "Tetrahedron.h"
#include <iostream>
#include <math.h>
using namespace std;
Tetrahedron::Tetrahedron(double xValue, double yValue, double zValue, double edgeValue) : ThreeDimensionalShape(xValue, yValue, zValue)
{
	setedge(edgeValue);
}

void Tetrahedron::setedge(double radiusValue)
{
	edge = radiusValue;
}

double Tetrahedron::getedge()
{
	return edge;
}

double Tetrahedron::getarea()
{
	return edge * edge * sqrt(3);
}

double Tetrahedron::getvolume()
{
	return sqrt(2) / 12.0 * edge * edge * edge;
}

void Tetrahedron::print()
{
	cout << "The tetrahedron with radius " << getedge() << " that is located at (" << getx() << "," << gety() << "," << getz() << ") has:" << endl;
	cout << "Surface area of " << getarea() << endl;
	cout << "Volume of " << getvolume() << endl;
}