#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree2.h"

using namespace std;

int main(){
    BinaryTree b;

    b.insert(5);
    b.insert(6);
    b.insert(4);
    b.insert(0);
    b.insert(7);
    b.insert(10);
    b.insert(3);
    b.insert(12);
    b.insert(11);
    b.insert(9);
    b.insert(1);
    b.insert(2);
    b.inorder();
    cout<<endl;
    b.deletek(11);
    b.inorder();
    cout<<endl;
    b.deletek(15);
    b.inorder();

    BinaryTree2 a;

    a.root = a.insert(a.root, 8);
    a.root = a.insert(a.root, 9);
    a.root = a.insert(a.root, 10);
    a.preorder();

    return 0;
}
