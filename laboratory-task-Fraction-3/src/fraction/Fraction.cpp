#include"Fraction.hpp"


/* =========================================================================== */
/* ============================ Приватные методы ============================= */
/* =========================================================================== */

// НОД числителя и знаменателя (приватный метод)
std::uint64_t Fraction::greatestCommonDivisor(int64_t a, int64_t b)
{
    a = std::abs(a);
    b = std::abs(b);
    if (a % b == 0) {
        return b;
    }
    if (b % a == 0){
        return a;
    }
    if (a > b) {
        return greatestCommonDivisor(a % b, b);
    }
    return greatestCommonDivisor(a, b % a);

}

// Сокращение дроби (приватный метод)
void Fraction::reduce()
{
    std::uint64_t divisor = greatestCommonDivisor(this->n, this->d);
    if (divisor != 1) {
        this->n /= divisor;
        this->d /= divisor;
    }
}

/* =========================================================================== */
/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

// Конструктор с параметром


Fraction::Fraction(const int64_t& numeratorVal, const int64_t& denominatorVal):
    n(numeratorVal),
    d(denominatorVal)
{
    if (denominatorVal == 0) {
        throw std::invalid_argument("You can't device by zerow!\n");
    }
    reduce();
}

// Конструктор копирования
Fraction::Fraction(const Fraction& rhs):
    n(rhs.n),
    d(rhs.d)
{}

// Конструктор перемещения
Fraction::Fraction(Fraction&& rhs) noexcept:
    n(rhs.n),
    d(rhs.d)
{
  rhs.n = 0;
  rhs.d = 1;
}

// Деструктор
Fraction::~Fraction()
{}


/* =========================================================================== */




/* =========================================================================== */
/* ============================ Геттеры ====================================== */
/* =========================================================================== */

// Получение числителя
int64_t Fraction::getN() const
{
    return n;
}

// Получение знаменателя
int64_t Fraction::getD() const
{
    return d;
}

/* =========================================================================== */




/* =========================================================================== */
/* ================================= Сеттеры ================================= */
/* =========================================================================== */

// Установка числителя
void Fraction::setN(const int64_t& n)
{
    this->n = n;
}

// Установка знаменателя
void Fraction::setD(const int64_t& d)
{
    if (d == 0) {
        throw std::invalid_argument("You can't device by zerow!\n");
    }
    this->d = d;
}

/* ======================================================================== */




/* =========================================================================== */
/* =================== Перегрузка дефолтного оператора присваивания ==================== */
/* =========================================================================== */

Fraction& Fraction::operator=(const Fraction& rhs)
{
    if (this != &rhs) {
        this->n = rhs.n;
        this->d = rhs.d;
    }
    return *this;
}

/* ======================================================================== */




/* =========================================================================== */
/* ============== Перегрузка унарных арифметических операторов =============== */
/* =========================================================================== */

// Префиксное инкрементирование [ дробь + 1 ]
Fraction& Fraction::operator++()
{
    n += d;
    if (Fraction::greatestCommonDivisor(n, d) != 1) {
        this->reduce();
    }
    return *this;
}

// Постфиксное инкрементирование [ дробь + 1 ]
Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    n += d;
    if (Fraction::greatestCommonDivisor(n, d) != 1) {
        temp.reduce();
    }
    return temp;
}
// Префиксное декрементирование [ дробь - 1 ]
Fraction& Fraction::operator--()
{
    n -= d;
    if (Fraction::greatestCommonDivisor(n, d) != 1) {
        this->reduce();
    }
    return *this;
}

// Постфиксное декрементирование [ дробь - 1 ]
Fraction Fraction::operator--(int)
{
    Fraction temp = *this;
    n -= d;
    if (Fraction::greatestCommonDivisor(n, d) != 1) {
        temp.reduce();
    }
    return temp;
}

