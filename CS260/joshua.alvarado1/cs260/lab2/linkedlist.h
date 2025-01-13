#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>
#include <iostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);
	void print();


private:
	//fill in your code here
	struct Node {
		char data;
		Node* next;
		Node(char ch);
	};
	Node* head;
	Node* tail;
};


#endif // _LINKED_LIST_
