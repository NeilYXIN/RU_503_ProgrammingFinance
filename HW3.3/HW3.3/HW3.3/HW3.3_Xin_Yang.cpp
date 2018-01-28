// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 3 using vector
// Submitting date: Oct/6/2017

#include<iostream>
#include<vector>
using namespace std;

void input(int *row, int *col, vector < vector <float> >& matrix)
{

	cout << "Please enter the number of row:" << endl;
	cin >> *row;
	cout << "Please enter the number of column:" << endl;
	cin >> *col;
	cout << "Please enter the elements:" << endl;
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			cin >> matrix[i][j];//set value to the elements in matrix
		}
	}

}

void display(vector < vector <float> > matrix, int *row, int *col)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			cout << matrix[i][j] << "\t";//show each row seperated by tabs
		}
		cout << endl;//seperate each row
	}
	cout << endl;
}

void addition(int *row1, int *row2, int *col1, int *col2, int *rowr, int *colr, vector < vector <float> >& matrix1, vector < vector <float> >& matrix2, vector < vector <float> >& mres)
{

	if (*row1 != *row2 || *col1 != *col2)//not supported if rows and columns inequal
	{
		cout << "The operation is not supported!" << endl << endl;
	}
	else
	{
		*rowr = *row1;//set mres row
		*colr = *col1;//set mres column
		for (int i = 0; i < *row1; i++)
		{
			for (int j = 0; j < *col1; j++)
			{
				mres[i][j] = matrix1[i][j] + matrix2[i][j];//calculate result
			}
		}
	}
}

void subtraction(int *row1, int *row2, int *col1, int *col2, int *rowr, int *colr, vector < vector <float> >& matrix1, vector < vector <float> >& matrix2, vector < vector <float> >& mres)
{

	if (*row1 != *row2 || *col1 != *col2)//not supported if rows and columns inequal
	{
		cout << "The operation is not supported!" << endl << endl;
	}
	else
	{
		*rowr = *row1;//set mres row
		*colr = *col1;//set mres column
		for (int i = 0; i < *row1; i++)
		{
			for (int j = 0; j < *col1; j++)
			{
				mres[i][j] = matrix1[i][j] - matrix2[i][j];//calculate subtraction
			}
		}
	}
}


void multiplication(int *row1, int *row2, int *col1, int *col2, int *rowr, int *colr, vector < vector <float> >& matrix1, vector < vector <float> >& matrix2, vector < vector <float> >& mres)
{
	if (*col1 != *row2)//not surpported if col1 != row2
	{
		cout << "The operation is not supported!" << endl << endl;
	}
	else
	{
		*rowr = *row1;
		*colr = *col2;
		for (int i = 0; i < *rowr; i++)
		{
			for (int j = 0; j < *colr; j++)
			{
				mres[i][j] = 0;
				for (int k = 0; k < *col1; k++)
				{
					mres[i][j] += matrix1[i][k] * matrix2[k][j];//calculate and set result
				}
			}
		}
	}
}

void transpose(int *row1, int *col1, int *rowr, int *colr, vector < vector <float> >& matrix1, vector < vector <float> >& mres)
{
	*rowr = *col1;
	*colr = *row1;
	for (int i = 0; i < *rowr; i++)
	{
		for (int j = 0; j < *colr; j++)
		{
			mres[i][j] = matrix1[j][i];//transpose to mres
		}
	}
}

void determinant(int *row1, int *col1, vector < vector <float> >& matrix1, float *det)
{
	if (*row1 != 3 || *col1 != 3)
	{
		cout << "The operation is not supported!" << endl << endl;
	}
	else//calculate inverse
	{
		*det = matrix1[0][0] * matrix1[1][1] * matrix1[2][2] + matrix1[1][0] * matrix1[2][1] * matrix1[0][2] + matrix1[2][0] * matrix1[0][1] * matrix1[1][2]
			- matrix1[2][0] * matrix1[1][1] * matrix1[0][2] - matrix1[2][1] * matrix1[1][2] * matrix1[0][0] - matrix1[2][2] * matrix1[1][0] * matrix1[0][1];
	}
}

