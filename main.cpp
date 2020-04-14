#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
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

    return 0;
}
