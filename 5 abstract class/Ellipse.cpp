#include "Ellips.h"
#include <string>

Ellipse::Ellipse(float _a, float _b)
{
	a = _a;
	b = _b;
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

int Ellipse::calculate(float x)
{
	float e = 1e-6;
	int result = -1;
	if (abs(x) - a > e)
	{
		y = result = -1;
	}
	else if (abs(x - a) < e)
	{
		y = result = 0;
	}
	else if (abs(x) - a < e)
	{
		y = sqrt(b * b * (1 - (x * x / (a * a))));
		result = 1;
	}
	return result;
}

std::string Ellipse::print(int result)
{
	//<< "x = " << x <<

	if (result == -1)
		return "Y for this ellips doesn`t exist \n";
	else if (result == 0)
		return "Ellips: a = " + std::to_string(a) + " y = " + std::to_string(y) + " b = " + std::to_string(b);

	return "Ellips: a = " + std::to_string(a) + " y1 = " + std::to_string(y) + " y2 = " + std::to_string(-y) + " b = " + std::to_string(b);
}
