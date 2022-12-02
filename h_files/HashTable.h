#ifndef DATASTRUCTURES2021_HASHTABLE_H
#define DATASTRUCTURES2021_HASHTABLE_H
#include<iostream>
#include <string>
#include "Slot.h"
#include<algorithm>
#include<fstream>
#include <cstring>

using namespace std;

/**
 * [*] empty() -> Returns if the given cell of the HashMap is empty or not
 * Functions: Insert, Search
 */
class HashTable {
public:

    HashTable(int i);
    ~HashTable();

    void insertHashTable(string theWord), searchHashTable(string theWord); //Init
    bool empty(int i); //In order to check if is empty

    unsigned long int hashingFunction(string theWord);
    int wordCounter(){
        return count;
    }

private:
    int count, theSize;
    Slot **Map;

};


#endif //DATASTRUCTURES2021_HASHTABLE_H
