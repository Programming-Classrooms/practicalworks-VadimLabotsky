#include "Time.hpp"

Time::Time():hour(0), minute (0)
{
}

Time::Time(size_t timeHour, size_t timeMinute): hour(timeHour), minute(timeMinute)
{
}

Time::Time(const Time& rhs): hour(rhs.hour), minute(rhs.minute)
{
}

Time::~Time()
{
}

bool Time::operator<=(const Time& rhs) const {
	if (hour == rhs.hour) {
		return minute <= rhs.minute;
	}
	return hour <= rhs.hour;
}

bool Time::operator>=(const Time& rhs) const {
	if (operator<=(rhs)) {
		return false;
	}
	return true;
}

std::istream& operator>>(std::istream& in, Time& rhs)
{
	in >> rhs.hour;
	in.ignore();
	in>> rhs.minute;
	return in;
}

std::ostream& operator<<(std::ostream& out, Time rhs)
{
	out << rhs.hour << ":";
	if(rhs.minute < 10)	{
		out << 0 << rhs.minute;
		return out;
	}
	else
	{
		out << rhs.minute;
		return out;
	}
	
}
