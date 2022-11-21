#pragma once
#include "Function.h"
#include<math.h>
#include<iostream>

class Ellipse : public Function
{
private:
	float y;
public:
	Ellipse() {a = 0; b = 0; }
	Ellipse(float _a, float _b);

	void set_a(float _a);
	void set_y(float _y);
	void set_b(float _b);

	float get_a() const;
	float get_y() const;
	float get_b() const;

	int calculate(float x) override;
	std::string print(int) override;
};