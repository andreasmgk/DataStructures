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

    cout << "Binary Tree" << endl;
    cout << "------------------------" << endl;
    auto start = high_resolution_clock::now();
    for(int i = 0; i < 1000; i++) {
        a.search(Q[i]);
    }
    auto stop = high_resolution_clock::now();
    auto duration_b = duration_cast<milliseconds>(stop - start);
    cout << "------------------------" << endl<<endl<<endl;


    cout << "AVLTree" << endl;
    cout << "------------------------" << endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < 1000; i++) {
        b.search(Q[i]);
    }
    stop = high_resolution_clock::now();
    auto duration_avl = duration_cast<milliseconds>(stop - start);
    cout << "------------------------" << endl<<endl<<endl;


    cout << "HashTable" << endl;
    cout << "------------------------" << endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < 1000; i++) {
        c.search(Q[i]);
    }
    stop = high_resolution_clock::now();
    auto duration_hash = duration_cast<milliseconds>(stop - start);
    cout << "------------------------" << endl;


    cout << "Total running time of Binary Tree: " << duration_b.count() <<" milliseconds"<< endl;
    cout << "Total running time of AVL Tree: " << duration_avl.count() <<" milliseconds"<< endl;
    cout << "Total running time of Hash Table: " << duration_hash.count() <<" milliseconds"<< endl;
    return 0;
}
