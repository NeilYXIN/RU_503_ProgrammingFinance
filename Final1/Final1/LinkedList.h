#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
class LinkedList
{
	friend class StockAccount;
public:
	LinkedList();
	~LinkedList();
	void sort();
	void insertEnd(Node *node);
	void erase(Node *node);
	void swap(Node * node_a, Node * node_b);
	int getLength();
	bool nameExist(string namevalue);
	void traversalPrint();
	Node* getNode(string namevalue);
	
private:
	Node *root;
	Node *end;
	int length;

};


#endif // !LINKEDLIST_H
