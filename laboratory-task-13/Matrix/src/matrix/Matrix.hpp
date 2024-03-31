#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>

class Matrix 
{
private:
    double** matrix; // Указатель на первый элемент
    size_t rows;// Количество столбцов
    size_t cols;// Количество строк

public:
    //Конструкторы
    Matrix();
    Matrix(size_t numRows, size_t numCols);
    Matrix(const Matrix& other);
    Matrix(Matrix&&) noexcept;

    //Деструкторы
    ~Matrix();

    //Геттеры
    size_t  getRows() const;
    size_t  getCols() const;

    //Сеттеры
    void setRows(const size_t&);
    void setCols(const size_t&);

    // Дефолтный оператор присваивания
    Matrix& operator=(const Matrix& );

    // Перегрузки бинарных арифметических операторов
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix& operator*(double);

    Matrix& operator/(double scalar);

    friend Matrix operator*(double, Matrix&);
    friend Matrix operator/(double, Matrix&);

    //Перегрузка оператора присваивания
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(double);
    Matrix& operator/=(double scalar);
    friend Matrix operator*=(double, Matrix&);
    friend Matrix operator/=(double, Matrix&);

    //Перегрузка оператора равно, не равно
    bool operator==(const Matrix&);
    bool operator!=(const Matrix&);

    //Дружественный оператор вывода
    friend std::ostream& operator<<(std::ostream&, const Matrix&);

    //Дружественный оператор ввода
    friend std::istream& operator>>(std::istream&, Matrix& mat);
};

#endif //MATRIX_H
