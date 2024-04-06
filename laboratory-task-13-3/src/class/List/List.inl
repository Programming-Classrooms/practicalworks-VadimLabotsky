#include "List.hpp"
/* ========================================================================== */
/* ============================== Конструктор =============================== */
/* ========================================================================== */

// Конструктор с параметром
template<typename T>
List<T>::ListItem::ListItem(T sInfo) : info(sInfo), next(nullptr)
{}
/* =========================================================================== */


/* =========================================================================== */
/* ============================ Приватные методы ============================= */
/* =========================================================================== */
// Метод удаления однонаправленного списка
template<typename T>
void List<T>::clone(const List<T>& L)
{
	ListItem* currentItemL, * currentItem, * lastItem;
	lastItem = NULL;
	currentItemL = L.first;
	while (currentItemL != NULL)
	{
		currentItem = new ListItem;
		currentItem->Info = currentItemL->Info;
		currentItem->Next = NULL;
		if (lastItem == NULL) {
			first = currentItem;
		}
		else {
			lastItem->Next = currentItem;
		}
		lastItem = currentItem;
		currentItemL = currentItemL->Next;
	}
}

// Метод копирования однонаправленного списка
template<typename T>
void List<T>::erase()
{
	ListItem* currentItem, * temp;
	currentItem = first;
	while (currentItem != NULL) {
		temp = currentItem->next;
		delete currentItem;
		currentItem = temp;
	}
	first = NULL;
}
/* ======================================================================== */


/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

// Конструктор по умолчанию
template<typename T>
List<T>::List() :first(NULL)
{
}

// Конструктор копирования
template<typename T>
List<T>::List(const List<T>& L)
{
	List<T>::clone(L);
}

// Деструктор
template<typename T>
List<T>::~List()
{
	erase();
}
/* ======================================================================== */



/* =========================================================================== */
/* =================== Перегрузка дефолтного оператора присваивания ==================== */
/* =========================================================================== */

template<typename T>
List<T>& List<T>::operator=(const List<T>& rhs)
{
	if (this != &rhs)
	{
		erase();
		clone(rhs);
	}
	return *this;
}
/* ======================================================================== */


/* ===================================================================== */
/* ============================== Методы =============================== */
/* ===================================================================== */

// Метод добавления элемента в начало списка
template<typename T>
void List<T>::insertFirst(const T& infoRhs)
{
	if (first == nullptr) {
		first = new ListItem( infoRhs);
		first->info = infoRhs;
		first->next = nullptr;
	}
	else {
	ListItem* time = new ListItem(infoRhs);
	time->info = infoRhs;
	time->next = first;
	first = time;
	}
}

// Метод удаления первого элемента
template<typename T>
bool List<T>::deleteFirst()
{
	if (first == NULL) {
		return false;
	}
	ListItem* time = first;
	first = first->next;
	delete time;
	return true;
}
// Метод добавления элемента в конец списка
template<typename T>
void List<T>::insertLast(const T& infoRhs)
{
	if (!first)
	{
		ListItem* newNode = new ListItem(infoRhs);
		newNode->info = infoRhs;
		newNode->next = nullptr;
		first = newNode;
	}
	else {
		ListItem* timeFirst = first;
		while (timeFirst->next != nullptr) {
			timeFirst = timeFirst->next;
		}
		ListItem* time = new ListItem(infoRhs);
		time->info = infoRhs;
		time->next = nullptr;
		timeFirst->next = time;
	}
}

// Метод удаления последнего элемента
template<typename T>
bool List<T>::deleteLast()
{
	if (first == nullptr)
	{
		return false;
	}
	if (first->next == nullptr)
	{
		deleteFirst();
		return true;
	}
	ListItem* timeFirst = first;
	while (timeFirst->next->next != nullptr) {
		timeFirst = timeFirst->next;
	}
	delete  timeFirst->next;
	timeFirst->next = nullptr;
	return true;
}

// Метод удаления элемента из списка по информации
template<typename T>
bool List<T>::deleteByInfo(T info)
{
	if (first == nullptr)
	{
		return false;
	}
	if (first->info == info)
	{
		deleteFirst();
		return true;
	}
	ListItem* timeFirst = first;
	while (timeFirst->next->next != nullptr)
	{
		if (timeFirst->next->info == info)
		{
			ListItem* time = timeFirst->next->next;
			delete(timeFirst->next);
			timeFirst->next = time;
			return true;
		}
		timeFirst = timeFirst->next;
	}
	if (timeFirst->next->info == info)
	{
		deleteLast();
		return true;
	}
	return false;
}

// Метод поиск элемента по значению с подсчетом числа сравнений,	выполненных в процессе поиска
template<typename T>
int List<T>::searchByInfo(T info)
{
	size_t count = 0;
	if (first == nullptr)
	{
		return -1;

	}

	ListItem* timeFirst = first;
	while (timeFirst != nullptr)
	{
		++count;
		if (timeFirst->info == info)
		{
			return count;
		}
		timeFirst = timeFirst->next;
	}
	return 0;
}

// Метод просмотра списка с изменением всех значений
template<typename T>
void List<T>::print()
{
	ListItem* current = first;
	while (current != nullptr)
	{
		std::cout << current->info;
		current = current->next;
	}
}

// Просмотр списка с вызовом callback-функции, которая не изменяет хранящееся значение
template<typename T>
void List<T>::viewWithCallBackFunction(void(*callback)(T))
{
	ListItem* timeFirst = first;
	while (timeFirst != nullptr)
	{
		callback(timeFirst->info);
		timeFirst = timeFirst->next;
	}
}
/* ======================================================================== */
