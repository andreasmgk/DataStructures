#include "HashTable.h"

HashTable::HashTable() {
    tab_len = 50000017;
    inserts = 0;
    R = tab_len / 2;
    table = new Cell[tab_len];
    for(int i = 0; i < tab_len; i++){
        table[i].word = "";
        table[i].count = 0;
    }
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

    int counter = 0;
    for(int i = 0; i < tab_len / 2  &&  counter <= inserts; i++){
        if(table[i].word != ""){
            for(int j = 0; j < tab_len / 2; j++){
                int hasher = h(temp, table[i].word, j);
                if(hasher > 0){
                    Cell *ncell;
                    ncell = &temp[hasher];
                    ncell->word = table[i].word;
                    ncell->count = table[i].count;
                    counter++;
                    break;
                }
            }
        }
    }
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
                hasher = h(table, value, i);
            }
            ncell = &table[hasher];
            ncell->word = value;
            ncell->count = 1;
            inserts++;
            break;
        }else if(hasher < 0 && table[hasher * (-1)].word == value){
            table[hasher * (-1)].count++;
            break;
        }
    }
}

Cell *HashTable::search(const string& value) {
    for(int i = 0; i < tab_len; i++){
        int hasher = h(table, value, i);
        if(hasher < 0 && table[hasher * (-1)].word == value)
            return &table[hasher * (-1)];
    }
    return nullptr;
}

void HashTable::print(const string& value) {
    Cell *temp = search(value);
    if(temp != nullptr) {
        cout<< temp->word << " Counted: " << temp->count << endl;
    }
}
