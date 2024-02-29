#include "spiral.h"

double Spiral::getPointX(double t)
	{
		double x = _radius * cos(t);
		return x;
	}
double Spiral::getPointY(double t)
	{
		double y = _radius * sin(t);
		return y;
	}
double Spiral::getPointZ(double t)
	{
	double z = step * t;
	    return z;
	}
double Spiral::getDeriativeX(double t)
	{
	double dx = -_radius * sin(t);
		return dx;
	}
double Spiral::getDeriativeY(double t)
	{
	double dy = _radius * cos(t);
		return dy;
	}
double Spiral::getDeriativeZ()
	{
	double dz = _step;
		return dz;
	}
	
	
