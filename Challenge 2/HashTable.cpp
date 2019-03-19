#include "HashTable.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

HashTable::HashTable(int hashTableSize)
{
     this->hashTableSize = hashTableSize;
     hashTable = new wordItem*[hashTableSize];

     for(int i=0;i<hashTableSize;i++)
     {
          hashTable[i] = nullptr;
     }

     numItems = 0;
     numCollisions = 0;
     treeRoot = NULL;
     wordsPrinted = 0;
}

HashTable::~HashTable()
{
     wordItem* wordAtIndex;
     wordItem* toDelete;

     for(int i = 0; i<hashTableSize; i++)
     {
          //Checks if the head of the list excists
          if(hashTable[i] != nullptr)
          {
               wordAtIndex = hashTable[i];
               //Deletes the entire linked list
               while(wordAtIndex->next != NULL)
               {
                    toDelete = wordAtIndex;
                    wordAtIndex = wordAtIndex->next;
                    delete toDelete;
               }

               //Deletes the last element
               delete wordAtIndex;
          }
     }

     delete[] hashTable;
}

void HashTable::addWord(std::string word)
{
     numItems++;
     int index = getHash(word);

     wordItem* newWordItem = new wordItem();
     newWordItem->word = word;
     newWordItem->count = 1;
     newWordItem->next = NULL;

     //If the head at the index is empty...
     if(hashTable[index] == nullptr)
     {
          //Make this word item the head
          hashTable[index] = newWordItem;
     }
     else
     {
          numCollisions++;
          //Make the new word item the head and push everything else back
          newWordItem->next = hashTable[index];
          hashTable[index] = newWordItem;
     }
}

bool HashTable::isInTable(std::string word)
{
     if(searchTable(word) == NULL)
     {
          return false;
     }
     else
     {
          return true;
     }
}

void HashTable::incrementCount(std::string word)
{
     wordItem* wordToIncrement = searchTable(word);

     wordToIncrement->count++;
}

wordItem* Insert(wordItem* root, wordItem* newNode)
{
     if(root == NULL)
     {
          root = newNode;
     }
     else if(newNode->count > root->count)
     {
          root->left = Insert(root->left, newNode);
     }
     else
     {
          root->right = Insert(root->right, newNode);
     }

     return root;
}

void HashTable::PrintInOrder(wordItem* root, int n, int totalNumberOfWords)
{
     if(root == NULL)
     {
          return;
     }

     PrintInOrder(root->left, n, totalNumberOfWords);

     if(wordsPrinted == n)
     {
          return;
     }

     //Prints the linked list assosiated with this node
     std::cout << std::fixed << std::setprecision(4) << (float)root->count/totalNumberOfWords << " - " << root->word << '\n';
     wordsPrinted++;

     PrintInOrder(root->right, n, totalNumberOfWords);
}

void HashTable::printTopN(int n)
{
     wordItem* wordAtIndex;

     for(int i = 0; i<hashTableSize; i++)
     {
          //Checks if the head of the list excists
          if(hashTable[i] != nullptr)
          {
               wordAtIndex = hashTable[i];
               while(wordAtIndex->next != NULL)
               {
                    treeRoot = Insert(treeRoot, wordAtIndex);
                    wordAtIndex = wordAtIndex->next;
               }

               treeRoot = Insert(treeRoot, wordAtIndex);
          }
     }

     PrintInOrder(treeRoot, n, getTotalNumWords());
}

int HashTable::getNumCollisions()
{
     return numCollisions;
}

int HashTable::getNumItems()
{
     return numItems;
}

int HashTable::getTotalNumWords()
{
     int totalNum = 0;
     wordItem* wordAtIndex;

     for(int i = 0; i<hashTableSize; i++)
     {
          //Checks if the head of the list excists
          if(hashTable[i] != nullptr)
          {
               wordAtIndex = hashTable[i];
               while(wordAtIndex->next != NULL)
               {
                    totalNum += wordAtIndex->count;
                    wordAtIndex = wordAtIndex->next;
               }

               totalNum += wordAtIndex->count;
          }
     }

     return totalNum;
}

unsigned int HashTable::getHash(std::string word)
{
     unsigned int hashValue = 5381;
     int length = word.length();

     for(int i=0; i<length; i++)
     {
          hashValue = ((hashValue<<5)+hashValue) + word[i];
     }

     hashValue %= hashTableSize;

     return hashValue;
}

wordItem* HashTable::searchTable(std::string word)
{
     int index = getHash(word);
     wordItem* wordAtIndex;

     //Checks if the head of the list excists
     if(hashTable[index] == nullptr)
     {
          return NULL;
     }
     else
     {
          wordAtIndex = hashTable[index];
     }

     //Travers the linked list lookinf for the word
     while(wordAtIndex->next != NULL)
     {
          if(wordAtIndex->word == word)
          {
               return wordAtIndex;
          }
          else
          {
               wordAtIndex = wordAtIndex->next;
          }
     }

     //Checks the last item in the linked list
     if(wordAtIndex->word == word)
     {
          return wordAtIndex;
     }
     else
     {
          return NULL;
     }
}
