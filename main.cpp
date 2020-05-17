#include <iostream>
#include "BinaryTree.h"
#include "AVLTree.h"

using namespace std;

int main(){    
    //BinaryTree b;
    AVLTree b;

    b.insert("hello");
    b.insert("cat");
    b.insert("apple");
    b.inorder();
    cout<<endl;
    b.deletek("cat");
    b.inorder();
    cout<<endl;
    b.deletek("cat");
    b.inorder();
    cout<<endl;

    return 0;
}
