#ifndef ARRAYTREE_H
#define ARRAYTREE_H
#include "src/class/Tree/Tree.hpp"
#include "src/class/ForestTree/ForestTree.hpp"
#include "src/class/FruitTree/FruitTree.hpp"
#include <vector>
#include <algorithm>
class ArrayTree final: public Tree
{
private:
	std::vector<Tree*> forest;
public:
	//Деструкторы
	~ArrayTree() = default;

	//Методы
	void addTree(Tree*);
	size_t countTreeType(Tipe);
	void sortArrayByName();
	void sortArrayByAge();
	void print() const override;

	//Дружественный оператор ввода
	friend std::istream& operator>>(std::istream& in, ArrayTree& rhs);
};

#endif // ARRAYTREE_H


