#pragma once
#include "framework.h"
#include <iostream>
#include "Ellipse.h"

// MyCircle.h
class MyCircle : public MyEllipse
{
public:
	MyCircle(double tx, double ty, double r) : MyEllipse(tx, ty, r, r) {}
};