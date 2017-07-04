#include "Maze.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

Maze::Maze(){};
char Maze::Casting(int _value)
{
	char wall = 177;
	char way = 219;
	if (0 == _value||1==_value)
	{
		return wall;//for wall
	}
	else if (8==_value)
	{
		return way;//for way
	}
	else if (2 == _value)
	{
		return 'P';// for start
	}
	else if (3 == _value)
	{
		return 'G';// for goal
	}
}
Point Maze::MoveUP(Point _point)
{
	_point.setPoint(_point.getX()-1, _point.getY());
	return _point;
}
Point Maze::MoveRight(Point _point)
{
	_point.setPoint(_point.getX(), _point.getY() + 1);
	return _point;
}
Point Maze::MoveDown(Point _point)
{
	_point.setPoint(_point.getX()+1, _point.getY());
	return _point;
}
Point Maze::MoveLeft(Point _point)
{
	_point.setPoint(_point.getX() , _point.getY()-1);
	return _point;
}
/////////////   is block or not  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
bool Maze::isBlock(Point _point)
{
	if ((getValue(_point) == 0) || getValue(_point) == 8)//0 for wall ,8 for gone
		return true;
	return false;// 1 for way
}
void Maze::setValue(Point _point, int _value)
{
	maze.set_value(_point.getX(), _point.getY(), _value);
}
/////////////////  choose direction gone   \\\\\\\\\\\\\\\\\\\\\/
int Maze::getDirection(Point _point)
{
	Point temp;
	//////////////////////////////// UP\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
	temp.setPoint(_point.getX() - 1, _point.getY());
	if (correctMove(temp))
		if (!isBlock(temp))
			return Direction::up;// 0 for up
	//////////////////////////////   Right   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
	temp.setPoint(_point.getX(), _point.getY() + 1);
	if (correctMove(temp))
		if (!isBlock(temp))
			return Direction::right;// 1 for right
	/////////////////////////  Down  \\\\\\\\\\\\\\\\\\\\\\\\\\/
	temp.setPoint(_point.getX() + 1, _point.getY());
	if (correctMove(temp))
		if (!isBlock(temp))
			return Direction::down;// 2 for down
	///////////////////////////   Left   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
	temp.setPoint(_point.getX(), _point.getY() - 1);
	if (correctMove(temp))
		if (!isBlock(temp))
			return Direction::left; // 3 for left
	/////////////////////////////  backtrack   \\\\\\\\\\\\\\\\\\\\\\\\\\\/
	return Direction::backtrack;//4 for backtrack
}
////////////////////////  return value  \\\\\\\\\\\\\\\\\\\\\\\/
int Maze::getValue(Point _point)
{
	return maze.get_value(_point.getX(), _point.getY());
}
//////////////////////// choose moving  \\\\\\\\\\\\\\\\\\\\\\\\\/
Point Maze::getMove(Point _point)
{
	Point temp;
	int result = getDirection(_point);
	switch (result)
	{
	case ::up:
		temp= MoveUP(_point);
		push_set(temp,8);// 8 for gone
		break;
	case ::right:
		temp= MoveRight(_point);
		push_set(temp, 8);// 8 for gone
		break;
	case ::down:
		temp= MoveDown(_point);
		push_set(temp, 8);// 8 for gone
		break;
	case ::left:
		temp= MoveLeft(_point);
		push_set(temp, 8);// 8 for gone
		break;
	case ::backtrack:
		temp = way.Pop();
		Point NOT(-5, -5);
		if(temp!=NOT)
			setValue(temp, 0);//0 for wall
 		temp = way.pick();
		break;
	}
	return temp;
}
//////////////////////   print solving maze   \\\\\\\\\\\\\\\\\\\\\\\\/
void Maze::PrintSymbolic()
{
	for (int i = 0; i < maze.getRow(); i++)
	{
		for (int j = 0; j < maze.getColumn(); j++)
		{
			cout << Casting(maze.get_value(i, j));
		}
		cout << endl;
	}
}
////////////////   solving   \\\\\\\\\\\\\\\\\\\\\\//   
bool Maze::Solve()
{
	Point check(-5, -5);//for checking way is Empty
	Point AUX = start;
	//way.Push(start);
	AUX = getMove(AUX);
	while ( AUX != end)
	{
		if (AUX==check)
		{
			return false;
		}
		AUX = getMove(AUX);
	}
	setValue(AUX, 3);
	return true;
}
////////////////  seting maze in/from file  \\\\\\\\\\\\\\\\\\\\\/
int Maze::SetMaze(string filename, int numOfmap)
{
	int AUX;
	Point coordinate; // number of row and column
	ifstream file(filename);
	if (!file)
	{
		cout << "could not open file" << endl;
		return -10;
	}
	file >> AUX;
	cout << "------------------number of map is : " << AUX << "-------------------" << endl;
	int byte=calcStartByte(numOfmap, file);
	coordinate = readPoint(file);
	Mat temp (coordinate.getX(), coordinate.getY());
	maze = temp;
	maze = readMaze(file, coordinate);
	setStart_End(coordinate);
	file.close();
	return numOfmap;
}
///////////////  reading maze from file  \\\\\\\\\\\\\\\\\\\\/
Mat Maze::readMaze(ifstream& _file,Point _coordinate)
{
	char AUX;
	for (int i = 0; i < _coordinate.getX(); i++)
	{
		for (int j = 0; j < _coordinate.getY();j++)
		{
			_file >> AUX;
			maze.set_value(i, j, AUX - '0');
		}
	}
	return maze;
}
///////////////////  read number of row &column \\\\\\\\\\\\\\\\\\\/
Point Maze::readPoint(ifstream& _file)
{
	int x, y;
	Point temp;
	_file >> x;
	_file >> y;
	temp.setPoint(x, y);
	return temp;
}
//////////////////////   seting start & end   \\\\\\\\\\\\\\\\\\\\\\\/
void Maze::setStart_End(Point _point)
{
	for (int i = 0; i < _point.getX(); i++)
	{
		for (int j = 0; j < _point.getY(); j++)
		{
			if (maze.get_value(i,j) == 2)
				start.setPoint(i, j);
			if (maze.get_value(i, j) == 3)
				end.setPoint(i, j);
		}
	}
}
/////////////////  caring that move in" 0 _ size"
bool Maze::correctMove( Point _point)
{
	int x = _point.getX();
	int y = _point.getY();
	if (-1 == x )
		return false;
	if (-1 == y )
		return false;
	if (x  == maze.getRow())
		return false;
	if (y  == maze.getColumn())
		return false;
	return true;
}
/////////////////////   push & setvalue in stack   \\\\\\\\\\\\\\\\\\\\\/
void Maze::push_set(Point _point, int val)
{
	way.Push(_point);
	setValue(_point, val);
}
////////////////// calculate startByte   \\\\\\\\\\\\\\\\\\/
int Maze::calcStartByte(int num,ifstream& file)
{
	char temp;
	Point AUX;
	int startByte = 1;
	for (int i = 1; i < num; i++)
	{
		AUX=readPoint(file);
		int j;
		for (j = 0; j < AUX.getX()*AUX.getY(); j++)
		{
			file >> temp;
		}
		startByte += j;
	}
	return startByte;
}
/////////////////////////    open result file        \\\\\\\\\\\\\\\\\\\\\\\\\\\/
void Maze::openResultFile(string filename,bool result)
{
	ofstream file(filename,ios::app);
	if (!file)
	{
		cout << "can't open " << filename << endl;
		return;
	}
	if (result)
	{
		file << "Yes" << endl;
		file.close();
		return;
	}
	file << "No" << endl;
	file.close();
	return;
}
////////////////   printing result of all maze in file  \\\\\\\\\\\\\\\\\\\\\\\\/
void Maze::printTofile(string filename_in,string filename_out)
{
	for (int i = 0;true; i++)
	{
		int check = SetMaze(filename_in, i);
		if (check <= i || check != -10)
		{
			openResultFile(filename_out, Solve());
		}
		else
			return;
	}	
}
//////////// menu of printing solved maze  \\\\\\\\\\\\\\\\\\\\\\\\\\/
void menu(Maze& _maze)
{
	bool result;// result of solving maze
	int choice = 1;// choice of user to terminate or continue
	while (choice)
	{
		printMenu();
		cin >> choice;
		if (!choice)// if user enter 0 exiting
			return;
		_maze.SetMaze("out.txt", choice);
		result = _maze.Solve();
		if (result)// if maze solve printing it else printing error
			_maze.PrintSymbolic();
		else
			cout << "Can not solve...!" << endl;

	}
}
/////////////////  printing text of menu  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
void printMenu()
{
	cout << "Please enter:" << endl << "\t"
		<< "0  to exite" << endl << "\t" << "Number of Map" << endl;
}