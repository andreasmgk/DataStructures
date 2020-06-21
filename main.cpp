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
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Total running time: " << duration.count() << endl;
    cout << "------------------------" << endl;

    cout << "AVLTree" << endl;
    cout << "------------------------" << endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < 1000; i++) {
        b.search(Q[i]);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Total running time: " << duration.count() << endl;
    cout << "------------------------" << endl;

    cout << "HashTable" << endl;
    cout << "------------------------" << endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < 1000; i++) {
        c.search(Q[i]);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Total running time: " << duration.count() << endl;
    cout << "------------------------" << endl;
    return 0;
}
