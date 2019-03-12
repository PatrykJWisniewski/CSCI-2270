// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //TODO: Search the list at that specific index and return the node if found
    node* nodeAtIndex;
    if(table[index] == nullptr)
    {
         return NULL;
    }
    else
    {
         nodeAtIndex = table[index];
    }

    while(nodeAtIndex->next != NULL)
    {
         if(nodeAtIndex->key == key)
         {
              return nodeAtIndex;
         }
         else
         {
              nodeAtIndex = nodeAtIndex->next;
         }
    }

    if(nodeAtIndex->key == key)
    {
         return nodeAtIndex;
    }
    else
    {
         return NULL;
    }
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        int index = hashFunction(key);
        node* newNode = createNode(key, NULL);
        if(table[index] == nullptr)
        {
             table[index] = newNode;
        }
        else
        {
             newNode->next = table[index];
             table[index] = newNode;
        }
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << i <<"|| ";

        if(table[i] == nullptr)
        {
             std::cout << '\n';
        }
        else
        {
             node* nodeAtIndex = table[i];

             while(nodeAtIndex->next != NULL)
             {
                  std::cout << nodeAtIndex->key << ", ";
                  nodeAtIndex = nodeAtIndex->next;
             }

             std::cout << nodeAtIndex->key << '\n';
        }
    }

 }
