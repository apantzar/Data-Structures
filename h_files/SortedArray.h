#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include<string>
#include<algorithm>
#include <cstdlib>
#pragma once
#include<iostream>
#include<fstream>
#include "Array.h"

using namespace std;


class SortedArray
{


public:
    SortedArray();
    void insertSortedArray(string& A, int p, int r);
    int searchInSortedArray(string theWord);
    void deleteInSortedArray(string theWord);
    int partition(string& A, int p, int r);
    void swap(char& a, char& b);


private:
    string* theArray;
    int theSize, numOfElements;

};



#endif // SORTEDARRAY_H
