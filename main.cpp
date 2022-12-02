#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "HashTable.h"
#include "HashTable.h"
#include "Array.h"
#include "SortedArray.h"

using namespace std;
using namespace std::chrono;


/**
 *[*] The 'lowerCase' has to convert all the words (from file) to lower.
 * (In order to test=TEST=TesT etc.)
 *
 * @param wordToLower -> the word that will be lowercase
 */
void lowerCase(string &wordToLower){

    for(int i=0; i<wordToLower.length();i++){
        wordToLower[i] = tolower(wordToLower[i]);
    }

}

/**
 * ========changeTheSizeNow========
 * [*] The 'changeTheSizeNow' has to allocate new memory size
 * for the input array!
 *
 * [*] allocation size::3000
 *
 * returns -> mediator
 *
 *
 * (Parameters by reference)
 */
string* changeTheSizeNow(string* &array, int &size) {
    string *mediator;
    mediator = new string[size + 2500];

    for (int i = 0; i < size; i++) {
        mediator[i] = array[i];
    }
    delete[] array;
    size += 2500;
    return mediator;
}





/**
 * [*] The 'stripTheSymbols' has to strip the symbols from the input.
 * @param theWord -> init word & the striped word (without symbols)
 * @return -> the striped word (without symbols)
 */
string stripTheSymbols(string theWord){
    char symbols[]=" ()~`%^&*-_+=<>.'!@#$:\\\",/|{}[]:;? ";

    for(unsigned int i=0; i<strlen(symbols); i++){

        theWord.erase(std::remove(theWord.begin(), theWord.end(), symbols[i]), theWord.end());


    }

    return theWord;

}



