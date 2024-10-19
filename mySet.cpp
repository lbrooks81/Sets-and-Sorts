#include "mySet.h"

#include <iostream>
#include <stdexcept>

namespace mySet
{
    static const size_t npos = -1;

    template<typename T>
    int MySet<T>::get_size() const
    {
        if(size % 2 == 0)
        {
            return (size / 2 + (size / 2) + 1) / 2;
        }

        return (size + 1) / 2;
    }

    template<typename T>
    T MySet<T>::median()
    {
        return items[size / 2];
    }

    template<typename T>
    MySet<T>::MySet()
    {
        size = 0;
        capacity = 4;
        items = new T[capacity];
        count = 0;
    }

    template<typename T>
    MySet<T>::MySet(int capacity) : capacity(capacity)
    {
        items = new T[capacity];
        size = capacity;
        count = 0;
    }

    template<typename T>
    MySet<T>::~MySet()
    {
        delete[] items;
    }

    template<typename T>
    T & MySet<T>::operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("index is out of range");
        }
        return items[index];
    }

    template<typename T>
    void MySet<T>::grow()
    {
        T* tempArray = new T[capacity == 0 ? 1 : capacity * 2];

        for(int i = 0; i < capacity; i++)
        {
            tempArray[i] = items[i];
        }

        capacity = capacity == 0 ? 1 : capacity * 2;
        delete [] items;
        items = tempArray;
    }

    template<typename T>
    void MySet<T>::shrink()
    {
        T* tempArray = new T[capacity / 2];
        {
            for(int i = 0; i < size; i++)
            {
                tempArray[i] = items[i];
            }

            capacity /= 2;
            items = tempArray;
            delete [] tempArray;
        }
    }

    template<typename T>
    size_t MySet<T>::find(T match)
    {
        int left = 0;
        int right = capacity - 1;

        while(right >= left)
        {
            int mid = left + (right - left) / 2;

            if(items[mid] == match)
            {
                return mid;
            }
            if(items[mid] > match)
            {
                right = mid - 1;
            }
            else if(items[mid] < match)
            {
                left = mid + 1;
            }
        }
        return npos;
    }

    template<typename T>
    bool MySet<T>::insert(const T item)
    {
        if(capacity == 0)
        {
            items = new T[1];
            capacity++;
        }

        for(int i = 0; i < size; i++)
        {
            if(items[i] == item)
            {
                return false;
            }
        }

        if(find(item) == npos)
        {
            if(size + 1 >= capacity)
            {
                grow();
            }

            items[size] = item;
            size++;
        }
        return true;
    }

    template<typename T>
    void MySet<T>::remove(T item)
    {
        size_t index = find(item);
        if(index != npos)
        {
            removeAt(index);
        }
    }

    template<typename T>
    void MySet<T>::removeAt(const size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range.");
        }

        for(size_t i = index; i < capacity; i++)
        {
            items[i] = items[i + 1];
        }

        if(--size < capacity / 4)
        {
            shrink();
        }
    }

    template<typename T>
    void MySet<T>::clear()
    {
        size = 0;
        delete [] items;
        items = new T[capacity];
    }

    template<typename T>
    std::string MySet<T>::toString()
    {
        std::string s;

        for(int i = 0; i < size; i++)
        {
            s += std::to_string(items[i]) + ", ";
        }

        return s.substr(0, s.size() - 2);
    }

    template<typename T>
    void MySet<T>::swap(T* item1, T* item2)
    {
        T temp = *item1;
        *item1 = *item2;
        *item2 = temp;
    }

    template<typename T>
    void MySet<T>::bubbleSort(bool bidirectional)
    {
        bool sorted = false;
        size_t unsortedUntilIndex = size - 1;

        while(sorted == false)
        {
            sorted = true;

            for(int i = 0; i < unsortedUntilIndex; i++)
            {
                if(items[i] > items[i + 1])
                {
                    swap(&items[i], &items[i + 1]);
                    sorted = false;
                }
            }

            if(bidirectional)
            {
                for(size_t i = unsortedUntilIndex; i > 0; i--)
                {
                    if(items[i] < items[i - 1])
                    {
                        swap(&items[i], &items[i - 1]);
                        sorted = false;
                    }
                }
            }
            unsortedUntilIndex--;
        }
    }

    template<typename T>
    void MySet<T>::insertionSort()
    {
        for(int i = 1; i < size; i++)
        {
            T temp = items[i];
            int j = i - 1;
            for(; j >= 0 && items[j] > temp; j--)
            {
                items[j + 1] = items[j];
            }
            items[j + 1] = temp;
        }
    }

    template<typename T>
    void MySet<T>::insertionSortVerbose()
    {
        int copyCount = 0;
        int comparisonCount = 0;

        for(int i = 1; i < size; i++)
        {
            T temp = items[i];
            copyCount++;
            int j = i - 1;
            for(; j >= 0 && items[j] > temp; j--)
            {
                comparisonCount++;
                items[j + 1] = items[j];
            }
            items[j + 1] = temp;
        }

        std::cout << "Set sorted. Total copies made: " << copyCount << ". Total comparisons made: " << comparisonCount << std::endl;
    }

    template<typename T>
    void MySet<T>::selectionSort()
    {
        for(int i = 0; i < size - 1; i++)
        {
            int minIndex = i;
            for(int j = i + 1; j < size; j++)
            {
                if (items[j] < items[minIndex])
                {
                    minIndex = j;
                }
            }

            if(minIndex != i)
            {
                swap(&items[i], &items[minIndex]);
            }

        }
    }

    template<typename T>
    void MySet<T>::oddEven()
    {
        bool sorted = false;

        while(sorted == false)
        {
            sorted = true;

            for(int i = 1; i < size; i += 2)
            {
                if(items[i] > items[i + 1])
                {
                    swap(&items[i], &items[i + 1]);
                    sorted = false;
                }
            }

            for(int i = 0; i < size; i += 2)
            {
                if(items[i] > items[i + 1])
                {
                    swap(&items[i], &items[i + 1]);
                    sorted = false;
                }
            }
        }
    }

    template class MySet<int>;

}

