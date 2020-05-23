#include "BinaryTree.h"

BinaryTree::BinaryTree() { root = nullptr; }

node *BinaryTree::search(const string& k){
    node *leaf = new node(k);
    leaf = root;
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

void BinaryTree::insert(const string& k){
    node *leaf = new node(k);
    if(root == nullptr){
        root = leaf;
    }else{
        node* leaf2 = root;
        while(leaf2 != nullptr){
            //left leaf
            if(leaf->value.compare(leaf2->value) < 0){
                if(leaf2->left == nullptr){
                    leaf2->left = leaf;
                    leaf->parent = leaf2;
                    leaf2->count = 1;
                    break;
                }
                leaf2 = leaf2->left;
            //right leaf
            }else if(leaf->value.compare(leaf2->value) > 0){
                if(leaf2->right == nullptr){
                    leaf2->right = leaf;
                    leaf->parent = leaf2;
                    leaf2->count = 1;
                    break;
                }
                leaf2 = leaf2->right;
            }else{
                leaf2->count++;
                delete leaf;
                break;
            }
        }
    }
}

void BinaryTree::deletek(const string& k){
    node *leaf = new node(k);
    leaf = search(k);
    if(leaf == nullptr)
        return;
    else{
        if(leaf->count == 1) {
            if (leaf->left && leaf->right) {
                node *t = leaf->left;
                node *tpar = leaf;
                while (t->right) {
                    tpar = t;
                    t = t->right;
                }
                leaf->value = t->value;
                leaf = t;
                leaf->parent = tpar;
            }
            node *temp;
            if (leaf->left)
                temp = leaf->left;
            else
                temp = leaf->right;
            if (leaf == root)
                root = temp;
            else {
                if (leaf == (leaf->parent)->left)
                    (leaf->parent)->left = temp;
                else
                    (leaf->parent)->right = temp;
            }
            delete leaf;
        }else {
            leaf->count--;
        }
    }
}

void BinaryTree::preorder(node *leaf){
    if(leaf == nullptr){
        return;
    }
    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
    preorder(leaf->left);
    preorder(leaf->right);
}

void BinaryTree::inorder(node *leaf){
     if(leaf == nullptr){
            return;
     }
     inorder(leaf->left);
     printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
     inorder(leaf->right);
}

void BinaryTree::postorder(node *leaf){
    if(leaf == nullptr){
        return;
    }
    postorder(leaf->left);
    postorder(leaf->right);
    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
}
