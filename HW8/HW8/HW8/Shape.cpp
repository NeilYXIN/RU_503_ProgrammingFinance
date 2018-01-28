#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape(double xValue, double yValue, double zValue):x(xValue),y(yValue),z(zValue)
{

}

void Shape::setx(double xValue)
{
	x = xValue;
}

void Shape::sety(double yValue)
{
	y = yValue;
}

void Shape::setz(double zValue)
{
	z = zValue;
}
double Shape::getx()
{
	return x;
}

double Shape::gety()
{
	return y;
}

double Shape::getz()
{
	return z;
}