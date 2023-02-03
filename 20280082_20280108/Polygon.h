#pragma once
#include "framework.h"
#include "Point.h"
#include <iostream>
#include "Shape.h"

// MyPolygon.h
class MyPolygon : public MyShape
{
protected:
	int vertices;
	MyPoint* points;
public:
	MyPolygon(int numVers = 0, MyPoint* p = NULL) : vertices(numVers) { setPoints(numVers, p); }
	virtual ~MyPolygon() { delete[] points; }
	virtual void setPoints(int n ,MyPoint* p);
	virtual MyPoint getCenter() const;
	virtual void Move(double dx, double dy);
	virtual void Scale(MyPoint Center, double s);
	virtual void Scale(double s) { Scale(getCenter(), s); }
	virtual bool isPointInside(MyPoint p) const;
	virtual bool isPointInLine(MyPoint p) const;
	virtual bool Intersection(MyShape* S, HDC hdc, COLORREF c = RGB(156, 200, 30)) const;
	virtual void Draw(HDC hdc, COLORREF c = RGB(0, 100, 100)) const;
};