void inverse(int *row1, int *col1, int *rowr, int *colr, vector < vector <float> >& matrix1, vector < vector <float> >& mres)
{
	float det = -1;
	determinant(&*row1, &*col1, matrix1, &det);//get det first
	if (det == 0)
	{
		cout << "The operation is not supported!" << endl << endl;
	}
	else//calculate inverse
	{
		*rowr = 3;
		*colr = 3;
		mres[0][0] = (matrix1[1][1] * matrix1[2][2] - matrix1[1][2] * matrix1[2][1]) / det;
		mres[0][1] = (matrix1[0][2] * matrix1[2][1] - matrix1[0][1] * matrix1[2][2]) / det;
		mres[0][2] = (matrix1[0][1] * matrix1[1][2] - matrix1[0][2] * matrix1[1][1]) / det;

		mres[1][0] = (matrix1[1][2] * matrix1[2][0] - matrix1[1][0] * matrix1[2][2]) / det;
		mres[1][1] = (matrix1[0][0] * matrix1[2][2] - matrix1[0][2] * matrix1[2][0]) / det;
		mres[1][2] = (matrix1[1][0] * matrix1[0][2] - matrix1[0][0] * matrix1[1][2]) / det;

		mres[2][0] = (matrix1[1][0] * matrix1[2][1] - matrix1[1][1] * matrix1[2][0]) / det;
		mres[2][1] = (matrix1[0][1] * matrix1[2][0] - matrix1[0][0] * matrix1[2][1]) / det;
		mres[2][2] = (matrix1[0][0] * matrix1[1][1] - matrix1[1][0] * matrix1[0][1]) / det;
	}
}
int main()
{
	while (true)
	{
		//declare variables when new menu appeared
		int choice = 0;
		int row1, col1 = 0;
		vector < vector <float> > matrix1(10);//set 2-dimension vector
		for (int i = 0; i < 10; i ++)//initialize
			matrix1[i].resize(10);//set as 10x10

		int row2, col2 = 0;
		vector < vector <float> > matrix2(10);//set 2-dimension vector
		for (int i = 0; i < 10; i++)//initialize
			matrix2[i].resize(10);//set as 10x10

		int rowr, colr = { 0 };
		vector < vector <float> > mres(10);//set 2-dimension vector
		for (int i = 0; i < 10; i++)//initialize
			mres[i].resize(10);//set as 10x10

		cout << "Menu " << endl << " Choice 1: Addition" << endl << " Choice 2: Subtraction" << endl << " Choice 3: Multiplication" << endl
			<< " Choice 4: Transpose" << endl << " Choice 5: Determinant(3x3)" << endl << " Choice 6: Inverse(3x3)" << endl << " Choice 7: Quit" << endl << "Enter your choice:" << endl;
		cin >> choice;
		switch (choice)
		{
		default://default quit
			break;
		case 1://addition
		{
			input(&row1, &col1, matrix1);//input matrix1
			cout << "Your input is:" << endl;//display input hint 
			display(matrix1, &row1, &col1);//display matrix1

			input(&row2, &col2, matrix2);//input matrix2
			cout << "Your input is:" << endl;//display input hint
			display(matrix2, &row2, &col2);//display matrix2
			addition(&row1, &row2, &col1, &col2, &rowr, &colr, matrix1, matrix2, mres);//call addition func
			cout << "Your result is:" << endl;//output hint
			display(mres, &rowr, &colr);//display result;
			break;
		}
		case 2://subtraction
		{
			input(&row1, &col1, matrix1);//input matrix1
			cout << "Your input is:" << endl;//display input hint 
			display(matrix1, &row1, &col1);//display matrix1
			input(&row2, &col2, matrix2);//input matrix2
			cout << "Your input is:" << endl;//display input hint
			display(matrix2, &row2, &col2);//display matrix2
			subtraction(&row1, &row2, &col1, &col2, &rowr, &colr, matrix1, matrix2, mres);//call subtraction func
			cout << "Your result is:" << endl;//output hint
			display(mres, &rowr, &colr);//display result;
			break;
		}
		case 3://multiplication
		{
			input(&row1, &col1, matrix1);//input matrix1
			cout << "Your input is:" << endl;//display input hint 
			display(matrix1, &row1, &col1);//display matrix1
			input(&row2, &col2, matrix2);//input matrix2
			cout << "Your input is:" << endl;//display input hint
			display(matrix2, &row2, &col2);//display matrix2
			multiplication(&row1, &row2, &col1, &col2, &rowr, &colr, matrix1, matrix2, mres);//call multiplication func
			cout << "Your result is:" << endl;//output hint
			display(mres, &rowr, &colr);//display result;
			break;
		}
		case 4://transpose
		{
			input(&row1, &col1, matrix1);//input matrix1
			cout << "Your input is:" << endl;//display input hint 
			display(matrix1, &row1, &col1);//display matrix1
			transpose(&row1, &col1, &rowr, &colr, matrix1, mres);
			cout << "Your result is:" << endl;//output hint
			display(mres, &rowr, &colr);//display result;
			break;
		}
		case 5://determinant
		{
			input(&row1, &col1, matrix1);//input matrix1
			cout << "Your input is:" << endl;//display input hint 
			display(matrix1, &row1, &col1);//display matrix1
			float det = 0;//declare det
			determinant(&row1, &col1, matrix1, &det);//call determinant func
			cout << "Your result is:" << endl;//output hint
			cout << det << endl;//display result;
			break;
		}
		case 6://inverse
		{
			input(&row1, &col1, matrix1);//input matrix1
			cout << "Your input is:" << endl;//display input hint 
			display(matrix1, &row1, &col1);//display matrix1
			inverse(&row1, &col1, &rowr, &colr, matrix1, mres);//call inverse func
			cout << "Your result is:" << endl;//output hint
			display(mres, &rowr, &colr);//display result;
			break;
		}
		case 7://quit
			break;
		}

		if (choice == 7)//quit loop
		{
			break;
		}
	}



	//system("pause");
}