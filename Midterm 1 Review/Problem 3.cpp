#include <iostream>
#include <string>

int push(int n, int arrayOfInts[], int arrayLength, int maxSize)
{
     arrayOfInts[arrayLength] = n;
     arrayLength++;
     return arrayLength;
}

int pop(int arrayOfInts[], int arrayLength, int maxSize)
{
     return arrayLength-1;
}

void print(int arrayOfInts[], int arrayLength)
{
     for(int i = 0; i<arrayLength; i++)
     {
          std::cout << arrayOfInts[i] << '\n';
     }
}

int main()
{
     int* ints = new int[5];
     int currentSize = 0;
     int intsLength = 5;
     std::string input;

     std::cout << "1=push 2=pop 3=print" << '\n';
     std::cin >> input;

     while(input == "1" || input == "2" || input == "3")
     {
          if(input == "1")
          {
               if(currentSize+1 > intsLength)
               {
                    std::cout << "array doubled" << '\n';
                    int* newInts = new int[intsLength*2];
                    for(int i = 0; i<intsLength; i++)
                    {
                         newInts[i] = ints[i];
                    }
                    delete[] ints;
                    ints = newInts;
                    intsLength *= 2;
               }

               std::cout << "enter number" << '\n';
               std::cin >> input;
               currentSize = push(stoi(input), ints, currentSize, intsLength);

               std::cout << "the current size is" << currentSize << '\n';
          }
          else if(input == "2")
          {
               currentSize = pop(ints, currentSize, intsLength);

               std::cout << "the current size is" << currentSize << '\n';

               if(currentSize == intsLength/2 && currentSize > 4)
               {
                    std::cout << "array halved" << '\n';
                    int* newInts = new int[intsLength/2];
                    for(int i = 0; i<intsLength; i++)
                    {
                         newInts[i] = ints[i];
                    }
                    delete[] ints;
                    ints = newInts;
                    intsLength /= 2;
               }
          }
          else if(input == "3")
          {
               std::cout << '\n';
               print(ints, currentSize);
          }

          std::cout << '\n';
          std::cout << "1=push 2=pop 3=print" << '\n';
          std::cin >> input;
     }
}
