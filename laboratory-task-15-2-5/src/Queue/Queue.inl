#include "Queue.hpp"


template<typename T>
TQueue<T>::TQueue()
{}

template<typename T>
TQueue<T>::TQueue(const TQueue& rhs): elements(rhs.elements)
{}

template<typename T>
TQueue<T>::~TQueue()
{
	elements.clear();
}

template<typename T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& rhs)
{
	if (this != &rhs)
	{
		elements = rhs.elements;
	}
	return *this;
}

template<typename T>
auto TQueue<T>::operator[](int index)
{
	if (index < 0 || index >= elements.size()) {
        throw std::out_of_range("Index out of range");
    }
	auto time = elements.begin();
	std::advance(time, index);
	return time;
}

template<typename T>
void TQueue<T>::pushBack(const T& info)
{
	elements.push_back(info);
}

template<typename T>
void TQueue<T>::erase(const T& info)
{
	if (elements.empty()) {
        throw std::out_of_range("Queue is empty");
    }
	elements.pop_front();
}

template<typename T>
void TQueue<T>::print(std::ostream& out) const
{
	for (const auto& element:elements)
	{
		out << element << '\t';
	}
	out << '\n';
}

template<typename T>
auto TQueue<T>::get(size_t find)
{
	return operator[](find);
}

template<typename T>
int TQueue<T>::find(const T& element) const
{
	size_t index = 0;
	for (const auto& time:elements)
	{
		if (time == element)
		{
			return index;
		}
		++index;
	}
	return -1;
}
