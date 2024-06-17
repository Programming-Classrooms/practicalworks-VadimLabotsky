#include "src/class/StudentAfterSecondSession/StudentAfterSecondSession.hpp"

/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

// Конструктор с параметром
StudentAfterSecondSession::StudentAfterSecondSession(const std::string& name, size_t course, size_t group,
    size_t recordBookNumber, const size_t grade[], const size_t allGrades[] ):StudentAfterFirstSession(name, course, group, recordBookNumber,
	grade)
{
	for (size_t i = 0; i < 5; i++)
	{
		this->allGrades[i] = allGrades[i];
	}
}

// Конструктор копирования
StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession& rhs):
    StudentAfterFirstSession(rhs), allGrades{ 
	rhs.allGrades[0],rhs.allGrades[1], rhs.allGrades[2], rhs.allGrades[3], rhs.allGrades[4] }
{
}
//Деструктор
StudentAfterSecondSession::~StudentAfterSecondSession()
{
  
}
/* =========================================================================== */




/* =========================================================================== */
/* ============================ Геттер  ====================================== */
/* =========================================================================== */

// Получение массива из 5 оценок за 2 семестр
const size_t* StudentAfterSecondSession::getSecondGrades() const
{
    return allGrades;
}
/* =========================================================================== */




/* =========================================================================== */
/* =================================  Сеттер ================================= */
/* =========================================================================== */

// Установка массива из 5 оценок за 2 семестр
void StudentAfterSecondSession::setSecondGrades(const size_t newAllGrades[]) 
{
    for (size_t i = 0; i < 5; ++i) {
        allGrades[i] = newAllGrades[i];
    }
}


/* =========================================================================== */




/* =========================================================================== */
/* =================================  Метод  ================================= */
/* =========================================================================== */

// Высчитывания среднего балла за 2 семестр
double StudentAfterSecondSession::calculateAverageGrade() const {
    double sum = 0.0;
    for (size_t i = 0; i < 4; ++i) {
        sum += grades[i];
    }
    for (size_t i = 0; i < 5; ++i) {
        sum += allGrades[i];
    }
    return sum / 9;
}

/* =========================================================================== */




/* =========================================================================== */
/* ===================== Перегрузки операторов вывода ======================== */
/* =========================================================================== */

// Оператор вывода (дружественный)
std::ostream& operator<<(std::ostream& out, const StudentAfterSecondSession& rhs)
{
    out << rhs.name << '\t' << rhs.id << '\t' << rhs.course << '\t' << rhs.group << '\t' << rhs.recordBookNumber ;
    for (size_t i = 0; i < 5; i++)
    {
        out << rhs.allGrades[i] << '\t';
    }
    out << '\n';
    return out;
}
/* =========================================================================== */