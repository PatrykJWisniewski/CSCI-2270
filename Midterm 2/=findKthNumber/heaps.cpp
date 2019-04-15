#include "heaps.hpp"
#include <iostream>

Heap::Heap(int heapSize)
{
     currentSize = 0;
     this->heapSize = heapSize;
     heap = new int[heapSize];
}

Heap::~Heap()
{
     delete[] heap;
}

void Heap::printHeap()
{
     int iter = 0;
     while(iter < currentSize)
     {
          std::cout<<heap[iter]<<" ";
          iter = iter + 1;
     }
     std::cout<<'\n';
}

void Heap::addToHeap(int value)
{
     if(currentSize == heapSize)
     {
          std::cout << "Heap full, cannot enqueue" << '\n';
          return;
     }

     heap[currentSize] = value;
     currentSize++;

     repairUpward(currentSize-1);
}

int Heap::removeFromHeap()
{
     if(currentSize == 0)
     {
          std::cout << "Heap empty, cannot dequeue" << '\n';
     }

     heap[0] = heap[currentSize-1];
     currentSize--;

     repairDownward(0);
}

int Heap::peekValue()
{
     if(currentSize == 0)
     {
          std::cout << "Heap empty, nothing to peek" << '\n';
     }

     return heap[0];
}

bool Heap::isFull()
{
     if(currentSize == heapSize)
     {
          return true;
     }
     else
     {
          return false;
     }
}

bool Heap::isEmpty()
{
     if(currentSize == 0)
     {
          return true;
     }
     else
     {
          return false;
     }
}

int Heap::parent(int nodeIndex)
{
     return (nodeIndex-1)/2;
}

int Heap::leftChild(int nodeIndex)
{
     return (nodeIndex*2)+1;
}

int Heap::rightChild(int nodeIndex)
{
     return (nodeIndex*2)+2;
}

void swap(int *a, int *b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}

void Heap::repairUpward(int nodeIndex)
{
     while (nodeIndex != 0 && heap[parent(nodeIndex)] > heap[nodeIndex])
     {
          swap(&heap[nodeIndex], &heap[parent(nodeIndex)]);
          nodeIndex = parent(nodeIndex);
     }
}

void Heap::repairDownward(int nodeIndex)
{
     int l = leftChild(nodeIndex);
     int r = rightChild(nodeIndex);
     int smallest = nodeIndex;

     if(l < currentSize && heap[l] < heap[nodeIndex])
     {
          smallest = l;
     }
     if(r < currentSize && heap[r] < heap[smallest])
     {
          smallest = r;
     }
     if(smallest !=nodeIndex)
     {
          swap(&heap[nodeIndex], &heap[smallest]);
          repairDownward(smallest);
    }
}
