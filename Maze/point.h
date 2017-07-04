#include<iostream> 
#pragma once
class Point
{
private: 
	int x, y;
public:
	Point() :x(0), y(0) {}
	Point(int _x, int _y);
	void setX(int _x);
	void setY(int _y);
	void setPoint(int _x, int _y);
	int getX();
	int getY();
	bool operator==(Point _in);
	bool operator!=(Point _in);
};
//istream& operator>>(istream& input, Point& temp);


