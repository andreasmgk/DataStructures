#include <iostream>
#include <string>
#include "node.cpp"

using namespace std;

class BinaryTree
{
    private:
        node *root;

        node *deletek(node *, string, bool);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        node *searchk(const string&);
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(const string&);
        void deletek(string s){
            root = deletek(root, s, false);
        }
        void preorder(){
            preorder(root);
        }
        void inorder(){
            inorder(root);
        }
        void postorder(){
            postorder(root);
        }
    void search(string s) {
        node *temp;
        temp = searchk(s);
        if(temp == nullptr) {
            cout << s << ": 0" << endl;
        }else {
            cout << s << ": " << temp->count << endl;
        }
    }
};
