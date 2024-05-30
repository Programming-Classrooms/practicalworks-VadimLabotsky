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
public:
    void copyMap();
    Buses() = default;
    Buses(std::queue <Bus>);
    Buses(const Buses&);
    ~Buses();
    void find(size_t);
    void print(std::string);
    void erase(size_t);
    void sortNumberBus();
    void sortNumberBusRouter();
    friend std::istream& operator>>(std::istream&, Buses&);
    friend std::ostream& operator<<(std::ostream&, const Buses&);
};

#endif // BUS_HPP
