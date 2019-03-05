#include "MovieTree.hpp"
#include <iostream>

MovieTree::MovieTree()
{
     root = NULL;
}

void DeleteAllNodes(TreeNode* root)
{
     //If the root of the tree is not there.
     if(root == NULL)
     {
          return;
     }

     //Deletes all the tree nodes in post order
     DeleteAllNodes(root->leftChild);
     DeleteAllNodes(root->rightChild);

     //Deletes the linked list assosiated with the tree node
     LLMovieNode* temp = root->head;
     while(temp->next != NULL)
     {
          LLMovieNode* toDelete = temp;
          temp = temp->next;
          delete toDelete;
     }
     delete temp; //Deletes the last element of the linked list

     delete root; //Deletes the node itself
}

MovieTree::~MovieTree()
{
     DeleteAllNodes(root);
}

void PrintLinkedList(LLMovieNode* head)
{
     //Goes through each node in the linked list but the last one
     while(head->next != NULL)
     {
          std::cout << " >> " << head->title << " " << head->rating << '\n';
          head = head->next;
     }

     //Prints the last node
     std::cout << " >> " << head->title << " " << head->rating << '\n';
}

void PrintInOrder(TreeNode* root)
{
     if(root == NULL)
     {
          return;
     }

     PrintInOrder(root->leftChild);

     //Prints the linked list assosiated with this node
     std::cout << "Movies starting with letter: " << root->titleChar << '\n';
     PrintLinkedList(root->head);

     PrintInOrder(root->rightChild);
}

void MovieTree::printMovieInventory()
{
     PrintInOrder(root);
}

void AddToLinkedList(TreeNode* root, LLMovieNode* newNode)
{
     LLMovieNode* tempNode = root->head;

     //Checks if the new node comes before the current head
     if(newNode->title.compare((root->head)->title) < 0)
     {
          newNode->next = tempNode;
          root->head = newNode;
          return;
     }

     //Traverses the entire linked list to find the new nodes place
     while(tempNode->next != NULL)
     {
          if(newNode->title.compare((tempNode->next)->title) < 0)
          {
               newNode->next = tempNode->next;
               tempNode->next = newNode;
               return;
          }
          else
          {
               tempNode = tempNode->next;
          }
     }

     //If no node was found then it goes at the end of the linked list
     tempNode->next = newNode;
     return;
}

TreeNode* Insert(TreeNode* root, LLMovieNode* newNode)
{
     //If the root is not yet established...
     if(root == NULL)
     {
          TreeNode* tempNode = new TreeNode();
          //std::cout << "Adding " << newNode->title << '\n';
          tempNode->head = newNode;
          //std::cout << "Adding new head--------" << newNode->title[0] << '\n';
          tempNode->titleChar = newNode->title[0];
          root = tempNode;
     }
     //If the new movie starts with the same letter as this node
     else if(newNode->title[0] == root->titleChar)
     {
          //std::cout << "Adding " << newNode->title << '\n';
          AddToLinkedList(root, newNode);
     }
     //If the movie is alpbeticly before the root node
     else if(newNode->title[0] < (root->titleChar))
     {
          //std::cout << "left" << '\n';
          root->leftChild = Insert(root->leftChild, newNode);
          root->parent = root;
     }
     //If the movie is alpbeticly after the root node
     else
     {
          //std::cout << "right" << '\n';
          root->rightChild = Insert(root->rightChild, newNode);
          root->parent = root;
     }

     return root;
}

void MovieTree::addMovie(int ranking, std::string title, int year, float rating)
{
     LLMovieNode* newNode = new LLMovieNode(ranking, title, year, rating);
     root = Insert(root, newNode);
}


TreeNode* DeleteTreeNode(TreeNode* toDelete, std::string title)
{
     //If there is nothing to left to delete
     if(toDelete == NULL)
     {
          std::cout << "Movie: " << title << " not found, cannot delete." << '\n';
          return toDelete;
     }

     //Finds the right node to delete
     if(title[0] < toDelete->titleChar)
     {
          toDelete->leftChild = DeleteTreeNode(toDelete->leftChild, title);
          return toDelete;
     }
     else if(title[0] > toDelete->titleChar)
     {
          toDelete->rightChild = DeleteTreeNode(toDelete->rightChild, title);
          return toDelete;
     }

     //If this tree node still has a linked list in it
     if(toDelete->head != NULL)
     {
          LLMovieNode* p = toDelete->head;
          //Deletes the node inside a linked list
          if(p->title == title)
          {
               LLMovieNode* toBeDeleated = p;
               p = p->next;
               toDelete->head = p;
               delete toBeDeleated;
          }
          else
          {
               while(p->next != NULL && p != NULL)
               {
                    if((p->next)->title == title)
                    {
                         LLMovieNode* toBeDeleated = p->next;
                         p->next = (p->next)->next;
                         delete toBeDeleated;
                    }
                    else
                    {
                         p = p->next;
                    }
               }

               if(p->title == title && p != NULL)
               {
                    delete p;
               }
          }
     }

     //Checks to see if the tree node needs to be deleted
     if(toDelete->head != NULL)
     {
          return toDelete;
     }

     //If the tree node needs to be deleted.
     //If there is only one child...
     if(toDelete->leftChild == NULL)
     {
          TreeNode* temp = toDelete->rightChild;
          delete toDelete;
          return temp;
     }
     else if(toDelete->rightChild == NULL)
     {
          TreeNode* temp = toDelete->leftChild;
          delete toDelete;
          return temp;
     }
     //If there are two childen
     else
     {
          TreeNode* succParent = toDelete->rightChild;
          TreeNode* succ = toDelete->rightChild;

          while(succ->leftChild != NULL)
          {
               succParent = succ;
               succ = succ->leftChild;
          }

          //This may be the right code
          //toDelete->rightChild = deleteNode(toDelete->rightChild, succ->titleChar);
          succParent->leftChild = succ->rightChild;
          toDelete->head = succ->head;
          toDelete->titleChar = succ->titleChar;
          delete succ;
          return toDelete;
     }
}

void MovieTree::deleteMovie(std::string title)
{
     root = DeleteTreeNode(root, title);
}
