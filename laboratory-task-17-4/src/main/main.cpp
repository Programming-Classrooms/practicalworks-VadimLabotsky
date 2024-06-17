#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>

void printInfo(std::set<std::string> time, std::ofstream& fout)
{
	for (auto fish: time)
	{
		fout <<std::setw(10)<< fish << std::setw(10);
	}
	fout << '\n';
}
int main()
{
	std::set <std::string> lake{ "smelt", "perch", "bream", "pike", "pike-perch", "chub", "carp", "catfish", "eel" };
	std::set <std::string> fishman1{ "smelt", "carp" };
	std::set <std::string> fishman2{ "perch", "pike" };
	std::set <std::string> fishman3{"chub", "smelt", "carp" };
	std::set <std::string> fishThatCaught;
	std::set_union(fishman1.begin(), fishman1.end(), fishman2.begin(), fishman2.end(), std::inserter(fishThatCaught, fishThatCaught.begin()));
	std::set_union(fishThatCaught.begin(), fishThatCaught.end(), fishman3.begin(), fishman3.end(), std::inserter(fishThatCaught, fishThatCaught.begin()));
	std::set<std::string> fishThatNoCaught;
	std::set_difference(lake.begin(), lake.end(), fishThatCaught.begin(), fishThatCaught.end(), std::inserter(fishThatNoCaught, fishThatNoCaught.begin()));
	std::ofstream fout("src/file/Info.txt");
	fout << "Fishman first: ";
	printInfo(fishman1, fout);
	fout << "Fishman second: ";
	printInfo(fishman2, fout);
	fout << "Fishman third: ";
	printInfo(fishman3, fout);
	fout << "\nTypes of fish caught by at least one fisherman: ";
	printInfo(fishThatCaught, fout);
	fout << "\nFish that are in the lake, but not in the catch of any of the fishermen: ";
	printInfo(fishThatNoCaught, fout);
	return 0;
}
