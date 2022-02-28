#include "HashTable.h"

template <typename T>
HashTable<T>::HashTable<T>()
{
	_table = new List<T>[0]{};
	_capacity = 0;
	_itemTotal = 0;
};

template <typename T>
HashTable<T>::HashTable<T>(int capacity, std::function<unsigned long(T)> keySelector)
{
	// Initialize as a table with capacity enough for worst cast scenario
	_table = new List<T>[capacity];
	_capacity = capacity;
	_itemTotal = 0;

	// PREVENT HASHING COLLISIONS:  Set capacity of list to 1!
	for (int index = 0; index < capacity; index++)
		_table[index] = new List<T>(1);
}

template <typename T>
HashTable<T>::~HashTable<T>()
{
	// Delete hash table items
	for (int tableIndex = 0; tableIndex < _capacity; tableIndex++)
	{
		for (int listIndex = 0; listIndex < _table[tableIndex]->Count(); listIndex++)
			delete _table[tableIndex]->Get(tableIndex);
	}

	delete[] _table;
}

template <typename T>
void HashTable<T>::Add(T value)
{
	if (_capacity == 0)
		throw std::exception("Must initialize hash table with capacity greater than zero");

	// Use delegate to calculate the hash key
	unsigned long key = _keySelector(value);

	int index = this->GetIndex(key);

	if (index < 0 || index >= _capacity)
		throw std::exception("Index outside the capacity of the hash table");

	if (_table[index]->Count() > 0)
		throw std::exception("HASH COLLISION DETECTED:  HashTable.cpp");

	_table[index]->Add(value);

	_itemTotal++;
}

template <typename T>
T HashTable<T>::Remove(unsigned long key)
{
	if (_capacity == 0)
		throw std::exception("Must initialize hash table with capacity greater than zero");

	int index = this->GetIndex(key);

	if (index < 0 || index >= _capacity)
		throw std::exception("Index outside the capacity of the hash table");

	T item;
	bool found = false;

	for (int listIndex = 0; listIndex < _table[index]->Count(); listIndex++)
	{
		// Call key selector to calculate hash key for the item
		if (_keySelector(_table[index]->Get(listIndex)) == key)
		{
			// Fetch the item to return 
			item = _table[index]->Get(listIndex);

			// Flag as found
			found = true;

			// REMOVE ITEM
			_table[index].Remove(listIndex);

			_itemTotal--;

			break;
		}
	}

	if (!found)
		throw std::exception("Unfound hash entry HashTable<T>::Remove");

	return item;
}

template <typename T>
T HashTable<T>::Get(unsigned long key)
{
	if (_capacity == 0)
		throw std::exception("Must initialize hash table with capacity greater than zero");

	int index = this->GetIndex(key);

	if (index < 0 || index >= _capacity)
		throw std::exception("Index outside the capacity of the hash table");

	T item;
	bool found = false;

	for (int listIndex = 0; listIndex < _table[index]->Count(); listIndex++)
	{
		// Call key selector to calculate hash key for the item
		if (_keySelector(_table[index]->Get(listIndex)) == key)
		{
			// Fetch the item to return
			item = _table[index]->Get(listIndex);

			// Flag as found
			found = true;

			break;
		}
	}

	if (!found)
		throw std::exception("Unfound hash entry HashTable<T>::Remove");

	return item;
}

template <typename T>
bool HashTable<T>::Contains(T item)
{
	if (_capacity == 0)
		throw std::exception("Must initialize hash table with capacity greater than zero");

	// Calculate hash key
	unsigned long _keySelector(item);

	// Call hashing function
	int index = this->GetIndex(key);

	if (index < 0 || index >= _capacity)
		throw std::exception("Index outside the capacity of the hash table");

	// Check list for the hash bucket
	for (int listIndex = 0; listIndex < _table[index]->Count(); listIndex++)
	{
		// Call key selector to calculate hash key for the item
		if (_keySelector(_table[index]->Get(listIndex)) == key)
			return true;
	}

	return false;
}

template <typename T>
bool HashTable<T>::ContainsKey(unsigned long key)
{
	if (_capacity == 0)
		throw std::exception("Must initialize hash table with capacity greater than zero");

	// Call hashing function
	int index = this->GetIndex(key);

	if (index < 0 || index >= _capacity)
		throw std::exception("Index outside the capacity of the hash table");

	if (_table[index]->Count() == 0)
		return false;

	else
		return true;
}

template <typename T>
List<T> HashTable<T>::GetItems()
{
	List<T> result = List<T>(_itemTotal);

	for (int index = 0; index < _capacity; index++)
	{
		for (int listIndex = 0; listIndex < _table[index]->Count(); listIndex++)
			result.Add(_table[index]->Get(listIndex));
	}

	return result;
}

template <typename T>
int HashTable<T>::GetIndex(unsigned long hashCodeKey)
{
	return hashCodeKey % _capacity;
}