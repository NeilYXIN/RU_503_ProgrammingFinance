// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 3
// Submitting date: Sep/20/2017
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

// function main begins program execution
int main() {
	ofstream file;
	//opens the file myfile.txt
	file.open("myfile.txt");
	srand(time(0));
	double x = 0, y = 0, pi = 0;
	int count = 0, valid = 0;
	//for loop to write the values to the file
	for (int i = 0; i<100; i++) {
		count++;//count all generated numbers
		x = double(rand()) / RAND_MAX;//make sure x in range 0~1
		y = double(rand()) / RAND_MAX;//make sure y in range 0~1
		file << x << "," << y << "\n";
		if ((x * x + y * y) <= 1)
		{
			valid++;//if in the circle, increase valid count
		}
	}
	pi = 4. * valid / count;//Monte Carlo method of calculating pi
	cout << "Printed numbers to file myfile.txt\n";
	cout << "Estimated pi is: " << pi << endl;//output estimeted result
	system("pause");
}