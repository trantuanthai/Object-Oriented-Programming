#include "Ellipse.h"

void MyEllipse::Draw(HDC hdc, COLORREF c) const
{
	Ellipse(hdc, T.GetX() - a, T.GetY() - b, T.GetX() + a, T.GetY() + b);
}

bool MyEllipse::isPointInside(MyPoint A) const
{
	double x = A.GetX() - T.GetX(), y = A.GetY() - T.GetY();
	return x * x / a / a + y * y / b / b <= 1;
}

bool MyEllipse::isPointInLine(MyPoint A) const
{
	double r = 0.03;
	double dx = A.GetX() - T.GetX();
	double dy = A.GetY() - T.GetY();
	double d = (dx / a) * (dx / a) + (dy / b) * (dy / b) - 1;
	return (fabs(d) <= r);
}

bool MyEllipse::Intersection(MyShape* S, HDC hdc, COLORREF c) const
{
	bool check = 0;
	for (double i = T.GetX() - a; i <= T.GetX() + a; i++)
		for (double j = T.GetY() - b; j <= T.GetY() + b; j++)
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
