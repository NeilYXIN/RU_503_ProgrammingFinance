#include <iostream>
using namespace std;
bool Jump(int a, int b, int c[], int size);
int main()
{
	int c[10] = {};
	int i = 0;
	int counter = 0;

	cout << "Input:" << endl;
	cin >> c[i];

	while (c[i] != 0) {
		cout << "Input" << endl;
		i++;
		cin >> c[i];
	}
	cout << i + 1 << endl;
	for (int j = 0; j < i + 1; j++)
	{
		cout << c[j] << " ";

	}cout << endl;
	int size = i + 1;
	bool t = Jump(0, c[0], c, size);
	cout << t << endl;
	for (int j = 0; j < i + 1; j++)
	{
		cout << c[j] << " ";
	}
	system("pause");
	return 0;
}


bool Jump(int a, int b, int c[], int size)
{
	int hold = 0;
	int temp = 0;
	if (b == 0)
		return true;

	if (b < 0)
		return false;
	else
	{
		temp = c[a];
		c[a] = -1;
	}


	if (b <(size - a))
	{
		hold = temp;
		c[a] = -1;
	//	a += hold;
	//	b = c[a];
		if (Jump(a+hold, c[a+hold], c, size))
			return true;
	}

	if (b < (a + 1))
	{
		hold = temp;
		c[a] = -1;
	//	a -= hold;
	//	b = c[a];
		if (Jump(a-hold, c[a-hold], c, size))
			return true;
		else
			return false;
	}
	return false;
}

