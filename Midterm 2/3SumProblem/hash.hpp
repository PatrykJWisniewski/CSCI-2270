/*
Starter HPP File for Hash Tables.
DISCLAIMER: We recommend everyone to at least have these functions implemented properly.

For the exams the variable type might change form int to char / any other custom type.
You will also have extra functions which will be the main exam problems. These will just be added to this hpp file and it will be given to you during your exam
*/



#ifndef HASH_HPP
#define HASH_HPP


using namespace std;

// Struct for a linked list node
struct node
{
    int data; // data to be stored in the node
    struct node* next; // pointer to the next node
};

class HashTable
{
     private:
          int tableSize;
          node **hashTable;

          node* createNode(int key, node* next);
     public:
          HashTable(int bsize);
          ~HashTable();
          bool insertItem(int key);
          unsigned int hashFunction(int key);
          void printTable();
          node* searchItem(int key);
};

#endif
