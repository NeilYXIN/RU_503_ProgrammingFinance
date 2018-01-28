// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 2 part 1
// Submitting date: Sep/16/2017
#include<iostream>
using namespace std;
int main()
{
	int max = 0;
	cout << "Please input the maximum number of *:" << endl;//input hint
	cin >> max;
	for (int i = 1; i <= max; i++)//loop for numbers of line
	{
		for (int j = 1; j <= i; j++)//loop for numbers of * in every line
		{
			cout << "*";
		}
		cout << endl;//finish each line
	}
	system("pause");
}