#include "Weather Checker.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char * argv[]){
	int choice = 0;
	int year;
	int month;
	WeatherData weatherCheck;
	cout << "This program allows you to check the highest and average weather by month and year." << endl;
	cout << "Please select the number of the option you want to choose." << endl;
	while(choice!=5){
		cout << "1- Average Temperature by Year" << endl;
		cout << "2- Highest Temperature by Year" << endl;
		cout << "3- Average Temperature by Month" << endl;
		cout << "4- Highest Temperature by Month" << endl;
		cout << "5- Exit!" << endl;
		cin >> choice;
		if(choice == 1)
		{
			cout << "Please enter the year you would like to check" << endl;
			cin >> year;
			weatherCheck.aveTempYear(year);
		}
		if(choice == 2)
		{
			cout << "Please enter the year you would like to check" << endl;
			cin >> year;
			weatherCheck.highTempYear(year);
		}
		if(choice == 3)
		{
			cout << "Please enter the month you would like to check" << endl;
			cin >> month;
			weatherCheck.aveTempMonth(month);
		}
		if(choice == 4)
		{
			cout << "Please enter the month you would like to check" << endl;
			cin >> month;
			weatherCheck.highTempMonth(month);
		}
		if(choice == 5)
			cout << "Thank you for using this weather checker!" << endl;
	}
	return 0;
}