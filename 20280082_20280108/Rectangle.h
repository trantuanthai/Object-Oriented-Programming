#pragma once
#include "framework.h"
#include "Point.h"
#include <iostream>
#include "Polygon.h"

// Rectangle.h
class MyRectangle  : public MyPolygon
{
public:
	MyRectangle(int n = 0, MyPoint* p = NULL) { this->vertices = n; setPoints(n, p); }
	virtual ~MyRectangle() { delete[] points; }
	virtual void setPoints(int n, MyPoint* p);
};
