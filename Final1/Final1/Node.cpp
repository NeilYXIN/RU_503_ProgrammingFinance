#include "Node.h"

Node::Node(string name, int num)
{
	stockname = name;
	stocknum = num;
	tempprice = 0;
	front = NULL;
	next = NULL;

}

Node::~Node()
{
	//delete front;
	//delete next;
}