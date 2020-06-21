#include <iostream>
#include <string>
#include "node.cpp"

using namespace std;

class BinaryTree
{
    private:
        //Root node
        node *root;

        //Deletes a node if exists from tree
        node *deletek(node *, string, bool);
        //Preorder print
        void preorder(node *);
        //Inorder print
        void inorder(node *);
        //Postorder print
        void postorder(node *);
        //Finds a node with passed value, else null
        node *searchk(const string&);
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(const string&);

        //Below functions overload the same as the above ones, but handles the root argument
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
