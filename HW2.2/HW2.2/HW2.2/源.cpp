// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 2 part 2
// Submitting date: Sep/16/2017
#include<iostream>
using namespace std;
int main()
{
	int max=0;
	while (max % 2 != 1)//detect input is odd
	{
		cout << "Please input maximun number of *(must be odd)" << endl;//input hint
		cin >> max;
	}
	for (int i = 1; i <= (max+1)/2; i++)//upper part of diamond
	{
		for (int j = 1; j <= (max + 1) / 2 - i; j++)//output spaces
			cout << " ";
		for (int k = 1; k <= i * 2 - 1; k++)//output *
			cout << "*" ;
		cout << endl;//finish each line
	}


	for (int i = (max + 1) / 2 - 1; i >= 1; i--)//down part of diamond
	{
		for (int j = 1; j <= (max + 1) / 2 - i; j++)//output spaces for the down part
			cout << " ";
		for (int k = (max + 1) / 2 - i; k <= (max + 1) / 2 - 2 + i; k++)//output *
			cout<<"*";
		cout<<endl;//finish each line
	}
	system("pause");
	
}