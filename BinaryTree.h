#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

using namespace std;

struct node{
    node *parent = nullptr;
    node *left = nullptr;
    node *right = nullptr;
    int value;
};

class BinaryTree
{
    private:
        node *root;
        void print(node *);
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int);
        void print(){
            print(root);
        }

    protected:
};

#endif // BINARYTREE_H
