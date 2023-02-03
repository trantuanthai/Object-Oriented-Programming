#pragma once
#include "framework.h"
#include "Point.h"
#include <iostream>
#include "Polygon.h"
#include "Point.h"

// MyTriangle.h
class MyTriangle : public MyPolygon
{
public:
	MyTriangle(int n, MyPoint* p) : MyPolygon(n, p) {};
	MyTriangle() { delete[] points; }
};
