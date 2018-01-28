// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Inclass 4
// Submitting date: Oct/7/2017
#include<iostream>
#include<string>
using namespace std;

int recursion(string s, char c, int count, int pos)
{
	if (s[pos] == c)
	{
		count++;
	}
	if (s[pos + 1])
	{
		count = recursion(s, c, count, pos + 1);
	}
	return count;
}

int main()
{
	string s;
	char c;
	int count = 0;
	int pos = 0;
	cout << "Please typein string: " << endl;
	cin >> s;
	cout << "Please typein character: " << endl;
	cin >> c;
		if (s.empty())
		{
			cout << "c appeared in s " << 0 << " times." << endl;
		}
		else
		{
			int res = recursion(s, c, count, pos);
			cout << "c appeared in s " << res << " times." << endl;
		}
	system("pause");
}