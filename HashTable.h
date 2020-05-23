#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H
#include <iostream>
#include <string>

using namespace std;

struct Cell {
    int count;
    string word;
};

class HashTable
{
private:
    Cell *table;
    Cell *growTable();
    int tab_len;
    int insert_it;
public:
    HashTable();
    void insert(const string&);
    Cell *search(const string&);
    void print(const string&);
};
#endif //DATASTRUCTURES_HASHTABLE_H
