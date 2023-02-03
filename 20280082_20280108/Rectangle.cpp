#include "Rectangle.h"

void MyRectangle::setPoints(int n, MyPoint* p)
{
	if (p == NULL) {
		return;
	}
	MyPoint temp1[4];
	temp1[0].SetX(p[0].GetX());
	temp1[0].SetY(p[0].GetY());
	temp1[1].SetX(p[0].GetX());
	temp1[1].SetY(p[1].GetY());
	temp1[2].SetX(p[1].GetX());
	temp1[2].SetY(p[1].GetY());
	temp1[3].SetX(p[1].GetX());
	temp1[3].SetY(p[0].GetY());
	points = new MyPoint[vertices = n];
	memcpy(points, temp1, n * sizeof(MyPoint));
}
