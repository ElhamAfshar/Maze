#include "PointStack.h"

void PointStack::Push(Point _point)
{
	stack.insert_at_back(_point);
}
Point PointStack::Pop()
{
	if (!isEmpty())
	{
		Node temp = *stack.get_lastNode();
		stack.remove_from_back();
		return temp.getData();
	}
	Point temp(-5, -5);
	return temp;
}
Point PointStack::pick()
{
	if (!isEmpty())
		return stack.get_lastNode()->getData();
	Point temp(-5, -5);
	return temp;
}

bool PointStack:: isEmpty()
{
	if (stack.isEmpty())
		return true;
	return false;
}