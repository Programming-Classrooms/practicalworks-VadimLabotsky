#include "FruitTree.hpp"

/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */



// Конструктор с параметром
FruitTree::FruitTree(std::string timeName, size_t timeAge,Tipe timeTipe, double timeCropWeight, size_t timeAverageStorageTime):
	Tree(timeName, timeAge, timeTipe), cropWeight(timeCropWeight), averageStorageTime(timeAverageStorageTime)
{
}
// Конструктор копирования
FruitTree::FruitTree(const FruitTree& rhs, double timeCropWeight, size_t timeAverageStorageTime): Tree(rhs), cropWeight(timeCropWeight), averageStorageTime(timeAverageStorageTime)
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



/* =============================================== */
/* =================== Методы ==================== */
/* =============================================== */
void FruitTree::print() const
{
	std::cout << "Fruit tree" << '\t'<< name << '\t' << age << '\t' << "Coniferous" << '\t' << cropWeight << '\t' << averageStorageTime << '\n';
}
/* ======================================================================== */
