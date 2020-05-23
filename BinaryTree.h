#include <iostream>
#include <string>
#include "node.cpp"

using namespace std;

class BinaryTree
{
    private:
        node *root;
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
    public:
        BinaryTree();

        node *search(const string&);
        void insert(const string&);
        void deletek(const string&);
        void preorder(){
            preorder(root);
        }
        void inorder(){
            inorder(root);
        }
        void postorder(){
            postorder(root);
        }
};
