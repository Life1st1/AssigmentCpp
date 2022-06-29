#ifndef __ASS_11_H__
#define __ASS_11_H__

class CShape{
	public:
		int color;
		virtual void draw(int x, int y) = 0;
};

class CLine: public CShape{
	public:
		int length;
		CLine(int len, int para_color);
		void draw(int x, int y);
};

class CCircle: public CShape{
	public:
		int radium;
		CCircle(int rad, int para_color);
		void draw(int x, int y);
};

class CRectangle: public CShape{
	public:
		int width;
		int length;
		CRectangle(){};
		CRectangle(int wid, int len, int para_color);
		void draw(int x, int y);
};

class CSquare: public CRectangle
{
	public:
		CSquare(int side, int color);
};

class CPicture{
	public:
		CShape* picture[4];
};

#endif //__ASS_11_H__
