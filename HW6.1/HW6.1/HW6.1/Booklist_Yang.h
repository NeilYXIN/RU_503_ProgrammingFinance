// Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 6
// Submitting date: Oct/16/2017
#pragma once
#ifndef BOOKLIST_H
#define BOOKLIST_H
class Booklist
{
private:
	int isbn[20];//array list
	int numinl;//number in the list
	bool sorted;//is sorted or not
public:
	Booklist();//constructor function
	void issorted();//determine sorted or not
	void print();//print list
	int getnuminl();//get number in list
	void insert(int new_element);//insert at end
	void insert_at(int at_position, int new_element);//insert at certain position
	int find_linear(int element);//linear search
	int find_binary(int element);//binary search
	void delete_item_position(int position);//delete at certain position
	void delete_item_isbn(int element);//delete by isbn
	void sort_list_selection();//sort 
	void sort_list_bubble();//bubble sort
	int returnnuminl();//return num in list
	bool returnsorted();//return soreted value


};

#endif // !BOOKLIST_H
