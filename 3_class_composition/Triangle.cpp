
#include "Triangle.h"

Triangle::Triangle()
{
	A = 0, B = 0, C = 0;

	angleA = 0;
	angleB = 0;
	angleC = 0;
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	A = p1;
	B = p2;
	C = p3;
	double AB_ = AB();
	double BC_ = BC();
	double AC_ = AC();
	
	angleA = acos((AB_ * AB_ + AC_ * AC_ - BC_ * BC_) / (2 * AB_ * AC_)) * 180.0 / PI;
	angleB = acos((AB_ * AB_ + BC_ * BC_ - AC_ * AC_) / (2 * AB_ * BC_)) * 180.0 / PI;
	angleC = acos((BC_ * BC_ + AC_ * AC_ - AB_ * AB_) / (2 * BC_ * AC_)) * 180.0 / PI;
}

Triangle::Triangle(const Triangle& triangle)
{
	Triangle new_triangle;
	new_triangle.Set_A(triangle.Get_A());
	new_triangle.Set_B(triangle.Get_B());
	new_triangle.Set_C(triangle.Get_C());
}

bool Triangle::CheckSides()
{
	bool result = true;
	double AB_ = AB();
	double BC_ = BC();
	double AC_ = AC();
	if ((AB_ <= 0 || BC_ <= 0 || AC_ <= 0) || (AB_ + BC_ <= AC_ || BC_ + AC_ <= AB_ || AC_ + AB_ <= BC_))
	{
		result = false;
	}
	return result;
}

bool Triangle::CheckAngles()
{
	bool result = true;
	if ((abs(angleA) <= E || angleA - 180.0 >= E) || (abs(angleB) <= E || angleB - 180.0 >= E) ||
		(abs(angleC) <= E || angleC - 180.0 >= E) || (abs(angleA + angleB + angleC - 180.0) < E))
	{
		result = false;
	}
	return result;
}

double Triangle::Get_angleA()
{
	return angleA;
}

double Triangle::Get_angleB()
{
	return angleB;
}

double Triangle::Get_angleC()
{
	return angleC;
}

double Triangle::CalcArea()
{
	double area;
	double h_perim = CalcPerim() / 2;

	return sqrt(h_perim * (h_perim - AB()) * (h_perim - BC()) * (h_perim - AC()));
}

double Triangle::CalcPerim()
{
	return AB() + BC() + AC();
}

void Triangle::CalcHeights(double& h1, double& h2, double& h3)
{
	h1 = AB() * sin(angleA * PI / 180.0);
	h2 = BC() * sin(angleB * PI / 180.0);
	h3 = AC() * sin(angleC * PI / 180.0);
}

std::string Triangle::TriType()
{
	std::string type;

	double AB_ = AB(), BC_ = BC(), AC_ = AC();
	if (angleA - 90.0 < E && angleB - 90.0 < E && angleC - 90.0 < E)
	{
		type = "Остроугольный треугольник\n";
	}
	//else if (angleA - 90.0 > E || angleB - 90.0 > E || angleC - 90.0 > E)
	else if (abs(AB_ * AB_ + BC_ * BC_ - AC_ * AC_) < E || abs(AC_ * AC_ + BC_ * BC_ - AB_ * AB_) < E
		|| abs(AB_ * AB_ + AC_ * AC_ - BC_ * BC_) < E)
	{
		type = "Прямоугольный треугольник\n";
	}
	else
	{
		type = "Тупоугольный треугольник\n";
	}

	return type;
}

std::string Triangle::toString()
{
	double AB_ = AB(), BC_ = BC(), AC_ = AC();
	return "Сторона AB = " + std::to_string(AB_) + "\nСторона BC = " + std::to_string(BC_) + "\nСторона AC = " + std::to_string(AC_) +
		"\nУгол А = " + std::to_string(angleA) + "\nУгол B = " + std::to_string(angleB) + "\nУгол C = " + std::to_string(angleC) + "\n";
}

