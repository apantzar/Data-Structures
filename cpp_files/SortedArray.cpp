#include "SortedArray.h"
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include <cstdlib>




using namespace std;


/**
 * Empty Constructor
 */
SortedArray::SortedArray() {
    theArray = new string[5000];
    theSize = 5000;
    numOfElements = 0;

}

/**
 * Function to insert an element to the array using quicksort algorithm
 * @param A --> address of the word to insert
 * @param p --> lowest value of array
 * @param r --> highest value of array
 */
void SortedArray::insertSortedArray(string& A, int p, int r)
{

    //if p (lowest vale) is smaller than r (highest value) call the partition function
    if (p < r)
    {
        int q = partition(A, p, r);

        /**
        * Sorting elements before & after partition
        * Recursion with changes (locations)
        */

        insertSortedArray(A, p, q - 1); //moving
        insertSortedArray(A, q + 1, r);
    }


}


/**
 * Function to search an element of the array
 * @param theWord --> the word to search
 * @return
 */
int SortedArray::searchInSortedArray(string theWord) {
    int start = 0, theEnd = theSize;
    int index;
    bool isFound = false;

    while (true) {

        //if the word is in the start position
        if (theArray[start] == theWord) {
            isFound = true;
            index = start;

            break;

        }
        //if the word is in the end position
        if (theArray[theEnd] == theWord) {
            isFound = true;
            index = theEnd;
            break;

        }

      //moving the 'limits' (end & start) to find the word
        if (start == theEnd) {
            if (theArray[start] == theWord) {
                isFound = true;
                index = start;
                break;
            }
            else {
                break;
            }
        }
        start++;
        theEnd--;


    }
    if (isFound) {
        return index; //Found! Found! Found! :)
    }
    else {
        return 0;
    }


}



/**
* Function responsible for deletion of an element of the array
*@param theWord --> the word to delete
*/
void SortedArray::deleteInSortedArray(string theWord){
    int index;
    string temp;
    index = this->searchInSortedArray(theWord);

    if (index != 0) {
        for (int i = index; i <= numOfElements; i++) {
            theArray[i] = theArray[i + 1]; //moving element <----
        }

        numOfElements--;
    }
    else {
        cout <<"The word doesn't exist! Please try another..." << endl;
    }





}



/**
* This function assign the last element (pivot element) &
* moves it to the correct position in the sorted array.
*
* Algorithm:
*    elements < pivot ==> left
*    elements > pivot ==> right
*
* @param A --> address of the word to insert
* @param p --> lowest value of array
* @param r --> highest value of array
*/
int SortedArray::partition(string& A, int p, int r)
{
    char x = A[r];
    int i = p-1;

    for (int j=p; j<=(r-1); ++j)
    {
        if (A[j] <= x)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);

    return i+1;
};



/**
*This function is responsible to swap elements using their address
*@param a -> first address
*@param b -> first address
*/
void SortedArray::swap(char& a, char& b)
{
    char valA = a;
    char valB = b;

    a = valB;
    b = valA;
}
