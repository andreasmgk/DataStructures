#include <iostream>
#include <string>

using namespace std;

struct avl{
    string d;
    avl *left;
    avl *right;
    avl *parent;
};

class AVLTree
{
    private:
        avl *root;

        int height(avl *);
        int difference(avl *);
        avl *rr_rotat(avl *);
        avl *ll_rotat(avl *);
        avl *lr_rotat(avl *);
        avl *rl_rotat(avl *);
        avl *balance(avl *);

        avl *insert(avl *, string);
        avl *search(string);
        avl *deletek(avl *, string);
        void preorder(avl *);
        void inorder(avl *);
        void postorder(avl *);
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