#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
void print(std::vector <int> numbers)
{
	for (int& i : numbers)
	{
		std::cout << i << '\t';
	}
	std::cout << '\n';
}
int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector <int> numbers;
	int input = 0;
	std::cout << "Введите числа! Когда захотите закончить ввод чисел введите символ!\n";
	while (std::cin >> input )
	{
		numbers.push_back(input);
	}
	int summa = 0;
	summa = std::accumulate(numbers.begin(), numbers.end(), 0);

	std::cout << "Сумма всех чисел = " << summa << '\n';

	std::cout<< "Общее количество чисел = " << numbers.size() << '\n';
	
	std::cout << "Введите число, которого хотите посчитать количество!\n";
	int time = 0;
	size_t count = 0;
	std::cin.clear();
	std::cin.ignore();
	std::cin >> time;
	count = std::count(numbers.begin(), numbers.end(), time);
	if (count == 0)
	{
		std::cout << "Нет таких чисел!\n";
	}
	else
	{
		std::cout << "Количество чисел равному данному = " << count << '\n';
	}

	time = 0;
	count = 0;
	std::cout << "Введите число, которое будет больше чисел!\n";
	std::cin >> time;
	count = std::count_if(numbers.begin(), numbers.end(), [time](int num) { return num > time; });
	if (count == 0)
	{
		std::cout << "Нет таких чисел!\n";
	}
	else
	{
		std::cout << "Количество чисел больше данного = " << count << '\n';
	}

	int avg = (summa / numbers.size());
	std::replace(numbers.begin(), numbers.end(), 0, avg);
	std::cout << "Полученный массив после замены всех 0  средним арифметическим!" <<  '\n';
	print(numbers);
	
	int left = 0;
	int right = 0;
	std::cout << "Введите интервал!" << '\n';
	std::cin >> left >> right;
	int summaInterval = 0;
	for (int& i : numbers)
	{
		if (i >= left && i <= right)
		{
			summaInterval += i;
		}
	}
	for (int& i : numbers)
	{
		i += summaInterval;
	}
	std::cout << "Вывод массива после добавления к каждому элементу вектора сумму всех чисел из	заданного интервала этого же вектора" << '\n';
	print(numbers);
	int max = *std::max_element(numbers.begin(), numbers.end());
	int min = *std::min_element(numbers.begin(), numbers.end());
	int minMax = max - min;
	for (int& i :numbers)
	{
		if (std::abs(i) % 2 == 0)
		{
			i = minMax;
		}
	}
	std::cout << "Вывод массива после замены всех чисел, модуль которых есть четное число, на разность максимального и минимального элемента этого вектора" << '\n'; 
	print(numbers);

	std::vector<int> uniqueNumbers;
	for (int num : numbers) {
		if (std::find(uniqueNumbers.begin(), uniqueNumbers.end(), std::abs(num)) == uniqueNumbers.end()) {
			uniqueNumbers.push_back(std::abs(num));
		}
	}

	std::cout << "Вывод массива после удалиния из последовательности все равные по модулю числа, кроме первого из них!" << '\n';
	print(uniqueNumbers);
	return 0;
}
