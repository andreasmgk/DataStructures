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

void BinaryTree::print(node *leaf){
     if(leaf == nullptr){
            return;
     }
     print(leaf->left);
     printf("%d \n",leaf->value);
     print(leaf->right);
}
