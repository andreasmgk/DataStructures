#include "BinaryTree.h"

// When creating a tree, set
// its root to the nulpointer
BinaryTree::BinaryTree() { root = nullptr; }

// A casual destructor
BinaryTree::~BinaryTree(){}

// Return the node with value k
node *BinaryTree::searchk(const string& k){

    // Create a new node with value k
    // to be searchked
    node *leaf = new node(k);

    // Start the searchk from the root
    leaf = root;

    // Traverse the tree until you find the node or reach a nullpointer
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

// Add a node with value k to the tree or
// increase the counter of an existing node
void BinaryTree::insert(const string& k){

    // Create a new node with value k
    // to be inserted
    node *leaf = new node(k);

    // If the tree is empty create the root
    if(root == nullptr){
        root = leaf;
    }else{

        // Create a second node that will
        // traverse the tree
        node* leaf2 = root;

        // Traverse the tree until you find the right spot or
        // find the node already exists
        while(leaf2 != nullptr){

            // searchk the left leaf
            if(leaf->value.compare(leaf2->value) < 0){

                // If you find the right spot insert the node
                // and exit the loop
                if(leaf2->left == nullptr){
                    leaf2->left = leaf;
                    leaf->parent = leaf2;
                    break;
                }

                // Else continue with the left subtree
                leaf2 = leaf2->left;

            // searchk the right leaf
            }else if(leaf->value.compare(leaf2->value) > 0){

                // If you find the right spot insert the node
                // and exit the loop
                if(leaf2->right == nullptr){
                    leaf2->right = leaf;
                    leaf->parent = leaf2;
                    break;
                }

                // Else continue with the right subtree
                leaf2 = leaf2->right;

            // If the node already exists increase its counter
            }else{
                leaf2->count++;
                delete leaf;
                break;
            }
        }
    }
}

// Delete the node with value s or
// decrease the counter of an existing node
node *BinaryTree::deletek(node *root, string s, bool flag){

    // The flag is set to false when entering the function the first time
    // and its used as a guard to ensure that the leftmost leaf of a node
    // with 2 children will be deleted,
    // instead of copying that leaf to the node

    // If the tree is empty or
    // the node doesn't exist
    // don't do anything
    if(root == nullptr)
        return root;

    // Start going down the tree

    // If the node to be deleted has smaller value
    // than the current node move to the left
    // subtree
    if(s < root->value)
        root->left = deletek(root->left, s, flag);

    // If the node to be deleted has greater value
    // than the current node move to the left
    // subtree
    else if(s > root->value)
        root->right = deletek(root->right, s, flag);

    // If the node to be deleted and the current node are
    // the same, delete the current node
    else{

        // If the node to be deleted has a counter equal to 1,
        // delete the node
        if(root->count == 1 || flag){

            // If the node has 0 or only a right child,
            // delete the node and return
            // the nullpointer or that child
            if(root->left == nullptr){
                node *temp = root->right;

                delete root;
                return temp;

            // If the node has only a left child,
            // delete the node and return
            // that child
            }else if(root->right == nullptr){
                node *temp = root->left;

                delete root;
                return temp;
            }

            // If the node has 2 children,
            // find the leftmost leaf of the right subtree,
            // copy its value and counter to the node,
            // and delete that leaf
            node *temp = root->right;
            while(temp && temp->left != nullptr)
                temp = temp->left;
            root->value = temp->value;
            root->count = temp->count;
            flag = true;
            root->right = deletek(root->right, temp->value, flag);

        // If the node to be deleted has a counter greater than 1,
        // decrease its counter by 1
        }else if(root->count > 1){
            root->count--;
        }
    }

    return root;
}

// Print all the elements of the tree
// according to the preorder pattern
void BinaryTree::preorder(node *leaf){

    if(leaf == nullptr){
        return;
    }

    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
    preorder(leaf->left);
    preorder(leaf->right);
}

// Print all the elements of the tree
// according to the inorder pattern
void BinaryTree::inorder(node *leaf){

     if(leaf == nullptr){
            return;
     }

     inorder(leaf->left);
     printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
     inorder(leaf->right);
}

// Print all the elements of the tree
// according to the postorder pattern
void BinaryTree::postorder(node *leaf){

    if(leaf == nullptr){
        return;
    }

    postorder(leaf->left);
    postorder(leaf->right);
    printf("%s Counted:%d\n", leaf->value.c_str(), leaf->count);
}
