#pragma once
#include "framework.h"
#include "Point.h"
#include "Shape.h"
#include <iostream>

// MyEllipse.h
class MyEllipse : public MyShape
{
protected:
	MyPoint T;
	double a;
	double b;
public:
	MyEllipse(double tx, double ty, double aa, double bb) : T(tx, ty), a(aa), b(bb) {}
	~MyEllipse() { T.SetX(0); T.SetY(0); a = b = 0; }
	virtual void Move(double dx, double dy) { T.Move(dx, dy); }
	virtual void Scale(double t) { a *= t; b *= t; }
	virtual void Draw(HDC hdc, COLORREF c = RGB(0, 0, 255)) const;
	virtual bool isPointInside(MyPoint A) const;
	virtual bool isPointInLine(MyPoint A) const;
	virtual bool Intersection(MyShape* S, HDC hdc, COLORREF c = RGB(156, 200, 30)) const;
};