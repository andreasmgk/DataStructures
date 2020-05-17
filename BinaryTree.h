#include <iostream>
#include <string>

using namespace std;

struct node{
    node *parent = nullptr;
    node *left = nullptr;
    node *right = nullptr;
    string value;
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

        node *search(string);
        void insert(string);
        void deletek(string);
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