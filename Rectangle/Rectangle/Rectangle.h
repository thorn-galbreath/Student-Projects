#include <iostream>
using namespace std;

class Rectangle{
private:
	float length;
	float width;
public:
	Rectangle();
	Rectangle(float, float);
	float area();
	float perimeter();
	void setLength(float);
	void setWidth(float);
	float getLength();
	float getWidth();
	void display();
};