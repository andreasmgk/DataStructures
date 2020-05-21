#include "AVLTree.h"
#include <iostream>
#include <cmath>

using namespace std;

AVLTree::AVLTree(){
    root = nullptr;
}

int AVLTree::height(node *t){
    int h = 0;
    if(t != nullptr){
        int l_height = height(t->left);
        int r_height = height(t->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int AVLTree::difference(node *t){
    int l_height = height(t->left);
    int r_height = height(t->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

node *AVLTree::ll_rotat(node *parent){
    node *t;
    t = parent->right;
    parent->right = t->left;
    t->left = parent;
    return t;
}

node *AVLTree::rr_rotat(node *parent){
    node *t;
    t = parent->left;
    parent->left = t->right;
    t->right = parent;
    return t;
}

node *AVLTree::rl_rotat(node *parent){
    node *t;
    t = parent->left;
    parent->left = ll_rotat(t);
    return rr_rotat(parent);
}

node *AVLTree::lr_rotat(node *parent){
    node *t;
    t = parent->right;
    parent->right = rr_rotat(t);
    return ll_rotat(parent);
}

node *AVLTree::balance(node *t){
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

node *AVLTree::insert(node *r, string v){
    if(r == nullptr){
        r = new node(v);
        return r;
    }else if(v.compare(r->value) < 0){
        r->left = insert(r->left, v);
        r = balance(r);
    }else if(v.compare(r->value) > 0){
        r->right = insert(r->right, v);
        r = balance(r);
    }else{
        r->count++;
    }
    return r;
}

node *AVLTree::search(string k){
    node *leaf = root;
    while(leaf){
        if(leaf->value.compare(k) < 0)
            leaf = leaf->right;
        else if(leaf->value.compare(k) > 0)
            leaf = leaf->left;
        else
            break;
    }
    return leaf;
}

node *AVLTree::deletek(node *r, string k){
    if(r == nullptr)
        return r;
    if(r->value.compare(k) > 0)
        r->left = deletek(r->left, k);
    else if(r->value.compare(k) < 0)
        r->right = deletek(r->right, k);
    else{
        if(r->count == 1) {
            if (r->left == nullptr || r->right == nullptr) {
                node *temp = r->left ? r->left : r->right;

                if (temp == nullptr) {
                    temp = r;
                    r = nullptr;
                } else
                    *r = *temp;
                delete temp;
            } else {
                node *current = r->right;
                while (current->left != nullptr)
                    current = current->left;
                node *temp = current;
                r->value = temp->value;
                r->right = deletek(r->right, temp->value);
            }
        }else {
            r->count--;
        }
    }
    if(r == nullptr)
        return r;

    r = balance(r);

    return r;
}

void AVLTree::preorder(node *leaf){
    if(leaf == nullptr)
        return;
    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
    preorder(leaf->left);
    preorder(leaf->right);
}

void AVLTree::inorder(node *leaf){
    if(leaf == nullptr)
        return;
    inorder(leaf->left);
    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
    inorder(leaf->right);
}

void AVLTree::postorder(node *leaf){
    if(leaf == nullptr)
        return;
    postorder(leaf->left);
    postorder(leaf->right);
    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
}
