#pragma once
#include"Node.h"

class List
{
private:
	Node *firstPtr;
	Node *lastPtr;
	Node *get_New_Node(Point val);
public:
	List() { firstPtr = 0; lastPtr = 0; }
	Node* get_lastNode();
	void insert_at_front(const Point val);
	void insert_at_back(const Point val);
	bool remove_from_front();
	bool remove_from_back(); 
	bool isEmpty();
};

