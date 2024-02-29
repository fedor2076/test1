#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include<algorithm>
const double PI = 3.1415926;
const double step = 0.01;

class Curve
{
public:
virtual ~Curve(){}
	virtual double getPointX(double t)=0;
	virtual double getPointY(double t)=0;
	virtual double getDeriativeX(double t)=0;
	virtual double getDeriativeY(double t)=0;
};


