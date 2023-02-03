#include "SemiCircle.h"

void MySemiCircle::Draw(HDC hdc, COLORREF c) const
{
	Pie(hdc, T.GetX() - r, T.GetY() + r, T.GetX() + r, T.GetY() - r,
		T.GetX() - r, T.GetY(), T.GetX() + r,T.GetY());
}

bool MySemiCircle::isPointInside(MyPoint A) const
{
	bool check = 0;
	bool temp1 = false, temp2 = false;
	if ((A.GetY() - T.GetY()) * (r) - (T.GetY() - T.GetY()) * (A.GetX() - (T.GetX()+r)) >= 0) {
		temp1 = true;
	}
	if (r >= T.Distance(A))
	{
		temp2 = true;
	}
	if (temp1 && temp2)
	{
		check = 1;
	}
	return check;
}

bool MySemiCircle::isPointInLine(MyPoint A) const
{
	double r = 0.03;
	double dx = A.GetX() - T.GetX();
	double dy = A.GetY() - T.GetY();
	double d = (dx / r) * (dx / r) + (dy / r) * (dy / r) - 1;
	return (fabs(d) <= r);
}

bool MySemiCircle::Intersection(MyShape* S, HDC hdc, COLORREF c) const
{
	bool check = 0;
	for (double i = T.GetX() - r; i <= T.GetX() + r; i++)
		for (double j = T.GetY() ; j <= T.GetY() + r; j++)
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
