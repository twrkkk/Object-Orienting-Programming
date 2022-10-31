#include "Triad.h"

Triad::Triad(const int p1, const int p2, const int p3)
{
	first = p1;
	second = p2;
	third = p3;
}

void Triad::set_first(int value)
{
	first = value;
}

void Triad::set_second(int value)
{
	second = value;
}

void Triad::set_third(int value)
{
	third = value;
}

int Triad::get_first() const
{
	return first;
}

int Triad::get_second() const
{
	return second;
}

int Triad::get_third() const
{
	return third;
}

int Triad::compare(const Triad& another)
{
	return (first > another.get_first() ? 1 : first < another.get_first() ? -1 :
		second>another.get_second() ? 1 : second<another.get_second() ? -1 :
		third>another.get_third() ? 1 : third < another.get_third() ? -1 : 0);
}
