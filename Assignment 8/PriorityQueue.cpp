#include <iostream>
#include "PriorityQueue.hpp"

PriorityQueue::PriorityQueue(int queueSize)
{
     maxQueueSize = queueSize;
     currentQueueSize = 0;
     priorityQueue = new GroupNode[maxQueueSize];
}

PriorityQueue::~PriorityQueue()
{
     delete[] priorityQueue;
}

void PriorityQueue::enqueue(std::string _groupName, int _groupSize, int _cookingTime)
{
     if(currentQueueSize == maxQueueSize)
     {
          std::cout << "Heap full, cannot enqueue" << '\n';
          return;
     }

     GroupNode newGroupNode;
     newGroupNode.groupName = _groupName;
     newGroupNode.groupSize = _groupSize;
     newGroupNode.cookingTime = _cookingTime;

     priorityQueue[currentQueueSize] = newGroupNode;
     currentQueueSize++;

     repairUpward(currentQueueSize-1);
}

void PriorityQueue::dequeue()
{
     if(currentQueueSize == 0)
     {
          std::cout << "Heap empty, cannot dequeue" << '\n';
     }

     priorityQueue[0] = priorityQueue[currentQueueSize-1];
     currentQueueSize--;

     repairDownward(0);
}

GroupNode PriorityQueue::peek()
{
     if(currentQueueSize == 0)
     {
          std::cout << "Heap empty, nothing to peek" << '\n';
     }

     return priorityQueue[0];
}

bool PriorityQueue::isFull()
{
     if(currentQueueSize == maxQueueSize)
     {
          return true;
     }
     else
     {
          return false;
     }
}

bool PriorityQueue::isEmpty()
{
     if(currentQueueSize == 0)
     {
          return true;
     }
     else
     {
          return false;
     }
}

void PriorityQueue::repairUpward(int nodeIndex)
{
     bool swap;

     do
     {
          if(priorityQueue[nodeIndex].groupSize < priorityQueue[(nodeIndex-1)/2].groupSize)
          {
               swap = true;
          }
          else if(priorityQueue[nodeIndex].groupSize == priorityQueue[(nodeIndex-1)/2].groupSize)
          {
               if(priorityQueue[nodeIndex].cookingTime < priorityQueue[(nodeIndex-1)/2].cookingTime)
               {
                    swap = true;
               }
               else
               {
                    swap = false;
               }
          }
          else
          {
               swap = false;
          }

          if(swap)
          {
               GroupNode tempNode = priorityQueue[(nodeIndex-1)/2];
               priorityQueue[(nodeIndex-1)/2] = priorityQueue[nodeIndex];
               priorityQueue[nodeIndex] = tempNode;
               nodeIndex = (nodeIndex-1)/2;
          }

          if(nodeIndex == 0)
          {
               return;
          }
     }
     while(swap);
}

void PriorityQueue::repairDownward(int nodeIndex)
{
     bool swap;
     int indexToSwapAt;

     do
     {
          //Checks to see if the next node to check is outside the queue size
          if(nodeIndex*2+1 >= currentQueueSize)
          {
               return;
          }

          if(priorityQueue[nodeIndex*2+1].groupSize == priorityQueue[nodeIndex].groupSize)
          {
               if(priorityQueue[nodeIndex*2+1].cookingTime < priorityQueue[nodeIndex].cookingTime)
               {
                    swap = true;
                    indexToSwapAt = nodeIndex*2+1;
               }
          }
          else if(priorityQueue[nodeIndex*2+1].groupSize < priorityQueue[nodeIndex].groupSize)
          {
               swap = true;
               indexToSwapAt = nodeIndex*2+1;
          }

          if(priorityQueue[nodeIndex*2+2].groupSize == priorityQueue[nodeIndex*2+1].groupSize)
          {
               if(priorityQueue[nodeIndex*2+2].cookingTime < priorityQueue[nodeIndex*2+1].cookingTime)
               {
                    swap = true;
                    indexToSwapAt = nodeIndex*2+2;
               }
          }
          else if(priorityQueue[nodeIndex*2+2].groupSize < priorityQueue[nodeIndex*2+1].groupSize)
          {
               swap = true;
               indexToSwapAt = nodeIndex*2+2;
          }

          if(nodeIndex == indexToSwapAt)
          {
               swap = false;
          }

          if(swap)
          {
               GroupNode tempNode = priorityQueue[indexToSwapAt];
               priorityQueue[indexToSwapAt] = priorityQueue[nodeIndex];
               priorityQueue[nodeIndex] = tempNode;
               nodeIndex = indexToSwapAt;
          }
     }
     while(swap);
}
