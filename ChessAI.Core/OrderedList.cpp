#include "OrderedList.h"

template <typename T>
OrderedList<T>::OrderedList()
{
    _list = new List<T>(0);
    _comparer = OrderedList::DefaultComparer;
}

template <typename T>
OrderedList<T>::OrderedList(int capacity, std::function<int(T, T)> comparer)
{
    _list = new List<T>(capacity);
    _comparer = comparer;
}

template<typename T>
OrderedList<T>::~OrderedList()
{
    delete _list;
}

template <typename T>
int OrderedList<T>::Count()
{
    return _list->Count();
}

template <typename T>
void OrderedList<T>::Add(T item)
{
    int index = GetInsertIndex(item);

    _list->Insert(index, item);
}

template <typename T>
bool OrderedList<T>::Contains(T item)
{
    return this->GetInsertIndex(item) != this->UnsuccessfulSearch;
}

template <typename T>
void OrderedList<T>::Remove(T item)
{
    int index = this->GetInsertIndex(item);

    if (index == this->UnsuccessfulSearch)
        throw std::exception("Item not found in collection OrderedList::Remove");

    _list->RemoveAt(index);
}

template <typename T>
T OrderedList<T>::Get(int index)
{
    return _list->Get(index);
}

template <typename T>
int OrderedList<T>::BinarySearch(T searchItem, int& insertIndex)
{
    /*
        function binary_search(A, n, T) is
            L := 0
            R := n − 1
            while L ≤ R do
                m := floor((L + R) / 2)
                if A[m] < T then
                    L := m + 1
                else if A[m] > T then
                    R := m − 1
                else:
                    return m
            return unsuccessful
     */

    int leftIndex = 0;
    int rightIndex = _list->Count() - 1;

    // Initialize insert index to be the left index
    insertIndex = leftIndex;

    while (leftIndex <= rightIndex)
    {
        int middleIndex = (int)floor((leftIndex + rightIndex) / 2.0);
        T item = _list->Get(middleIndex);

        // SET INSERT INDEX
        insertIndex = middleIndex;

        // Item's value is LESS THAN search value
        if (_comparer(item, searchItem) < 0)
            leftIndex = middleIndex + 1;

        // GREATER THAN
        else if (_comparer(item, searchItem) > 0)
            rightIndex = middleIndex - 1;

        else
            return middleIndex;
    }

    return this->UnsuccessfulSearch;
}

template <typename T>
int OrderedList<T>::GetInsertIndex(T item)
{
    int insertIndex = this->UnsuccessfulSearch;
    int searchIndex = this->BinarySearch(item, &insertIndex);

    // NOT FOUND
    if (searchIndex == this->UnsuccessfulSearch)
    {
        return insertIndex;
    }
    else
    {
        return searchIndex;
    }
}