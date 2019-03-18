#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "HashTable.hpp"

/* size to make your stopwords hash table */
const int STOPWORD_TABLE_SIZE = 50;

/* load stopwords into the stopwords hash table */
void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable)
{
     //Creates a varaible for the file and line and opens it
     std::ifstream file;
     std::string line;
     file.open(ignoreWordFileName);

     //If the file was opened...
     if(file.is_open())
     {
          //Reads throuth every single line in the file
          while(std::getline(file, line))
          {
               stopWordsTable.addWord(line);
          }
     }
     //If the file was not opened
     else
     {
          std::cout << "Failed to open " << ignoreWordFileName << '\n';
     }
}

/* check table to see if a word is a stopword or not */
bool isStopWord(std::string word, HashTable &stopWordsTable)
{
     return stopWordsTable.isInTable(word);
}

// [1] Number of common words to print
// [2] Name of text file to process
// [3] Name of stopwords file
// [4] Size of hash table
int main(int argc, char *argv[])
{
     HashTable stopWordsTable(STOPWORD_TABLE_SIZE);
     HashTable uniqueWordsTable(std::stoi(argv[4]));

     getStopWords(argv[3], stopWordsTable);

     //Creates a varaible for the file and line and opens it
     std::ifstream file;
     std::string word;
     file.open(argv[2]);
     //If the file was opened...
     if(file.is_open())
     {
          //Reads each word in the line
          while (file >> word)
          {
               //If the word should not be ignored...
               if(!isStopWord(word, stopWordsTable))
               {
                    if(uniqueWordsTable.isInTable(word))
                    {
                         uniqueWordsTable.incrementCount(word);
                    }
                    else
                    {
                         uniqueWordsTable.addWord(word);
                    }
               }
          }
     }
     //If the file was not opened
     else
     {
          std::cout << "Failed to open " << argv[2] << '\n';
     }

     uniqueWordsTable.printTopN(std::stoi(argv[1]));
     std::cout << "#" << '\n';
     std::cout << "Number of collisions: " << uniqueWordsTable.getNumCollisions() << '\n';
     std::cout << "#" << '\n';
     std::cout << "Unique non-stop words: " << uniqueWordsTable.getNumItems() << '\n';
     std::cout << "#" << '\n';
     std::cout << "Total non-stop words: " << uniqueWordsTable.getTotalNumWords() << '\n';

     return 0;
}
