#include <iostream>
#include <vector>
#include <cmath>
#include <random>
const double PI = 3.1415926;


class Curve
{
public:
	virtual double getPointX(double t) = 0;
	virtual double getPointY(double t) = 0;
	virtual double getDeriative(double t) = 0;
};

class Circle : public Curve
{
public:
	Circle(double radius) :_radius(radius) {}
	double getPointX(double t)  override
	{
		double x = _radius * cos(t);
		return x;
	}
	double getPointY(double t)  override
	{
		double y = _radius * sin(t);
		return y;
	}
	double getDeriative(double t)
	{
		double dx = -_radius * sin(t);
		double dy = _radius * cos(t);
		return dy / dx;
	}

private:
	double _radius;
};


class Ellipse : public Curve
{
public:
	Ellipse(double radiusA, double radiusB) :_radiusA(radiusA), _radiusB(radiusB) {}

	double getPointX(double t)  override
	{
		double x = _radiusB * cos(t);
		return x;
	}
	double getPointY(double t)  override
	{
		double y = _radiusA * sin(t);
		return y;
	}
	double getDeriative(double t)
	{
		double dx = -_radiusA * sin(t);
		double dy = _radiusB * cos(t);
		return dy / dx;
	}
private:
	double _radiusA, _radiusB;
};
class Spiral : public Curve
{
public:
	Spiral(double a, double b) :_a(a), _b(b) {}

	double getPointX(double t)  override
	{
		double x = _a * cos(t) + _b * cos(2 * t);
		return x;
	}
	double getPointY(double t)  override
	{
		double y = _a * sin(t) + _b * sin(2 * t);
		return y;
	}
	double getDeriative(double t)
	{
		double dy = -_a * cos(t) - _b * cos(2 * t);
		double dx = _a * sin(t) + _b * sin(2 * t);
		return dy / dx;
	}
private:
	double _a, _b;
};

int main()
{
	std::vector<Curve*> curves;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dist(0.1, 10.0);
	for (int i = 0; i < 3; i++)
	{
		double radius = dist(gen);
		curves.push_back(new Circle(radius));


		double a_radius = dist(gen);
		double b_radius = dist(gen);
		curves.push_back(new Ellipse(a_radius, b_radius));
		double a_spiral = dist(gen);
		double b_spiral = dist(gen);
		curves.push_back(new Spiral(a_spiral, b_spiral));

		double t = PI / 4;

		for (auto curve : curves)
		{
			double pointX = curve->getPointX(t);
			double pointY = curve->getPointY(t);
			double derivative = curve->getDeriative(t);
			std::cout << "pointX = " << pointX << "; pointY = " << pointY << "; derivative = " << derivative << "\n";
		}
	}
	for (auto curve : curves)
	{
		delete curve;
	}
	curves.clear();
}




