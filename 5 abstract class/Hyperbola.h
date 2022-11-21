#pragma once
#include "Function.h"
#include <iostream>
#include <math.h>
#include <string>
//А,б перенести в функцию х убрать т.к. передаем его при вычислении значение У может быть несколько Лаба ооп 6 22 стр 125
class Hyperbola :public Function
{
private:
	float y;
public:
	Hyperbola() { a = 0; y = 0; b = 0; }
	Hyperbola(float _a, float _b);

	void set_a(float _a);
	void set_y(float _y);
	void set_b(float _b);

	float get_a() const;
	float get_y() const;
	float get_b() const;

	int calculate(float x) override;
	std::string print(int) override;
};