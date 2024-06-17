#ifndef STUDENT_HPP
#define STUDENT_HPP
#define _CRT_SECURE_NO_WARNINGS
#include "src/class/Person/Person.hpp"
class Student : public Person
{
private:
	size_t course;// Курс
	size_t group;//Группа
public:
	//Конструкторы
	Student(const char*, size_t, size_t);
	Student(const Student&);

	//Деструктор
	~Student();

	//Геттеры
	size_t getCourse() const;
	size_t getGroup() const;

	//Сеттеры
	void setCourse(size_t);
	void setGroup(size_t);

	// Виртуальный метод вывода информации
	virtual void print(std::ostream&) const override;

};


#endif//STUDENT_HPP

