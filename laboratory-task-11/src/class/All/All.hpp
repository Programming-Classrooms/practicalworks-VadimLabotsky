#ifndef ALL_HPP
#define ALL_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
void checkFile(std::ifstream&);
std::string getDelimeters(std::ifstream&);
bool chek(size_t, size_t);
void removeNegativeOrDoubleDigit(int32_t*&, size_t&);
void enterElementsForAllNumber(int32_t*&, size_t&, size_t&, std::string);
void enterNewElements(int32_t*&, std::string*&, size_t&, size_t);
#endif // !ALL_HPP

