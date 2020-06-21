#include <iostream>
#include <string>
#include "node.cpp"

using namespace std;

class AVLTree
{
    private:
        // root node of the AVLTree
        node *root;

        //Returns the height of the node
        int height(node *);
        //Return which side is heavier from the node
        int difference(node *);
        //Right-right rotation
        node *rr_rotat(node *);
        //Left-left rotation
        node *ll_rotat(node *);
        //Left-right rotation
        node *lr_rotat(node *);
        //Right-left rotation
        node *rl_rotat(node *);

        //Chooses which rotation should be done
        node *balance(node *);

        //Add a new word in the tree
        node *insert(node *, string);
        //Finds a node with passed value, else null
        node *searchk(string);
        //Deletes a node if exists from tree
        node *deletek(node *, string, bool);
        //Preorder print
        void preorder(node *);
        //Inorder print
        void inorder(node *);
        //Postorder print
        void postorder(node *);
    public:
        AVLTree();
        ~AVLTree();

        //Below functions overload the same as the above ones, but handles the root argument
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

        //Finds the word counted inside the structure, else print O
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
