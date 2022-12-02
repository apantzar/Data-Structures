#include "HashTable.h"
#include<fstream>
#include<iostream>
#include<algorithm>
#include <cstring>
#include <string>
#include "Slot.h"

using namespace std;


HashTable::HashTable(int i) {
    Map = new Slot *[2*i]; //New array (with pointers) using slot (This will have the x2 the size of the uniqueWords)

    for(int k = 0; k < 2*i; k++){
        Map[k] = NULL; //Init all to null
    }

    theSize = 2*i;
    count = 0;
}


/**
 * !!!Warning!!!
 * Oh this will destroy the universe :/ (all elements & the map)
 */
HashTable::~HashTable() {
    for(int i = 0; i < theSize; i++){
        delete Map[i];
    }
    delete[] Map;
}


/**
 * This will use the djb2 hash function in order to 'find' (with maths) the
 * key for map for each word.
 * @param theWord
 * @return
 */

unsigned long int HashTable::hashingFunction(string theWord) {
    unsigned long hash = 5381;
    unsigned int wordLength = theWord.length();

    for(int i = 0; i < wordLength; i++){
        hash = ((hash << 5) + hash) + (theWord[i]);
    }

    return (hash % theSize);
}





/**
 * [*] key -> The key for the word that will be inserted
 * [*] start -> The first key
 *
 *
 * Loop until the word is found :
 *
 *          -> This function will access all the slots (NOT necessary)!
 *
 * @param theWord -> given word
 */

void HashTable::searchHashTable(string theWord) {
    unsigned long int first;
    unsigned long int key;
    bool isFound = false;

    key = hashingFunction(theWord); //assign the key of the specific word
    first = key;

    do
    {

        //Checking if the not-null slot contains the word
        if(Map[key] != NULL){

            if (Map[key]->getTheword() == theWord)   {
                isFound = true; //isFound status changed :: Word Found
            }
            else{
                key = (key + 1) % this->theSize; //changes key
            }
        }
        else{
            key = (key + 1) % this->theSize;
        }
    }
    while ( isFound == false && first != key );

}



/**
 * i= key
 * start= first key
 * @param theWord -> Given word
 */

void HashTable::insertHashTable(string theWord) {

    unsigned long int i,  first;

    bool isFound = false; //init

    /**
     * Calculating the key of the given word
     */
    i = hashingFunction(theWord);
    first = i;

    do
    {
        if (Map[i] == NULL)
        {
            //Oh, this is empty (I will use it)
            Map[i] = new Slot(theWord);
            isFound = true; //found status true
        }
        else if (Map[i]->getTheword() == theWord)
        {
            //If the word has already found (duplicates ++)
            Map[i]->setTheduplicates( Map[i]-> getTheduplicates() + 1 );
            break;
        }
        else
        {
            //This slot is not empty (next..)
            i = (i + 1) % this->theSize;
        }
    }
        //Condition to keep going
    while ( isFound == false && first != i);

    count++;
}



/**
 *
 *
 * Checks with the given key of slot
 * if the slot is empty or not.
 *
 * @param i -> given element
 *
 *
 * @return :
 *    [*] True -> is empty
 *    [*] False -> Not empty
 */




bool HashTable::empty(int i)
{
    if (Map[i] != NULL)
    {
        cout<<Map[i]->getTheword()<<" "<<Map[i]->getTheduplicates()<<endl;
        return false;
    }
    return true;

}

