#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "src/class/Tree/Tree.hpp"
class ForestTree : public Tree
{
private:
	double amountOfWood;// Количество древесины
public:
	//Конструкторы
	ForestTree(std::string, size_t, Tipe, double);
	ForestTree(const ForestTree&, double);
	ForestTree(const ForestTree&);

	//Деструктор
	~ForestTree();

	//Геттеры
	double getAmountOfWood() const;

	//Сеттеры
	void setAmountOfWood(double);


	//Виртуальный метод вывода информации
	void print() const override;

	friend std::istream& operator>>(std::istream&, ForestTree&);
};
#endif // FORESTTREE_HPP
