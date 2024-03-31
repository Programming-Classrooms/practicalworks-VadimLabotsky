#ifndef FRACTION_HPP
#define FRACTION_HPP

#include<iostream>
#include <cmath>
#include <cstdint>

class Fraction
{
  private:
  int64_t n; // Числитель
  int64_t d; //Знаменатель

  std::uint64_t greatestCommonDivisor(int64_t,int64_t); // НОД числителя и знаменателя
  void reduce();// Сокращение дроби

  public:
  //Конструкторы
  Fraction(const int64_t& = 0, const int64_t& = 1);
  Fraction(const Fraction&);
  Fraction(Fraction&&) noexcept;

  //Деструктор
  ~Fraction();

  //Геттеры
  int64_t  getN() const;
  int64_t  getD() const;

  //Сеттеры
  void setN(const int64_t&);
  void setD(const int64_t&);

  // Дефолтный оператор присваивания
  Fraction& operator=(const Fraction&);

  // Перегрузкa операротора преобразования типа
  explicit operator double() const;

  // Перегрузки унарных арифметических операторов
  Fraction& operator++();
  Fraction operator++(int);
  Fraction& operator--();
  Fraction operator--(int);

  // Перегрузки бинарных арифметических операторов
  Fraction operator+(const Fraction&);
  Fraction operator-(const Fraction&);
  Fraction operator*(const Fraction&);
  Fraction operator/(const Fraction&);

  Fraction operator+(const int& );
  Fraction operator-(const int&);
  Fraction operator*(const int&);
  Fraction operator/(const int&);

  Fraction operator+(const int64_t&);
  Fraction operator-(const int64_t&);
  Fraction operator*(const int64_t&);
  Fraction operator/(const int64_t&);

  friend Fraction operator+(const int&, const Fraction&);
  friend Fraction operator-(const int&, const Fraction&);
  friend Fraction operator*(const int&, const Fraction&);
  friend Fraction operator/(const int&, const Fraction&);

  friend Fraction operator+(const int64_t&, const Fraction&);
  friend Fraction operator-(const int64_t&, const Fraction&);
  friend Fraction operator*(const int64_t&, const Fraction&);
  friend Fraction operator/(const int64_t&, const Fraction&);

  //Перегрузка оператора присваивания
  Fraction& operator+=(const Fraction&);
  Fraction& operator-=(const Fraction&);  
  Fraction& operator*=(const Fraction&);
  Fraction& operator/=(const Fraction&);

  //Перегрузка оператора отрицания
  Fraction operator!() const;
  
  //Дружественный оператор вывода
  friend std::ostream& operator<< (std::ostream&, const Fraction&);

  //Дружественный оператор ввода
  friend std::istream& operator>> (std::istream&, Fraction&);

};

#endif //FRACTION_H