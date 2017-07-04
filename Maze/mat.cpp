#include<iostream>
#include<iomanip>
#include "mat.h"
using namespace std;

Mat::Mat()
{
	mat[100][100];
}
////////////////////////////////////////////////////////
Mat::Mat(int _row, int _column)
{
	row = _row;
	column = _column;
	mat = new int*[row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new int[column];
	}
}
//////////////////////////////////////////////////////
Mat Mat::operator+(Mat _in)
{
	if ((row != _in.row) || (column != _in.column))
	{
		cout << "no currect......";
		//return;
	}
	Mat result(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			result.mat[i][j] = _in.mat[i][j] + mat[i][j];
		}
	}
	return result;
}
////////////////////////////////////////////////////
Mat Mat::operator-(Mat _in)
{
	if ((row != _in.row) || (column != _in.column))
	{
		cout << "no currect......";
		//return;
	}
	Mat result(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			result.mat[i][j] = mat[i][j] - _in.mat[i][j];
		}
	}
	return result;
}
////////////////////////////////////////////////////
Mat Mat::operator*(Mat _in)
{
	if (column != _in.row)
	{
		cout << "not current.....";
		//return;
	}
	Mat result(row, _in.column);
	for (int i = 0; i < result.row; i++)
	{
		for (int j = 0; j < result.column; j++)
		{
			result.mat[i][j] = 0;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <_in.column; j++)
		{
			for (int k = 0; k < result.row; k++)
			{
				result.mat[i][j] += mat[i][k] * (_in.mat[k][j]);
			}
		}
	}
	return result;
}
/////////////////////////////////////////////////////////////////////
Mat Mat::operator!()
{

	Mat result(row,column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			result.mat[i][j] = mat[j][i];
		}
	}
	return result;
}
///////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& output, Mat _mat)
{
	for (int i = 0; i < _mat.row; i++)
	{
		for (int j = 0; j < _mat.column; j++)
		{
			output << _mat.mat[i][j];
		}
		output << endl;
	}
	return output;
}
//////////////////////////////////////////////////////////////////////
istream& operator>>(istream& input, Mat _mat)
{
	for (int i = 0; i < _mat.row; i++)
	{
		for (int j = 0; j < _mat.column; j++)
		{
			input >> _mat.mat[i][j];
		}
	}
	return input;
}

int Mat::get_value(int _row, int _colmn)
{
	return mat[_row][_colmn];
}

void Mat::set_value(int _row, int _colmn, int value)
{
	mat[_row][_colmn] = value;
}

int Mat::getRow()
{
	return row;
}

int Mat::getColumn()
{
	return column;
}
