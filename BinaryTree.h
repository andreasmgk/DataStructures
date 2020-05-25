#include <iostream>
#include <string>
#include "node.cpp"

using namespace std;

class BinaryTree
{
    private:
        node *root;

        node *deletek(node *, string, bool);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
    public:
        BinaryTree();
        ~BinaryTree();

        node *search(const string&);
        void insert(const string&);
        void deletek(string s){
            root = deletek(root, s, false);
        }
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
