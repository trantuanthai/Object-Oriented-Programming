#include "Point.h"
#include <math.h>

const double PI = atan(1) * 4;

void MyPoint::Mark(HDC hdc, int sz) const
{
	for (int i = -sz; i <= sz; i++)
		SetPixel(hdc, x + i, y, RGB(0, 0, 0));
	for (int i = -sz; i <= sz; i++)
		SetPixel(hdc, x, y + i, RGB(0, 0, 0));
}

void MyPoint::Scale(MyPoint center, double tile)
{
	x = (x - center.GetX()) * tile + center.GetX();
	y = (y - center.GetY()) * tile + center.GetY();
}

double MyPoint::Distance(MyPoint a) const
{
	double dx = this->GetX() - a.GetX(), dy = this->GetY() - a.GetY();
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

void MyPoint::Mark(HDC hdc, int size, COLORREF c)
{
	SetPixel(hdc, x, y, c);
	for (int i = 0; i < size; i++)
	{
		SetPixel(hdc, x - i, y, c);
		SetPixel(hdc, x + i, y, c);
		SetPixel(hdc, x, y - i, c);
		SetPixel(hdc, x, y + i, c);
	}
}