#pragma once
#include "framework.h"
#include <iostream>
#include "Rectangle.h"

// MySquare.h
class MySquare : public MyRectangle
{
protected:
	double d;
public:
	MySquare(int n, MyPoint* p, double d) { this->vertices = n; this->d = d; setPoints(n, p, d); }
	~MySquare() { delete[] points; }
	void setPoints(int n, MyPoint* p, double d = 0);
};

