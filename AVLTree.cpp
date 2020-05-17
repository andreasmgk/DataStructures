#include "AVLTree.h"
#include <iostream>
#include <cmath>

using namespace std;

AVLTree::AVLTree(){
    root = nullptr;
}

int AVLTree::height(avl *t){
    int h = 0;
    if(t != nullptr){
        int l_height = height(t->left);
        int r_height = height(t->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int AVLTree::difference(avl *t){
    int l_height = height(t->left);
    int r_height = height(t->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

avl *AVLTree::ll_rotat(avl *parent){
    avl *t;
    t = parent->right;
    parent->right = t->left;
    t->left = parent;
    return t;
}

avl *AVLTree::rr_rotat(avl *parent){
    avl *t;
    t = parent->left;
    parent->left = t->right;
    t->right = parent;
    return t;
}

avl *AVLTree::rl_rotat(avl *parent){
    avl *t;
    t = parent->left;
    parent->left = ll_rotat(t);
    return rr_rotat(parent);
}

avl *AVLTree::lr_rotat(avl *parent){
    avl *t;
    t = parent->right;
    parent->right = rr_rotat(t);
    return ll_rotat(parent);
}

avl *AVLTree::balance(avl *t){
    int bal_factor = difference(t);
    if(bal_factor > 1){
        if(difference(t->left) > 0)
            t = rr_rotat(t);
        else
            t = rl_rotat(t);
    }else if(bal_factor < -1){
        if(difference(t->right) > 0)
            t = lr_rotat(t);
        else
            t = ll_rotat(t);
    }
    return t;
}

avl *AVLTree::insert(avl *r, string v){
    if(r == nullptr){
        r = new avl;
        r->d = v;
        r->left = nullptr;
        r->right = nullptr;
        r->parent = nullptr;
        return r;
    }else if(v.compare(r->d) < 0){
        r->left = insert(r->left, v);
        r = balance(r);
    }else if(v.compare(r->d) > 0){
        r->right = insert(r->right, v);
        r = balance(r);
    }else{
        cout<<"This value already exists."<<endl;
    }
    return r;
}

avl *AVLTree::search(string k){
    avl *leaf = new avl;
    leaf = root;
    while(leaf){
        if(leaf->d.compare(k) < 0)
            leaf = leaf->right;
        else if(leaf->d.compare(k) > 0)
            leaf = leaf->left;
        else
            break;
    }
    return leaf;
}

avl *AVLTree::deletek(avl *r, string k){
    if(r == nullptr)
        return r;
    if(k < r->d)
        r->left = deletek(r->left, k);
    else if(k > r->d)
        r->right = deletek(r->right, k);
    else{
        if(r->left == nullptr || r->right == nullptr){
            avl *temp = r->left?r->left:r->right;

            if(temp == nullptr){
                temp = r;
                r = nullptr;
            }else
                *r = *temp;
            delete temp;
        }else{
            avl *current = r->right;
            while(current->left != nullptr)
                current = current->left;
            avl *temp = current;
            r->d = temp->d;
            r->right = deletek(r->right, temp->d);
        }
    }
    if(r == nullptr)
        return r;

    r = balance(r);

    return r;
}

void AVLTree::preorder(avl *leaf){
    if(leaf == nullptr)
        return;
    printf("%s \n", leaf->d.c_str());
    preorder(leaf->left);
    preorder(leaf->right);
}

void AVLTree::inorder(avl *leaf){
    if(leaf == nullptr)
        return;
    inorder(leaf->left);
    printf("%s \n", leaf->d.c_str());
    inorder(leaf->right);
}

void AVLTree::postorder(avl *leaf){
    if(leaf == nullptr)
        return;
    postorder(leaf->left);
    postorder(leaf->right);
    printf("%s \n", leaf->d.c_str());
}
