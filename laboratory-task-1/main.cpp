/*
	Задания к лабораторной работе №1 : Разработать консольное приложение для вычисления приближённого значения
	функции,используя представление ее в виде ряда Тейлора.Вычисления заканчивать, когда очередное слагаемое
	окажется по модулю меньше заданного числа epsilon, где 0 < epsilon <= 10 - k, k – натуральное число, k > 1.
	Сравнить полученный результат со значением, вычисленным с помощью стандартных функций.
	Значение x и k ввести по запросу.
	ln(1 + x) = x - x ^ 2 / 2 + x ^ 3 / 3 - x ^ 4 / 4 + …,где x∈(-1; +1]
*/


#include <iostream>
#include <cmath>


int main() 
{
	double result = 0,
	double p = 0;
	double s = 0;
	double x = 0;
	const double E = 2.71828182846;
	int32_t k = 0;
	int32_t n = 1;
	std::cout << "Please, enter x!\n-1 < x <= 1\n";
	std::cin >> x;
	std::cout << "Please, enter k!\nk > 1\n";
	std::cin >> k;
	p = x;
	result = (exp (x) - exp(-x)) / 2;
	if (k > 1 || (x < -1 && x <= 1)) {
       		while (fabs(p) > pow(10, -k)) {
        	    s += p;
        	    p = (p * x * x) / (2 * n * (2 * n + 1));
        	    ++n;
        	}
       		std::cout << result <<"  =  " << s;
	}
	else {
        	std::cout << "Please, enter k, x not satisfying the condition!";
    	}
    	return 0;
}

