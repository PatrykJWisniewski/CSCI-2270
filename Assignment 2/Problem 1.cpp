#include <iostream>
#include <string>
#include <fstream>

struct wordItem
{
     std::string word;
     int count = 0;
};

void getStopWords(const char *ignoreWordsfilename, std::string ignoreWords[])
{
     //Creates a varaible for the file and line and opens it
     std::ifstream file;
     std::string line;
     file.open(ignoreWordsfilename);

     //If the file was opened...
     if(file.is_open())
     {
          int i = 0;
          //Reads throuth every single line in the file
          while(std::getline(file, line))
          {
               ignoreWords[i] = line;
               i++;
          }
     }
     //If the file was not opened
     else
     {
          std::cout << "Failed to open " << ignoreWordsfilename << '\n';
     }
}

bool isStopWord(std::string word, std::string ignoreWords[])
{
     for(int i = 0; i<50; i++)
     {
          if(word == ignoreWords[i])
          {
               return true;
          }
     }
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
     int numOfWords;

     for(int i = 0; i<length; i++)
     {
          numOfWords += uniqueWords[i].count;
     }

     return numOfWords;
}

void arraySort(wordItem uniqueWords[], int length)
{
     wordItem temp;
}

int main(int argc, char *argv[])
{
     std::string ignoreWords[50];

     if(argv[3] == NULL || argv[4] != NULL)
     {
          std::cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << '\n';
          return 0;
     }

     getStopWords(argv[3], ignoreWords);

     wordItem *uniqueWords = new wordItem[100];
     int uniqueWordsLength = 100;
     int index = 0;
     int timesDoubled = 0;
     //Creates a varaible for the file and line and opens it
     std::ifstream file;
     std::string word;
     file.open(argv[2]);

     //If the file was opened...
     if(file.is_open())
     {
          while (file >> word)
          {
               if(!isStopWord(word, ignoreWords))
               {
                    bool foundMatch = false;

                    for(int i = 0; i<uniqueWordsLength; i++)
                    {
                         if(word == uniqueWords[i].word)
                         {
                              uniqueWords[i].count++;
                              foundMatch = true;
                         }
                    }

                    if(!foundMatch)
                    {
                         uniqueWords[index].word = word;
                         uniqueWords[index].count = 1;
                         index++;
                    }
               }

               if(index == uniqueWordsLength)
               {
                    wordItem *newUniqueWords = new wordItem[uniqueWordsLength*2];
                    for(int i = 0; i<uniqueWordsLength; i++)
                    {
                         newUniqueWords[i] = uniqueWords[i];
                    }
                    uniqueWordsLength *= 2;

                    delete[] uniqueWords;
                    uniqueWords = newUniqueWords;
                    timesDoubled++;
               }
          }
     }

     std::cout << uniqueWords[0].word << '\n';
     std::cout << uniqueWords[0].count << '\n';
     std::cout << timesDoubled << '\n';
}
