#include<iostream>
using namespace std; 

class Node { 
public: 
    int   data; 
    Node* left; 
    Node* right; 
    Node(int v){ data=v; left=right=nullptr; } 
}; 
 
class Tree { 
public: 
    Node* root; 
    Tree(){ root=nullptr; } 
    ~Tree();                      // free all nodes 
    Node* insert(Node* n, int v); 
    bool  search(Node* n, int v); 
    Node* findMin(Node* n); 
    Node* deleteNode(Node* n, int v); 
    void  inOrder(Node* n); 
    void  preOrder(Node* n); 
    int   height(Node* n); 
    void  levelOrder();
    void printlevel(Node* n,int level); 
};  