// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 10
// Submitting date: Nov/13/2017
#pragma once
#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <string>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	int size() const;
	void addToStart(Node *);
	void addToEnd(Node *);
	void printList();
	bool removeFromStart();
	bool removeFromEnd();
	void removeNodeFromList(int);
	void removeNodeFromList(string);
private:
	Node *myHead;
	Node *myTail;
	int mySize;
};
#endif // !LINKEDLIST