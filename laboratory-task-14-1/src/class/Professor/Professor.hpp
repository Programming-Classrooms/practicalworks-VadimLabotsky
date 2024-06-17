#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#define _CRT_SECURE_NO_WARNINGS
#include "src/class/Person/Person.hpp"
class Professor: public Person
{
private:
	char* department;// Кафедра
public:
	//Конструкторы
	Professor(const char*, const char*);
	Professor(const Professor&);
	//Деструктор
	virtual ~Professor() override;

	//Геттеры
	char* getDepartment();

	//Сеттеры
	void setDepartment(const char*);

	// Виртуальный метод вывода информации
	virtual void print(std::ostream&) const override;

};


#endif//PROFESSOR_HPP

