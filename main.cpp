#include <iostream>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "HashTable.h"

using namespace std;

int main(){

    string h[5] = {"d", "a", "b", "c", "e"};

    //BinaryTree b;
    BinaryTree a;

    cout<< "BinaryTree" <<endl;
    cout<< "------------------------------" <<endl;
    for(int i = 0; i<1000000;i++)
        a.insert(h[i % 5]);
    a.preorder();
    cout<<endl;
    a.inorder();
    cout<<endl;
    a.postorder();
    cout<<endl;
    for(int i = 0; i<1000000; i++)
        a.deletek(h[i % 4]);
    a.preorder();
    cout<<endl;
    a.inorder();
    cout<<endl;
    a.postorder();
    cout<<endl;

    //AVLTree
    AVLTree b;

    cout<< "AVLTree" <<endl;
    cout<< "------------------------------" <<endl;
    for(int i = 0; i<1000000;i++)
        b.insert(h[i % 5]);
    b.preorder();
    cout<<endl;
    b.inorder();
    cout<<endl;
    b.postorder();
    cout<<endl;
    for(int i = 0; i<1000000; i++)
        b.deletek(h[i % 1]);
    b.preorder();
    cout<<endl;
    b.inorder();
    cout<<endl;
    b.postorder();
    cout<<endl;

    //AVLTree
    HashTable c;

    cout<< "HashTable" <<endl;
    cout<< "------------------------------" <<endl;
    for(int i = 0; i<1000000000;i++)
        c.insert(h[i % 5]);
    c.print("a");
    c.print("b");
    c.print("c");
    c.print("d");
    c.print("e");
    cout<<endl;
    return 0;
}
