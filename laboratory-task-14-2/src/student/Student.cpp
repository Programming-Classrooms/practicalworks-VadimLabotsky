#include "Student.h"
size_t Student::count = 0;

/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

// Конструктор с параметром
Student::Student(const std::string & name, size_t course, size_t group, size_t recordBookNumber):name(name), id(++count),
course(course), group(group), recordBookNumber(recordBookNumber)
{
}

// Конструктор копирования
Student::Student(const Student& other):name(other.name), id(++count), course(other.course), group(other.group), 
recordBookNumber(other.recordBookNumber)
{
}

// Деструктор
Student::~Student()
{}
/* =========================================================================== */




/* =========================================================================== */
/* ============================ Геттеры ====================================== */
/* =========================================================================== */

// Поучения id
size_t Student::getId() const
{
	return this->id;
}

//Получения имени
const std::string& Student::getName() const
{
	return this->name;
}

//Получения курса
size_t Student::getCourse() const
{
	return this->course;
}

//Получения группы
size_t Student::getGroup() const
{
	return this->group;
}

//Получения номера записной книжки
size_t Student::getRecordBookNumber() const
{
	return this->recordBookNumber;
}

/* =========================================================================== */




/* =========================================================================== */
/* ================================= Сеттеры ================================= */
/* =========================================================================== */

// Установка курса
void Student::setCourse(size_t timeCourse)
{
	this->course = timeCourse;
}
// Установка группы
void Student::setGroup(size_t timeGroup)
{
	this->group = timeGroup;
}

/* =========================================================================== */




/* =========================================================================== */
/* ===================== Перегрузки операторов вывода ======================== */
/* =========================================================================== */

// Оператор вывода (дружественный)
std::ostream& operator<<(std::ostream& out, const Student& rhs)
{
	out << rhs.name << '\t' << rhs.id << '\t' << rhs.course << '\t' << rhs.group << '\t' << rhs.recordBookNumber << '\n';
	return out;
}
/* =========================================================================== */
