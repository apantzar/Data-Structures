#include "BinaryTree.h"
#include<iostream>
#include<algorithm>
#include<fstream>
#include <cstring>
#include <string>

using namespace std;


/**
 * Function responsible for insertion into the BST
 * @param theNode ->The node for the insert function
 * @param theWord ->Each word from the given file
 * @return -> if theNode is equals to NULL-> theNode's duplicates ++
 */
BinaryTree* InsertElement(BinaryTree* theNode, string theWord){

    // if the node doesn't exist, we create it, initialize it's values and store the given word
    if(theNode==NULL){
        BinaryTree *theNode = new BinaryTree();
        theNode->Right = theNode->Left = NULL;
        theNode->temp = theWord;
        theNode->theDuplicates = 1;

        return theNode;

    }else if (theNode->temp == theWord){
        // if the word already exists in the BST we increase theDuplicates's value
        theNode->theDuplicates++;
    }else if(theWord > theNode->temp){
        // if the word is greater than the node's value, we go to the right child
        theNode->Right = InsertElement(theNode->Right, theWord);
    }else if (theWord < theNode->temp){
        // if the word is less than the node's value, we go to the left child
        theNode->Left = InsertElement(theNode->Left, theWord);
    }


    return theNode;

}

/**
 * Recursive function responsible for deletion of a node of the BST
 * @param theNode ->The node for the delete function
 * @param theWord ->Each word from the given file
 * @return
 */


BinaryTree* DeleteElement(BinaryTree* theNode, string theWord){
    //if the node doesn't exist, we return it
    if(theNode==NULL){
        return theNode;
    }

    if(theWord> theNode->temp){
        // if the word is greater than the node's value, we go to the right child and we call the function again
        theNode->Right = DeleteElement(theNode->Right, theWord);
    }else if(theWord < theNode->temp){
        // if the word is less than the node's value, we go to the left child and we call the function again
        theNode->Left = DeleteElement(theNode->Left, theWord);

    }else{
        //if we found the node and it has one or zero child
        if(theNode->Left==NULL){ //it has a right child and deletes theNode
            BinaryTree *temporaryTree=theNode->Right;
            delete theNode;
            return temporaryTree;
        }else if(theNode->Right==NULL){ //it has a right child and deletes theNode
            BinaryTree *temporaryTree=theNode->Left;
            delete theNode;
            return  temporaryTree;
        }

        //if we found the node and it has two children
        BinaryTree* temporaryTree=sInorder(theNode->Right);

        // copying back the values of temporaryTree to theNode
        theNode->temp = temporaryTree->temp;
        theNode->Left = temporaryTree->Left;
        theNode->Right = temporaryTree->Right;
        theNode->theDuplicates = temporaryTree->theDuplicates;

        // call the delete function to delete the temporaryTree
        theNode->Right = DeleteElement(theNode->Right, temporaryTree->temp);
    }
    return theNode;

}

/**
 * Function that implements the next node in Inorder traversal of the binary tree (inorder successor)
 * @param theNode ->The node for the sInorder function
 * @return temporaryTree -> temporary binary tree
 */
BinaryTree* sInorder(BinaryTree* theNode){
    BinaryTree* temporaryTree = theNode;

    // in order to find the inorder successor
    while (temporaryTree && temporaryTree->Left!=NULL){
        temporaryTree = temporaryTree->Left;
    }

    return temporaryTree;
}


/**
 * Function responsible for searching in the BST
 * @param theNode ->The node for the search function
 * @param theWord ->the word to search
 * @return
 */
BinaryTree* SearchElement(BinaryTree *theNode, string theWord)
{
    //if the node doesn't exist, we return it
    if (theNode==NULL){
        return theNode ;
    }

    // if theWord has been found, return it
    if (theNode->temp == theWord){
        return theNode;
    }

    // if the word is greater than the node's value, we go to the right child and we call the function again
    if (theNode->temp < theWord){
        return SearchElement(theNode->Right, theWord);
    }

    // if the word is less than the node's value, we go to the left child and we call the function again
    return SearchElement(theNode->Left, theWord);
}


/**
 * Preorder: Root --> Left --> Right
 * @param root
 */

void preorder(BinaryTree* root){
    if(root !=NULL) {
        cout<<root->temp<<endl;
        preorder(root->Left);
        preorder(root->Right);
    }
}

/**
 * Inorder: Left --> Root --> Right
 * @param root
 */
void inorder(BinaryTree* root){
    if(root!=NULL){
        inorder(root->Left);
        cout<<root->temp<<endl;
        inorder(root->Right);
    }

}

/**
 * Postorder: Left --> Right --> Root
 * @param root
 */
void postorder(BinaryTree* root)
{

    if (root != NULL)
    {
        postorder(root->Left);
        postorder(root->Right);
        cout<<root->temp<<endl;
    }
}


