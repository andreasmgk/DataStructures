#include "HashTable.h"

HashTable::HashTable() {
    tab_len = 50000017; // prime number
    inserts = 0;
    R = tab_len / 2; // a hashing factor
    table = new Cell[tab_len];
    // initialize the table
    for(int i = 0; i < tab_len; i++){
        table[i].word = "";
        table[i].count = 0;
    }
}

int HashTable::h(Cell *matrix, const string& key, int k){
    int hashVal = 0;

    for(int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + int(key[i]); // conversion of the string into an integer

    int func = (hashVal % tab_len + k * (R -(hashVal % R))) % tab_len;
    if(matrix[func].word == "") // there is place for the string in the table
        return func;
    else // couldn't find a place for the string in the table
        return func * (-1);
}

void HashTable::growTable() {
    tab_len *= 2;
    Cell *temp = new Cell[tab_len];

    // initialize the new table
    for(int i = 0; i < tab_len; i++){
        temp[i].word = "";
        temp[i].count = 0;
    }

    // does rehashing
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
    R *= 2;// modifies the hashing factor
}

void HashTable::insert(const string& value) {
    // tries to find a position for the word in the table
    for(int i = 0; i < tab_len; i++){
        int hasher = h(table, value, i);
        // there is place for the word in the table
        if(hasher > 0){
            Cell *ncell;
            // checks if the inserts are more than half the size of the table
            if(inserts > tab_len / 2){
                growTable();
                bool flag = false;
                // re-calculates the hasher
                for(int j = 0; j < tab_len && !flag; j++){
                    hasher = h(table, value, j);
                    if(hasher > 0)
                        flag = true;

                }
                if(!flag)
                    break;
            }
            // inserts the element in the table
            ncell = &table[hasher];
            ncell->word = value;
            ncell->count = 1;
            inserts++;
            // checks if the table with the hashers is smaller than the inserts & re-allocates its size
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
        // the word already exists in the table
        }else if(hasher < 0 && table[hasher * (-1)].word == value){
            table[hasher * (-1)].count++;
            break;
        }
    }
}

Cell *HashTable::search(const string& value) {
    // goes across the hashers table
    for(int i = 0; i < inserts; i++){
        if(table[hashers[i]].word == value)
            return &table[hashers[i]];
    }
    return nullptr;
}

void HashTable::print(const string& value) {
    Cell *temp = search(value);
    // if the word exists in the table
    if(temp != nullptr) {
        cout<< temp->word << " Counted: " << temp->count << endl;
    }
}
