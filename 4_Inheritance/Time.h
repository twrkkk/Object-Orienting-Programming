#pragma once
#include "Triad.h"
#include <iostream>

class Time : public Triad
{
public:
	Time() { set_first(0); set_second(0); set_third(0); }
	Time(int t1, int t2, int t3);

	void set_hours(int h);
	void set_min(int m);
	void set_sec(int s);

	int get_hours() const;
	int get_min() const;
	int get_sec() const;

	int calculateDifference(Time anotherTime);
	int toSeconds();
	int toMinutes();

	bool operator> (Time& time);
	bool operator< (Time& time);
	bool operator>= (Time& time);
	bool operator<= (Time& time);
};