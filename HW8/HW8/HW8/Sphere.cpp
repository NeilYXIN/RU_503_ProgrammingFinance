#include "Sphere.h"
#include <iostream>
using namespace std;

Sphere::Sphere(double xValue, double yValue, double zValue, double radiusValue) : ThreeDimensionalShape(xValue, yValue, zValue)
{
	setradius(radiusValue);
}

void Sphere::setradius(double radiusValue)
{
	radius = radiusValue;
}

double Sphere::getradius()
{
	return radius;
}

double Sphere::getarea()
{
	return 4 * 3.14 * radius *radius;
}

double Sphere::getvolume()
{
	return 4.0 * 3.14 * radius * radius * radius / 3.0;
}

void Sphere::print()
{
	cout << "The sphere with radius " << getradius() << " that is located at (" << getx() << "," << gety() << "," << getz() << ") has:" << endl;
	cout << "Surface area of " << getarea() << endl;
	cout << "Volume of " << getvolume() << endl;
}