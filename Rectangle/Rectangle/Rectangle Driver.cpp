#include <iostream>
#include "Rectangle.h"
using namespace std;

int main(){
	Rectangle rectangle1;
	float l1, w1, l2, w2;
	cout << "Welcome to the rectangle manager where we will " <<endl;
	cout << "compare the area and perimeter of two different rectangles." << endl;
	cout << "Please enter the length and width of rectangle 1 seperated by spaces" << endl;
	cin >> l1 >> w1;
	rectangle1.setLength(l1);
	rectangle1.setWidth(w1);
	cout << "Now enter the length and width of rectangle 2" << endl;
	cin >> l2 >> w2;
	Rectangle rectangle2(l2,w2);
	cout << "Rectangle 1" << endl;
	rectangle1.display();
	cout << "Rectangle 2" << endl;
	rectangle2.display();

	return 0;
}
