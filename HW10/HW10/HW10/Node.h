// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 10
// Submitting date: Nov/13/2017
#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;
class Node
{
	friend class LinkedList;
public:
	Node(string& name, int no)
		:itemName(name), itemNo(no)
	{
		this->next = NULL;
	}
private:
	string itemName;
	int itemNo;
	Node *next;
};
#endif //NODE_H