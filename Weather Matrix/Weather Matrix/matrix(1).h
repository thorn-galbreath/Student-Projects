#pragma once
#include <iostream>
#include <string>
using namespace std;
typedef float Type;



class Matrix
{
public:
	//defaults
	static const int MAXROWS = 2;
	static const int MAXCOLS = 2;
	  //Overload the stream insertion and extraction operators

	Matrix(void);
	Matrix (int,int);
	Matrix (Matrix & c);
	
	void setStart(const char * year);
	void read (const char * fileName);
	void read (fstream &fileIn);
	Type sumRow (const int r)const;
	string getMonth(int c);
	void avgCol (int c);
	void avgRow (int r);
	void highestForRow(int r);
	void highestForCol(int c);
	void lowestForRow(int r);
	void lowestForCol(int c);
	Type get(int,int);
	void set (int,int,Type);
	void menu();
	void print ();

	Matrix  multiply (Matrix m);
	~Matrix(void);
private:
	int numRows;
	int numCols;
	Type ** matrix;							//dynamically allocated
	int start;
};