int main()
{

    /**
     * [*] uniqueWords, totalWords, wordsForSearch: These variables are for dynamic array creation (pointers)
     * [*] fName: file's name (file.txt)
     * [*] theWordVariable: stores the words from file (1 word each time)
     * [*] totalCap : capacity of totalWords
     *     uniqueCap: capacity of uniqueWords
     * [*] fileIn: To 'insert' file
     * [*] fileOut: To 'print' into file
     */
    int iCounter=0,jCounter=0, q=0;
    string *uniqueWords,*totalWords,*wordsForSearch;
    string fName="file.txt", theWordVariable;
    int totalCap = 5000, uniqueCap = 5000;
    ifstream fileIn;
    ofstream fileOut;
    uniqueWords = new string [totalCap];
    totalWords = new string [uniqueCap];




    ////////////////////////////////Creation of structures/////////////////////////////////
    Array arr;
    SortedArray sortArr;
    BinaryTree *rootOfBinary = NULL;
    AVLTree *rootOfAVL = NULL;
    HashTable *hashTable = NULL;


    try{
        fileIn.open(fName.c_str()); //opens txt
    }catch(exception & e){
        cout<<"File 'file.txt' not found";
        return 0;
    }


    cout<<"+------------------------------------------------------+"<<endl;
    cout<<"|     [*] Loading the uniqueWords, Please wait...      |"<<endl;
    cout<<"+------------------------------------------------------+"<<endl<<endl;

    //The insertion of structures begins..
    while (fileIn >> theWordVariable)
    {
        theWordVariable = stripTheSymbols(theWordVariable); //strips the symbols
        lowerCase(theWordVariable); //convert word to lower case
        if ( !SearchElement(rootOfBinary, theWordVariable) )
        {
            if (iCounter >= totalCap)
            {
                uniqueWords = changeTheSizeNow(uniqueWords, totalCap);   //size will change if the iCounter is greater than the capacity of total words array
            }
            uniqueWords[iCounter]=theWordVariable;
            iCounter++;
        }
        if (jCounter >= uniqueCap)
        {
            totalWords = changeTheSizeNow(totalWords, uniqueCap);        //size will change if the jCounter is greater than the capacity of unique words array
        }
        totalWords[jCounter]=theWordVariable;
        jCounter++;
        //Inserting the words to the structures :)
        rootOfBinary = InsertElement(rootOfBinary, theWordVariable);
        rootOfAVL = searchInAVL(rootOfAVL, theWordVariable);
        arr.insertArray(theWordVariable);
        int n = theWordVariable.size(); //size of theWordVariable
        sortArr.insertSortedArray(theWordVariable, 0, n); //sortArr.insert(word, start, end)




    }

    fileIn.close();// closes the file


    //Inserting the words to the hashtable
    hashTable = new HashTable(iCounter );
    for (int i=0; i < jCounter ; i++)
    {
        hashTable->insertHashTable(totalWords[i]);
    }



    /**
     * Inserting the words (randomly) into the 'wordsForSearch'.
     *
     * This is useful for the search function
     */


    wordsForSearch = new string [iCounter];

    srand (time(NULL)); //for random numbers

    for(int i=0; i < iCounter; i++)
    {
        if (rand() %8 == 1)// in order to select the ~13% of the unique words (
        {
            //cout<<"I am in the rand"<<endl;
            wordsForSearch[q] = uniqueWords[i];
            q++;
        }
    }

    // cout<<"The iCounter is-> "<<iCounter<<endl;



    //To open the output.txt

    fileOut.open("output.txt");



    cout<<"Searching into the below structures has been started! [OK]"<<endl<<endl;
    cout<<"====================================="<<endl;




/**
 * ======================= [HOW IT WORKS] =======================
 * [*] For each structure calculates the total time (end time - start time)
 * [*] For each structure starts the searching process
 * [*] Stores all the results to a generated .txt file (output.txt)
 * [*] Results include:
 *          -> Total time for each structure
 *          -> Number of times that the unique word exists in file
 *
 *
 * (Preferred structure Binary Tree)
 */


    //--------------------------------------------Structure:Array--------------------------------------------

    cout<<"\t[*] Array"<<endl;
    auto arrayClockStart = high_resolution_clock::now();

    for (int i=0; i < q ; i++)
    {
        arr.theSearch(wordsForSearch[i]);
    }

    auto arrayClockStop = high_resolution_clock::now();
    auto arrayTotalTime = duration_cast<nanoseconds>(arrayClockStop - arrayClockStart);






    //--------------------------------------------Structure: Sorted Array--------------------------------------------
    cout<<"\t[*] Sorted Array"<<endl;
    auto sortedArrayClockStart = high_resolution_clock::now();



    for (int i=0; i < q ; i++)
    {
        sortArr.searchInSortedArray(wordsForSearch[i]);
    }

    auto sortedArrayClockStop = high_resolution_clock::now();
    auto sortedArrayTotalTime = duration_cast<nanoseconds>(sortedArrayClockStop - sortedArrayClockStart);


    cout<<"\t[*] Binary Search Tree"<<endl;




    //--------------------------------------------Structure: Binary Tree --------------------------------------------



    auto binaryClockStart = high_resolution_clock::now();

    for (int i=0; i < q ; i++)
    {
        SearchElement(rootOfBinary, wordsForSearch[i]);
    }

    auto binaryClockStop = high_resolution_clock::now();
    auto totalBinaryTime = duration_cast<nanoseconds>(binaryClockStop - binaryClockStart);


    cout<<"\t[*] AVL Tree"<<endl;







    //--------------------------------------------Structure:AVL--------------------------------------------
    auto avlClockStart = high_resolution_clock::now();

    for (int i=0; i < q ; i++)
    {
        searchInAVL(rootOfAVL, wordsForSearch[i]);
    }

    auto avlClockStop = high_resolution_clock::now();
    auto avlTotalTime = duration_cast<nanoseconds>(avlClockStop - avlClockStart);


    cout<<"\t[*] HashTable"<<endl;







    //--------------------------------------------Structure:HashTable--------------------------------------------
    auto hashClockStart = high_resolution_clock::now();

    for (int i=0; i <= q; i++)
    {
        hashTable->insertHashTable(wordsForSearch[i]);
    }

    auto hashClockStop = high_resolution_clock::now();
    auto hashTotalTime = duration_cast<nanoseconds>(hashClockStop - hashClockStart);



    cout<<"====================================="<<endl; //For ui :)


    fileOut <<"   _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._\n"
             " ,'_.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._`.\n"
             "( (                   AEM | ΟΝΟΜΑΤΕΠΩΝΥΜΟ                     \n"
             " ) )                 ----------------------                   \n"
             "( (                  3471 |  'Αννα Τζανακοπούλου              \n"
             " ) )                 3216 |   Αναστάσιος Παντζαρτζής          \n"
             "( (                                                           \n"
             " ) ) Output                                                   \n"
             "( (  ======                                                   \n"
             " ) )   Array Search       : " << arrayTotalTime.count() << "ns      \n"
                                                                     "( (    Sorted array Search: " << sortedArrayTotalTime.count() << "ns \n"
                                                                                                                                    " ) )   Binary Search Tree : " << totalBinaryTime.count() << "ns       \n"
                                                                                                                                                                                          "( (    AVL Search         : " << avlTotalTime.count() << "ns       \n"
                                                                                                                                                                                                                                                " ) )   Hash Table Search  : " << hashTotalTime.count() << "ns      \n"
                                                                                                                                                                                                                                                                                                       "( (                                                           \n"
                                                                                                                                                                                                                                                                                                       " ) )_.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._ \n"
                                                                                                                                                                                                                                                                                                       " `._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._,'" << endl<<endl;


    fileOut<<endl<<endl<<endl<<"-----------------"<<endl<<"Results of search"<<endl<<"-----------------"<<endl<<endl;

    fileOut << "Number of words:  " << q << endl << endl;


    //PRINTING ALL THE SEARCH WORDS WITH THEIR DUPLICATES
    for (int i=0; i < q ; i++)
    {
        if(!SearchElement(rootOfBinary, wordsForSearch[i])){
            fileOut <<i+1 << ") "<< wordsForSearch[i] << " not found!" <<endl;
        }
        else{
            fileOut <<i+1 << ") "<< wordsForSearch[i] << " \t\tfound,  (" << SearchElement(rootOfBinary, wordsForSearch[i])->giveMeTheDuplicates() << ") times." << endl;
        }

    }

    fileOut.close();
    cout<<endl<<"[RESULT] Results have been written in the output.txt file."<<endl;

    return 0;
}
