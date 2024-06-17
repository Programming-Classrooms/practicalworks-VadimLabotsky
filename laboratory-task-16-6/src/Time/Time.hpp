#ifndef TIME_HPP
#define TIME_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
class Time
{
protected:
	size_t hour;
	size_t minute;
public:
	Time();
	Time(size_t, size_t);
	Time(const Time&);
	~Time();
	bool operator<=(const Time&) const;
	bool operator>=(const Time&) const;
	friend std::istream& operator>>(std::istream&, Time&);
	friend std::ostream& operator<<(std::ostream&, Time);

};

#endif // !TIME_HPP

