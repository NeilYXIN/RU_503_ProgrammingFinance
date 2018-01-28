// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 6
// Submitting date: Oct/16/2017
#include"Booklist_Yang.h"
#include<iostream>
using namespace std;
Booklist::Booklist()//constructor function
{
	for (int i = 0; i < 20; i++)//initialize all elements as 0
	{
		this->isbn[i] = 0;
	}
	this->numinl = 0;//set number in list as 0
	this->sorted = false;//set sorted as false
}

int Booklist::getnuminl()//update num in list when needed
{
	this->numinl = 0;
	for (int i = 0; i < 20; i++)//traversal
	{
		if (this->isbn[i] == 0)
		{
			this->numinl = i;
			break;
		}
		if (this->isbn[19] != 0)//list is full
			this->numinl = 20;
	}
	return this->numinl;
}

void Booklist::insert(int new_element)//insert at the end of list
{
	this->isbn[this->numinl] = new_element;
}

void Booklist::insert_at(int at_position, int new_element)//insert at location
{
	if (this->numinl == 20 || at_position <= 0 || at_position > 20 || at_position > this->numinl + 1)//detect error
	{
		cout << "invalid position!" << endl;
	}
	else
	{
		for (int i = this->numinl - 1; i >= at_position - 1; i--)//insert at location and adjust list
		{
			this->isbn[i + 1] = this->isbn[i];
		}
		this->isbn[at_position - 1] = new_element;
	}
}


int Booklist::find_linear( int element)
{
	for (int i = 0; i < this->numinl; i++)//search from  front to end
	{
		if (this->isbn[i] == element)
		{
			return i + 1;
		}
	}
	return 0;
}

int Booklist::find_binary( int element)//binary search
{
	int left = 0;
	int right = this->numinl - 1;
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (element == this->isbn[middle])//find element and return
		{
			return middle + 1;
		}
		else
		{
			if (element < this->isbn[middle])//element on the left side
			{
				right = middle - 1;//update right
			}
			else
			{
				left = middle + 1;//element on right side update left
			}
		}
	}
	return 0;
}

void Booklist::delete_item_position(int position)
{
	for (int i = position - 1; i < this->numinl; i++)//traversal and find position
	{
		this->isbn[i] = this->isbn[i + 1];//move back elements ahead
	}
}

void Booklist::delete_item_isbn(int element)
{
	int flag = 0;
	for (int i = 0; i < this->numinl; i++)//find element by isbn
	{
		if (this->isbn[i] == element)
		{
			flag = 1;//set flag in case no such element exist
			for (int j = i; j < this->numinl; j++)
			{
				this->isbn[j] = this->isbn[j + 1];
			}
		}
	}
	if (flag == 0)//no element exist
	{
		cout << "invalid element!" << endl;
	}
}

void Booklist::sort_list_selection()
{
	int j, k, smallest, index;
	for (k = 0; k < this->numinl - 1; k++)//loop to compare num in list - 1 rounds
	{
		smallest = *(this->isbn + k);
		index = k;
		for (j = k + 1; j < this->numinl; j++)//for each k, compare and move the smallest
		{
			if (*(this->isbn + j) < smallest)
			{
				smallest = *(this->isbn + j);
				index = j;
			}
		}
		int temp = *(this->isbn + index);//change smallest and current
		*(this->isbn + index) = *(this->isbn + k);
		*(this->isbn + k) = temp;
	}
}

void Booklist::sort_list_bubble()
{
	for (int i = 0; i < this->numinl - 1; i++)//loop num in list -2 rounds
	{
		for (int j = 0; j < this->numinl - 1 - i; j++)//each round put biggest of left elements to the last
		{
			if (*(this->isbn + j)>*(this->isbn + j + 1))
			{
				int t = *(this->isbn + j + 1);
				*(this->isbn + j + 1) = *(this->isbn + j);
				*(this->isbn + j) = t;
			}
		}
	}
}

void Booklist::print()
{

	for (int i = 0; i < 20; i++)//traversal the list
	{
		if (this->isbn[i] != 0)
		{
			cout << i + 1 << ". " << this->isbn[i] << endl; // output if element exists
		}
	}
	cout << endl;
}

void Booklist::issorted()//return if the list is sorted or not
{
	for (int i = 0; i < this->numinl - 1; i++)
	{
		if (this->isbn[i + 1] < this->isbn[i])
		{
			this->sorted = false;
			break;
		}
		else this->sorted = true;
	}

}

int Booklist::returnnuminl()//return number in list
{
	return this->numinl;
}

bool Booklist::returnsorted()//return sorted or not
{
	return this->sorted;
}