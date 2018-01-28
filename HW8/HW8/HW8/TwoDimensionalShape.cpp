#include "TwoDimensionalShape.h"
#include <iostream>
using namespace std;

TwoDimensionalShape::TwoDimensionalShape(double xValue, double yValue):Shape(xValue, yValue)
{
	
}

double TwoDimensionalShape::getarea()
{
	return area;
}

