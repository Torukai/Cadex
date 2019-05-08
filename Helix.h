#pragma once
#define _USE_MATH_DEFINES
#include "Curve.h"
#include <string>
#include <math.h>
#include <tuple>


class Helix : public Curve
{
private:
	std::string name = "Helix";
	int step, radius;

public:
	Helix();
	~Helix();

	std::tuple<double, double, double> get3DPoint(double t) {
		x = radius*cos(t);
		y = radius*sin(t);
		z = t* 2 * M_PI;

		return  std::make_tuple(x, y, z);
	}

	std::tuple<double, double, double> firstDerivative(double t) {
		f_x = (radius*cos(t + dt) - radius*cos(t)) / dt;
		f_y = (radius*sin(t + dt) - radius*sin(t)) / dt;
		f_z = 2 * M_PI;
		return  std::make_tuple(f_x, f_y, f_z);
	}
};
