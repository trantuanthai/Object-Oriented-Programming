#pragma once
#include "framework.h"
#include <iostream>
#include "Ellipse.h"

// MySemiCircle.h
class MySemiCircle : public MyShape
{
protected:
	MyPoint T;
	double r;
public:
	MySemiCircle(double tx, double ty, double r) : T(tx,ty),r(r) {};
	void Move(double dx, double dy) { T.Move(dx, dy); }
	void Scale(double t) { r *= t; }
	void Draw(HDC hdc, COLORREF c = RGB(0, 0, 255)) const;
	bool isPointInside(MyPoint A) const;
	bool isPointInLine(MyPoint A) const;
	bool Intersection(MyShape* S, HDC hdc, COLORREF c = RGB(156, 200, 30)) const;
};