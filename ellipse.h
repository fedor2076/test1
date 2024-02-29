#pragma once
#include "curve.h"

class Ellipse : public Curve
{
public:
	Ellipse(double radiusA, double radiusB) :_radiusA(radiusA), _radiusB(radiusB) {}
	double getPointX(double t)  override;
	double getPointY(double t)  override;
	double getDeriativeX(double t) override;
    double getDeriativeY(double t) override;
private:
	double _radiusA, _radiusB;
};

