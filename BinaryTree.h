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
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
    public:
        BinaryTree();
        ~BinaryTree();

        node *search(int);
        void insert(int);
        void deletek(int);
        void preorder(){
            preorder(root);
        }
        void inorder(){
            inorder(root);
        }
        void postorder(){
            postorder(root);
        }

    protected:
};

#endif // BINARYTREE_H
