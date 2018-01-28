#pragma once
#ifndef SPHERE_H
#define SPHERE_H
#include "ThreeDimensionalShape.h"
class Sphere : public ThreeDimensionalShape
{
public:
	Sphere(double = 0, double = 0, double = 0, double = 0);
	void setradius(double radiusValue);
	double getradius();
	double getarea();
	double getvolume();
	void print();

private:
	double radius;
};
#endif // !SPHERE_H

