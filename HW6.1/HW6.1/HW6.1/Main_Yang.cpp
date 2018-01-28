// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 6
// Submitting date: Oct/16/2017
#include"Booklist_Yang.h"
#include<iostream>
using namespace std;
void welcome(int* input)//show welcome menu info
{
	cout << "Welcome to the Book list program." << endl << "What would you like to do ?" << endl;
	cout << "    1. add an emelent to end of list" << endl;
	cout << "    2. add an element at a location" << endl;
	cout << "    3. find an element by ISBN number (linear search)" << endl;
	cout << "    4. find an element by ISBN number (binary search)" << endl;
	cout << "    5. delete an element at a position" << endl;
	cout << "    6. delete an element by ISBN number" << endl;
	cout << "    7. sort the list (using selection sort)" << endl;
	cout << "    8. sort the list (using bubble sort)" << endl;
	cout << "    9. print the list" << endl;
	cout << "    0. exit" << endl;
	cin >> *input;
	cout << "your choice is: " << *input << endl;
}

int main()
{
	int input = -1;
	int pos = -1;
	int num = 0;

	Booklist booklist;//create instance Booklist
	while (input != 0)
	{
		welcome(&input);//show welcome information

		switch (input)
		{
		default://invalid input
		{
			cout << "invalid choice!" << endl;
			break;
		}
		case 0://break loop and exit
		{
			break;
		}
		case 1://insert at the end
		{

			num = 0;
			cout << "Please type in the element: ";
			cin >> num;
			booklist.getnuminl();//get num in list and determine if it's full
			if (booklist.returnnuminl() == 20)
			{
				cout << "list is full!" << endl;
			}
			else
			{
				booklist.insert(num);//do insert
				booklist.getnuminl();//update num in list
				booklist.print();//print current list
			}
			break;
		}
		case 2://insert at position
		{
			pos = 0;
			num = 0;
			cout << "Please type in the element: ";
			cin >> num;
			cout << "Please type in the position: ";
			cin >> pos;
			booklist.getnuminl();
			booklist.insert_at(pos, num);//do insert
			booklist.getnuminl();//update num in list
			booklist.print();//print current list
			break;
		}
		case 3://find element by isbn
		{
			pos = 0;
			booklist.getnuminl();
			cout << "Please type in the element: ";
			cin >> num;
			pos = booklist.find_linear(num);//find position or return 0 for invalid element
			if (pos == 0)
			{
				cout << "No such element!" << endl;//no such element exist
			}
			else
			{
				cout << "The position is: " << pos << endl;//output location
			}
			break;
		}
		case 4://find element by isbn
		{
			pos = 0;
			booklist.getnuminl();
			cout << "Please type in the element: ";
			cin >> num;
			booklist.issorted();//update sorted
			if (booklist.returnsorted())//if sorted run binary search
			{
				pos = booklist.find_binary(num);
				if (pos == 0)
				{
					cout << "No such element!" << endl;
				}
				else
				{
					cout << "The position is: " << pos << endl;
				}
			}
			else//if not sorted, ask user to sort first
			{
				cout << "Need to be sorted first!" << endl;
			}
			break;
		}
		case 5://delete elemnt by position
		{

			cout << "Please type in the deleted postion: ";
			cin >> pos;
			booklist.getnuminl();//get num in list
			if (pos <= booklist.returnnuminl() || pos <= 0)//delete if input position is valid
			{
				booklist.delete_item_position(pos);//do delete operation
				booklist.getnuminl();//update num in list
				booklist.print();//print new list
			}
			else//output invalid position if out of boundary
			{
				cout << "invalid position!" << endl;
			}
			break;
		}
		case 6://delete by element
		{
			cout << "Please type in the deleted element: ";
			cin >> num;
			booklist.getnuminl();//update num in list
			booklist.delete_item_isbn(num);// do delete operation
			booklist.getnuminl();//update num in list
			booklist.print();//print new list		
			break;
		}
		case 7://sort
		{
			booklist.getnuminl();
			booklist.sort_list_selection();//do sort
			booklist.print();//output result
			break;
		}
		case 8://bubble sort
		{
			booklist.getnuminl();
			booklist.sort_list_bubble();//do bubble sort
			booklist.print();//print result
			break;
		}
		case 9://print list
		{
			booklist.getnuminl();//get num in list
			booklist.print();//call print function
			break;
		}

		}
	}



}