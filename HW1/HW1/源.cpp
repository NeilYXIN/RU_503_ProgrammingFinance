
// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Compare Five Numbers Program
// Submitting date: Sep/9/2017
#include<iostream>
using namespace std;

int main()
{
	int num1, num2, num3, num4, num5, min, max;//define all needed variables
	cout << "Please input five numbers:" << endl;
	cin >> num1 >> num2 >> num3 >> num4 >> num5;//input five numbers
	if (num1 >= num2)//initialize min& max
	{
		max = num1;
		min = num2;
	}
	else
	{
		max = num2;
		min = num1;
	}
	if (num3 > max)//compare num3 with min& max then update
		max = num3;
	else if (num3 < min)
	{
		min = num3;
	}
	if (num4 > max)//compare num4 with min& max then update
	{
		max = num4;
	}
	else if (num4 < min)
	{
		min = num4;
	}
	if (num5 > max)//compare num5 with min& max then update
	{
		max = num5;
	}
	else if (num5 < min)
	{
		min = num5;
	}
	cout << "Max number is: " << max << endl << "Min number is: " << min << endl;//output final result
}

