#include "Hyperbola.h"

Hyperbola::Hyperbola(float _a, float _b)
{
	a = _a;
	b = _b;
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

int Hyperbola::calculate(float x)
{
	float e = 1e-6;
	int result = -1;

	if (abs(x) - a > e)
	{
		y = sqrt(b * b * ((x * x / (a * a) - 1)));
		result = 1;
	}
	else if (abs(x - a) > e)
	{
		y = result = -1;
	}
	else if (abs(x) - a < e)
	{
		y = result = 0;
	}
	
	return result;
}

std::string Hyperbola::print(int result)
{
	if (result == -1)
		return "Y for this hyperbola doesn`t exist \n";
	else if (result == 0)
		return "Hyperbola: a = " + std::to_string(a) + " y = " + std::to_string(y) + " b = " + std::to_string(b);

	return "Hyperbola: a = " + std::to_string(a) + " y1 = " + std::to_string(y) + " y2 = " + std::to_string(-y) + " b = " + std::to_string(b);
}
