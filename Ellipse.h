#pragma once
#include "Curve.h"
#include <string>
#include <tuple>

class Ellipse : public Curve
{
private:
	std::string name = "Ellipse";
	int radius2;
	double a, b;

public:
	Ellipse();
	~Ellipse();
	std::tuple<double, double, double> get3DPoint(double t) {
		x = a*cos(t);
		y = b*sin(t);
		z = 0;

		return  std::make_tuple(x, y, z);
	}

	std::tuple<double, double, double> firstDerivative(double t) {
		f_x = (a*cos(t + dt) - a*cos(t)) / dt;
		f_y = (b*sin(t + dt) - b*sin(t)) / dt;
		f_z = 0;
		return  std::make_tuple(f_x, f_y, f_z);
	}

	
};
