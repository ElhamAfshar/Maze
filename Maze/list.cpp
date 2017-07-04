#include "list.h"

Node * List::get_New_Node(Point val)// create new node
{
	Node* temp = new Node(val);
	return temp;
}

Node* List::get_lastNode()
{
	return lastPtr;
}

void List::insert_at_front(const Point val)
{
	Node* newPtr = get_New_Node(val);
	if (isEmpty())
		firstPtr = lastPtr = newPtr;
	else
	{
		newPtr->nextPtr = firstPtr;
		firstPtr = newPtr;
	}
}

void List:: insert_at_back(const Point val)
{
	Node *temp = get_New_Node(val);
	if (isEmpty())
		firstPtr = lastPtr = temp;
	else
	{
		lastPtr->nextPtr = temp;
		lastPtr = temp;
	}
}

bool List:: remove_from_front()
{
	if (isEmpty())
		return false;
	else
	{
		Node *tempPtr = firstPtr;
		if (firstPtr == lastPtr)
			firstPtr = lastPtr = 0;
		else
			firstPtr = firstPtr->nextPtr;

		delete tempPtr;
		return true;
	}
}

bool List:: remove_from_back()
{
	if (isEmpty())
		return false;
	else
	{
		Node *tempPtr = lastPtr;
		if (firstPtr == lastPtr)
			firstPtr = lastPtr = 0;
		else
		{
			Node *currentPtr = firstPtr;
			while (currentPtr->nextPtr != lastPtr)
				currentPtr = currentPtr->nextPtr;

			lastPtr = currentPtr;
			currentPtr->nextPtr = 0;
		}
		delete tempPtr;
		return true;
	}
}

bool List::isEmpty()
{
	return firstPtr == 0;
}