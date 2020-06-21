#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H
#include <iostream>
#include <string>

using namespace std;

//The structure where both word and the counter is stored
struct Cell {
    int count;
    string word;
};

class HashTable
{
private:
    //Array of the Cell(s) inside the structure
    Cell *table;
    //Increases table size
    void growTable();
    //Length of table
    int tab_len;
    int R;
    //Finds a node with passed value, else null
    Cell *searchk(const string&);
    int inserts;
    int *hashers;
    int hashers_size;
public:
    HashTable();
    ~HashTable();
    long long h(Cell *,const string&, int);
    void insert(const string&);
    void print(const string&);
    void search(string s) {
        Cell *temp;
        temp = searchk(s);
        if(temp == nullptr) {
            cout << s << ": 0" << endl;
        }else {
            cout << s << ": " << temp->count << endl;
        }
    }
};
#endif //DATASTRUCTURES_HASHTABLE_H
