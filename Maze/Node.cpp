#include "Node.h"


Node::Node()
{
	nextPtr = nullptr;
	previousPtr = nullptr;
}
Node::Node(Point _point)
{
	point = _point;
	nextPtr = nullptr;
	previousPtr = nullptr;
}
Point Node::getData()
{
	return point;
}