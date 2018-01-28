// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Inclass 6
// Submitting date: Nov/4/2017
#include "threedimensionalpoint.h"

ThreeDimensionalPoint::ThreeDimensionalPoint(){
	setx(0);
	sety(0);
	setz(0);
}

ThreeDimensionalPoint::ThreeDimensionalPoint(int xin, int yin, int zin){
	//please implement this constructor to set the x, y and z values to the input parameter values
	setx(xin);
	sety(yin);
	setz(zin);
}
int ThreeDimensionalPoint::getz(){
	//please implement this function to get the z value
	return z;
}
void ThreeDimensionalPoint::setz(int zin){
	//please implement this function to set z value
	z = zin;
}

void ThreeDimensionalPoint::addPoints(ThreeDimensionalPoint pointin){
	//please implement this function to add the x,y and z values of point1 to values of the calling instance of the object
	setx(getx() + pointin.getx());
	sety(gety() + pointin.gety());
	setz(getz() + pointin.getz());
}