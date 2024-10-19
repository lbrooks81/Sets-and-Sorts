#ifndef IT230_PROJECT1_MYSET_H
#define IT230_PROJECT1_MYSET_H
#include <string>

namespace mySet
{
    template<typename T>
    class MySet
    {
    private:
        T* items;
        int size;

        void swap(T* item1, T* item2);
        void grow();
        void shrink();
    public:
        int count;
        int capacity;

        int get_size() const;
        T median();

        MySet();
        MySet(int capacity);
        ~MySet();

        T & operator[](size_t index);

        size_t find(T match);
        bool insert(T item);
        void remove(T item);
        void removeAt(size_t index);
        void clear();

        std::string toString();

        void bubbleSort(bool bidrectional);
        void insertionSort();
        void insertionSortVerbose();
        void selectionSort();
        void oddEven();

    };

}

#endif //IT230_PROJECT1_MYSET_H
