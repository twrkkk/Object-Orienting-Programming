#include "Hyperbola.h"

Hyperbola::Hyperbola(float _x, float _a, float _y, float _b)
{
	x = _x;
	a = _a;
	y = _y;
	b = _b;
}

void Hyperbola::set_x(float _x)
{
	x = _x;
}

void Hyperbola::set_a(float _a)
{
	a = _a;
}

void Hyperbola::set_y(float _y)
{
	y = _y;
}

void Hyperbola::set_b(float _b)
{
	b = _b;
}

float Hyperbola::get_x() const
{
	return x;
}

float Hyperbola::get_a() const
{
	return a;
}

float Hyperbola::get_y() const
{
	return y;
}

float Hyperbola::get_b() const
{
	return b;
}

float Hyperbola::calculate(float x)
{
	y = sqrt(b * b * ((x * x / (a * a) - 1)));
	return y;
}

void Hyperbola::print()
{
	calculate(x);
	std::cout << "Hyperbola: " << "x = " << x << " a = " << a << " y = " << y << " b = " << b << '\n';
}
