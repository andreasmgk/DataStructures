#include <iostream>
#include <string>
#include "node.cpp"

using namespace std;

class AVLTree
{
    private:
        node *root;

        int height(node *);
        int difference(node *);
        node *rr_rotat(node *);
        node *ll_rotat(node *);
        node *lr_rotat(node *);
        node *rl_rotat(node *);
        node *balance(node *);

        node *insert(node *, string);
        node *searchk(string);
        node *deletek(node *, string, bool);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
    public:
        AVLTree();
        ~AVLTree();
        void insert(string s) {
            root = insert(root, s);
        }
        void deletek(string s) {
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
