#include "circle.h"

double Circle::getPointX(double t)
	{
		double x = _radius * cos(t);
		return x;
	}
double Circle::getPointY(double t)
	{
		double y = _radius * sin(t);
		return y;
	}
double 	Circle::getDeriativeX(double t)
	{
		double dx = -_radius * sin(t);
		return dx;
	}
double 	Circle::getDeriativeY(double t)
	{
		double dy = _radius * cos(t);
		return dy;
	}

double 	Circle::getRadius()
	{
	return _radius;
	}

