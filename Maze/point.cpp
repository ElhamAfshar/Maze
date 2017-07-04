#include "Point.h"


Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Point::setX(int _x)
{
	x = _x;
}
void Point::setY(int _y)
{
	y = _y;
}
void Point::setPoint(int _x, int _y)
{
	setX(_x);
	setY(_y);
}
int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}
bool Point:: operator==(Point _in)
{
	return (_in.x == x) && (_in.y == y);
}
bool Point:: operator!=(Point _in)
{
	return(_in.x != x) || (_in.y != y);
}


