#include "Rectangle.h"
#include<iomanip>

Rectangle::Rectangle(){
	length = 0;
	width = 0;
}
Rectangle::Rectangle(float l, float w) {
	length = l;
	width = w;
}
float Rectangle::area(){
	return length * width;
}
float Rectangle::perimeter(){
	return ((2*length)+(2*width));
}
void Rectangle::setLength(float l){
	length = l;
}
void Rectangle::setWidth(float w){
	width = w;
}
float Rectangle::getLength(){
	return length;
}
float Rectangle::getWidth(){
	return width;
}
void Rectangle::display(){
	cout << setw(20) << setfill('*') << " " << endl;
	cout << "Length = "<< length << endl;
	cout << "Width = " << width << endl;
	cout << "Area = " << area() << endl;
	cout << "Perimeter = " << perimeter() << endl;
	cout << setw(20) << setfill('*') << " " << endl;
}
