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
    void growTable();
    int tab_len;
    int R;
    int inserts;
    int *hashers;
    int hashers_size;
public:
    HashTable();
    ~HashTable();
    long long h(Cell *,const string&, int);
    void insert(const string&);
    Cell *search(const string&);
    void print(const string&);
};
#endif //DATASTRUCTURES_HASHTABLE_H
