#include "Time.h"

Time::Time(int t1, int t2, int t3)
{
	set_first(t1);
	set_second(t2);
	set_third(t3);
}

int Time::calculateDifference(Time anotherTime)
{
	return abs(toSeconds() - anotherTime.toSeconds());
}

int Time::toSeconds()
{
	return (get_first() * 3600 + get_second() * 60 + get_third());
}

int Time::toMinutes()
{
	return (get_first() * 60 + get_second() + ((get_third() >= 30) ? 1 : 0));
}
