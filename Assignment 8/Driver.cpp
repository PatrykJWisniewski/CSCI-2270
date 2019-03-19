#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "PriorityQueue.hpp"

void PrintMenu()
{
     std::cout << "============Main Menu============" << '\n';
     std::cout << "1. Get group information from file" << '\n';
     std::cout << "2. Add a group to Priority Queue" << '\n';
     std::cout << "3. Show next group in the queue" << '\n';
     std::cout << "4. Serve Next group" << '\n';
     std::cout << "5. Serve Entire Queue" << '\n';
     std::cout << "6. Quit" << '\n';
}

int main(int argc, char const *argv[])
{
     PriorityQueue foodQueue(std::stoi(argv[1]));
     GroupNode newNode;

     char menuInput;
     std::string stringInput;
     std::ifstream data;
     std::string line;

     do
     {
          PrintMenu();
          std::cin >> menuInput;

          switch(menuInput)
          {
               case '1':
                    std::cout << "Enter filename:" << '\n';
                    std::cin >> stringInput;

                    data.open(stringInput);
                    //For each line row in the file fill out the user information based off the cell information
                    while(std::getline(data,line))
                    {
                         std::stringstream ss;
                         ss<<line;
                         std::string cell;

                         std::getline(ss,cell,' ');
                         newNode.groupName = cell;

                         std::getline(ss,cell,' ');
                         newNode.groupSize = std::stoi(cell);

                         std::getline(ss,cell);
                         newNode.cookingTime = std::stoi(cell);

                         if(foodQueue.isFull())
                         {
                              std::cout << "Heap full, cannot enqueue" << '\n';
                              break;
                         }

                         foodQueue.enqueue(newNode.groupName, newNode.groupSize, newNode.cookingTime);
                    }
                    break;

               case '2':
                    if(foodQueue.isFull())
                    {
                         std::cout << "Heap full, cannot enqueue" << '\n';
                         break;
                    }

                    std::cout << "Enter Group Name:" << '\n';
                    std::cin >> stringInput;
                    newNode.groupName = stringInput;

                    std::cout << "Enter Group Size:" << '\n';
                    std::cin >> stringInput;
                    newNode.groupSize = std::stoi(stringInput);

                    std::cout << "Enter Estimated Cooking Time:" << '\n';
                    std::cin >> stringInput;
                    newNode.cookingTime = std::stoi(stringInput);

                    foodQueue.enqueue(newNode.groupName, newNode.groupSize, newNode.cookingTime);

                    break;

               case '3':
                    if(foodQueue.isEmpty())
                    {
                         std::cout << "Heap empty, nothing to peek" << '\n';
                         break;
                    }

                    std::cout << "Group Name: " << foodQueue.peek().groupName << '\n';
                    std::cout << "Group Size: " << foodQueue.peek().groupSize << '\n';
                    std::cout << "Group Time: " << foodQueue.peek().cookingTime << '\n';

                    break;

               case '4':
                    if(foodQueue.isEmpty())
                    {
                         std::cout << "Heap empty, cannot dequeue" << '\n';
                         break;
                    }

                    std::cout << "Group Name: " << foodQueue.peek().groupName << " - Total Cook Time for the Group: " << foodQueue.peek().cookingTime << '\n';
                    foodQueue.dequeue();
                    break;

               case '5':
                    if(foodQueue.isEmpty())
                    {
                         std::cout << "Heap empty, cannot dequeue" << '\n';
                         break;
                    }

                    while(!foodQueue.isEmpty())
                    {
                         std::cout << "Group Name: " << foodQueue.peek().groupName << "  - Total Cook Time for the Group: " << foodQueue.peek().cookingTime << '\n';
                         foodQueue.dequeue();
                    }
                    break;

               case '6':
                    std::cout << "Goodbye!" << '\n';
                    break;

               default:
                    std::cout << "Eneter Valid option" << '\n';
                    break;
          }
     }
     while(menuInput != '6');

     return 0;
}
