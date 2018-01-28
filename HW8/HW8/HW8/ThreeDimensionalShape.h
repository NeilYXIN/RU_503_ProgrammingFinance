#pragma once
#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H
#include "Shape.h"
class ThreeDimensionalShape: public Shape
{
public:
	ThreeDimensionalShape(double = 0, double = 0, double = 0);
	double getarea();
	double getvolume();
	//	void setarea(double areaValue);

private:
	double area;
	double volume;
};
#endif // !THREEDIMENSIONALSHAPE_H
