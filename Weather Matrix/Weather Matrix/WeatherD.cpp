#include <iostream>
#include <fstream>
#include <string>
#include "Weather Checker.h"
using namespace std;

WeatherData::WeatherData(){
	year = 0;
	month = 0;
	ifstream read("WeatherTemps.txt");
	while(!read.eof())
	{
		for(int i = 0; i < 144; i++)
		{
			for(int j = 0; j < 12; j++)
				read >> tempData[i][j];
		}
	}
}
string WeatherData::getMonth(int m){
	switch(m){
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
	}
}

void WeatherData::TempofMonth(int y, int m){
	if(y >= 1869 && m <= 12)
	{
		year = y - 1869;
		month = m -1;
	}
	cout << "The average temerature for " << getMonth(m) << " in " << y << " is: " << tempData[year][month] << endl;
}
void WeatherData::aveTempYear(int y){
	if(y >= 1869)
		year = y - 1869;
	double sum = 0;
	double average;
	for(int i = 0; i < 12; i ++)
		sum += tempData[year][i];
	average = sum / 12;
	cout << "The average temperature for " << y << " is: " << average << endl;
}
void WeatherData::highTempYear(int y){
	int highest = 0;
	if(y >= 1869)
		year = y - 1869;
	for(int i = 0; i < 12; i++)
	{
		if(tempData[year][highest] < tempData[year][i])
			highest = i;
	}
	cout << "The highest temperatur for the year " << y << " was " << tempData[year][highest] << " degrees in " << getMonth(highest) << endl;
}
void WeatherData::aveTempMonth(int m){
	double sum = 0;
	double average;
	if(m <= 12)
		month = m - 1;
	for(int i = 0; i < 144; i++)
		sum += tempData[i][month];
	average = sum / 144;
	cout << "The average temperature for " << getMonth(month) << " is: " << average << endl;
}
void WeatherData::highTempMonth(int m){
	int highest = 0;
	if( m <= 12)
		month = m - 1;
	for(int i = 0; i < 144; i++)
	{
		if(tempData[highest][month] < tempData[i][month])
			highest = i;
	}
	cout << "The highest temperature for " << getMonth(month) << " was " << tempData[highest][month] << " in " << highest+1869 << endl;
}



