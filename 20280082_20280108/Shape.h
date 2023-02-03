#pragma once
#include "framework.h"
#include "Point.h"
#include <iostream>

// MyShape.h
class MyShape
{
public:
	virtual void Move(double dx, double dy) = 0;
	virtual void Scale(double s) = 0;
	virtual bool isPointInside(MyPoint p) const  = 0;
	virtual bool isPointInLine(MyPoint p) const = 0;
	virtual bool Intersection(MyShape* aS, HDC hdc, COLORREF c = RGB(156, 200, 30)) const = 0 ;
	virtual void Draw(HDC hdc, COLORREF c = RGB(0, 100, 100)) const = 0;
};