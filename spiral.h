#pragma once
#include "curve.h"

class Spiral : public Curve
{
public:
	Spiral(double radius, double step) :_radius(radius), _step(step) {}
	double getPointX(double t)  override;
	double getPointY(double t)  override;
	double getPointZ(double t); 
	double getDeriativeX(double t) override;
	double getDeriativeY(double t) override;
	double getDeriativeZ();
private:
	double _radius, _step;
};
