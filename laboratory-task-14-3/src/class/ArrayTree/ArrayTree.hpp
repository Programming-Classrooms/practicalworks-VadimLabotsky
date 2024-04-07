#ifndef ARRAYTREE_H
#define ARRAYTREE_H
#include "src/class/Tree/Tree.hpp"
#include "src/class/ForestTree/ForestTree.hpp"
#include "src/class/FruitTree/FruitTree.hpp"
#include <vector>
#include <algorithm>
class ArrayTree
{
private:
	std::vector<Tree*> forest;
	static bool ruleForSortName(Tree*, Tree*);
	static bool ruleForSortByAge(Tree*, Tree*);
public:
	//Конструкторы
	ArrayTree();
	ArrayTree(const ArrayTree&);

	//Деструкторы
	~ArrayTree() = default;

	//Методы
	void addTree(Tree*);
	void sortArrayByName();
	void sortArrayByAge();
	void print();
};

#endif // ARRAYTREE_H


