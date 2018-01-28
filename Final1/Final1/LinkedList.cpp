#include "LinkedList.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
	root = new Node("",-1);
	end = new Node("", -1);
	root->next = end;
	end->front = root;
	length = 0;
}

// empty the memory when terminated
LinkedList::~LinkedList()
{
	Node* t = root;
	if (root->next != end)
	{
		erase(root->next);
	}
	delete root;
	delete end;
}

// bubble sort
void LinkedList::sort()
{
	Node* times = new Node("",0);
	Node* point = new Node("",0);
	int i = 0;
	int j = 0;
	int length = getLength();
	int count_i = 0;
	int count_j = 0;
	while (count_i < length - 1)
	{
		
		times = root;
		for (int i = 0; i <= count_i; i++)
		{
			times = times->next;
		}
		count_j = 0;
		while (count_j < length - count_i - 1)
		{
			
			point = root;
			for (int j = 0; j <= count_j; j++)
			{
				point = point->next;
			}
			count_j++;
			if (point->tempprice*point->stocknum < point->next->tempprice*point->next->stocknum)
			{
				swap(point, point->next);
			}
			

		}

		count_i++;
	}
}
// change the order of two nodes in the list
void LinkedList::swap(Node * node_a, Node * node_b) 
{
	// neibhgour nodes
	if (node_a->front == node_b)
	{
		node_b->front->next = node_a;
		node_a->next->front = node_b;

		node_a->front = node_b->next;

		node_b->front = node_a;
		node_b->next = node_a->next;

		node_a->next = node_b;
	}
	else if (node_a->next == node_b)
	{
		node_a->front->next = node_b;
		node_b->next->front = node_a;

		node_b->front = node_a->front;

		node_a->front = node_b;
		node_a->next = node_b->next;

		node_b->next = node_a;
	}
	// separate nodes
	else
	{
		Node *node_c = new Node("",0);
		node_c->front = node_a->front;
		node_c->next = node_a->next;

		node_a->front->next = node_b;
		node_a->next->front = node_b;

		node_b->front->next = node_a;
		node_b->next->front = node_a;

		node_a->front = node_b->front;
		node_a->next = node_b->next;

		node_b->front = node_c->front;
		node_b->next = node_c->next;
	}
}
void LinkedList::insertEnd(Node *node) // determine if already exist
{
	// empty list, initialize
	if (root->next == end)
	{
		root->next = node;
		node->front = root;
		node->next = end;
		end->front = node;
	}
	// list not empty, find last and insert
	else
	{
		Node * temp = root;
		while (true)
		{
			// find last
			if (temp->next != end)
			{
				temp = temp->next;
			}
			// temp is last
			else
				break;
		}
		temp->next = node;
		node->front = temp;
		node->next = end;
		end->front = node;
	}

	//traversalPrint();

}

void LinkedList::erase(Node * node) // delete node from list
{
	// determine at last

	node->front->next = node->next;
	node->next->front = node->front;
	node->front = NULL;
	node->next = NULL;
	delete node; // delete erased node to release memory
}



// get length of list
int LinkedList::getLength() 
{
	int length = 0;
	Node * count = root;
	while (true)
	{
		if (count->next != end)
		{
			count = count->next;
			length++;
		}
		else return length;
	}
}

// detect if there's such stock in the result.txt file
bool LinkedList::nameExist(string namevalue)
{
	Node * count = root;
	while (true)
	{
		if (count->next != end)
		{
			count = count->next;
			if (!strcmp((count->stockname).c_str(), namevalue.c_str()))
			{
				return true;
			}
		}
		else
		{
			break;
		}
	}
	return false;
}

// print the whole list
void LinkedList::traversalPrint()
{
	Node * point = root;
	while (true)
	{
		if (point->next != end)
		{
			point = point->next;
			cout << "Stock: " << point->stockname << " Num: " << point->stocknum << endl;
		}
		else
		{
			cout << endl;
			break;
		}
	}
}

// get a single node by name of stock
Node* LinkedList::getNode(string namevalue)
{
	Node * count = root;
	while (count->next != end)
	{
		count = count->next;
		if (!strcmp((count->stockname).c_str(), namevalue.c_str()))
		{
			return count;
		}
	}
	return end;
}