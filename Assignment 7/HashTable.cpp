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

void HashTable::printTopN(int n)
{
     int totalNumberOfWords = getTotalNumWords();

     int topWordsCount[n];
     std::string topWords[n];
     for(int i=0;i<n;i++)
     {
          topWordsCount[i] = 0;
     }

     wordItem* wordAtIndex;

     //For the first emement of the high frequency arrays since they dont need to be copared too the last element
     for(int i = 0; i<hashTableSize; i++)
     {
          //Checks if the head of the list excists
          if(hashTable[i] != nullptr)
          {
               wordAtIndex = hashTable[i];
               while(wordAtIndex->next != NULL)
               {
                    //If this word has been counted the most, but less then the last biggest word...
                    if(wordAtIndex->count > topWordsCount[0])
                    {
                         topWords[0] = wordAtIndex->word;
                         topWordsCount[0] = wordAtIndex->count;
                    }
                    wordAtIndex = wordAtIndex->next;
               }

               //Checks the last word in the linked list
               if(wordAtIndex->count > topWordsCount[0])
               {
                    topWords[0] = wordAtIndex->word;
                    topWordsCount[0] = wordAtIndex->count;
               }
          }
     }

     //Serches the hashtable n amount of times for high frequency words
     for(int a = 1; a<n; a++)
     {
          //For each linked list head...
          for(int i = 0; i<hashTableSize; i++)
          {
               //Checks if the head of the list excists
               if(hashTable[i] != nullptr)
               {
                    wordAtIndex = hashTable[i];
                    while(wordAtIndex->next != NULL)
                    {
                         //If this word has been counted the most, but less then the last biggest word...
                         if(wordAtIndex->count > topWordsCount[a] && wordAtIndex->count < topWordsCount[a-1])
                         {
                              topWords[a] = wordAtIndex->word;
                              topWordsCount[a] = wordAtIndex->count;
                         }
                         wordAtIndex = wordAtIndex->next;
                    }

                    //Checks the last word in the linked list
                    if(wordAtIndex->count > topWordsCount[a] && wordAtIndex->count < topWordsCount[a-1])
                    {
                         topWords[a] = wordAtIndex->word;
                         topWordsCount[a] = wordAtIndex->count;
                    }
               }
          }
     }

     for(int i=0; i<n; i++)
     {
          std::cout << std::fixed << std::setprecision(4) << (float)topWordsCount[i]/totalNumberOfWords << " - " << topWords[i] << '\n';
     }
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
