#ifndef BUSES_HPP
#define BUSES_HPP
#include "../Bus/Bus.hpp"
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
class Buses: public Bus
{
private:
    std::queue <Bus> buses;
    void copy(std::vector<Bus>&);
    std::map<size_t,Bus> mapBuses;
    void copy();
public:
    Buses();
    Buses(std::queue <Bus>);
    Buses(const Buses&);
    ~Buses();

 
    void sortNumberBus();
    void sortNumberBusRouter();
    friend std::istream& operator>>(std::istream&, Buses&);
    friend std::ostream& operator<<(std::ostream&, const Buses&);
};

#endif // BUS_HPP
