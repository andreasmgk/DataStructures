#ifndef NODE
#define NODE
#include <iostream>
#include <string>

using namespace std;
struct node{
    node *parent;
    node *left;
    node *right;
    string value;
    int count;
    node(const string& k) : parent(nullptr), left(nullptr), right(nullptr), value(k), count(1) {};
};
#endif