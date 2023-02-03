#pragma once
#include "framework.h"
#include <iostream>

// MyPoint.h
class MyPoint
{
protected:
	double x;
	double y;
public:
	MyPoint(double xx, double yy) : x(xx), y(yy) {}
	MyPoint(double xx) : x(xx), y(0) {}
	MyPoint() { x = 0; y = 0; }
	void SetX(double t) { this->x = t; }
	void SetY(double t) { this->y = t; }
	double GetX() const { return x; }
	double GetY() const { return y; }
	void Move(double dx, double dy) { x += dx; y += dy; }
	void Mark(HDC hdc, int size, COLORREF c);
	void Mark(HDC hdc, int sz = 5) const;
	void Scale(MyPoint center, double tile);
	double Distance(MyPoint a) const;
};