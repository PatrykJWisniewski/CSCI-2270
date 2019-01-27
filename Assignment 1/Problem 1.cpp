#include <iostream>
#include <fstream>
#include <string>

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
     int sortedArray[100]; //Intilizes a new array to act as a temp holder for the sorted ints

     //If this is the first entry then set it as the first element
     if(numEntries == 0)
     {
          sortedArray[0] = newValue;
     }
     //If this is not the first entry...
     else
     {
          //For each entry in the array
          for(int i = 0; i<numEntries+1; i++)
          {
               int value = myArray[i]; //Find the value that we will be comparing too

               //If the value of the new entry is greater then the previous value in the array...
               if(newValue > value)
               {
                    sortedArray[i] = value; //Then just leave the old value at the same index
               }
               //If the value of the new entry is less the the previous value in the array...
               else
               {
                    sortedArray[i] = newValue; //Set the new entry at the current index we are comparing
                    i++;
                    //Move every int that is greater then the new entry down one slot in the array
                    for(i; i<numEntries+1; i++)
                    {
                         sortedArray[i] = myArray[i-1];
                    }
               }
          }
     }

     //Set the values of the orginal array that was passed into the function to be equal too the value of the sorted temp array
     for(int i = 0; i<numEntries+1; i++)
     {
          myArray[i] = sortedArray[i];
     }

     numEntries++;
     return numEntries;
}

//Main takes in a argument for the name of the file to be read
int main(int argc, char *argv[])
{
     //Intilizes the array of ints and sets them all to a high number
     int arrayOfInts[100];
     for(int a=0; a<100; a++)
     {
          arrayOfInts[a] = 100000;
     }
     int entries = 0;

     //Creates a varaible for the file and line and opens it
     std::ifstream file;
     std::string line;
     file.open(argv[1]);

     //If the file was opened...
     if(file.is_open())
     {
          //Reads throuth every single line in the file
          while(std::getline(file, line))
          {
               entries = insertIntoSortedArray(arrayOfInts, entries, stoi(line)); //Sorts the number on the line into the array
               //Prints out each number that is in the array now
               for(int i = 0; i<entries; i++)
               {
                    if(i < entries-1)
                    {
                         std::cout << arrayOfInts[i] << ",";
                    }
                    else
                    {
                         std::cout << arrayOfInts[i];
                    }
               }
               std::cout << '\n';
          }
     }
     //If the file was not opened
     else
     {
          std::cout << "Failed to open the file." << '\n';
     }
}
