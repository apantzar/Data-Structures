#include "AVLTree.h"
#include<iostream>
#include<algorithm>
#include<fstream>
#include <cstring>
#include <string>


using namespace std;

AVLTree::AVLTree(string temp) {
    this->temp = temp;//init
    height = 1;// obj's hight -> 1
    theDuplicates = 1; //counter for words (how many times does the word exists?)

    //init to null
    left = NULL;
    right = NULL;
}


/**
 * To give the height
 * @param node  the node
 * @return 0 or height
 */
int heightOfAVL(AVLTree *node){
    if(node == NULL){
        return 0;
    } else{
        return node->height;
    }
}


/**
 * Calculates & checks if 'subtrees' are the same/ or sets the 'height' difference
 * @param node ->the node
 * @return the height difference
 */
int calcDifHeight(AVLTree *node){
    if(node == NULL){
        return 0;
    }else{
       int theHeightDif= (heightOfAVL(node->left) - heightOfAVL(node->right));
        return theHeightDif;
    }
}



/**
 * To find the max value of two 'elements'
 * @param value1 first value
 * @param value2 second value
 * @return max value
 */
int maxValue(int value1, int value2){
    if(value1>value2){
        return value1;
    } else{
        return value2;
    }
}



/**
 *       c                             b
 *      /     Right Rotation          / \
 *     b      - - - - - - - >        a  c
 *    /
 *   a
 *
 *
 *
 * @param rotationNode node that will rotate
 * @return the root
 */

AVLTree *rightRotation(AVLTree *rotationNode){
    AVLTree *root = rotationNode->left;
    AVLTree *tempNode = root->right;

    root->right = rotationNode;
    rotationNode->left = tempNode;

    rotationNode->height = maxValue(heightOfAVL(rotationNode->left), heightOfAVL(rotationNode->right) + 1);
    root->height = maxValue(heightOfAVL(root->left), heightOfAVL(root->right) + 1);

    return root;
}



/**
 *       c                             b
 *        \     Left Rotation         / \
 *         b    - - - - - - - >      a  c
 *          \
 *           a
 *
 *
 *
 * @param rotationNode node that will rotate
 * @return the root
 */

AVLTree *leftRotation(AVLTree *rotationNode){
    AVLTree *root = rotationNode->right;
    AVLTree *tempNode = root->left;

    root->left = rotationNode;
    rotationNode->right = tempNode;

    rotationNode->height = maxValue(heightOfAVL(rotationNode->left), heightOfAVL(rotationNode->right) + 1);
    root->height = maxValue(heightOfAVL(root->left), heightOfAVL(root->right) + 1);

    return root;
}





/**
 * To insert the given word into this structure
 * @param node
 * @param theWord
 * @return
 */
AVLTree* insertNode(AVLTree* node, string theWord){

    //When the node is empty
    if(node == NULL){
        AVLTree* node = new AVLTree(theWord);
        return(node);
    }

    //Word is already in the structure (increase the counter of duplicates)
    if(theWord == node->temp){
        node->theDuplicates++;
    }
        //---> child (right)
    else if(theWord > node->temp){
        node->right = insertNode(node->right, theWord);

    }   //<--- child (left)
    else if(theWord < node->temp){
        node->left = insertNode(node->left, theWord);
    } else{
        return node;
    }



    node->height = 1 + maxValue(heightOfAVL(node->left), heightOfAVL(node->right));// height will change


    /**
     * Try to keep the tree with same 'node-height'
     *
     * Rotations needed
     */
    int difOfHeight = calcDifHeight(node);

    //Left-Right
    if((difOfHeight > 1) && (theWord >node->left->temp))
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);

    }
    //Right-Left
    else if((difOfHeight < -1) && (theWord < node->right->temp))
    {

        node->right = rightRotation(node->right);
        return leftRotation(node);
    } //Left-Left
    else if((difOfHeight > 1) && (theWord < node->left->temp))
    {

        return rightRotation(node);
    }
    //Right-Right
    else if((difOfHeight < -1) && (theWord > node->right->temp))
    {

        return leftRotation(node);
    }

    return node;
}




/**
 * Responsible to delete the node
 * @param node
 * @param theWord
 * @return
 */
AVLTree* deleteNode(AVLTree* node, string theWord){
    if(node == NULL){
        return node;
    }


    //----> Child (right)
    if(theWord > node->temp){

        node->right = deleteNode(node->right, theWord);

      //<---- Child (left)
    } else if(theWord < node->temp){

        node->left = deleteNode(node->left, theWord);

    } else{

        //Oh this node has 2 children....
        if((node->left != NULL) && (node->right != NULL)){
            AVLTree* tempNode = node->right; //'transfer' the child with smallest value to the (right) ---> subtree

            while (tempNode->left != NULL){
                //<---- in the subtree
                tempNode = tempNode->left; //the left from the right subtree
            }

            node->temp = tempNode->temp;
            node->right = deleteNode(node->right, tempNode->temp);
        } else{

            //1 or no child
            AVLTree* tempNode = node->left;

            if(node->right){
                tempNode = node->right;
            }


            //No child here
            if(tempNode == NULL){

                node = NULL;
                tempNode = node;


            } else{
                //node's content will be replaced with temp's (specification: child's value)
                *node = *tempNode;
            }

            //will delete the pointer that points to the tempNode
            free(tempNode);
        }
    }

    if(node == NULL){
        return node;
    }

    node->height = 1 + maxValue(heightOfAVL(node->left), heightOfAVL(node->right));

    int difOfHeight = heightOfAVL(node->left) - heightOfAVL(node->right); //in order to check if the node is in the same 'height'

    //The Left - Right
    if((difOfHeight > 1) && (calcDifHeight(node->left) < 0)){
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    //The Right-Left
    if((calcDifHeight(node->right) > 0) && (difOfHeight < -1)){
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    //The Left-Left
    if((calcDifHeight(node->left) >= 0) && (difOfHeight > 1)){
        return rightRotation(node);
    }

    //The Right-Right
    if((calcDifHeight(node->right) <= 0) && (difOfHeight < -1)){
        return leftRotation(node);
    }

    return node;

}



/**
 * Responsible to search the given word:
 *      uses recursion
 * @param node -> state
 * @param theWord -> given word to search
 * @return node
 */
AVLTree* searchInAVL(AVLTree* node, string theWord){
    if(node == NULL){
        return node;
    }
    if (node->temp == theWord){
        return node;
    }
    if(node->temp < theWord){
        return searchInAVL(node->right, theWord);
    }

    return searchInAVL(node->left, theWord);
}



/**
 * Preorder: Root --> Left --> Right
 * @param root
 */
void preorder(AVLTree *root){
    if(root != NULL){
        cout<<root->temp<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}


/**
 * Postorder: Left --> Right --> Root
 * @param root
 */
void postorder(AVLTree *root){
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->temp<<endl;
    }
}



/**
 * Inorder: Left --> Root --> Right
 * @param root
 */
void inorder(AVLTree *root){
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->temp<<endl;
        inorder(root->right);
    }
}



