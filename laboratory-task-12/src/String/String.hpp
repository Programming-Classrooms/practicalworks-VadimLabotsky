#ifndef STRING_HPP
#define STRING_HPP
#include <iostream>
#include <cstring>
#include <string>
class String
{
private:
	size_t size;
	char* str;

	void enterStr(std::istream&);// Ввод строки
	void printStr(std::ostream&);// Вывод строки
public:
	//Конструкторы
	String();
	String(std::string);
	String(size_t);
	String(const String&);

	//Деструктор
	~String();

	//Геттеры
	char* fillString() const ;
	size_t getSise() const;

	//Сеттеры
	void setSize(size_t);
	
	//Перегрузка оператора присваивания
	String& operator=(String);

	// Перегрузки бинарных арифметических операторов
	String operator+(const String&);
	String operator+(const char*);

	//Перегрузка оператора присваивания
	String& operator+=(String);
	String& operator+=(const char*);

	//Перегрузка оператора равно, не равно
	bool operator==(String);
	bool operator!=(String);

	// Метод копирования
	String copy(size_t, size_t);

	//Дружественный оператор ввода
	friend std::istream& operator >> (std::istream& out, String& point);

	//Дружественный оператор вывода
	friend std::ostream& operator<< (std::ostream& out, String& point);
};
#endif //STRING_HPP