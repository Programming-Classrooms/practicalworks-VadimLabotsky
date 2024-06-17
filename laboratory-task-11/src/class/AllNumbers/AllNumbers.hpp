#ifndef ALLNUMBERS_HPP
#define ALLNUMBERS_HPP
#include "../All/All.hpp"
bool isNumber(std::string word);
void findNumber(std::string line, std::string& delims, std::ifstream& fin, std::string& result, size_t& count);
void arrayAllNumbers(std::string& result, size_t& count, int32_t*& allNumbers);
void paritySort(int32_t*& arr, size_t count);
#endif // !ALLNUMBERS_HPP

