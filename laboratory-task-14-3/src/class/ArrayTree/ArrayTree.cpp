#include "ArrayTree.hpp"

/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

// Конструктор по умолчанию
ArrayTree::ArrayTree() : forest(0)
{}

// Конструктор копирования
ArrayTree::ArrayTree(const ArrayTree& rhs)
{
	forest = rhs.forest;
}
/* ======================================================================== */



/* =============================================== */
/* =================== Методы ==================== */
/* =============================================== */
// Метод добавления элемента
void ArrayTree::addTree(Tree* init)
{
	forest.push_back(init);
}

// Сортировка массива по имени
void ArrayTree::sortArrayByName()
{
	std::sort(forest.begin(), forest.end(), ruleForSortName);
}

//Сортировка по возрасту
void ArrayTree::sortArrayByAge()
{
	std::sort(forest.begin(), forest.end(), ruleForSortByAge);
}
// Метод вывода информации
void ArrayTree::print()
{
	for (size_t i = 0; i < forest.size(); ++i)
	{
		forest[i]->print();
	}
}

// Компаратор по имени
bool ArrayTree::ruleForSortName(Tree* lhs, Tree* rhs)
{
	return lhs->getName() < rhs->getName();
}

// Компаратор по возрасту
bool ArrayTree::ruleForSortByAge(Tree* lhs, Tree* rhs)
{
	return lhs->getAge() > rhs->getAge();
}
/* ======================================================================== */
