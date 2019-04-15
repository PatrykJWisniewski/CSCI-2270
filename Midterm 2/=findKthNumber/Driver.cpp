#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "heaps.hpp"

float findKthNumber(int arr[], Heap &h)
{
     for(int i=0; i<4; i++)
     {
          if(arr[i] < 0)
          {
               arr[i] = arr[i]*-1;
          }
          h.addToHeap(arr[i]);
     }

     h.printHeap();

     std::cout << h.peekValue() << '\n';

     h.removeFromHeap();

     h.printHeap();

     std::cout << h.peekValue() << '\n';
}

int main()
{
     int arr[4] = {5, 6, -17, 25};
     Heap heap(4);

     findKthNumber(arr, heap);
}
