#pragma once
#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H


#include "Shape.h"

class TwoDimensionalShape : public Shape
{
public:
	TwoDimensionalShape(double = 0, double = 0);
	double getarea();
//	void setarea(double areaValue);

private:
	double area;

};

#endif // !TWODIMENSIONALSHAPE_H