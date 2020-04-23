#include "BinaryTree2.h"
#include <iostream>
#include <cmath>

using namespace std;

BinaryTree2::BinaryTree2(){
    //ctor
    root = nullptr;
}

BinaryTree2::~BinaryTree2(){
    //dtor
}

int BinaryTree2::height(avl *t){
    int h = 0;
    if(t != nullptr){
        int l_height = height(t->left);
        int r_height = height(t->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int BinaryTree2::difference(avl *t){
    int l_height = height(t->left);
    int r_height = height(t->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

avl *BinaryTree2::rr_rotat(avl *parent){
    avl *t;
    t = parent->right;
    parent->right = t->left;
    t->left = parent;
    return t;
}

avl *BinaryTree2::ll_rotat(avl *parent){
    avl *t;
    t = parent->left;
    parent->left = t->right;
    t->right = parent;
    return t;
}

avl *BinaryTree2::lr_rotat(avl *parent){
    avl *t;
    t = parent->left;
    parent->left = rr_rotat(t);
    return ll_rotat(parent);
}

avl *BinaryTree2::rl_rotat(avl *parent){
    avl *t;
    t = parent->right;
    parent->right = ll_rotat(t);
    return rr_rotat(parent);
}

avl *BinaryTree2::balance(avl *t){
    int bal_factor = difference(t);
    if(bal_factor > 1){
        if(difference(t->left) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    }else if(bal_factor < -1){
        if(difference(t->right) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}

avl *BinaryTree2::insert(avl *r, int v){
    if(r == nullptr){
        r = new avl;
        r->d = v;
        r->left = nullptr;
        r->right = nullptr;
        return r;
    }else if(v < r->d){
        r->left = insert(r->left, v);
        r = balance(r);
    }else if(v > r->d){
        r->right = insert(r->right, v);
        r = balance(r);
    }else{
        cout<<"This value already exists."<<endl;
    }
    return r;
}

avl *BinaryTree2::search(int k){
    avl *leaf = new avl;
    leaf = root;
    while(leaf){
        if(leaf->d < k)
            leaf = leaf->right;
        else if(leaf->d > k)
            leaf = leaf->left;
        else
            break;
    }
    return leaf;
}

void BinaryTree2::preorder(avl *leaf){
    if(leaf == nullptr)
        return;
    printf("%d \n", leaf->d);
    preorder(leaf->left);
    preorder(leaf->right);
}

void BinaryTree2::inorder(avl *leaf){
    if(leaf == nullptr)
        return;
    inorder(leaf->left);
    printf("%d \n", leaf->d);
    inorder(leaf->right);
}

void BinaryTree2::postorder(avl *leaf){
    if(leaf == nullptr)
        return;
    postorder(leaf->left);
    postorder(leaf->right);
    printf("%d \n", leaf->d);
}
