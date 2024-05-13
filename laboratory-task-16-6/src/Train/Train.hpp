#ifndef TRAIN_HPP
#define TRAIN_HPP
#include <string>
#include "../Time/Time.hpp"

enum class Type
{
	Пассажирский,
	Скорый,

};
class Train: public Time
{
private:
	size_t trainNumber;
	std::string nameOfDestination;
	Type typeOfTrain;
	Time departureTime;
	size_t travelTime;
public:
	Train();
	Train(size_t, std::string,Type, Time, size_t);
	Train(const Train&);
	~Train();
	Time getDepartureTime() const;
	std::string getNameOfDestination() const;
	size_t getTravelTime() const;
	Type getTypeOfTrain() const;
	bool operator<= (const Train&);
	friend std::istream& operator>>(std::istream&, Train&);
	friend std::ostream& operator<<(std::ostream&, Train);
};

#endif // !TRAIN_HPP
