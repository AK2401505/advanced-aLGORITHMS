#include<iostream>
#include "Tree.h"
using namespace std;  

Node* Tree::insert(Node* n, int value) { 
    if (n == nullptr) return new Node(value); 
    if (value < n->data) n->left  = insert(n->left,  value); 
    else if(value > n->data) n->right = insert(n->right, value); 
    // equal: duplicate ignored 
    return n; 
} 

int Tree::height(Node* n) { 
if (n == nullptr) return -1;  // -1: height of empty subtree 
int lh = height(n->left); 
int rh = height(n->right); 
return 1 + max(lh, rh); 
} 

void Tree::levelOrder() { 
    if(root==nullptr)
        return;
    int h=height(root);
    for(int i=1; i<=h+1;i++){
        printlevel(root,i);
    }
    cout<<endl;
} 

void Tree::preOrder(Node* n){
    if (n==nullptr)
        return;
    cout<<n->data;
    preOrder(n->left);
    preOrder(n->right);
}

void Tree::inOrder(Node* n){
    if (n==nullptr)
        return;
    inOrder(n->left);
    cout<<n->data;
    inOrder(n->right);
}

void Tree::printlevel(Node*n,int level){
    if(n==nullptr)
        cout<<n->data<<" ";
    if (level == 1) {
        cout << n->data << " ";
    } else {
        printlevel(n->left, level - 1);
        printlevel(n->right, level - 1);
    }
}

bool Tree::search(Node* n, int v) {
    if (n == nullptr)
        return false;
    if (n->data == v)
        return true;

    if (v < n->data)
        return search(n->left, v);

    return search(n->right, v);
}

Node* Tree::deleteNode(Node* n, int v) {
    if (n == nullptr)
        return nullptr;

    if (v < n->data) {
        n->left = deleteNode(n->left, v);
    }
    else if (v > n->data) {
        n->right = deleteNode(n->right, v);
    }
    else {
        // Case 1: No children
        if (n->left == nullptr && n->right == nullptr) {
            delete n;
            return nullptr;
        }

        // Case 2: One child
        if (n->left == nullptr) {
            Node* temp = n->right;
            delete n;
            return temp;
        }

        if (n->right == nullptr) {
            Node* temp = n->left;
            delete n;
            return temp;
        }

        // Case 3: Two children
        Node* temp = n->right;

        while (temp->left != nullptr)
            temp = temp->left;

        n->data = temp->data;
        n->right = deleteNode(n->right, temp->data);
    }

    return n;
}

Node* Tree::findMin(Node* n) {
    if (n == nullptr)
        return;

    while (n->left != nullptr) {
        n = n->left;
    }

    return n;
}


    


