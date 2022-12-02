#include "Array.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
/**
 * Empty Constructor
 */
Array::Array() {
    array = new string[1];
    size = 1;
    numOfElements = 0;
}

/**
 * Function responsible for insertion into array
 * @param theWord -> the word to insert into the array
 */
void Array::insertArray(string theWord){

    //if numOfElements is equal to the size of the array, we double the size because there is not enough space
    if (numOfElements==size) {
        string* temp = new string[2 * size];
        // copy the values to the new array
        for (int i = 0; i<size; i++) {
            temp[i] = array[i];
        }

        delete[] array;  // deleting the initial array
        size *= 2; // change the value of the size to size*2
        array = temp;
    }

    array[numOfElements] = theWord; // insert the word to the array
    numOfElements++;
}

/**
 * Function responsible for deletion of an element of the array
 * @param theWord -> the word to delete from the array
 */
void Array::deleteArray(string theWord){
    int index;
    bool isFound = false;
    string temp;

    //checks into the array if the input word exists
    for (int i = 0; i <= numOfElements; i++) {
        //if the word has been found then isFound->true and
        // we store the index of the array where the word exists
        if (array[i] == theWord) {
            isFound = true;
            index = i;
        }
    }

    // if the input word is found it deletes it
    if (isFound) {
        temp = array[numOfElements];
        array[numOfElements] = array[index];
        array[index] = temp;
        numOfElements--;
    }
    else
    {
        cout << "The word doesn't exist! Please try another..." << endl;
    }

}

/**
 * Function responsible for searching an element of the array
 * @param theWord -> the word to search into the array
 */
void Array::theSearch(string theWord){
    //checks into the array if the input word exists
    for (int i = 0; i <= numOfElements; i++) {
        //if the word has been found then isFound->true and
        // we store the index of the array where the word exists
        if (array[i] == theWord) {
            break;
        }
    }

}

