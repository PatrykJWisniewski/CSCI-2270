#include <iostream>
#include "BST.hpp"
using namespace std;

BST::BST()
{
     root = NULL;
}

Node* BST::createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, Node* newNode)
{
     if(root == NULL)
     {
          root = newNode;
     }
     else if(newNode->key < root->key)
     {
          root->left = Insert(root->left, newNode);
     }
     else
     {
          root->right = Insert(root->right, newNode);
     }

     return root;
}

void BST::addNode(int key)
{
     Node* newNode = createNode(key);
     root = Insert(root, newNode);
}

//A recusrive function that takes the root of a tree
//and merges it by traversing the entire tree and then
//delteing the node once it has been added too the tree
void BST::mergeTree(Node* rootOfTreeToMerge)
{
     if(rootOfTreeToMerge == NULL)
     {
          return;
     }

     mergeTree(rootOfTreeToMerge->left);
     mergeTree(rootOfTreeToMerge->right);

     addNode(rootOfTreeToMerge->key);
     delete rootOfTreeToMerge;
}

void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::print2DUtil(int space)
{
     print2DUtilHelper(root, space);
}

Node* BST::getRoot()
{
     return root;
}
