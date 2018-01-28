// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 4
// Submitting date: Oct/8/2017
#include<iostream>
using namespace std;
int getnuminl(int mylist[], int* numinl)//update num in list when needed
{
	*numinl = 0;
	for (int i = 0; i < 20; i++)//traversal
	{
		if (mylist[i] == 0)
		{
			*numinl = i;
			break;
		}
		if (mylist[19] != 0)//list is full
			*numinl = 20;
	}
	return *numinl;
}
void insert(int mylist[], int num_in_list, int new_element)//insert at the end of list
{
	mylist[num_in_list] = new_element;
}
void insert_at(int mylist[], int num_in_list, int at_position, int new_element)//insert at location
{
	if (num_in_list == 20 || at_position <= 0 || at_position > 20 || at_position > num_in_list+1)//detect error
	{
		cout << "invalid position!" << endl;
	}
	else
	{
		for (int i = num_in_list-1; i >= at_position-1; i--)//insert at location and adjust list
		{
			mylist[i + 1] = mylist[i];
		}
		mylist[at_position - 1] = new_element;
	}
}
int find_linear(int mylist[], int num_in_list, int element)
{
	for (int i = 0; i < num_in_list; i++)//search from  front to end
	{
		if (mylist[i] == element)
		{
			return i + 1;
		}
	}
	return 0;
}
int find_binary(int mylist[], int num_in_list, int element, bool sorted)//binary search
{
	int left = 0;
	int right = num_in_list - 1;
	int middle;
	while (left <= right)
	{
		 middle = (left + right) / 2;
		if (element == mylist[middle])//find element and return
		{
			return middle+1;
		}
		else
		{
			if (element < mylist[middle])//element on the left side
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
void delete_item_position(int mylist[], int num_in_list, int position)
{
	for (int i = position-1; i < num_in_list; i++)//traversal and find position
	{
		mylist[i] = mylist[i + 1];//move back elements ahead
	}
}
void delete_item_isbn(int mylist[], int num_in_list, int element)
{
	int flag = 0;
	for (int i = 0; i < num_in_list; i++)//find element by isbn
	{
		if (mylist[i] == element)
		{
			flag = 1;//set flag in case no such element exist
			for (int j = i; j < num_in_list; j++)
			{
				mylist[j] = mylist[j + 1];
			}
		}
	}
	if (flag == 0)//no element exist
	{
		cout << "invalid element!" << endl;
	}
}
void sort_list_selection(int mylist[], int num_in_list)
{
	int j, k, smallest,index;
	for (k = 0;k < num_in_list-1; k++)//loop to compare num in list - 1 rounds
	{
		smallest = *(mylist+k);
		index = k;
		for (j = k + 1; j < num_in_list; j++)//for each k, compare and move the smallest
		{
			if (*(mylist + j) < smallest)
			{
				smallest = *(mylist + j);
				index = j;
			}
		}
		int temp = *(mylist + index);//change smallest and current
		*(mylist + index) = *(mylist + k);
		*(mylist + k) = temp;
	}
}
void sort_list_bubble(int mylist[], int num_in_list)
{
	for (int i = 0; i < num_in_list-1; i++)//loop num in list -2 rounds
	{
		for (int j = 0; j < num_in_list - 1 - i; j++)//each round put biggest of left elements to the last
		{
			if (*(mylist+j)>*(mylist+j+1))
			{
				int t = *(mylist + j + 1);
				*(mylist + j + 1) = *(mylist + j);
				*(mylist + j) = t;
			}
		}
	}
}
void print(int mylist[], int num_in_list)
{
	
	for (int i = 0; i < 20; i++)//traversal the list
	{
		if (mylist[i] != 0)
		{
			cout << i+1 <<". " << mylist[i] << endl; // output if element exists
		}
	}
	cout << endl;
}
void issorted(int mylist[], int numinl, bool *sorted)//return if the list is sorted or not
{
	for (int i = 0; i < numinl - 1; i++)
	{
		if (mylist[i+1] < mylist[i] )
		{
			*sorted = false;
			break;
		}
		else *sorted = true;
	}
	
}


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
	bool sorted = true;
	int input = -1;
	int pos = -1;
	int num = 0;
	int numinl = 0;
	int isbn[20] = {0};
	while (input != 0)
	{
		welcome(&input);
		
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
			cout << "Please type in the element: " ;
			cin >> num;
			getnuminl(isbn, &numinl);//get num in list and determine if it's full
			if (numinl == 20)
			{
				cout << "list is full!" << endl;
			}
			else
			{
				insert(isbn, numinl, num);//do insert
				getnuminl(isbn, &numinl);//update num in list
				print(isbn, numinl);//print current list
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
			getnuminl(isbn, &numinl);	
			insert_at(isbn, numinl, pos, num);//do insert
			getnuminl(isbn, &numinl);//update num in list
			print(isbn, numinl);//print current list
			
			
		
			break;
		}
		case 3://find element by isbn
		{
			pos = 0;
			getnuminl(isbn, &numinl);
			cout << "Please type in the element: ";
			cin >> num;
			pos = find_linear(isbn, numinl, num);//find position or return 0 for invalid element
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
			getnuminl(isbn, &numinl);
			cout << "Please type in the element: ";
			cin >> num;
			issorted(isbn, numinl, &sorted);//update sorted
			if (sorted)//if sorted run binary search
			{
				pos = find_binary(isbn, numinl, num, sorted);
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
			getnuminl(isbn, &numinl);//get num in list
			if (pos <= numinl || pos <= 0)//delete if input position is valid
			{
				delete_item_position(isbn, numinl, pos);//do delete operation
				getnuminl(isbn, &numinl);//update num in list
				print(isbn, numinl);//print new list
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
			getnuminl(isbn, &numinl);//update num in list
			delete_item_isbn(isbn, numinl, num);// do delete operation
			getnuminl(isbn, &numinl);//update num in list
			print(isbn, numinl);//print new list		
			break;
		}
		case 7://sort
		{
			getnuminl(isbn, &numinl);
			sort_list_selection(isbn, numinl);//do sort
			print(isbn, numinl);//output result
			break;
		}
		case 8://bubble sort
		{
			getnuminl(isbn, &numinl);
			sort_list_bubble(isbn, numinl);//do bubble sort
			print(isbn, numinl);//print result
			break;
		}
		case 9://print list
		{
			getnuminl(isbn, &numinl);//get num in list
			print(isbn, numinl);//call print function
			break;
		}

		}
	}


	
}