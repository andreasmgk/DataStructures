#include "HashTable.h"

//When creating the table, create a table to store the positions of each Cell,
//set their size to a large prime, create a variable for the number of the Cells,
//create a variable to use in the hashing function
//and initialize the values of the Hash Table
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

//Destructor to delete the elements of the 2 tables from the heap
HashTable::~HashTable(){
    delete[] table;
    delete[] hashers;
}

// Generates the hash function, which is:
// ( hash(x) + f(i) ) % TableSize, where
// f(i) = i * ( R - ( x % R ) )
long long HashTable::h(Cell *matrix, const string& key, int k){
    long long hashVal = 0;

    //traverse the string to generate a single identifier
    for(int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + int(key[i]);
    long long hashVal_2 = hashVal % tab_len;
    if(hashVal_2 < 0)
        hashVal_2 += tab_len;

    // hashVal = x
    // hashVal_2 = hash(x)
    long long func = (hashVal_2 + k * (R -(hashVal % R))) % tab_len;

    // If it finds an empty spot, return the value of the function
    if(matrix[func].word == "")
        return func;
    //If it does not find an empty spot, return the opposite of function's value
    else
        return func * (-1);
}

//Doubles the size of the Hash Table
void HashTable::growTable() {
    tab_len *= 2;

    //Create a temporary table to move the existing words
    Cell *temp = new Cell[tab_len];

    //Initialize the new table
    for(int i = 0; i < tab_len; i++){
        temp[i].word = "";
        temp[i].count = 0;
    }

    //Traverse all the words
    for(int i = 0; i < inserts; i++){
        //Try to find an empty spot in the new table
        for(int j = 0; j < tab_len; j++){
            int hasher = h(temp, table[hashers[i]].word, j);
            if(hasher > 0){
                Cell *ncell;
                ncell = &temp[hasher];
                ncell->word = table[i].word;
                ncell->count = table[i].count;
                //Update the position for the word
                hashers[i] = hasher;
                break;
            }
        }
    }

    //Make the the old table pointer point to the new table
    table = temp;

    //Double the variable used in the hashing function
    R *= 2;
}

//Add a Cell with word value to the table or
//increase the counter of an existing Cell
void HashTable::insert(const string& value) {
    //Try to find an empty spot in the table
    for(int i = 0; i < tab_len; i++){
        int hasher = h(table, value, i);
        //If you found an empty spot, complete the insertion
        if(hasher > 0){
            //Create a new Cell to store the word value
            Cell *ncell;

            //If the Cells in the Hash Table are greater than half its size, increase its size
            if(inserts > tab_len / 2){
                growTable();
                //Try to find an empty spot in the new table
                bool flag = false;
                for(int j = 0; j < tab_len && !flag; j++){
                    hasher = h(table, value, j);
                    if(hasher > 0)
                        flag = true;

                }
                if(!flag)
                    break;
            }
            //Insert the Cell in the Hash Table
            ncell = &table[hasher];
            //Set its word value equal to "value"
            ncell->word = value;
            //Set its counter equal to 1
            ncell->count = 1;
            //Increase the number of words by 1
            inserts++;

            //If the numbers of words is greater than size of the table for their positions, double its size
            if(inserts > hashers_size){
                int *t = new int[hashers_size * 2];
                for(int i = 0; i < hashers_size; i++)
                    t[i] = hashers[i];
                hashers_size *= 2;
                delete[] hashers;
                hashers = t;
            }
            //Insert the position of the current Cell to the table for the positions
            hashers[inserts - 1] = hasher;
            break;
        //If you found the same word, increase its counter by 1
        }else if(hasher < 0 && table[hasher * (-1)].word == value){
            table[hasher * (-1)].count++;
            break;
        }
    }
}

//Return the Cell with value "value"
Cell *HashTable::searchk(const string& value) {
    //Traverse the positions table to find the word
    for(int i = 0; i < inserts; i++){
        //Then see if the word in that position in the Hash Table is equal to the one we are searching
        if(table[hashers[i]].word == value)
            return &table[hashers[i]];
    }
    return nullptr;
}

//Print the Cell with the value "value"
void HashTable::print(const string& value) {
    Cell *temp = searchk(value);
    if(temp != nullptr) {
        cout<< temp->word << " Counted: " << temp->count << endl;
    }
}
