#ifndef PERSON_HPP
#define PERSON_HPP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <exception>

class Person
{
protected:
	char* fullName;// ФИО
public:
	//Конструкторы
	Person(const char* = nullptr);
	Person(const Person&);

	//Деструктор
	virtual ~Person();

	//Геттер
	char* getFullName() const;

	//Сеттер
	void setFullName(char*);

	// Виртуальный метод вывода информации
	virtual void print(std::ostream&) const;
};
#endif//PERSON_HPP

