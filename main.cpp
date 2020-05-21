#include <iostream>
#include "BinaryTree.h"
#include "AVLTree.h"

using namespace std;

int main(){    
    //BinaryTree b;
    BinaryTree a;

    cout<< "BinaryTree" <<endl;
    cout<< "------------------------------" <<endl;
    a.insert("hello");
    a.insert("cat");
    a.insert("apple");
    a.insert("apple");
    a.insert("apple");
    a.inorder();
    cout<<endl;
    a.deletek("apple");
    a.inorder();
    cout<<endl;
    a.deletek("apple");
    a.inorder();
    cout<<endl;

    //AVLTree
    AVLTree b;

    cout<< "AVLTree" <<endl;
    cout<< "------------------------------" <<endl;
    b.insert("hello");
    b.insert("cat");
    b.insert("apple");
    b.insert("apple");
    b.insert("apple");
    b.inorder();
    cout<<endl;
    b.deletek("apple");
    b.inorder();
    cout<<endl;
    b.deletek("apple");
    b.inorder();
    cout<<endl;
    return 0;
}