// Нахождение дроби обратной
Fraction Fraction::operator!() const
{
    if (this->d == 0 && this->n == 0) {
        throw std::invalid_argument("You can't get fraction, because you have numerator by zerow!\n");
    }
    return Fraction(d, n);
}
/* =========================================================================== */




/* =========================================================================== */
/* =================== Перегрузка оператора преобразования ================== */
/* =========================================================================== */

// Преобразование к double
Fraction::operator double() const
{
    return (static_cast<double>(this->n) / this->d);
}

/* ========================================================================= */




/* =========================================================================== */
/* ============== Перегрузки бинарных арифметических операторов ============== */
/* =========================================================================== */

// Бинарное сложение   [ дробь + дробь ]
Fraction Fraction::operator+(const Fraction& rhs)
{
    Fraction time(n * rhs.d + d * rhs.n, d * rhs.d);
    time.reduce();
    return time;
}
// Бинарное вычитание   [ дробь - дробь ]
Fraction Fraction::operator-(const Fraction& rhs)
{
    Fraction time(n * rhs.d - d * rhs.n, d * rhs.d);
    time.reduce();
    return time;
}

// Бинарное умножение   [ дробь * дробь ]
Fraction Fraction::operator*(const Fraction& rhs)
{
    Fraction time(n * rhs.n, d * rhs.d);
    time.reduce();
    return time;
}

// Бинарное умножение   [ дробь / дробь ]
Fraction Fraction::operator/(const Fraction& rhs)
{
    if (rhs.n == 0) {
        throw std::invalid_argument("Numerator doesn't be zerow!\n");
    }
    Fraction time(n * rhs.d, d * rhs.n);
    time.reduce();
    return time;
}

// Сложение с int [ дробь + литерал ]
Fraction Fraction::operator+(const int& num)
{
    n += num * d;
    this->reduce();
    return *this;
}

// Вычитание с int [ дробь - литерал ]
Fraction Fraction::operator-(const int& num)
{
    n = n - num * d;
    this->reduce();
    return *this;
}

// Умножение на int [ дробь * литерал ]
Fraction Fraction::operator*(const int& num) 
{
    n = n * num;
    this->reduce();
    return *this;
}

// Деление на int [ дробь / литерал ]
Fraction Fraction::operator/(const int& num) 
{
    if (num == 0) {
        throw std::invalid_argument("Num doesn't be zerow!\n");
    }
    d *= num ;
    this->reduce();
    return *this;
}

// Сложение с int64_t  [ дробь + целое число ]
Fraction Fraction::operator+(const int64_t& num)
{
    n += num * d;
    this->reduce();
    return *this;
}

// Вычитание с int64_t  [ дробь - целое число ]
Fraction Fraction::operator-(const int64_t& num)
{
    n -= num * d;
    this->reduce();
    return *this;
}

// Умножение с int64_t  [ дробь - целое число ]
Fraction Fraction::operator*(const int64_t& num)
{
    n *= num;
    this->reduce();
    return *this;
}

// Деление с int64_t  [ дробь - целое число ]
Fraction Fraction::operator/(const int64_t& num)
{
    if (num == 0) {
        throw std::invalid_argument("Num doesn't be zerow!\n");
    }
    d *= num;
    this->reduce();
    return *this;
}

// Сложение int64_t с дробью  [ целое число + дробь ]
Fraction operator+(const int64_t& lhs, const Fraction &rhs)
{
    return (Fraction(lhs) + rhs);
}

// Вычитание int64_t с дробью  [ целое число - дробь ]
Fraction operator-(const int64_t& lhs, const Fraction& rhs)
{
    return Fraction(lhs) - rhs;
}
// Умножение int64_t с дробью  [ целое число * дробь ]
Fraction operator*(const int64_t& lhs, const Fraction& rhs)
{
    return Fraction(lhs) * rhs;
}

