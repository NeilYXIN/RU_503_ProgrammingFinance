// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 10
// Submitting date: Nov/13/2017
#include <iostream>
#include "LinkedList.h"
#include <string>
using namespace std;

LinkedList::LinkedList()//constructor
{
	myHead = NULL;
	myTail = NULL;
	mySize = 0;
}

LinkedList::~LinkedList()//when destroyed clean
{
	myHead = NULL;
	myTail = NULL;
	mySize = 0;
}

int LinkedList::size () const//get size
{
	return mySize;
}

void LinkedList::addToStart(Node * newnode)//add to first
{
	if (mySize == 0)//when first added
	{
		myTail = newnode;
		myHead = newnode;
	}
	else//not the first element
	{
		newnode->next = myHead;
		myHead = newnode;
	}
	mySize++;
}

void LinkedList::addToEnd(Node * newnode)//add to last
{
	if (mySize == 0)//when it's the first element
	{
		myHead = newnode;
		myTail = newnode;
	}
	else//not the first element
	{
		myTail->next = newnode;
		myTail = newnode;
	}
	mySize++;
}

void LinkedList::printList()//print list
{
	cout << "List" << endl;
	cout << "Item No" << '\t' << "Item Name" << endl;
	Node * count = myHead;
	for (int i = 1; i <= mySize; i++)
	{
		cout << count->itemNo << "\t" << count->itemName << endl;
			count = count->next;
	}
}

bool LinkedList::removeFromStart()//remove first
{
	Node * temp = myHead;
	myHead = myHead->next;
	temp->next = NULL;
	delete temp;
	mySize--;
	return true;
}

bool LinkedList::removeFromEnd()//remove last
{
	Node *temp = myHead;
	while (temp->next != myTail)//go to the one before target
	{
		temp = temp->next;
	}
	myTail = temp;
	temp = temp->next;
	delete temp;
	myTail->next = NULL;
	mySize--;
	return true;
}

void LinkedList::removeNodeFromList(int num)//delete by number
{
	Node * temp = myHead;
	if (temp->itemNo != num)
	{
		while (temp->next != NULL && temp->next->itemNo != num)//go to the one before target
		{
			temp = temp->next;
		}
		if (temp->next != NULL && temp->next->itemNo == num)
		{
			if (temp->next->next != NULL)//target in the middle
			{
				Node * tmp = temp->next;
				temp->next = temp->next->next;
				delete tmp;
				mySize--;
			}
			else//target is last
			{
				removeFromEnd();
			}
		}
		else//not in the list
		{
			cout << "Item not found!" << endl;
		}
	}
	else//target is first
	{
		removeFromStart();
	}
}

void LinkedList::removeNodeFromList(string name)//delete by name
{
	Node * temp = myHead;
	if (temp->itemName != name)//first is not target
	{
		while (temp->next != NULL && temp->next->itemName != name)//go to the one before target
		{
			temp = temp->next;
		}
		if (temp->next != NULL && temp->next->itemName == name)
		{
			if (temp->next->next != NULL)//target is not last
			{
				Node * tmp = temp->next;
				temp->next = temp->next->next;
				delete tmp;
				mySize--;
			}
			else//target is last
			{
				removeFromEnd();
			}		
		}
		else//no item in the list
		{
			cout << "Item not found!" << endl;
		}
	}
	else//target is first
	{
		removeFromStart();
	}
}