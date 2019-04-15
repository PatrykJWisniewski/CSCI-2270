#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "hash.hpp"

bool findThreeSum(int arr[])
{
     HashTable ht1(10);

     for(int i = 0; i<10; i++)
     {
          int twoSum = arr[i]*-1;
          for(int j = i+1; j<10; j++)
          {
               node* nodeAtIndex = ht1.searchItem(twoSum-arr[j]);
               if(nodeAtIndex != NULL)
               {
                    std::cout << "Index " << i << '\n';
                    std::cout << "Searching for " << twoSum << '\n';
                    std::cout << "Found 3 pair " << arr[i] << " " << twoSum-arr[j] << " " << arr[j] << '\n' << '\n';
                    return true;
               }

               ht1.insertItem(arr[j]);
          }
     }

     return false;
}

int main()
{
     int array[10] = {-1,0,4,10,1,2,5,3,-3,-2};

     if(findThreeSum(array))
     {
          std::cout << "True" << '\n';
     }
     else
     {
          std::cout << "False" << '\n';
     }
}