// Деление int64_t с дробью  [ целое число / дробь ]
Fraction operator/(const int64_t& lhs, const Fraction& rhs)
{
    if (rhs.d == 0) {
        throw std::invalid_argument("You can't device by nume, because you have denaminator by zerow!!\n");
    }
    
    return Fraction(lhs) / rhs;
}

// Сложение int с дробью  [ целое число + дробь ]
Fraction operator+(const int&  lhs, const Fraction& rhs)
{
    return (Fraction(lhs) + rhs);
}

// Вычитание int с дробью  [ целое число - дробь ]
Fraction operator-(const int& lhs, const Fraction& rhs)
{
    return Fraction(lhs) - rhs;
}

// Умножение int с дробью  [ целое число * дробь ]
Fraction operator*(const int& lhs, const Fraction& rhs)
{
    return Fraction(lhs) * rhs;
}

// Деление int с дробью  [ целое число / дробь ]
Fraction operator/(const int& lhs, const Fraction& rhs)
{
    return Fraction(lhs) / rhs;
}
/* ======================================================================== */




/* =========================================================================== */
/* =================== Перегрузки операторов присваивания ==================== */
/* =========================================================================== */

// Оператор присваивания сложения
Fraction& Fraction::operator+=(const Fraction& rhs)
{
    this->n = this->n * rhs.d + rhs.n * this->d;
    this->d *= rhs.n;
    this->reduce();
    return *this ;
}

// Оператор присваивания вычитания
Fraction& Fraction::operator-=(const Fraction& rhs)
{
    this->n = this->n * rhs.d - rhs.n * this->d;
    this->d *= rhs.n;
    this->reduce();
    return *this;
}

// Оператор присваивания умножения
Fraction& Fraction::operator*=(const Fraction& rhs)
{
    this->n *=  rhs.n;
    this->d *= rhs.d;
    this->reduce();
    return *this;
}

// Оператор присваивания деления
Fraction& Fraction::operator/=(const Fraction& rhs)
{
    if (rhs.n == 0) {
        throw std::invalid_argument("You can't device by zerow!\n");
    }
    this->n *= rhs.d;
    this->d *= rhs.n;
    this->reduce();
    return *this;
}

/* =========================================================================== */




/* =========================================================================== */
/* ===================== Перегрузки операторов вывода ======================== */
/* =========================================================================== */

// Оператор вывода (дружественный)
std::ostream& operator<<(std::ostream& out, const Fraction& rhs)
{
    if (rhs.d == 1 ) {
        out << rhs.n << '\n';
        return out;
    }
    if (rhs.n == 0) {
        out << 0;
        return out;
    }
    if (rhs.n < 0 && rhs.d < 0) {
        out << -rhs.n << " / " << -rhs.d << '\n';
        return out;
    }
    if (rhs.d < 0 ) {
        out << -rhs.n << " / " << -rhs.d << '\n';
        return out;
    }
    out << rhs.n << " / " << rhs.d << '\n';
    return out;
}
/* =========================================================================== */




/* =========================================================================== */
/* ===================== Перегрузки операторов ввода ======================== */
/* =========================================================================== */

// Оператор ввода (дружественный)
std::istream& operator>>(std::istream& in, Fraction& rhs)
{
    int64_t timeN = 0;
    int64_t timeD = 0;
    std::cout << "Please enter numerator!\n";
    in >> timeN;
    if (!static_cast<char>(timeN)) {
        throw std::invalid_argument("You have entered a symbol!\n");
    }
    rhs.setN(timeN);
    std::cout << "Please enter denominator!\n";
    in >> timeD; 
    if (!static_cast<char>(timeD)) {
        throw std::invalid_argument("You have entered a symbol!\n");
    }
    if (timeD ==0) {
        throw std::invalid_argument("You can't divide by zero\n");
    }
    rhs.setD(timeD);
    if (rhs.d < 0)
    {
        rhs.d = -rhs.d; 
        rhs.n = -rhs.n;
    }
    return in;
}
/* =========================================================================== */
