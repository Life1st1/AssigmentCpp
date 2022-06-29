#include <iostream>
#include "ass11.h"

using namespace std;


/**************************************************************
*Decription: constructor fuction of CLine class
*Input: int len, int para_color
*Output: None
*Return: None
***************************************************************/
CLine::CLine(int len, int para_color){
	length = len;
	color = para_color;
}

/**************************************************************
*Decription: constructor fuction of CCircle class
*Input: int rad, int para_color
*Output:None
*Return: None
***************************************************************/
CCircle::CCircle(int rad, int para_color){
	radium = rad;
	color = para_color;
}

/**************************************************************
*Decription: constructor fuction of CRectangle class
*Input: int wid, int len, int para_color
*Output: None
*Return: None
***************************************************************/
CRectangle::CRectangle(int wid, int len, int para_color){
	width = wid;
	length = len;
	color = para_color;
}

/**************************************************************
*Decription: constructor fuction of CSquare class
*Input: int side, int para_colorv
*Output: None
*Return: None
***************************************************************/
CSquare::CSquare(int side, int para_color){
	width = side;
	length = side;
	color = para_color;
}

/**************************************************************
*Decription: Show parameter of Line, format: Line(Lengh, colr:Color)
*Input: coordinate of Line
*Output: None
*Return: None
***************************************************************/
void CLine::draw(int x, int y){
	while(y--)
		cout << endl;
	while(x--)
		cout << " ";
	cout << "Line(" << length << ", colr:" << color << ")";
}

/**************************************************************
*Decription: Show parameter of Circle, format: Circle(Radium, colr:Color)
*Input:coordinate of Circle
*Output: None
*Return: None
***************************************************************/
void CCircle::draw(int x, int y){
	while(y--)
		cout << endl;
	while(x--)
		cout << " ";
	cout << "Circle(" << radium << ", colr:" << color << ")";
}

/**************************************************************
*Decription: Show parameter of Rectangle, format: Rectangle(width, length, colr:Color) or Square(side length, side length)
*Input: coordinate of Rectangle
*Output: None
*Return: None
***************************************************************/
void CRectangle::draw(int x, int y){
	while(y--)
		cout << endl;
	while(x--)
		cout << " ";
	if(width != length)
		cout << "Rectangle(" << width << "," << length << ",colr:" << color << ")";
	else	
		cout << "CSquare(" << width << ", colr:" << color << ")";
}


int main(){
	CPicture Picture;
	Picture.picture[0] = new CLine(1, 2);
    Picture.picture[1] = new CCircle(1, 2);
    Picture.picture[2] = new CRectangle(1, 2, 3);
    Picture.picture[3] = new CSquare(2, 3);
	
	Picture.picture[0]->draw(0,2);
	Picture.picture[1]->draw(3,0);
	Picture.picture[2]->draw(3,0);
	Picture.picture[3]->draw(3,0);
	cout << endl;
	return 0;
}