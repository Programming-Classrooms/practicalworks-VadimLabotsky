#include <iostream>
using std::cout;
using std::cin;
int main()
{
	int64_t number, min{ 9 }, last_number{ 0 };
	int64_t time_number;
	double x = 0.1;
	int last_digit;
	int modified_number = 0;
	cout << "Input number\n";
	cin >> number;
	while (number <= 0)
	{
		cout << "ERROR! Please, enter natural number!!! \n ";
		cin >> number;
	}
	time_number = number;
	while (number)
	{
		last_number = number % 10;
		if (last_number < min)
		{
			min = last_number;
		}
		number /= 10;
	}
	number = time_number;
	while (number > 0)
	{
		int64_t last_digit = number % 10;
		number /= 10;
		if (last_digit % min != 0)
		{
			x *= 10;
		}
		if (last_digit % min != 0)
		{
			modified_number = modified_number + (last_digit * x);
		}
	}
	number = time_number;
	system("cls");
	cout << number << '\n';
	cout << "Modified number\n" << modified_number;


	return 0;
}
