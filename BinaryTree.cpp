#include "BinaryTree.h"

BinaryTree::BinaryTree() { root = nullptr; }

BinaryTree::~BinaryTree(){}

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

node *BinaryTree::deletek(node *root, string s, bool flag){
    if(root == nullptr)
        return root;
    if(s < root->value)
        root->left = deletek(root->left, s, flag);
    else if(s > root->value)
        root->right = deletek(root->right, s, flag);
    else{
        if(root->count == 1 || flag){
            if(root->left == nullptr){
                node *temp = root->right;
                /*if(root == (root->parent)->right)
                    (root->parent)->right = temp;
                else if(root == (root->parent)->left)
                    (root->parent)->left = temp;*/
                delete root;
                return temp;
            }else if(root->right == nullptr){
                node *temp = root->left;
                /*if(root == (root->parent)->right)
                    (root->parent)->right = temp;
                else if(root == (root->parent)->left)
                    (root->parent)->left = temp;*/
                delete root;
                return temp;
            }
            node *temp = root->right;
            while(temp && temp->left != nullptr)
                temp = temp->left;
            root->value = temp->value;
            root->count = temp->count;
            flag = true;
            root->right = deletek(root->right, temp->value, flag);
        }else if(root->count > 1){
            root->count--;
        }
    }
    return root;
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
