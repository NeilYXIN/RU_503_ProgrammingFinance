// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 10
// Submitting date: Nov/13/2017
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

void printmenu()//print menu function
{
	cout << "Please choose an option :" << endl;
	cout << "1.  Add a new node at the beginning" << endl;
	cout << "2.  Add a new node at the end" << endl;
	cout << "3.  Remove the beginning node" << endl;
	cout << "4.  Remove the end node" << endl;
	cout << "5.  Remove a node from the list by entering an item number" << endl;
	cout << "6.  Remove a node from the list by entering an item name" << endl;
	cout << "7.  Print out the list" << endl;
	cout << "8.  Quit the program" << endl;
}

int main()
{
	LinkedList list;//new linkedlist instance
	int choice = 0;
	string newname = "";
	int newnum = 0;
	string delname = "";
	int delnum = -1;
	while (choice != 8)
	{
		printmenu();//print menu
		cin >> choice;//get user choice
		switch (choice)
		{
		default://default invalid number
		{
			cout << "invalid choice!" << endl << endl;
			break;
		}
		case 1://insert at first
		{
			newnum = 0;
			newname = "";
			cout << "Please enter product number to insert at the beginning:" << endl;
			cin >> newnum;
			cout << "Please enter the name for the product:" << endl;
			cin >> newname;
			//have to create new node
			Node * newnode = new Node(newname, newnum);
			list.addToStart(newnode);
			list.printList();
			break;
		}
		case 2://insert at last
		{
			newnum = 0;
			newname = "";
			cout << "Please enter product number to insert at the end:" << endl;
			cin >> newnum;
			cout << "Please enter the name for the product:" << endl;
			cin >> newname;
			//have to create new node
			Node * newnode = new Node(newname, newnum);
			list.addToEnd(newnode);
			list.printList();
			break;
		}
		case 3://delete first
		{
			list.removeFromStart();
			list.printList();
			break;
		}
		case 4://delete last
		{
			list.removeFromEnd();
			list.printList();
			break;
		}
		case 5://delete by number
		{
			cout << "Please enter the Number to delete:" << endl;
			cin >> delnum;
			list.removeNodeFromList(delnum);
			list.printList();
			break;
		}
		case 6://delete by name
		{
			cout << "Please enter the Name to delete:" << endl;
			cin >> delname;
			list.removeNodeFromList(delname);
			list.printList();
			break;
		}
		case 7://print list
		{
			list.printList();
			break;
		}
		case 8://quit
		{
			break;
		}
		}
	}
	return 0;
}