#include "ThreeDimensionalShape.h"
#include <iostream>
using namespace std;

ThreeDimensionalShape::ThreeDimensionalShape(double xValue, double yValue, double zValue) :Shape(xValue, yValue, zValue)
{

}

double ThreeDimensionalShape::getarea()
{
	return area;
}

double ThreeDimensionalShape::getvolume()
{
	return volume;
}
