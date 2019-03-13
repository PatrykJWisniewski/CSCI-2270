#ifndef BST_HPP
#define BST_HPP

#include<iostream>
using namespace std;

struct Node{
    int key;
    Node* left = NULL;
    Node* right = NULL;
};

class BST{
    private:
        Node* root;
        void printTreeHelper(Node*);
        void print2DUtilHelper(Node *, int);
        Node* createNode(int data);

    public:
        BST();
        void print2DUtil(int space);
        void addNode(int key);
        void mergeTree(Node* rootOfTreeToMerge);
        Node* getRoot();
};
#endif
