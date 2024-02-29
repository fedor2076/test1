#include "circle.h"
#include "ellipse.h"
#include "spiral.h"
/*
circle  x = R*cos(t)
        y = R*sin(t)
        x'=-R*sin(t)
        y'=R*cos(t)
ellipse 
        x = a_R*cos(t)
        y = b_R*sin(t)
        x'=-a_R*sin(t)
        y'=b_R*cos(t)
spiral
        x = R*cos(t)
        y = R*sin(t)
        z = step*t
        x'=-R*sin(t)
        y'=R*cos(t)
        z'=step
*/

int main()
{
	std::vector<Curve*> curves;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dist(2.0, 10.0);
	double t = PI / 4;
	for (int i = 0; i < 5; i++)
	{
		double radius = dist(gen);
		
		curves.push_back(new Circle(radius));
		double a_radius = dist(gen);
		double b_radius = dist(gen);
		curves.push_back(new Ellipse(a_radius, b_radius));

		double spiral_radius = dist(gen);
		curves.push_back(new Spiral(spiral_radius, step));
	}
    std::cout << "t = PI/4 = " << t << "\n";
   
    std::vector<Curve*> circles;
	
    for (auto curve : curves)
	{
	std::cout << "--------------------------------------------------------\n";
		if(dynamic_cast<Circle*>(curve))
		{
		circles.push_back(dynamic_cast<Circle*>(curve));
		double pointX = curve->getPointX(t);
		double pointY = curve->getPointY(t);
		double derivativeX = curve->getDeriativeX(t);
		double derivativeY = curve->getDeriativeY(t);
		std::cout << "Circle \n";
		std::cout << "pointX = " << pointX << "; pointY = " << pointY <<"; derivative dx = " << derivativeX << "; derivative dy = " << derivativeY <<"\n";
		}
		if(dynamic_cast<Ellipse*>(curve))
		{
		double pointX = curve->getPointX(t);
		double pointY = curve->getPointY(t);
		double derivativeX = curve->getDeriativeX(t);
		double derivativeY = curve->getDeriativeY(t);
		std::cout << "Ellipse \n";
		std::cout << "pointX = " << pointX << "; pointY = " << pointY << \
		"; derivative dx = " << derivativeX << "; derivative dy = " << derivativeY <<"\n";
		}
		if(dynamic_cast<Spiral*>(curve))
		{
		std::cout << "Spiral \n";
		double pointX = curve->getPointX(t);
		double pointY = curve->getPointY(t);
		double pointZ = dynamic_cast<Spiral*>(curve)->getPointZ(t);
		double derivativeX = curve->getDeriativeX(t);
		double derivativeY = curve->getDeriativeY(t);
		double derivativeZ = dynamic_cast<Spiral*>(curve)->getDeriativeZ();
	    std::cout << "pointX = " << pointX << "; pointY = " << pointY <<"; pointZ = " << pointZ<<"; derivative dx = " << \
	    derivativeX << "; derivative dy = " << derivativeY <<"; derivative dz = " << derivativeZ <<"\n";
	  	}
    
	}
	std::cout << "--------------------------------------------------------\n";
	double sumRadius=0;
	std::vector<double> radiusCircle;
	
	for (auto circle : circles)
	{
	std::cout << "Radius = " << dynamic_cast<Circle*>(circle)->getRadius() << "\n";
	sumRadius +=dynamic_cast<Circle*>(circle)->getRadius();
	radiusCircle.push_back(dynamic_cast<Circle*>(circle)->getRadius());
	}
	
	std::sort(radiusCircle.begin(), radiusCircle.end());
	std::cout << "--------------------------------------------------------\n";
	circles.clear();
	
	for (auto radius : radiusCircle)	
	{
		circles.push_back(new Circle(radius));
	}
	for (auto circle : circles)
	{
	std::cout << "Radius = " << dynamic_cast<Circle*>(circle)->getRadius() << "\n";
	}
	std::cout << "summa Radiuses = " << sumRadius << "\n";
	circles.clear();
	curves.clear();
}
