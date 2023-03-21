#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "matrix(1).h"

//default constructor - dynamically allocated 2d array
Matrix::Matrix(void):numRows(MAXROWS),numCols(MAXCOLS)
{
	matrix = new Type*[numRows];
	for (int i = 0; i<numRows; i++)
		matrix[i] = new Type [numCols];
	
}

Matrix::Matrix(int r, int c):numRows(r),numCols(c)
{
	matrix = new Type*[numRows];
	for (int i = 0; i<numRows; i++)
		matrix[i] = new Type [numCols];
}


//copy constructor
Matrix::Matrix(Matrix &c){
	
	numRows = c.numRows;
	numCols = c.numCols;
	matrix = new Type*[numRows];
	for (int i = 0; i<numRows; i++)
		matrix[i] = new Type [numCols];
	
	for (int row = 0; row < numRows; row++) {
			
		for (int col = 0; col < numCols; col++) {
			matrix[row][col]=c.matrix[row][col];
		}
		
	}
}
void Matrix::read (const char * fileName){
	fstream readFile(fileName);
	if(!readFile.is_open())
		cerr << fileName << " is not open!!!!" << endl;
	while(readFile)
	{
		for(int i = 0; i < numRows; i++)
		{
			for(int j = 0; j < numCols; j++)
				readFile >> matrix[i][j];
		}
	}

}
void Matrix::setStart(const char * year){
	start = atoi(year);
}
string Matrix::getMonth(int c){
	switch(c){
	case 0:
		return "January";
	case 1:
		return "February";
	case 2: 
		return "March";
	case 3:
		return "April";
	case 4:
		return "May";
	case 5:
		return "June";
	case 6: 
		return "July";
	case 7: 
		return "August";
	case 8:
		return "September";
	case 9: 
		return "October";
	case 10:
		return "November";
	case 11:
		return "December";
	default:
		return "Not a month.";
	}
}

Type Matrix::sumRow (const int r)const{
	Type sum =  0;	
	for (int col = 0; col < numCols; col++){
		sum += matrix[r][col];
	}
	return sum;
}
void Matrix::avgCol (int c){
	float avg = 0;
	for(int i = 0; i < numRows; i++)
	{
		avg += matrix[i][c];
	}
	avg = avg / numRows;
	cout << "The average temperature for the month " << getMonth(c) << " was " << avg << " degrees.\n" << endl;
}
void Matrix::avgRow (int r){
	float avg = 0;
	for(int i = 0; i < numCols; i++)
	{
		avg += matrix[r][i];
	}
	avg = avg / numCols;
	cout << "The average temperature for the year " << (start+r) << " was " << avg << " degrees.\n" << endl;
}
void Matrix::highestForRow(int r){
	int highest = 0;
	for(int i = 0; i < numCols; i++)
	{
		if(matrix[r][i] > matrix[r][highest])
			highest = i;
	}
	cout << "The highest temperature for the year " << (start+r) << " was " << matrix[r][highest] << " in " << getMonth(highest) << endl;
	cout << endl;
}
void Matrix::highestForCol(int c){
	int highest = 0;
	for(int i = 0; i < numRows; i++)
	{
		if(matrix[i][c] > matrix[highest][c])
			highest = i;
	}
	cout << "The highest temperature for the month " << getMonth(c) << " was " << matrix[highest][c] << " in " << (start+highest) << endl;
	cout << endl;
}
void Matrix::lowestForRow(int r){
	int lowest = 0;
	for(int i = 0; i < numCols; i++)
	{
		if(matrix[r][i] < matrix[r][lowest])
			lowest = i;
	}
	cout << "The lowest temperature for the year " << (1869+r) << " was " << matrix[r][lowest] << " in " << getMonth(lowest) << endl;
	cout << endl;
}
void Matrix::lowestForCol(int c){
	int lowest = 0;
	for(int i = 0; i < numRows; i++)
	{
		if(matrix[i][c] < matrix[lowest][c])
			lowest = i;
	}
	cout << "The lowest temperature for the month " << getMonth(c) << " was " << matrix[lowest][c] << " in " << (1869+lowest) << endl;
	cout << endl;
}

Type Matrix::get(int i, int j){
	return matrix[i][j];
}

Matrix::~Matrix(void)
{
		for (int row = 0; row < numRows; row++)
			delete [] matrix[row];
		delete [] matrix;
}

void Matrix::menu(){
	int choice = 0;
	int year;
	int month;
	cout << "This program allows you to check the highest and average weather by month and year." << endl;
	cout << "Please select the number of the option you want to choose." << endl;
	while(choice!=7){
		cout << "1- Average Temperature by Year" << endl;
		cout << "2- Highest Temperature by Year" << endl;
		cout << "3- Lowest Teperature by Year" << endl;
		cout << "4- Average Temperature by Month" << endl;
		cout << "5- Highest Temperature by Month" << endl;
		cout << "6- Lowest Temperature by Month" << endl;
		cout << "7- Exit!" << endl;
		cin >> choice;
		if(choice == 1)
		{
			cout << "Please enter the year you would like to check" << endl;
			cin >> year;
			avgRow(year-start);
		}
		else if(choice == 2)
		{
			cout << "Please enter the year you would like to check" << endl;
			cin >> year;
			highestForRow(year-start);
		}
		else if(choice == 3)
		{
			cout << "Please enter the year you would like to check" << endl;
			cin >> year;
			lowestForRow(year-start);
		}
		else if(choice == 4)
		{
			cout << "Please enter the month you would like to check" << endl;
			cin >> month;
			avgCol(month-1);
		}
		else if(choice == 5)
		{
			cout << "Please enter the month you would like to check" << endl;
			cin >> month;
			highestForCol(month-1);
		}
		else if(choice == 6)
		{
			cout << "Please enter the month you would like to check" << endl;
			cin >> year;
			lowestForCol(year-start);
		}
		else if(choice == 7)
		{
			cout << "Thank you for using this weather checker!" << endl;
			exit(1);
		}
		else
		{
			cout << "That was not a valid choice. Try again." << endl;
			menu();
		}
	}
}