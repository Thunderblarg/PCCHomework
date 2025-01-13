#include "linkedlist.h"


//implementations for the member functions of LinkedList class

LinkedList::LinkedList() {
	this->head = nullptr;
	this->tail = nullptr;
}

LinkedList::~LinkedList(){

}

void LinkedList::add(char ch) {
	Node* newNode = new Node(ch);
	if (!this->head){
		this->head = newNode;
	}

	if (this->tail){
		this->tail->next = newNode;
		this->tail = this->tail->next;
	} else {
		this->tail = newNode;
	}
}

bool LinkedList::find(char ch) {
	if(!this->head){
		std::cout << "There is nothing to find!" << std::endl;
	} else {
		Node* trav = this->head;
		do {
			if (trav->data == ch) {
				return true;
			} else {
				if (trav->next) {
					trav = trav->next;
				}
			}
		} while (trav->next);
	}
	
	return false;
}

bool LinkedList::del(char ch) {
	if(!this->head) {
		std::cout << "There is nothing to delete!" << std::endl;
	} else if (this->head->data == ch) {
		if(this->head->next) {
			Node* hold = this->head->next;
			delete this->head;
			this->head = hold; 
		} else {
			delete this->head;
			this->head = nullptr;
			// delete this->tail;
		}
	} else {
		Node* prev = this->head;
		Node* trav = this->head->next;
		do {
			if (trav->data == ch) {
				if(trav->next){
					prev->next = trav->next;
					delete trav;
					return true;
				} else {
					delete prev->next;
					this->tail = prev;
					return true;
				}
			} else {
				if(trav->next) {
					prev = trav;
					trav = trav->next;
				}
			}
		} 
		while (trav->next);

	}


	return false;
}

void LinkedList::print() {
	
	if(!this->head){
		std::cout << "The list is empty!" << std::endl;
	} else {
		bool keepPrinting = true;
		Node* printing = this->head;
		
		while (keepPrinting){
			std::cout << printing->data << std::endl;
			if (printing->next) {
				printing = printing->next;
			} else {
				keepPrinting = false;
			}
		}
	}
}

LinkedList::Node::Node(char ch): data(ch), next(nullptr) {}
