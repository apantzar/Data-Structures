#include "Slot.h"
#include <cstring>
#include <string>
#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

Slot::Slot(string theWord)
{

    /**
     * The basic init of words
     *   -> Constructor
     */
    this->theWord=theWord;
    theDuplicates = 1; //increase the duplicates

}
