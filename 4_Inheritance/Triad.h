#pragma once

class Triad
{
	int first, second, third;
public:
	Triad() { first = 0; second = 0; third = 0; };
	Triad(const int p1, const int p2, const int p3);
	void set_first(int value);
	void set_second(int value);
	void set_third(int value);
	int get_first() const;
	int get_second() const;
	int get_third() const;
	int compare(const Triad& another);
};