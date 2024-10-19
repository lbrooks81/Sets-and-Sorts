/*
 * Name: [Logan Brooks]
 * South Hills Username: [lbrooks81]
 */

#include <iostream>
#include "mySet.h"

using namespace mySet;

void testSet();

int main()
{
    testSet();
}

void populateSet(MySet<int>* set, int numElements)
{
    for(int i = 0; i < numElements; i++)
    {
        if(set->insert(rand() % 100) == false)
        {
            i--;
        }
    }
}

void testSet()
{
    MySet<int>* mySet = new MySet<int>();

    std::cout << "Insertion Sort" << std::endl;
    populateSet(mySet, 50);
    mySet->insertionSortVerbose();
    std::cout << "Size: " << mySet->get_size() << std::endl;


    std::cout << mySet->toString() << std::endl;
    mySet->clear();


    std::cout << "Selection Sort" << std::endl;
    populateSet(mySet, 50);
    mySet->selectionSort();

    std::cout << mySet->toString() << std::endl;
    mySet->clear();


    std::cout << "Bubble Sort" << std::endl;
    populateSet(mySet, 50);
    mySet->bubbleSort(false);

    std::cout << mySet->toString() << std::endl;
    mySet->clear();


    std::cout << "Bidirectional Bubble Sort" << std::endl;
    populateSet(mySet, 50);
    mySet->bubbleSort(true);

    std::cout << mySet->toString() << std::endl;
    mySet->clear();

    populateSet(mySet, 50);
    mySet->insertionSort();
    std::cout << mySet->toString() << std::endl;
    std::cout << "Size: " << mySet->get_size() << std::endl;



    std::cout << "Removing element at index 0" << std::endl;
    mySet->removeAt(0);
    std::cout << mySet->toString() << std::endl;

    std::cout << "Size: " << mySet->get_size() << std::endl;

    std::cout << "Median Element: " << mySet->median() << std::endl;
    std::cout << mySet->median() << std::endl;

}

