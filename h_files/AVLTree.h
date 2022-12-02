#ifndef DATASTRUCTURES2021_AVLTREE_H
#define DATASTRUCTURES2021_AVLTREE_H
#include<iostream>
#include<algorithm>
#include<fstream>
#include <cstring>
#include <string>

using namespace std;

class AVLTree {
public:

    AVLTree(string temp);

    friend AVLTree* insertNode(AVLTree* node, string theWord);
    friend AVLTree* deleteNode(AVLTree* node, string theWord);
    friend AVLTree* searchInAVL(AVLTree* node, string theWord);
    friend AVLTree *rightRotation(AVLTree *rotationNode);
    friend AVLTree *leftRotation(AVLTree *rotationNode);

    friend int calcDifHeight(AVLTree *node), heightOfAVL(AVLTree *node), maxValue(int a, int b);

    friend void preorder(AVLTree *root), postorder(AVLTree *root), inorder(AVLTree *root);

    string getTemp() {return temp;}
    int getTheDuplicates() {return theDuplicates;}

private:
    string temp;
    AVLTree *left;
    AVLTree *right;
    int theDuplicates;
    int height;
};


#endif //DATASTRUCTURES2021_AVLTREE_H
