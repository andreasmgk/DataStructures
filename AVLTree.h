#include <iostream>
#include <string>
#include "node.cpp"

using namespace std;

class AVLTree
{
    private:
        node *root;

        int height(node *);
        int difference(node *);
        node *rr_rotat(node *);
        node *ll_rotat(node *);
        node *lr_rotat(node *);
        node *rl_rotat(node *);
        node *balance(node *);

        node *insert(node *, string);
        node *search(string);
        node *deletek(node *, string);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
    public:
        AVLTree();
        void insert(string s) {
            root = insert(root, s);
        }
        void deletek(string s) {
            root = deletek(root, s);
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