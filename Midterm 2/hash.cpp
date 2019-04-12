#include "hash.hpp"
#include <iostream>

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->data = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
     this->tableSize = bsize;
     hashTable = new node*[tableSize];

     for(int i=0;i<bsize;i++)
     {
         hashTable[i] = nullptr;
     }
}

HashTable::~HashTable()
{
     node* nodeAtIndex;
     node* toDelete;

     for(int i = 0; i<tableSize; i++)
     {
          //Checks if the head of the list excists
          if(hashTable[i] != nullptr)
          {
               nodeAtIndex = hashTable[i];
               //Deletes the entire linked list
               while(nodeAtIndex->next != NULL)
               {
                    toDelete = nodeAtIndex;
                    nodeAtIndex = nodeAtIndex->next;
                    delete toDelete;
               }

               //Deletes the last element
               delete nodeAtIndex;
          }
     }

     delete[] hashTable;
}

bool HashTable::insertItem(int key)
{
     int index = hashFunction(key);

     node* newNode = new node();
     newNode->data = key;
     newNode->next = NULL;

     //If the head at the index is empty...
     if(hashTable[index] == nullptr)
     {
          //Make this word item the head
          hashTable[index] = newNode;
     }
     else
     {
          //Make the new word item the head and push everything else back
          newNode->next = hashTable[index];
          hashTable[index] = newNode;
     }
}

unsigned int HashTable::hashFunction(int key)
{
     return (key % tableSize);
}

void HashTable::printTable()
{
     for (int i = 0; i < tableSize; i++)
     {
         cout << i <<"|| ";

         if(hashTable[i] == nullptr)
         {
              std::cout << '\n';
         }
         else
         {
              node* nodeAtIndex = hashTable[i];

              while(nodeAtIndex->next != NULL)
              {
                   std::cout << nodeAtIndex->data << ", ";
                   nodeAtIndex = nodeAtIndex->next;
              }

              std::cout << nodeAtIndex->data << '\n';
         }
     }
}

node* HashTable::searchItem(int key)
{
     //Compute the index by using the hash function
     int index = hashFunction(key);

     node* nodeAtIndex;
     if(hashTable[index] == nullptr)
     {
         return NULL;
     }
     else
     {
         nodeAtIndex = hashTable[index];
     }

     while(nodeAtIndex->next != NULL)
     {
         if(nodeAtIndex->data == key)
         {
               return nodeAtIndex;
         }
         else
         {
               nodeAtIndex = nodeAtIndex->next;
         }
     }

     if(nodeAtIndex->data == key)
     {
         return nodeAtIndex;
     }
     else
     {
         return NULL;
     }
}
