#include "Matrix.hpp"


/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

// Конструктор по умолчанию
Matrix::Matrix() : rows(0), cols(0), matrix(nullptr) 
{}

// Конструктор с параметром
Matrix::Matrix(size_t numRows, size_t numCols) : rows(numRows), cols(numCols) 
{
    matrix = new double* [rows];
    for (size_t i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) 
{
    matrix = new double* [rows];
    for (size_t i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
        for (size_t j = 0; j < cols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}
// Конструктор перемещения
Matrix::Matrix(Matrix&& other) noexcept 
{
    rows = other.rows;
    cols = other.cols;
    matrix = other.matrix;
    other.rows = 0;
    other.cols = 0;
    other.matrix = nullptr;
}


// Деструктор
Matrix::~Matrix() 
{
    if (matrix != nullptr) {
        for (size_t i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}


/* =========================================================================== */




/* =========================================================================== */
/* ============================ Геттеры ====================================== */
/* =========================================================================== */

// Получение количества столбцов
size_t Matrix::getRows() const
{
    return rows;
}

// Получение количества строк
size_t Matrix::getCols() const
{
    return cols;
}
/* =========================================================================== */




/* =========================================================================== */
/* ================================= Сеттеры ================================= */
/* =========================================================================== */

// Установка количества столбцов
void Matrix::setRows(const size_t& rows)
{
    if (rows <=0 )
    {
        throw std::invalid_argument("Amount of rows can't be zerow!\n");
    }
    this->rows = rows;
}

// Установка количества строк
void Matrix::setCols(const size_t& cols)
{
    if (cols <= 0)
    {
        throw std::invalid_argument("Amount of cols can't be zerow!\n");
    }
    this->cols = cols;
}

/* ======================================================================== */




/* =========================================================================== */
/* =================== Перегрузка дефолтного оператора присваивания ==================== */
/* =========================================================================== */

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other) {
        for (size_t i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        rows = other.rows;
        cols = other.cols;
        matrix = new double* [rows];
        for (size_t i = 0; i < rows; ++i) {
            matrix[i] = new double[cols];
            for (size_t j = 0; j < cols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    return *this;
}
/* ========================================================================= */




/* =========================================================================== */
/* ============== Перегрузки бинарных арифметических операторов ============== */
/* =========================================================================== */

// Бинарное сложение   [ дробь + дробь ]
Matrix Matrix::operator+(const Matrix& other) 
{
    
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("You can't fold a matrix of different sizes!\n");
    }
    Matrix temp(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return temp;
}

// Бинарное сложение   [ дробь - дробь ]
Matrix Matrix::operator-(const Matrix& rhs) 
{
    if (rows != rhs.rows || cols != rhs.cols) {
        throw std::invalid_argument("You can't fold a matrix of different sizes!\n");
    }
    Matrix temp(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            temp.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
        }
    }
    return temp;
}

// Бинарное сложение   [ дробь * дробь ]
Matrix Matrix::operator*(const Matrix& rhs) 
{
    if (rows != rhs.cols) {
        throw std::invalid_argument("You can't fold a matrix of this sizes!\n");
    }
    Matrix temp(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
            for (size_t k = 0; k < rhs.cols; k++)
            {
                temp.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }
    return temp;
}

// Умножение на double [matrix * double]
Matrix& Matrix::operator*(double scalar)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            matrix[i][j] *= scalar;
        }
    }
    return *this;
}

// Деление на double [matrix / double]
Matrix& Matrix::operator/(double scalar)
{
    if (scalar == 0) {
        throw std::invalid_argument("You can't device by zerow!\n");
    }
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j) 
        {
            matrix[i][j] /= scalar;
        }
    }
    return *this;
}

// Умножение с double [double * matrix]
Matrix operator*(double scalar, Matrix& rhs)
{
    for (size_t i = 0; i < rhs.rows; ++i)
    {
        for (size_t j = 0; j < rhs.cols; ++j)
        {
            rhs.matrix[i][j] *= scalar;
        }
    }
    return rhs;
}

// Деление с double [double / matrix]
Matrix operator/(double scalar, Matrix& rhs)
{
    for (size_t i = 0; i < rhs.rows; ++i)
    {
        for (size_t j = 0; j < rhs.cols; ++j)
        {
            if (rhs.matrix[i][j] == 0)
            {
                throw std::invalid_argument("You can't device by zerow!\n");
            }
            rhs.matrix[i][j] = scalar / rhs.matrix[i][j];
        }
    }
    return rhs;
}
/* ======================================================================== */




/* =========================================================================== */
/* =================== Перегрузки операторов присваивания ==================== */
/* =========================================================================== */

// Оператор присваивания сложения
Matrix& Matrix::operator+=(const Matrix& rhs)
{
    return *this = *this + rhs;
}

// Оператор присваивания вычитания
Matrix& Matrix::operator-=(const Matrix& rhs)
{
    return *this = *this - rhs;
}

// Оператор присваивания умножения
Matrix& Matrix::operator*=(const Matrix& rhs)
{
    return *this = *this * rhs;
}

// Оператор присваивания умножения на double
Matrix& Matrix::operator*=(double scalar)
{
    return *this = *this * scalar;
}

// Оператор присваивания деления на double
Matrix& Matrix::operator/=(double scalar)
{
    return *this = *this / scalar;
}

// Оператор присваивания умножения double на matrix
Matrix operator*=(double scalar, Matrix& matr)
{
    return matr = scalar * matr;
}

// Оператор присваивания деления double на matrix
Matrix operator/=(double scalar, Matrix& matr)
{
    return matr =  scalar / matr;
}
/* ======================================================================== */




/* =========================================================================== */
/* ===================   Перегрузки операторов сравнения  ==================== */
/* =========================================================================== */

// Оператор равно
bool Matrix::operator==(const Matrix& other) {
    if (rows != other.cols) {
        throw std::invalid_argument("You can't fold a matrix of this sizes!\n");
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrix[i][j] != other.matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

// Оператор не равно
bool Matrix::operator!=(const Matrix& other) {
    if (Matrix::operator==(other))
    {
        return false;
    }
    return true;
}
/* =========================================================================== */




/* =========================================================================== */
/* ===================== Перегрузки операторов вывода ======================== */
/* =========================================================================== */

// Оператор вывода (дружественный)
std::ostream& operator<<(std::ostream& os, const Matrix& mat)
{
    for (size_t i = 0; i < mat.rows; ++i) {
        for (size_t j = 0; j < mat.cols; ++j) {
            os << std::setw(10) << mat.matrix[i][j] << std::setw(10);
        }
        os << '\n';
    }
    return os;
}
/* =========================================================================== */




/* =========================================================================== */
/* ===================== Перегрузки операторов ввода ======================== */
/* =========================================================================== */

// Оператор ввода (дружественный)
std::istream& operator>>(std::istream& in, Matrix& mat)
{
    std::cout << "Please enter rows.\n";
    in >> mat.rows;
    if (!static_cast<char>(mat.rows)) {
        throw std::invalid_argument("You have entered a symbol!\n");
    }
    if (mat.rows == 0) {
        throw std::invalid_argument("Rows can't be zero\n");
    }
    std::cout << "Please enter colums.\n";
    in >> mat.cols;
    if (!static_cast<char>(mat.cols)) {
        throw std::invalid_argument("You have entered a symbol!\n");
    }
    if (mat.cols == 0) {
        throw std::invalid_argument("Rows can't be zero\n");
    }
    mat.matrix = new double* [mat.rows];
    for (size_t i = 0; i < mat.rows; i++)
    {
        mat.matrix[i] = new double [mat.cols];
    }
    for (size_t i = 0; i < mat.rows; ++i) {
        for (size_t j = 0; j < mat.cols; ++j) {
            std::cout << "Enter elements matrix" << i << " " << j << '\n';
            in >> mat.matrix[i][j];
        }
    }
    return in;
}
