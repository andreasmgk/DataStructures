#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree2.h"

using namespace std;

int main(){
    /*BinaryTree b;

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
    cout<<endl;*/


    BinaryTree2 a;

    a.root = a.insert(a.root, 8);
    a.root = a.insert(a.root, 9);
    a.root = a.insert(a.root, 10);
    a.root = a.insert(a.root, 12);
    a.root = a.insert(a.root, 11);
    a.preorder();
    cout<<endl;
    a.inorder();
    a.root = a.deletek(a.root, 8);
    a.root = a.deletek(a.root, 12);
    cout<<endl;
    a.preorder();
    cout<<endl;
    a.inorder();
    cout<<endl;
    a.postorder();
    cout<<endl;

    return 0;
}
