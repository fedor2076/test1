#pragma once

#include "curve.h"

class Circle : public Curve
{
public:
	Circle(double radius) :_radius(radius) {}
	double getPointX(double t)  override;
	double getPointY(double t)  override;
	double getDeriativeX(double t) override;;
	double getDeriativeY(double t) override;; 
	double getRadius();
private:
	double _radius;
};
