#include "Polygon.h"
#include "Shape.h"

void MyPolygon::setPoints(int n, MyPoint* p)
{
	if (p == NULL) {
		return;
	}
	else {
		points = new MyPoint[vertices = n];
		memcpy(points, p, n * sizeof(MyPoint));
	}
}

MyPoint MyPolygon::getCenter() const
{
	double xx = 0, yy = 0;
	for (int i = 0; i < vertices; i++)
	{
		xx += points[i].GetX();
		yy += points[i].GetY();
	}
	return MyPoint(xx / vertices, yy / vertices);
}

void MyPolygon::Move(double dx, double dy)
{
	for (int i = 0; i < vertices; i++)
		points[i].Move(dx, dy);
}

void MyPolygon::Scale(MyPoint Center, double s)
{
	for (int i = 0; i < vertices; i++)
		points[i].Scale(Center, s);
}

#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

bool MyPolygon::isPointInside(MyPoint p) const
{
	int count = 0;
	double xInters;
	MyPoint p1, p2;
	for (int i = 0; i < vertices; i++)
	{
		p1 = points[i];
		p2 = points[(i + 1) % vertices];
		if (p.GetY() > MIN(p1.GetY(), p2.GetY()) && p.GetY() <= MAX(p1.GetY(), p2.GetY()))
			if (p.GetX() <= MAX(p1.GetX(), p2.GetX()))
				if (p1.GetY() != p2.GetY())
				{
					xInters = (p.GetY() - p1.GetY()) * (p2.GetX() - p1.GetX()) / (p2.GetY() - p1.GetY()) + p1.GetX();
					if (p1.GetX() == p2.GetX() || p.GetX() < xInters)
						count++;
				}
	}
	return (count % 2 != 0);
}

bool MyPolygon::isPointInLine(MyPoint p) const
{
	double d;
	double r = 0.04;
	for (int i = 0; i < vertices; i++)
	{
		d = p.Distance(points[i]) + p.Distance(points[(i + 1) % vertices]) - points[i].Distance(points[(i + 1) % vertices]);
		if (fabs(d) <= r)
			return true;
	}
	return false;
}

bool MyPolygon::Intersection(MyShape* S, HDC hdc, COLORREF c) const
{
	bool check = 0;
	double xMin = points[0].GetX(), yMin = points[0].GetY(), xMax = points[0].GetX(), yMax = points[0].GetY();
	for (int i = 1; i < vertices; i++)
	{
		if (xMin > points[i].GetX())
			xMin = points[i].GetX();
		if (xMax < points[i].GetX())
			xMax = points[i].GetX();
		if (yMin > points[i].GetY())
			yMin = points[i].GetY();
		if (yMax < points[i].GetY())
			yMax = points[i].GetY();
	}
	for (double i = xMin; i <= xMax; i++)
		for (double j = yMin; j <= yMax; j++)
		{
			MyPoint t(i, j);
			if ((this->isPointInLine(t) && S->isPointInside(t)) || (this->isPointInside(t) && S->isPointInLine(t)) || (this->isPointInLine(t) && S->isPointInLine(t)))
			{
				Ellipse(hdc, i - 0.5, j - 0.5, i + 0.5, j + 0.5);
				check = 1;
			}
			else
				if (this->isPointInside(t) && S->isPointInside(t))
				{
					SetPixel(hdc, i, j, c);
					check = 1;
				}
		}
	return check;
}

const int MAX_POINTS = 1000;

void MyPolygon::Draw(HDC hdc, COLORREF c) const
{
	static POINT apt[MAX_POINTS];
	for (int i = 0; i < vertices; i++)
	{
		apt[i].x = points[i].GetX();
		apt[i].y = points[i].GetY();
	}
	Polygon(hdc, apt, vertices);
}