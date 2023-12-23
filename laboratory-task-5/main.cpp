/*
    Задание 5. Подпрограммы

    Вычислить значение определенного интеграла с аналитически заданной подынтегральной функцией с заданной точностью    
    eps
    А) по формуле левых прямоугольников;
    Б) по формуле правых прямоугольников;
    В) по формуле средних прямоугольников;
    Г) по формуле трапеций;
    Д) по формуле Симпсона (параболических трапеций).
    Формула средних прямоугольников:
    ∫f(x)dx ≈ h*[f(x 1 )+ f(x 2 )+…+ f(x n )], где h=(b-leftborder)/n, f(x i )=leftborder+i*h-h/2,leftborder
    где n–число точек деления отрезка [leftborder, b]. Для вычисления первого приближения можно взять
    n=4. Чтобы оценить точность, с которой вычислено значение интеграла, необходимо найти второе
    приближение. Для этого можно увеличить n в два раза. Если s 1 и s 2 – два соседних приближения и |s 1
    – s 2 |<eps, то точность считается достигнутой и s 2 принимается за искомое значение интеграла. В
    противном случае надо положить s 1 = s 2 и удвоить число точек деления отрезка [leftborder, b]. После этого
    вычисляется новое значение s 2 . Процесс удвоения n и вычисления s 2 надо продолжать до тех пор,
    пока модуль разности s 1 и s 2 не станет меньше eps. Остальные формулы посмотреть самим.
    Разработать функции, реализующие методы вычислений интеграла, входными параметрами
    которых должны быть функция для вычисления значения подынтегрального выражения, пределы
    интегрирования и точность вычислений. Головная программа должна вывести результат вычислений
    для записанных в задании интегралов по заданным формулам и значение n, при котором достигнута
    заданная точность. Для проверки вычислений в таблице приведены значения интегралов.
    Номер задания равен вашему индивидуальному номеру.
    Вариант № 5
*/


#include <iostream> 
#include <cmath> 
#include <functional> 
#include <iomanip> 


double func1(double x)
{
  return (1 / ((x + 1) * sqrt(x * x + 1)));
}

double func2(double x)
{
  return sqrt(pow(2, x) - 1);
}

double func3(double x)
{
  return tan(x);
}

double InegrTrapecia(const double& leftborder, const double& rightborder, double& eps, double (*f)(double))
{
  double n = 4.0; 
  double sum = 0.0;
  double step = (rightborder - leftborder) / n;
  double otherSum = 0.0;
  double otherStep1 = 2 * step;
  double otherStep = step / 2; 
  sum = f(leftborder) + f(rightborder);
  for (size_t i = 1; i <= n - 1; ++i) {
    sum += 2 * f(leftborder + i * step);
  }
  sum *= step / 2;
  otherSum = f(leftborder) + f(rightborder);
  otherStep = 2 * step;
  for (size_t i = 1; i <= n - 1; ++i) {
    otherSum += 2 * f(leftborder + i * otherStep);
  }
  otherSum *= otherStep / 2;
  int32_t index = 0;
  while (abs(sum - otherSum) < eps) {
    ++index;
    sum = otherSum;
    otherSum = otherSum += 2 * f(leftborder + index * otherStep);
  }
  std::cout << "Method of Trapeze Rectangles = ";
  return sum;
}

double mediumRectangle(const double& leftborder, const double& rightborder, double& eps, double (*f)(double)) 
{
  double n = 4.0;
  double sum = 0.0;
  double step = (rightborder - leftborder) / n;
  double otherSum = 0.0;
  double otherStep1 = 2 * step;
  double otherStep = step / 2;
  for (size_t i = 0; i < n; ++i) {
    sum += f(leftborder + step * (i + otherStep));
  }
  sum *= step;
  for (size_t i = 0; i < n; ++i) {
    otherSum += f(leftborder + step * (i + otherStep));
  }
  otherSum *= otherStep1;
  int32_t index = 0;
  while (abs(sum - otherSum) < eps) {
    ++index;
    sum = otherSum;
    otherSum += f(leftborder + step * (index + otherStep));
  }
  std::cout << "Method of Middle Rectangles =  ";
  return sum;
}

void getAndCheckBorders(double& leftborder, double& rightborder) 
{
  std::cout << "Please enter leftborder!\n";
  std::cin >> leftborder;
  std::cout << "Please enter rightborder!\n";
  std::cin >> rightborder;
  if (leftborder > rightborder) {
  std::swap(leftborder, rightborder);
  }
}

double getEps()
{
  double eps = -1;
  while (eps <= 0) {
    std::cout << "Please enter epsselont. Epsselont must be natural.\n";
    std::cin >> eps;
  }
  return eps;
}

int main()
{
  double n = 4.0;
  double leftborder = 0;
  double rightborder = 0;
  double (*function[3])(double) = {func1, func2, func3};
  double eps = getEps();
  for (size_t i = 0; i < 3; ++i) {
    getAndCheckBorders(leftborder, rightborder);
    double Integral1 = mediumRectangle(leftborder, rightborder,  eps, function[i]);
    std::cout << std::setprecision(10) << Integral1 << '\n';
    double Integral2 = InegrTrapecia(leftborder, rightborder, eps, function[i]);
    std::cout << std::setprecision(10) << Integral2 << '\n';
  }
  return 0;
}
