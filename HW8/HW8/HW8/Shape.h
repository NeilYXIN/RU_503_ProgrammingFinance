#pragma once
#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	Shape(double = 0, double = 0, double = 0);
	double getx();
	double gety();
	double getz();
	void setx(double xValue);
	void sety(double yValue);
	void setz(double zValue);

private:
	double x;
	double y;
	double z;

};


#endif // !SHAPE_H
