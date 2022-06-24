#include <iostream>
#include "ass11.h"

using namespace std;


/**************************************************************
*Decription: 
*Input:
*Output:
*Return:
***************************************************************/
CLine::CLine(int len, int para_color){
	length = len;
	color = para_color;
}

/**************************************************************
*Decription: 
*Input:
*Output:
*Return:
***************************************************************/
CCircle::CCircle(int rad, int para_color){
	radium = rad;
	color = para_color;
}

/**************************************************************
*Decription: 
*Input:
*Output:
*Return:
***************************************************************/
CRectangle::CRectangle(int wid, int len, int para_color){
	width = wid;
	length = len;
	color = para_color;
}

/**************************************************************
*Decription: 
*Input:
*Output:
*Return:
***************************************************************/
CSquare::CSquare(int side, int para_color){
	width = side;
	length = side;
	color = para_color;
}

/**************************************************************
*Decription: 
*Input:
*Output:
*Return:
***************************************************************/
void CLine::draw(int x, int y){
	while(y--)
		cout << endl;
	while(x--)
		cout << " ";
	cout << "Line(" << length << ", colr:" << color << ")";
}

/**************************************************************
*Decription: 
*Input:
*Output:
*Return:
***************************************************************/
void CCircle::draw(int x, int y){
	while(y--)
		cout << endl;
	while(x--)
		cout << " ";
	cout << "Circle(" << radium << ", colr:" << color << ")";
}

/**************************************************************
*Decription: 
*Input:
*Output:
*Return:
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