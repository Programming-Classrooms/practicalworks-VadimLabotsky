#include "src/class/Tree/Tree.hpp"
#include "src/class/ForestTree/ForestTree.hpp"
#include "src/class/FruitTree/FruitTree.hpp"
#include "src/class/ArrayTree/ArrayTree.hpp"
int main()
{
	ForestTree* tree1 = new ForestTree;
	ForestTree* tree2 = new ForestTree("dub", 147, 7.8);
	tree1->print();
	tree2->print();
	FruitTree* tree3 = new FruitTree;
	FruitTree* tree4 = new FruitTree("Dub", 1, 7.8, 78);
	tree3->print();
	tree4->print();
	ArrayTree forest;
	forest.addTree(tree2);
	forest.addTree(tree1);
	forest.addTree(tree3);
	forest.addTree(tree4);
	forest.print();
	return 0;
}
