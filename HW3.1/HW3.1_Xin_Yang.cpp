// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Inclass Homework 3
// Submitting date: Sep/23/2017
#include<iostream>
#include<string>
using namespace std;
void input(int count, int votes[20][5])
{
	int temp = 0;//to save user input
	cout << "Student No." << count << "  Please vote candidates 1 to 5:" << endl;
	cin >> temp;
	while (temp>5||temp<1)//when enter wrong number, try again
	{
		cout << "Student No." << count<< "  Invalid input, please try again:" << endl;
		cin >> temp;
	}
	votes[count-1][temp-1]++;//update array votes

	cout << "Sure?yes/no" << endl;//ask if it needs to be changed
	string tp;
	cin >> tp;
	while (tp=="no")//while no sure, change vote
	{
		votes[count - 1][temp - 1]--;//cancel vote
		cout << "Please vote again:" << endl;
		cin >> temp;
		while (temp>5 || temp<1)//when enter wrong number, try again
		{
			cout << "Student No." << count << "  Invalid input, please try again:" << endl;
			cin >> temp;
		}
		votes[count - 1][temp - 1]++;//update array votes
		tp = "y";//avoid dead loop
	}

}

void counting(int sum[5], int votes[20][5])//count votes for every candidates
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			sum[i] += votes[j][i];//for candidates i, add votes[i]
		}
	}
}



void printArray(int votes[20][5])//to show votes of every person
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << votes[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int votes[20][5];//votes for every candidates
	for (int i = 0; i < 20; i++)//initialize array
	{
		for (int j = 0; j < 5; j++)
		{
			votes[i][j] = 0;
		}
	}
	int count = 1;
	for (count = 1; count <= 20; count++)//ask 20 students to input their votes
	{
		input(count, votes);//call input function to vote
	}
	printArray(votes);//for test

	int sum[5] = { 0,0,0,0,0 };
	counting(sum,votes);//sum votes 
	cout << sum[0] << sum[1] << sum[2] << sum[3] << sum[4];//for test

	

	int max = sum[0];//find max vote
	sum[0] = -1 * sum[0];//mark in case candidate 1 was max
	int maxnum = 0;//winner number
	for (int i = 1; i < 5; i++)//find max vote
	{
		if (sum[i]>=max)//bigger than former max
		{
			max = sum[i];
			maxnum = i;
			sum[i] = -1 * sum[i];//if was max,mark as opposite in case of no winner situation
		}
	}
	for (int i = 0; i < 5; i++)//find if there're two max votes
	{
		sum[i] += max;
		if (sum[i] == 0 && i != maxnum)//if there're two max, besides maxnum there should be another 0
		{
			cout << "There's no winner." << endl;
			system("pause");
			return 0;
		}
	}
	cout << "Winner is Candidate " << maxnum+1 << endl;//output winner info
	system("pause");
	return 0;
}