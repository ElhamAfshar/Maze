#pragma once
#include <iostream>
using namespace std;

class Mat
{
	friend ostream& operator<<(ostream& output, Mat _mat);
	friend istream& operator>>(istream& input, Mat _mat);
private:
	int row, column;
	int** mat;
public:
	Mat();
	Mat(int _row, int _column);
	Mat operator+(Mat _in);
	Mat operator-(Mat _in);
	Mat operator*(Mat _in);
	Mat operator!();
	int get_value(int _row, int _colmn);
	void set_value(int _row, int _colmn, int value);
	int getRow();
	int getColumn();
};


ostream& operator<<(ostream& output, Mat _mat);
istream& operator>>(istream& input, Mat _mat);
//Mat operator!(Mat _in);