#ifndef DATASTRUCTURES2021_BINARYTREE_H
#define DATASTRUCTURES2021_BINARYTREE_H

#include <string>

using  namespace std;

class BinaryTree {

public:
    friend BinaryTree* InsertElement(BinaryTree* node, string theWord); friend BinaryTree* SearchElement(BinaryTree* node, string theWord);
    friend BinaryTree* DeleteElement(BinaryTree* node, string theWord);
    friend BinaryTree* sInorder(BinaryTree* theNode);

    friend  void inorder(BinaryTree* root);
    friend void postorder(BinaryTree* root);
    friend void preorder(BinaryTree* root);

    string giveMeTheTemp(){
        return temp;
    }

    int giveMeTheDuplicates(){
        return theDuplicates;
    }




private:
    BinaryTree *Right, *Left;
    string temp;
    int theDuplicates;


};


#endif //DATASTRUCTURES2021_BINARYTREE_H
