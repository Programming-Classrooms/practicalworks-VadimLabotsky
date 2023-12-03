#include <iostream> 
#include <cmath> 
#include <functional> 
#include <iomanip> 


double func(double x) {
	return (1 / ((x + 1) * sqrt(x * x + 1)));
}

double func1(double x)
{
	return sqrt(pow(2, x) - 1);
}

double func2(double x)
{
	return tan(x);
}
double InegrTrapecia(const std::function<double(double)>& f, double a, double b, double eps)
{
	uint64_t n = 4;
	double weight = 0;
	double x1 = 0, x2 = 0;
	double s1 = 0;
	double s2 = 0.5 * (f(a) + f(b)) * (b - a);
	do {
		s1 = s2;
		n <<= 1;
		weight = (b - a) / n;
		s2 = 0;
		for (int step = 0; step < n; ++step) {
			x1 = a + step * weight;
			x2 = a + (step + 1) * weight;
			s2 += 0.5 * (x2 - x1) * (f(x1) + f(x2));
		}
	} while (fabs(s1 - s2) > eps);
	return s2;
}
double mediumRectangle(const std::function<double(double)>& f, double a, double b, double eps) {
	int32_t n = 4;
	double sum = 0.0;
	double step = (b - a) / n;
	double otherSum = 0.0;
	double otherStep1 = 2 * step;

	double otherStep = step / 2;

	for (int i = 0; i < n; ++i) {
		sum += f(a + step * (i + otherStep));
	}
	sum *= step;
	for (int i = 0; i < n; ++i) {
		otherSum += f(a + step * (i + otherStep));
	}

	otherSum *= otherStep1;

	int index = 0;

	while (abs(sum - otherSum) < eps)
	{
		++index;
		n <<= 1;
		sum = otherSum;
		otherSum += f(a + step * (index + otherStep));
	}
	return sum;
}
void getAandB(double& a, double& b) {
	std::cout << "Enter a = ";
	std::cin >> a;
	std::cout << "Enter b = ";
	std::cin >> b;
	if (a > b)
	{
	std::swap(a, b);
	}
}
double getEps() {
	double eps = -1;
	while (eps <= 0) {
		std::cout << "Epsselont must be natural: ";
		std::cin >> eps;
	}
	return eps;
}

int main()
{
	double a = 0;
	double b = 0;
	double (*function[3])(double) = {func, func1, func2};
	for (size_t i = 0; i < 3; ++i) {
		getAandB(a, b);
		double Integral1 = mediumRectangle(function[i], a, b, getEps());
		std::cout << std::setprecision(10) << Integral1 << '\n';
		double Integral2 = InegrTrapecia(function[i], a, b, getEps());
		std::cout << std::setprecision(10) << Integral2 << '\n';
	}
	return 0;
}
