#include "Ellips.h"

Ellipse::Ellipse(float _x, float _a, float _y, float _b)
{
	x = _x;
	a = _a;
	y = _y;
	b = _b;
}

void Ellipse::set_x(float _x)
{
	x = _x;
}

void Ellipse::set_a(float _a)
{
	a = _a;
}

void Ellipse::set_y(float _y)
{
	y = _y;
}

void Ellipse::set_b(float _b)
{
	b = _b;
}

float Ellipse::get_x() const
{
	return x;
}

float Ellipse::get_a() const
{
	return a;
}

float Ellipse::get_y() const
{
	return y;
}

float Ellipse::get_b() const
{
	return b;
}

float Ellipse::calculate(float x)
{
	y = sqrt(b * b * (1 - (x * x / (a * a))));
	return y;
}

void Ellipse::print()
{
	calculate(x);
	std::cout << "Ellips: " << "x = " << x << " a = " << a << " y = " << y << " b = " << b << '\n';
}
