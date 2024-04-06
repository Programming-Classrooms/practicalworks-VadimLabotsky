#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class List
{
private:
	struct ListItem
	{
		T info;//  Информация
		ListItem* next;// Указатель на следующий элемент
		// Конструкторы
		ListItem(T);// Конструктор со значением
	};
	ListItem* first;// Указатель на первый элемент

	void erase();// Метод удаления однонаправленного списка
	void clone(const List<T>&);// Метод копирования однонаправленного списка
public:
	
	// Конструкторы
	List<T>();// Конструктор по умолчанию
	List<T>(const List&);// Конструктор копирования
	// Деструктор
	~List();

	// Дефолтный оператор присваивания
	List<T>& operator=(const List<T>&);

	//Метод
	void insertFirst(const T&);// Метод добавления элемента в начало списка
	bool deleteFirst();// Метод удаления первого элемента
	void insertLast(const T&);// Метод добавления элемента в конец списка
	bool deleteLast();// Метод удаления последнего элемента
	bool deleteByInfo(T);// Метод удаления элемента из списка по информации
	int searchByInfo(T);// Метод поиск элемента по значению с подсчетом числа сравнений,	выполненных в процессе поиска
	void print();// Метод просмотра списка с изменением всех значений
	void viewWithCallBackFunction(void (*callback) (T));// Просмотр списка с вызовом callback-функции, которая не изменяет хранящееся значение

};

#include "List.inl"

#endif //LIST_HPP
