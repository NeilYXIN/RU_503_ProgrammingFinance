#pragma once
#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
class Node
{
	friend class LinkedList;
	friend class StockAccount;
public:
	Node(string name, int num);
	~Node();

private:
	string stockname;
	int stocknum;
	double tempprice;
	Node * front;
	Node * next;

};


#endif // !NODE_H

