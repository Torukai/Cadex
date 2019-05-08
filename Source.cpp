#include <iostream>
#include <vector>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <random>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;


void output(double x, double y, double z, double f_x, double f_y, double f_z) {
	cout << "{ " << x << ", " << y << ", " << z << " }" << endl;
	cout << "first derivative: ";
	cout << "{ " << f_x << ", " << f_y << ", " << f_z << " }" << endl;
	cout << endl;
}

bool IsTrue( Curve* c1,Curve* c2) {
	return c1->getRadius() < c2->getRadius();
}

int main() {
	int size = 20;
	int sum = 0;
	
	vector<Curve*> curves; 
	vector<Curve*> circles;

	double t = M_PI/4;
	Curve* c = nullptr;

	int m;
	double x, y, z;
	double f_x, f_y, f_z;
	//======================================================================
	//Filling a vector with random objects of 3 types.
	//Total amount of elements is 20.
	//Radii of the elements is a random number between 1 and 50
	//if object is a "Circle" it also will be added to the second container
	//======================================================================
	for (int i = 0; i < size; i++) {

		m = rand() % 3;

		switch (m) {

		case 0:
			cout << "Circle: ";
			c = new Circle();
			curves.push_back(c);
			circles.push_back(c);
			tie(x, y, z) = curves[i]->get3DPoint(t);
			tie(f_x, f_y, f_z) = curves[i]->firstDerivative(t);
			output(x, y, z, f_x, f_y, f_z);
 			break;

		case 1:
			cout << "Ellipse: ";
			curves.push_back(new Ellipse());
			tie(x, y, z) = curves[i]->get3DPoint(t);
			tie(f_x, f_y, f_z) = curves[i]->firstDerivative(t);
			output(x, y, z, f_x, f_y, f_z);
			break;

		case 2:
			cout << "Helix: ";
			curves.push_back(new Helix());
			tie(x, y, z) = curves[i]->get3DPoint(t);
			tie(f_x, f_y, f_z) = curves[i]->firstDerivative(t);
			output(x, y, z, f_x, f_y, f_z);
			break;

		default:
			break;

		}
	}

	//sorting the second container in the ascending order
	std::sort(circles.begin(), circles.end(), IsTrue);
	
	//sum up radii of circles
	for (auto v : circles) {	
		cout << "Radius = " << v->getRadius()<<endl;
		sum = sum + v->getRadius();
	}
	cout << endl;
	cout << "Sum of radii of the curves in the second container: " << sum << endl;


	system("Pause");
	return 0;
}