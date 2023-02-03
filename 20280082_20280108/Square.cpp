#include "Square.h"

void MySquare::setPoints(int n, MyPoint* p, double d)
{
	MyPoint temp2[4];
	temp2[0].SetX(p[0].GetX());
	temp2[0].SetY(p[0].GetY());
	temp2[1].SetX(p[0].GetX() + d);
	temp2[1].SetY(p[0].GetY());
	temp2[2].SetX(p[0].GetX() + d);
	temp2[2].SetY(p[0].GetY() + d);
	temp2[3].SetX(p[0].GetX());
	temp2[3].SetY(p[0].GetY() + d);
	points = new MyPoint[vertices = n];
	memcpy(points, temp2, n * sizeof(MyPoint));
}