#ifndef ALLSURNAMES_HPP
#define ALLSURNAMES_HPP
#include "../All/All.hpp"

bool isValidSurname(const std::string&);
void findName(std::string, std::string&, std::ifstream&, std::string&, size_t&);
void arrayAllSurname(std::string&, size_t&, std::string*&);
void insertionSort(size_t&, std::string*&);
bool compareSurnames(const std::string&, const std::string&);

#endif // ALLSURNAMES_HPP

