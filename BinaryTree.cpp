#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    //ctor
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    //dtor
}

node *BinaryTree::search(int k){
    node *leaf = new node;
    leaf = root;
    while(leaf){
        if(leaf->value < k)
            leaf = leaf->right;
        else if(leaf->value > k)
            leaf = leaf->left;
        else
            break;
    }
    return leaf;
}

void BinaryTree::insert(int k){
    node *leaf = new node;
    leaf->value = k;
    if(root == nullptr){
        root = leaf;
    }else{
        node* leaf2 = root;
        while(leaf2 != nullptr){
            //left leaf
            if(leaf->value<leaf2->value){
                if(leaf2->left == nullptr){
                    leaf2->left = leaf;
                    leaf->parent = leaf2;
                    break;
                }
                leaf2 = leaf2->left;
            //right leaf
            }else if(leaf->value>leaf2->value){
                if(leaf2->right == nullptr){
                    leaf2->right = leaf;
                    leaf->parent = leaf2;
                    break;
                }
                leaf2 = leaf2->right;
            }else{
                delete leaf;
                break;
            }
        }
    }
}

void BinaryTree::deletek(int k){
    node *leaf = new node;
    leaf = search(k);
    if(leaf == nullptr)
        return;
    else{
        if(leaf->left && leaf->right){
            node *t = leaf->left;
            node *tpar = leaf;
            while(t->right){
                tpar = t;
                t = t->right;
            }
            leaf->value = t->value;
            leaf = t;
            leaf->parent = tpar;
        }
        node *temp;
        if(leaf->left)
            temp = leaf->left;
        else
            temp = leaf->right;
        if(leaf == root)
            root = temp;
        else{
            if(leaf == (leaf->parent)->left)
                (leaf->parent)->left = temp;
            else
                (leaf->parent)->right = temp;
        }
        delete leaf;
    }
}

void BinaryTree::preorder(node *leaf){
    if(leaf == nullptr){
        return;
    }
    printf("%d \n", leaf->value);
    preorder(leaf->left);
    preorder(leaf->right);
}

void BinaryTree::inorder(node *leaf){
     if(leaf == nullptr){
            return;
     }
     inorder(leaf->left);
     printf("%d \n", leaf->value);
     inorder(leaf->right);
}

void BinaryTree::postorder(node *leaf){
    if(leaf == nullptr){
        return;
    }
    postorder(leaf->left);
    postorder(leaf->right);
    printf("%d \n", leaf->value);
}
