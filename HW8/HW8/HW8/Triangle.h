#pragma once
#ifndef TRIANGLE_H
#define TRIANLGE_H
#include "TwoDimensionalShape.h"
class Triangle: public TwoDimensionalShape
{
public:
	Triangle(double = 0, double = 0, double = 0);
	void setedge(double edgeValue);
	double getedge();
	double getarea();
	void print();
private:
	double edge;
};
#endif // !TRIANGLE_H
