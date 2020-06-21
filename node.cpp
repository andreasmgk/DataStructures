#ifndef NODE
#define NODE
#include <iostream>
#include <string>

using namespace std;
struct node{
    //Parent node
    node *parent;
    //Left subtree
    node *left;
    //Right subtree
    node *right;
    //node value
    string value;
    //Word counter
    int count;
    //Constructor for null initialization
    node(const string& k) : parent(nullptr), left(nullptr), right(nullptr), value(k), count(1) {};
};
#endif