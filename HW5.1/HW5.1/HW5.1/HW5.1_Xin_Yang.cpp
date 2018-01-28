// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 5.1
// Submitting date: Oct/12/2017
#include<iostream>
using namespace std;

void recursion(int num)
{
	if (num % 2 == 1 && num > 0)//if input is odd
	{
		cout << num*num;//if odd then print self
		if (num != 1)//seperate by comma
		{
			cout << ",";
		}
		recursion(num - 2);//recruse odd - 2 (need to > 0)
		if ((num - 1) != 0)//print comma and even number ascendingly, jump 0
		{
			cout << ",";
			cout << (num - 1)*(num - 1);
		}
	}
	if (num % 2 == 0 && num > 0)//if input is even
	{
		cout << (num - 1)*(num - 1);//print even - 1 first
		if (num != 2)//print comma after odd number
		{
			cout << ",";
		}
		recursion(num - 2);//recurse
		cout << ",";
		cout << num*num;
	}
}

int main()
{
	int num;
	cout << "Please input the number:";//ask user to type in
	cin >> num;//type number for num
	if (num > 0)//num need to be positive integer
	{
		recursion(num);//do recursion operation
		cout << endl;//for neat
	}
	else//invalid input number, ask to try again
	{
		cout << "invalid! need to be positive integer!" << endl;
	}
	return main();//return for the convenience of verify
}