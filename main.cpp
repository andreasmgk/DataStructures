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
    b.print();

    return 0;
}
