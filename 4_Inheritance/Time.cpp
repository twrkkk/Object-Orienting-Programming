#include "Time.h"

Time::Time(int t1, int t2, int t3)
{
	set_first(t1);
	set_second(t2);
	set_third(t3);
}

void Time::set_hours(int h)
{
	int value;
	h > -1 && h < 25 ? value = h : h < 0 ? value = 0 : value = 24;
	set_first(value);
}

void Time::set_min(int m)
{
	int value;
	m > -1 && m < 61 ? value = m : m < 0 ? value = 0 : value = 60;
	set_second(value);
}

void Time::set_sec(int s)
{
	int value;
	s > -1 && s < 61 ? value = s : s < 0 ? value = 0 : value = 60;
	set_third(value);
}

int Time::get_hours() const
{
	return get_first();
}

int Time::get_min() const
{
	return get_second();
}

int Time::get_sec() const
{
	return get_third();
}

int Time::calculateDifference(Time anotherTime)
{
	return abs(toSeconds() - anotherTime.toSeconds());
}

int Time::toSeconds()
{
	return (get_first() * 3600 + get_second() * 60 + get_third());
}

bool Time::operator>(Time& time)
{
	return get_first() > time.get_first() ? 1 :
		get_first() < time.get_first() ? 0 :
		get_second() > time.get_second() ? 1 :
		get_second() < time.get_second() ? 0 :
		get_third() > time.get_third() ? 1 :
		get_third() < time.get_third() ? 0 : 0;
}

bool Time::operator<(Time& time)
{
	return get_first() < time.get_first() ? 1 :
		get_first() > time.get_first() ? 0 :
		get_second() < time.get_second() ? 1 :
		get_second() > time.get_second() ? 0 :
		get_third() < time.get_third() ? 1 :
		get_third() > time.get_third() ? 0 : 0;
}

bool Time::operator>=(Time& time)
{
	return *this == time ? 1 :
		*this > time ? 1 : 0;
}

bool Time::operator<=(Time& time)
{
	return *this == time ? 1 :
		*this < time ? 1 : 0;
}

int Time::toMinutes()
{
	return (get_first() * 60 + get_second() + ((get_third() >= 30) ? 1 : 0));
}
