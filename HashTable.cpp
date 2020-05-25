#include "HashTable.h"

HashTable::HashTable() {
    tab_len = 10000019;
    hashers_size = tab_len;
    inserts = 0;
    R = tab_len / 2;
    table = new Cell[tab_len];
    hashers = new int[hashers_size];
    for(int i = 0; i < tab_len; i++){
        table[i].word = "";
        table[i].count = 0;
    }
}

HashTable::~HashTable(){
    delete[] table;
    delete[] hashers;
}

int HashTable::h(Cell *matrix, const string& key, int k){
    int hashVal = 0;

    for(int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + int(key[i]);

    int func = (hashVal % tab_len + k * (R -(hashVal % R))) % tab_len;
    if(matrix[func].word == "")
        return func;
    else
        return func * (-1);
}

void HashTable::growTable() {
    tab_len *= 2;
    Cell *temp = new Cell[tab_len];

    for(int i = 0; i < tab_len; i++){
        temp[i].word = "";
        temp[i].count = 0;
    }

    for(int i = 0; i < inserts; i++){
        for(int j = 0; j < tab_len; j++){
            int hasher = h(temp, table[hashers[i]].word, j);
            if(hasher > 0){
                Cell *ncell;
                ncell = &temp[hasher];
                ncell->word = table[i].word;
                ncell->count = table[i].count;
                break;
            }
        }
    }
    delete[] hashers;
    table = temp;
    R *= 2;
}

void HashTable::insert(const string& value) {
    for(int i = 0; i < tab_len; i++){
        int hasher = h(table, value, i);
        if(hasher > 0){
            Cell *ncell;
            if(inserts > tab_len / 2){
                growTable();
                bool flag = false;
                for(int j = 0; j < tab_len && !flag; j++){
                    hasher = h(table, value, j);
                    if(hasher > 0)
                        flag = true;

                }
                if(!flag)
                    break;
            }
            ncell = &table[hasher];
            ncell->word = value;
            ncell->count = 1;
            inserts++;
            if(inserts > hashers_size){
                int *t = new int[hashers_size * 2];
                for(int i = 0; i < hashers_size; i++)
                    t[i] = hashers[i];
                hashers_size *= 2;
                delete[] hashers;
                hashers = t;
            }
            hashers[inserts - 1] = hasher;
            break;
        }else if(hasher < 0 && table[hasher * (-1)].word == value){
            table[hasher * (-1)].count++;
            break;
        }
    }
}

Cell *HashTable::search(const string& value) {
    for(int i = 0; i < inserts; i++){
        if(table[hashers[i]].word == value)
            return &table[hashers[i]];
    }
    return nullptr;
}

void HashTable::print(const string& value) {
    Cell *temp = search(value);
    if(temp != nullptr) {
        cout<< temp->word << " Counted: " << temp->count << endl;
    }
}
