#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "src/class/Tree/Tree.hpp"
class ForestTree : public Tree
{
private:
	double amountOfWood;// Количество древесины
public:
	//Конструкторы
	ForestTree();
	ForestTree(std::string, size_t, double);
	ForestTree(const ForestTree&);

	//Деструктор
	~ForestTree();

	//Геттеры
	double getAmountOfWood() const;

	//Сеттеры
	void setAmountOfWood(double);

	// Дефолтный оператор присваивания
	ForestTree& operator=(const ForestTree&);

	//Виртуальный метод вывода информации
	void print() const override;
};
#endif // FORESTTREE_HPP
