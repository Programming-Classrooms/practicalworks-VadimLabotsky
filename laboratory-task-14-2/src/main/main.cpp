#include "src/class/StudentAfterSecondSession/StudentAfterSecondSession.hpp"


int main()
{
	size_t arr[4] = { 10, 9, 10, 10 };
	size_t arr1[5] = { 10, 10, 10, 10,10 };
	StudentAfterFirstSession Vadim1("Vadim", 1, 7121, 123456, arr);
	StudentAfterSecondSession Vadim2("Vadim", 1, 7121, 123456, arr,arr1);
	std::cout << Vadim1;
	std::cout << Vadim1.calculateAverageGrade() << '\n';
	std::cout << Vadim2;
	std::cout << Vadim2.calculateAverageGrade() << '\n';
	return 0;
}