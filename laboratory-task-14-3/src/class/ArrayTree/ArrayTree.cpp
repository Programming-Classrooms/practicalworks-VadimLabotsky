#include "ArrayTree.hpp"




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
	std::sort(forest.begin(), forest.end(), [](Tree* a, Tree* b){return a->getName() < b->getName();});
}

//Сортировка по возрасту
void ArrayTree::sortArrayByAge()
{
	std::sort(forest.begin(), forest.end(), [](Tree* a, Tree* b){return a->getAge() < b->getAge();});
}
// Метод вывода информации
void ArrayTree::print() const
{
	for (size_t i = 0; i < forest.size(); ++i)
    {
        forest[i]->print();
        std::cout << '\t';
    }
    
}

size_t ArrayTree::countTreeType(Tipe type)
{
	size_t count = 0;
	for (size_t i = 0; i < forest.size(); ++i)
	{
		if (forest[i] != nullptr && forest[i]->getTypeTree() == type)
		{
			++count;
		}
		
	}
	return count;
}
/* =========================================================================== */




/* =========================================================================== */
/* ===================== Перегрузки операторов ввода ======================== */
/* =========================================================================== */

// Оператор ввода (дружественный)
std::istream& operator>>(std::istream& in, ArrayTree& rhs)
{
    std::string type ,treeType, fruit("Deciduous"), forest("Coniferous"), treeName;
    size_t treeAge = 0, storageDuration = 0;
    double woodAmount = 0.0, cropMass = 0.0;
    Tree* initTree = nullptr;

    while (in >> type) {
        if (type == fruit || type == forest) {
            in >> treeName;
            in >> treeAge;
            in >> treeType;
            if (treeType == "Forest") {
                in >> woodAmount;
                initTree = new ForestTree(treeName, treeAge, (type == fruit ? Tipe::Deciduous : Tipe::Coniferous), woodAmount);
                rhs.addTree(initTree);
            }

            else if (treeType == "Fruit") {
                in >> cropMass;
                in >> storageDuration;
                initTree = new FruitTree(treeName, treeAge, (type == fruit ? Tipe::Deciduous : Tipe::Coniferous), cropMass, storageDuration);
                rhs.addTree(initTree);
            }

            else {
                throw std::runtime_error("Wrong tree Type name!");
            }
        }
        
        else {
            throw std::runtime_error("Can't find right Types of trees");
        }
    }

    return in;
}

/* =========================================================================== */
