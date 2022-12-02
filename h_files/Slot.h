
/**
 * This Class is complementary for
 * HashTable.cpp
 *
 */



#ifndef DATASTRUCTURES2021_SLOT_H
#define DATASTRUCTURES2021_SLOT_H

#include<iostream>
#include<algorithm>
#include<fstream>
#include <cstring>
#include <string>


using namespace std;



class Slot
{
public:
    //Constructor
    Slot(string word);


    /**
     * Basic function to delete word or
     * duplicates!
     */
    void wordDelete() {theWord.clear();}
    void DuplicatesDelete() {theDuplicates =0;}


    /**
     * Setters
     * @param value -> the value to set/Duplicates
     */
    void setTheword(string value) { theWord = value; }
    void setTheduplicates(int value) { theDuplicates = value; }


    /**
     * Getters to get theWord, Duplicates
     * @return return
     */
    string getTheword() { return theWord; }
    int getTheduplicates() { return theDuplicates; }


private:
    int theDuplicates;
    string theWord;

};


#endif //DATASTRUCTURES2021_SLOT_H


