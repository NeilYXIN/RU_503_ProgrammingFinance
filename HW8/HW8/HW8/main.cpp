#include <iostream>

#include "Circle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Tetrahedron.h"
using namespace std;

void printmenu()
{
	cout << "Please choose a shape or 0 to exit:" << endl;
	cout << "1.Circle" << endl;
	cout << "2.Triangle" << endl;
	cout << "3.Sphere" << endl;
	cout << "4.Regular Tetrahedron" << endl;
	cout << "0.Exit" << endl;
	cout << "Choice: ";
	
}

int main()
{
	int choice = 1;
	double x = 0, y = 0, z = 0;
	while (true)
	{
		printmenu();
		cin >> choice;
		switch (choice)
		{
		default:
		{
			cout << "Invalid Choice!" << endl;
			break;
		}

		case 0:
		{
			return 0;
		}
		case 1:
		{
			double r = 0;
			cout << "Please enter the center of the circle (x-coordinate and then y-coordinate): " << endl;
			cin >> x >> y;
			cout << "Please enter the radius of the circle: " << endl;
			cin >> r;

			Circle circle(x, y, r);
			circle.print();

			break;
		}

		case 2:
		{
			double edge = 0;
			cout << "Please enter the center of the triangle (x-coordinate and then y-coordinate): " << endl;
			cin >> x >> y;
			cout << "Please enter the edge length of the triangle: " << endl;
			cin >> edge;

			Triangle triangle(x, y, edge);
			triangle.print();

			break;
		}

		case 3:
		{
			double r = 0;
			cout << "Please enter the center of the sphere (x-coordinate, y-coordinate, then z-coordinate): " << endl;
			cin >> x >> y >> z;
			cout << "Please enter the radius of the sphere: " << endl;
			cin >> r;

			Sphere sphere(x, y, z, r);
			sphere.print();
			break;
		}

		case 4:
		{
			double edge = 0;
			cout << "Please enter the center of the tetrahedron (x-coordinate, y-coordinate, then z-coordinate): " << endl;
			cin >> x >> y >> z;
			cout << "Please enter the edge length of the tetrahedron: " << endl;
			cin >> edge;

			Tetrahedron tetrahedron(x, y, z, edge);
			tetrahedron.print();
			break;
		}
		}

	}

}
	

	

	
