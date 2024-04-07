#include "FruitTree.hpp"

/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

// Конструктор по умолчанию
FruitTree::FruitTree() :Tree("No name", 0, Tipe::Coniferous), cropWeight(0.0), averageStorageTime(0)
{}

// Конструктор с параметром
FruitTree::FruitTree(std::string timeName, size_t timeAge, double timeCropWeight, size_t timeAverageStorageTime):
	Tree(timeName, timeAge, Tipe::Coniferous), cropWeight(timeCropWeight), averageStorageTime(timeAverageStorageTime)
{
}

// Конструктор копирования
FruitTree::FruitTree(const FruitTree& rhs): Tree(rhs), cropWeight(rhs.cropWeight), averageStorageTime(rhs.averageStorageTime)
{
}

//Деструктор
FruitTree::~FruitTree()
{
}
/* =========================================================================== */



/* =========================================================================== */
/* ============================ Геттеры ====================================== */
/* =========================================================================== */

// Получение массы урожая
double FruitTree::getCropWeight() const
{
	return cropWeight;
}

// Получение средней продолжительности хранения
size_t FruitTree::getAverageStorageTime() const
{
	return averageStorageTime;
}
/* =========================================================================== */



/* =========================================================================== */
/* ================================= Сеттеры ================================= */
/* =========================================================================== */

// Установка массы урожая
void FruitTree::setCropWeight(double timeCropWeight)
{
	this->cropWeight = timeCropWeight;
}

// Установка средней продолжительности хранения
void FruitTree::setAverageStorageTime(size_t timeAverageStorageTime)
{
	this->averageStorageTime = timeAverageStorageTime;
}
/* ======================================================================== */



/* =========================================================================== */
/* =================== Перегрузка дефолтного оператора присваивания ==================== */
/* =========================================================================== */
FruitTree& FruitTree::operator=(const FruitTree& rhs)
{
	Tree::operator=(rhs);
	if (this != &rhs)
	{
		this->cropWeight = rhs.cropWeight;
		this->averageStorageTime = rhs.averageStorageTime;
	}
	return *this;
}
/* ======================================================================== */



/* =============================================== */
/* =================== Методы ==================== */
/* =============================================== */
void FruitTree::print() const
{
	std::cout << name << '\t' << age << '\t' << "Coniferous" << '\t' << cropWeight << '\t' << averageStorageTime << '\n';
}
/* ======================================================================== */
