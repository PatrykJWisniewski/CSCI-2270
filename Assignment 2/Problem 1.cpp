#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

struct wordItem
{
     std::string word;
     int count = 0;
};

//Reads all the words to be ignored from a file
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

//Checks if the word should be ignored
bool isStopWord(std::string word, std::string ignoreWords[])
{
     //Cheacks if the word should be ignored
     for(int i = 0; i<50; i++)
     {
          if(word == ignoreWords[i])
          {
               return true;
          }
     }

     return false;
}

//Gets the total amount of words that where not ignored in the file
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
     int numOfWords = 0;

     //Adds all the words from the array of wordItems
     for(int i = 0; i<length; i++)
     {
          numOfWords += uniqueWords[i].count;
     }

     return numOfWords;
}

//Sorts the array from greatest amount of words too least
void arraySort(wordItem uniqueWords[], int length)
{
     wordItem temp;
     int largeIndex;

     //Runs once for each element in the array
     for(int i = 0; i<length ; i++)
     {
          temp.count = 0;

          //ignored the correctly sorted elemts at the top
          for(int j = i; j<length; j++)
          {
               if(uniqueWords[j].count > temp.count)
               {
                    temp = uniqueWords[j];
                    largeIndex = j;
               }
          }

          //Swap the elements
          uniqueWords[largeIndex] = uniqueWords[i];
          uniqueWords[i] = temp;
     }
}

void printTopN(wordItem uniqueWords[], int topN, int totalNumWords)
{
     for(int i = 0; i < topN; i++)
     {
          float prop = (float)uniqueWords[i].count / totalNumWords;
          std::cout << std::fixed << std::setprecision(4) << prop << " - " << uniqueWords[i].word << '\n';
     }
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
          //Reads each word in the line
          while (file >> word)
          {
               //If the word should not be ignored...
               if(!isStopWord(word, ignoreWords))
               {
                    bool foundMatch = false;

                    //Checks if the word is already in the data base
                    for(int i = 0; i<uniqueWordsLength; i++)
                    {
                         //If the word is in the data base...
                         if(word == uniqueWords[i].word)
                         {
                              uniqueWords[i].count++; //Add one too the word count
                              foundMatch = true;
                              i = uniqueWordsLength+1; //Makes the forloop stop running
                         }
                    }

                    //If the word is not in the data base then add it too the data base
                    if(!foundMatch)
                    {
                         uniqueWords[index].word = word;
                         uniqueWords[index].count = 1;
                         index++;
                    }
               }

               //If the array has reached it's max size then double the array
               if(index == uniqueWordsLength)
               {
                    wordItem *newUniqueWords = new wordItem[uniqueWordsLength*2];
                    //Copys the old array too the new array
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
     //If the file was not opened
     else
     {
          std::cout << "Failed to open " << argv[2] << '\n';
     }
     int totalWords = getTotalNumberNonStopWords(uniqueWords, index);

     arraySort(uniqueWords, index);

     std::cout << "Array doubled: " << timesDoubled << '\n';
     std::cout << "#" << '\n';
     std::cout << "Unique non-common words: " << index << '\n';
     std::cout << "#" << '\n';
     std::cout << "Total non-common words: " << totalWords << '\n';
     std::cout << "#" << '\n';
     std::cout << "Probabilities of top " << std::stoi(argv[1]) << " most frequent words" << '\n';
     std::cout << "---------------------------------------" << '\n';

     printTopN(uniqueWords, std::stoi(argv[1]), totalWords);
}
