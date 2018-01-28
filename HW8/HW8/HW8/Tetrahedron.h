#pragma once
#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H
#include "ThreeDimensionalShape.h"
class Tetrahedron : public ThreeDimensionalShape
{
public:
	Tetrahedron(double = 0, double = 0, double = 0, double = 0);
	void setedge(double edgeValue);
	double getedge();
	double getarea();
	double getvolume();
	void print();

private:
	double edge;
};
#endif // !TETRAHEDRON_H
