#ifndef BUS_HPP
#define BUS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
class Bus
{
protected:
    size_t numberBusRouter;
    std::string driver;
    size_t numberBus;
    std::string markOfBus;
public:
    Bus();
    Bus(size_t, std::string, size_t, std::string);
    Bus(const Bus&);
    ~Bus();
    size_t getNumberBusRouter() const;
    std::string getDriver() const;
    size_t getNumberBus() const;
    std::string getMarkOfBus() const;

    void setNumberBusRouter(size_t);
    void setDriver(std::string);
    void setNumberBus(size_t);
    void setMarkOfBus(std::string);

    Bus operator=(const Bus&);
    
    friend std::istream& operator>>(std::istream&, Bus&);
    friend std::ostream& operator<<(std::ostream&, const Bus&);
};


#endif // BUS_HPP
