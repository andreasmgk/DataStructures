#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <chrono>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "HashTable.h"
#define Binary 10000000
#define AVL 10000000
#define Hash_Table 10000000

using namespace std;
using namespace std::chrono;

void performance() {
    string h[5] = {"d", "a", "b", "c", "e"};

    //HashTable c
    HashTable c;

    cout<< "HashTable" <<endl;
    cout<< "------------------------------" <<endl;
    auto start = high_resolution_clock::now();
    for(int i = 0; i < Hash_Table; i++)
        c.insert(h[i % 5]);
    c.print("a");
    c.print("b");
    c.print("c");
    c.print("d");
    c.print("e");
    cout<<endl;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    float hashtable = duration.count();

    //AVLTree b
    AVLTree b;

    cout<< "AVLTree" <<endl;
    cout<< "------------------------------" <<endl;
    start = high_resolution_clock::now();
    //for(int i = 0; i < AVL; i++)
      //  b.insert(h[i % 5]);
    for(int i = 0; i < Binary; i++)
        b.insert("d");
    for(int i = 0; i < Binary; i++)
        b.insert("a");
    for(int i = 0; i < Binary; i++)
        b.insert("b");
    for(int i = 0; i < Binary; i++)
        b.insert("c");
    for(int i = 0; i < Binary; i++)
        b.insert("e");
    b.preorder();
    cout<<endl;
    b.inorder();
    cout<<endl;
    b.postorder();
    cout<<endl;
    //for(int i = 0; i < AVL; i++)
      //  b.deletek(h[i % 4]);
    for(int i = 0; i < Binary; i++)
        b.deletek("d");
    for(int i = 0; i < Binary; i++)
        b.deletek("a");
    for(int i = 0; i < Binary; i++)
        b.deletek("b");
    for(int i = 0; i < Binary; i++)
        b.deletek("c");
    b.preorder();
    cout<<endl;
    b.inorder();
    cout<<endl;
    b.postorder();
    cout<<endl;
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
    float avl = duration.count();

    //BinaryTree a;
    BinaryTree a;

    cout<< "BinaryTree" <<endl;
    cout<< "------------------------------" <<endl;
    start = high_resolution_clock::now();
    //for(int i = 0; i < Binary; i++)
      //  a.insert(h[i % 5]);
    for(int i = 0; i < Binary; i++)
        a.insert("d");
    for(int i = 0; i < Binary; i++)
        a.insert("a");
    for(int i = 0; i < Binary; i++)
        a.insert("b");
    for(int i = 0; i < Binary; i++)
        a.insert("c");
    for(int i = 0; i < Binary; i++)
        a.insert("e");
    a.preorder();
    cout<<endl;
    a.inorder();
    cout<<endl;
    a.postorder();
    cout<<endl;
    //for(int i = 0; i < Binary; i++)
      //  a.deletek(h[i % 4]);
    for(int i = 0; i < Binary; i++)
        a.deletek("d");
    for(int i = 0; i < Binary; i++)
        a.deletek("a");
    for(int i = 0; i < Binary; i++)
        a.deletek("b");
    for(int i = 0; i < Binary; i++)
        a.deletek("c");
    a.preorder();
    cout<<endl;
    a.inorder();
    cout<<endl;
    a.postorder();
    cout<<endl;
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
    float tree = duration.count();

    cout<<"HashTable: "<<hashtable<<" millisec"<<endl;
    cout<<"AVL Tree: "<<avl<<" millisec"<<endl;
    cout<<"Binary Tree: "<<tree<<" millisec"<<endl;
}

int main(){
    BinaryTree a;
    AVLTree b;
    HashTable c;

    string Q[1000];
    int qcounter = 0;

    ifstream file("small-file.txt");
    string linestr;
    while (std::getline(file, linestr)) {
        stringstream ss(linestr);
        string word;
        while (ss >> word) {
            a.insert(word);
            b.insert(word);
            c.insert(word);
        }
    }
    file.close();
    bool flag;
    while(qcounter < 1000) {
        file.open("small-file.txt");
        while (std::getline(file, linestr) && !flag) {
            stringstream ss(linestr);
            string word;
            while (ss >> word && !flag) {
                if(qcounter == 1000) {
                    flag = true;
                } else {
                    if ((rand() % 2) == 1) {
                        Q[qcounter] = word;
                        qcounter++;
                    }
                }
            }
        }
        file.close();
    }
    for(int i = 0; i < 1000; i++) {
        a.search(Q[i]);
        b.search(Q[i]);
        c.search(Q[i]);
    }
    return 0;
}
