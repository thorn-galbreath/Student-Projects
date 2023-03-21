#include <string>
#include <iostream>
using namespace std;

class WeatherData{
private:
	double tempData[144][12];
	int month;
	int year;
public:
	WeatherData();
	string getMonth(int);
	void TempofMonth(int, int);
	void aveTempYear(int);
	void highTempYear(int);
	void aveTempMonth(int);
	void highTempMonth(int);
};