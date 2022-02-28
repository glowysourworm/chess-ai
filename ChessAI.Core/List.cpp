#include "List.h"

template<typename T>
List<T>::List<T>(int capacity)
{
	if (capacity <= 0)
		throw std::exception("Capacity of list must be greater than zero");

	_list = new T[capacity];
	_capacity = capacity;
	_tail = -1;
}

template<typename T>
List<T>::List<T>(T* array, int arrayLength)
{
	_list = new T[arrayLength];
	_capacity = arrayLength;
	_tail = -1;

	for (int index = 0; index < arrayLength; index++)
		Add(array[index]);
}

template<typename T>
List<T>::~List<T>()
{
	delete[] _list;

	_capacity = 0;
	_tail = -1;
}

template<typename T>
T List<T>::Get(int index)
{
	if (index < 0 || index > _tail)
		throw std::exception("Index falls outside the bounds of the assigned list elements");

	return _list[index];
}

template<typename T>
void List<T>::Add(T element)
{
	if ((_tail + 1) >= _capacity)
		throw std::exception("Capacity of list exceeded");

	_list[++_tail] = element;
}

template<typename T>
void List<T>::Insert(int index, T element)
{
	if (_capacity == 0)
		Add(element);

	if ((_tail + 1) >= _capacity)
		throw std::exception("Capacity of list exceeded");

	// INSERT BEFORE
	if (index < 0 || index > _tail)
		throw std::exception("Index falls outside the bounds of the array");

	// Iterate the elements and move them back by one
	for (int i = _tail; i >= index; i--)
		_list[i + 1] = _list[i];

	_list[index] = element;
	_tail++;
}

template<typename T>
T List<T>::RemoveAt(int index)
{
	if (index < 0 || index > _tail)
		throw std::exception("Index falls outside the bounds of the array");

	T removedElement = _list[index];

	// Iterate the elements and move them back by one
	for (int i = index; i < _tail; i++)
		_list[i] = _list[i + 1];

	// Null out the element that was at the tail
	_list[_tail] = nullptr;
	_tail--;

	return removedElement;
}

template<typename T>
int List<T>::Count()
{
	return _tail + 1;
}