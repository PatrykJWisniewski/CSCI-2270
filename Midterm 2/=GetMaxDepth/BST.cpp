#include "BST.hpp"
#include <iostream>
#define COUNT 10

Node* BST::createNode(int data)
{
     Node* newNode = new Node();
     newNode->key = data;
     return newNode;
}

Node* BST::addNodeHelper(Node* currNode, int data)
{
     if(currNode == NULL)
     {
          return createNode(data);
     }
     else if(data < currNode->key)
     {
          currNode->left = addNodeHelper(currNode->left, data);
     }
     else
     {
          currNode->right = addNodeHelper(currNode->right, data);
     }
}

Node* BST::deleteNodeHelper(Node *currNode, int value)
{
     //If there is nothing to left to delete
     if(currNode == NULL)
     {
          return currNode;
     }

     //Finds the right node to delete
     if(value < currNode->key)
     {
          currNode->left = deleteNodeHelper(currNode->left, value);
          return currNode;
     }
     else if(value > currNode->key)
     {
          currNode->right = deleteNodeHelper(currNode->right, value);
          return currNode;
     }

     //If the tree node needs to be deleted.
     //If there is only one child...
     if(currNode->left == NULL)
     {
          Node* temp = currNode->right;
          delete currNode;
          return temp;
     }
     else if(currNode->right == NULL)
     {
          Node* temp = currNode->left;
          delete currNode;
          return temp;
     }
     //If there are two childen
     else
     {
          ///Replace with Minimum from right subtree
          Node* succParent = currNode->right;
          Node* succ = currNode->right;

          while(succ->left != NULL)
          {
             succParent = succ;
             succ = succ->left;
          }

          currNode->key = succ->key;
          currNode->right = deleteNodeHelper(currNode->right, succ->key);

          return currNode;
     }
}

Node* BST::searchKeyHelper(Node* currNode, int data)
{
     if(currNode == NULL)
     {
          return NULL;
     }

     if(currNode->key == data)
     {
         return currNode;
     }

     if(currNode->key > data)
     {
         return searchKeyHelper(currNode->left, data);
     }

     return searchKeyHelper (currNode->right, data);
}

void BST::printTreeHelper(Node* currNode)
{
     if(currNode)
     {
        printTreeHelper(currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper(currNode->right);
     }
}

void BST::print2DUtilHelper(Node *currNode, int space)
{
     // Base case
    if (currNode == NULL)
    {
        return;
    }

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::addNode(int value)
{
     root = addNodeHelper(root, value);
}

void BST::deleteNode(int value)
{
     root = deleteNodeHelper(root, value);
}

bool BST::searchKey(int value)
{
     if(searchKeyHelper(root, value) == NULL)
     {
          return false;
     }
     else
     {
          return true;
     }
}

void BST::printTree()
{
     printTreeHelper(root);
}

BST::BST()
{
     root = NULL;
}

BST::BST(int data)
{
     root = createNode(data);
}

void DeleteAllNodes(Node* root)
{
     if(root == NULL)
     {
          return;
     }

     DeleteAllNodes(root->left);
     DeleteAllNodes(root->right);

     delete root;
}

BST::~BST()
{
     DeleteAllNodes(root);
}

void BST::print2DUtil(int space)
{
     print2DUtilHelper(root, space);
}
