#include <iostream>
#include <chrono>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "HashTable.h"
#define Binary 100000000
#define AVL 100000000
#define Hash_Table 10

using namespace std;
using namespace std::chrono;

int main(){

    string h[5] = {"d", "a", "b", "c", "e"};

    //BinaryTree b;
    BinaryTree a;

    cout<< "BinaryTree" <<endl;
    cout<< "------------------------------" <<endl;
    auto start = high_resolution_clock::now();
    for(int i = 0; i < Binary; i++)
        a.insert(h[i % 5]);
    a.preorder();
    cout<<endl;
    a.inorder();
    cout<<endl;
    a.postorder();
    cout<<endl;
    for(int i = 0; i < Binary; i++)
        a.deletek(h[i % 4]);
    a.preorder();
    cout<<endl;
    a.inorder();
    cout<<endl;
    a.postorder();
    cout<<endl;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    float tree = duration.count();

    //AVLTree
    AVLTree b;

    cout<< "AVLTree" <<endl;
    cout<< "------------------------------" <<endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < AVL; i++)
        b.insert(h[i % 5]);
    b.preorder();
    cout<<endl;
    b.inorder();
    cout<<endl;
    b.postorder();
    cout<<endl;
    for(int i = 0; i < AVL; i++)
        b.deletek(h[i % 4]);
    b.preorder();
    cout<<endl;
    b.inorder();
    cout<<endl;
    b.postorder();
    cout<<endl;
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
    float avl = duration.count();

    //AVLTree
    /*HashTable c;

    cout<< "HashTable" <<endl;
    cout<< "------------------------------" <<endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < Hash_Table; i++)
        c.insert(h[i % 5]);
    c.print("a");
    c.print("b");
    c.print("c");
    c.print("d");
    c.print("e");
    cout<<endl;
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
    float hashtable = duration.count();*/

    cout<<"Binary Tree: "<<tree<<" millisec"<<endl;
    cout<<"AVL Tree: "<<avl<<" millisec"<<endl;
    //cout<<"HashTable: "<<hashtable<<" millisec"<<endl;

    return 0;
}
