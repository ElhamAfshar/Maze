#pragma once
#include"list.h"

class PointStack
{
private:
	List stack;
public:
	PointStack(){}
	void Push(Point _point);
	Point Pop();
	Point pick();
	bool isEmpty();
};

