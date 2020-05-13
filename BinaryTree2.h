#ifndef BINARYTREE2_H
#define BINARYTREE2_H
#include <iostream>

using namespace std;

struct avl{
    int d;
    avl *left;
    avl *right;
    avl *parent;
};

class BinaryTree2
{
    private:
        void preorder(avl *);
        void inorder(avl *);
        void postorder(avl *);
    public:
        BinaryTree2();
        ~BinaryTree2();

        avl *root;

        int height(avl *);
        int difference(avl *);
        avl *rr_rotat(avl *);
        avl *ll_rotat(avl *);
        avl *lr_rotat(avl *);
        avl *rl_rotat(avl *);
        avl *balance(avl *);

        avl *insert(avl *, int);
        avl *search(int);
        avl *deletek(avl *, int);
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

#endif // BINARYTREE2_H
