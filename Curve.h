#pragma once
#include <iostream>
#include <tuple>
#include <cmath>

//Base class

class Curve
{
protected:
	double x, y, z, f_x, f_y, f_z;
	int a, b, radius;
	const double dt = 0.0001;
	
public:
	Curve();
	~Curve();

	virtual std::tuple<double, double, double> get3DPoint(double t) {
		x = radius*cos(t);
		y = radius*sin(t);
		z = 0;

		return  std::make_tuple(x, y, z);
	}

	virtual std::tuple<double, double, double> firstDerivative(double t) {
		return std::make_tuple(0, 0, 0);
	}

	virtual double getRadius() const {
		return this->radius;
	}

};

