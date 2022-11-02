#pragma once
#define PI 3.1415926
#define E 1e-10

#include <iostream>
#include <cmath>
#include <string>
#include "Point.h"

class Triangle
{
private:
	Point A, B, C;
	double angleA, angleB, angleC;
	bool CheckSides();
	bool CheckAngles();

public:
	Triangle();
	Triangle(Point, Point, Point);
	Triangle(const Triangle& triangle);

	double AB() { return A.distance_to_point(B); }
	double BC() { return C.distance_to_point(B); }
	double AC() { return A.distance_to_point(C); }

	double Get_angleA();
	double Get_angleB();
	double Get_angleC();

	Point Get_A()const { return A; };
	Point Get_B()const { return B; };
	Point Get_C()const { return C; };
	void Set_A(Point A_) { A = A_; };
	void Set_B(Point B_) { B = B_; };
	void Set_C(Point C_) { C = C_; };

	double CalcArea();
	double CalcPerim();
	void CalcHeights(double&, double&, double&);
	std::string TriType();

	std::string toString();
};