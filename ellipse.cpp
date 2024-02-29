#include "ellipse.h"


double  Ellipse::getPointX(double t)
	{
		double x = _radiusB * cos(t);
		return x;
	}
double Ellipse::getPointY(double t)
	{
		double y = _radiusA * sin(t);
		return y;
	}
double Ellipse::getDeriativeX(double t)
	{
		double dx = -_radiusA * sin(t);
		return dx;
	}
double Ellipse::getDeriativeY(double t)
	{
		double dy = _radiusB * cos(t);
		return dy;
	}
