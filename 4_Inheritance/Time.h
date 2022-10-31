#pragma once
#include "Triad.h"
#include <iostream>

class Time : public Triad
{
public:
//	using Triad::Triad;
	Time(int t1, int t2, int t3);

	int calculateDifference(Time anotherTime);
	int toSeconds();
	int toMinutes();
};