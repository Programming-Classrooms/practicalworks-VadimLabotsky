#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP
#include "src/class/Tree/Tree.hpp"
class FruitTree: public Tree
{
private:
	double cropWeight;// Массе урожая
	size_t averageStorageTime;//Средней продолжительности хранения
public:
	//Конструкторы
	FruitTree();
	FruitTree(std::string, size_t, double, size_t);
	FruitTree(const FruitTree&);

	//Деструктор
	~FruitTree();

	//Геттеры
	double getCropWeight() const;
	size_t getAverageStorageTime() const;

	//Сеттеры
	void setCropWeight(double);
	void setAverageStorageTime(size_t);

	// Дефолтный оператор присваивания
	FruitTree& operator=(const FruitTree&);

	//Виртуальный метод вывода информации
	void print() const override;

};
#endif // !FRUITTREE_HPP


