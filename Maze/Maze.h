#pragma once
#include"PointStack.h"
#include"mat.h"

enum Direction { up, right, down, left, backtrack };

class Maze
{
	friend class Mat;
private:
	Mat maze; // map of maze
	PointStack way;
	Point start, end;// start and goal in maze
	char Casting(int _value); // casting number to character
	Point MoveUP(Point _point);
	Point MoveRight(Point _point);
	Point MoveDown(Point _point);
	Point MoveLeft(Point _point);
	bool isBlock(Point _point);
	void setValue(Point _point, int _value); // seting value in maze 
	int getDirection(Point _point); // choosing type of direction
	int getValue(Point _point); // geting value maze
	Point getMove(Point _point);  // choosing type of move
	Mat readMaze(ifstream& _file,Point _Point); // read map of maze from file
	Point readPoint(ifstream& _file);// read number of row and column
	void setStart_End(Point _point);// assigning start and end in maze
	bool correctMove( Point _point);// say that the move is correct or no
	void push_set(Point _point, int val);//push the point to stack & set the value in mat
	int calcStartByte(int num,ifstream& file);
	void openResultFile(string filename, bool result);
public:
	Maze();// default constractor
	int SetMaze(string filename, int startByte);
	void PrintSymbolic();// printing maze
	bool Solve();// solving maze
	void printTofile( string filename_in, string filename_out);
};// end of class

void menu(Maze& _maze);
void printMenu();

