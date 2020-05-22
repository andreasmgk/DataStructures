#include "HashTable.h"

HashTable::HashTable() {
    tab_len = 1;
    table = new Cell[tab_len];
    table[0].word = "";
    table[0].count = 1;
}

Cell *HashTable::growTable() {
    Cell *temp = new Cell[tab_len + 1];
    copy(table, table + tab_len, temp);
    table = temp;
    tab_len++;
    return &table[tab_len - 1];
}

void HashTable::insert(const string& value) {
    if(table[0].word == "") {
        table[0].word = value;
        table[0].count = 1;
    }else {
        Cell *existing = search(value);
        if(existing == nullptr) {
            Cell *ncell = growTable();
            ncell->word = value;
            ncell->count = 1;
        }else {
            existing->count++;
        }
    }
}

Cell *HashTable::search(const string& value) {
    if(table[0].word == "") { return nullptr; }
    for(int i = 0; i < tab_len; i++) {
        if(table[i].word == value) {
            return &table[i];
        }
    }
    return nullptr;
}

void HashTable::print(const string& value) {
    Cell *temp = search(value);
    if(temp != nullptr) {
        cout<< temp->word << " Counted: " << temp->count << endl;
    }
}