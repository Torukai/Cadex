#pragma once
#include "Curve.h"
#include <string>
#include <tuple>
#include <cmath>

class Circle : public Curve {

private:
	std::string name = "Circle";
public:
	Circle();
	~Circle();

	std::tuple<double, double, double> get3DPoint(double t) {
		x = radius*cos(t);
		y = radius*sin(t);
		z = 0;

		return  std::make_tuple(x, y, z);
	}

	std::tuple<double, double, double> firstDerivative(double t) {
		f_x = (radius*cos(t + dt) - radius*cos(t)) / dt;
		f_y = (radius*sin(t + dt) - radius*sin(t)) / dt;
		f_z = 0;
		return  std::make_tuple(f_x, f_y, f_z);
	}

	double getRadius() {
		return this->radius;
	}
};
