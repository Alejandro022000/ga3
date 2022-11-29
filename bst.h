#include <iostream>
#include <fstream>
using namespace std;
 
class BST {
    string data;
    BST *left, *right;
 
public:    
    BST();// Default constructor     
    BST(string);// Parameterized constructor    
    BST* Insert(BST*, string);// Insert function
    void Preorder(BST*, ofstream &,string);// Preorder traversal
};
 //.
BST ::BST(): data(""), left(nullptr), right(nullptr){} 
BST ::BST(string value){data = value;left = right = NULL;}

BST* BST ::Insert(BST* root, string value){
    if (!root) {
        return new BST(value);
    }
    if (stoi(value) == stoi(root->data) )    
        root = Insert(root->right, value);//replace node if string sizes are equal  
    if (stoi(value) > stoi(root->data) )     
        root->right = Insert(root->right, value);//insert right node depending on str lenghts
    else if (stoi(value)< stoi(root->data))
        root->left = Insert(root->left, value);//insert right node depending on str lenghts
    return root;
}
 

void BST ::Preorder(BST* root, ofstream &out, string pre){
    if (!root)
        return;
  
    //cout <<pre<<"] "<< root->data <<endl;
    out << pre<<"] "<< root->data <<endl; 

    pre+='l';   
    Preorder(root->left, out, pre);//go to the left of the tree     
    pre.pop_back();
    pre+='r';  
    Preorder(root->right, out, pre);//go to the right of the tree
    
}
