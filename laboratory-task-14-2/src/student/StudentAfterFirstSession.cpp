#include "StudentAfterFirstSession.hpp"

/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

// Конструктор с параметром
StudentAfterFirstSession::StudentAfterFirstSession(const std::string& name, size_t course,
    size_t group, size_t recordBookNumber, const size_t grade[]): Student(name, course, group, recordBookNumber)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->grades[i] = grade[i];
	}
}

// Конструктор копирования
StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& rhs):
    Student(rhs), grades{rhs.grades[0], rhs.grades[1], rhs.grades[2], rhs.grades[3]}
{
}
//Деструктор
StudentAfterFirstSession::~StudentAfterFirstSession()
{
}
/* =========================================================================== */




/* =========================================================================== */
/* ============================ Геттер  ====================================== */
/* =========================================================================== */

// Получение массива из 4 оценок за 1 семестр
const size_t* StudentAfterFirstSession::getGrades() const 
{
    return grades;
}
/* =========================================================================== */




/* =========================================================================== */
/* =================================  Сеттер ================================= */
/* =========================================================================== */

// Установка массива из 4 оценок за 1 семестр
void StudentAfterFirstSession::setGrades(const size_t newGrades[]) 
{
    for (size_t i = 0; i < 4; ++i) {
        grades[i] = newGrades[i];
    }
}

/* =========================================================================== */




/* =========================================================================== */
/* =================================  Метод  ================================= */
/* =========================================================================== */

// Высчитывания среднего балла за 1 семестр
double StudentAfterFirstSession::calculateAverageGrade() const {
    double sum = 0.0;
    for (size_t i = 0; i < 4; ++i) {
        sum += grades[i];
    }
    return sum / 4;
}

/* =========================================================================== */




/* =========================================================================== */
/* ===================== Перегрузки операторов вывода ======================== */
/* =========================================================================== */

// Оператор вывода (дружественный)
std::ostream& operator<<(std::ostream& out, const StudentAfterFirstSession& rhs)
{
    out << rhs.name << '\t' << rhs.id << '\t' << rhs.course << '\t' << rhs.group << '\t' << rhs.recordBookNumber;
    for (size_t i = 0; i < 4; i++)
    {
        out << rhs.grades[i] << '\t';
    }
    out << '\n';
    return out;
}
/* =========================================================================== */