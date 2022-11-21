#pragma once
#include <string>

class Function
{
private:
public:
	float a, b;
	virtual int calculate(float x) = 0;
	virtual std::string print(int) = 0;
};