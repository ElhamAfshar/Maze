#include"point.h"
#pragma once
class Node
{
	friend class List;
private:
	Point point;//date
	Node *nextPtr;//next pointer
	Node *previousPtr;//previous pointer 
public:
	Node();
	Node(Point _point);
	Point getData();
};

