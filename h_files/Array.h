#ifndef ARRAY_H
#define ARRAY_H
#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
class Array{

    public:
        Array();
        void insertArray(string theWord);
        void deleteArray(string theWord);
        void theSearch(string theWord);

    private:

        string* array;
        int size, numOfElements;


};

#endif // ARRAY_H
