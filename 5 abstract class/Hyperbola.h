#pragma once
#include "Function.h"
#include <iostream>
#include <math.h>

class Hyperbola :public Function
{
private:
	float x, a, y, b;
public:
	Hyperbola() { x = 0; a = 0; y = 0; b = 0; }
	Hyperbola(float _x, float _a, float _y, float _b);

	void set_x(float _x);
	void set_a(float _a);
	void set_y(float _y);
	void set_b(float _b);

	float get_x() const;
	float get_a() const;
	float get_y() const;
	float get_b() const;

	float calculate(float x) override;
	void print() override;
};