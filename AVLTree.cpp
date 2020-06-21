#include "AVLTree.h"
#include <iostream>
#include <cmath>

using namespace std;

// When creating a tree, set
// its root to the nulpointer
AVLTree::AVLTree(){
    root = nullptr;
}

// A casual destructor
AVLTree::~AVLTree(){}

//Return the maximum height of the node t
int AVLTree::height(node *t){
    int h = 0;
    if(t != nullptr){
        //Find the height of the left subtree
        int l_height = height(t->left);
        //Find the height of the right subtree
        int r_height = height(t->right);
        //Find the maximum height
        int max_height = max(l_height, r_height);
        //Return the height of the node, include itself
        h = max_height + 1;
    }
    return h;
}

//Return which side is heavier from the node
int AVLTree::difference(node *t){
    //Find the height of the left subtree
    int l_height = height(t->left);
    //Find the height of the right subtree
    int r_height = height(t->right);
    //Subtract the right height from the left height
    int b_factor = l_height - r_height;

    //Return the resulting value
    return b_factor;
}

//Do the Left-Left Rotation
node *AVLTree::ll_rotat(node *parent){
    node *t;
    t = parent->right;
    parent->right = t->left;
    t->left = parent;
    return t;
}

//Do the Right-Right Rotation
node *AVLTree::rr_rotat(node *parent){
    node *t;
    t = parent->left;
    parent->left = t->right;
    t->right = parent;
    return t;
}

//Do the Right-Left Rotation
node *AVLTree::rl_rotat(node *parent){
    node *t;
    t = parent->left;
    parent->left = ll_rotat(t);
    return rr_rotat(parent);
}

//Do the Left-Right Rotation
node *AVLTree::lr_rotat(node *parent){
    node *t;
    t = parent->right;
    parent->right = rr_rotat(t);
    return ll_rotat(parent);
}

//Choose which rotation to do, and do it,
//then return the new root of the subtree
node *AVLTree::balance(node *t){
    //Find which rotation is needed, IF needed
    int bal_factor = difference(t);
    //Do the right rotation
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

    //Return the new root of the subtree
    return t;
}

// Add a node with value v to the tree or
// increase the counter of an existing node
node *AVLTree::insert(node *r, string v){
    // If the tree is empty create the root
    if(r == nullptr){
        r = new node(v);
        return r;


    // Traverse the tree until you find the right spot or
    // find the node already exists


    //If the word is smaller than the current, move to the left subtree
    }else if(v.compare(r->value) < 0){
        r->left = insert(r->left, v);
        //Balance the tree, IF needed
        r = balance(r);

    //If the word is greater than the current, move to the right subtree
    }else if(v.compare(r->value) > 0){
        r->right = insert(r->right, v);
        //Balance the tree, IF needed
        r = balance(r);

    //If the word already exists, increase its counter by 1
    }else{
        r->count++;
    }
    return r;
}

// Return the node with value k
node *AVLTree::searchk(string k){

    // Create a new node with value k
    // to be searchked
    // and start from the root
    node *leaf = root;

    // Traverse the tree until you find the node or reach a nullpointer
    while(leaf){
        if(leaf == nullptr)
            break;
        if(leaf->value.compare(k) < 0)
            leaf = leaf->right;
        else if(leaf->value.compare(k) > 0)
            leaf = leaf->left;
        else
            break;
    }
    return leaf;
}

// Delete the node with value k or
// decrease the counter of an existing node
node *AVLTree::deletek(node *r, string k, bool flag){

    // The flag is set to false when entering the function the first time
    // and its used as a guard to ensure that the leftmost leaf of a node
    // with 2 children will be deleted,
    // instead of copying that leaf to the node

    // If the tree is empty or
    // the node doesn't exist
    // don't do anything
    if(r == nullptr)
        return r;

    // Start going down the tree

    // If the node to be deleted has smaller value
    // than the current node move to the left
    // subtree
    if(r->value.compare(k) > 0)
        r->left = deletek(r->left, k, flag);

    // If the node to be deleted has greater value
    // than the current node move to the left
    // subtree
    else if(r->value.compare(k) < 0)
        r->right = deletek(r->right, k, flag);

    // If the node to be deleted and the current node are
    // the same, delete the current node
    else{

        // If the node to be deleted has a counter equal to 1,
        // delete the node
        if(r->count == 1 || flag) {

            // If the node has 0 or only one child,
            // delete the node and return
            // the nullpointer or that child
            if (r->left == nullptr || r->right == nullptr) {
                node *temp = r->left ? r->left : r->right;

                if (temp == nullptr) {
                    temp = r;
                    r = nullptr;
                } else
                    *r = *temp;
                delete temp;

            // If the node has 2 children,
            // find the leftmost leaf of the right subtree,
            // copy its value and counter to the node,
            // and delete that leaf
            } else {
                node *temp = r->right;
                while (temp && temp->left != nullptr)
                    temp = temp->left;
                r->value = temp->value;
                r->count = temp->count;
                flag = true;
                r->right = deletek(r->right, temp->value, flag);
            }

        // If the node to be deleted has a counter greater than 1,
        // decrease its counter by 1
        }else if(r->count > 1){
            r->count--;
        }
    }

    //If the root is a nullpointer, don't balance it
    if(r == nullptr)
        return r;

    r = balance(r);

    return r;
}

// Print all the elements of the tree
// according to the preorder pattern
void AVLTree::preorder(node *leaf){

    if(leaf == nullptr)
        return;

    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
    preorder(leaf->left);
    preorder(leaf->right);
}

// Print all the elements of the tree
// according to the inorder pattern
void AVLTree::inorder(node *leaf){

    if(leaf == nullptr)
        return;

    inorder(leaf->left);
    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
    inorder(leaf->right);
}

// Print all the elements of the tree
// according to the postorder pattern
void AVLTree::postorder(node *leaf){

    if(leaf == nullptr)
        return;

    postorder(leaf->left);
    postorder(leaf->right);
    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
}
