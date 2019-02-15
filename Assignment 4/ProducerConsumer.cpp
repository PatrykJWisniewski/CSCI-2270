#include "ProducerConsumer.hpp"
#include <iostream>

ProducerConsumer::ProducerConsumer()
{
     queueFront = -1;
     queueEnd = -1;
}

bool ProducerConsumer::isEmpty()
{
     //If there is nothing in the queue
     if(queueFront == -1 && queueEnd == -1)
     {
          return true;
     }
     else
     {
          return false;
     }
}

bool ProducerConsumer::isFull()
{
     //If the queue has 20 items in it
     if((queueEnd+1)%SIZE == queueFront)
     {
          return true;
     }
     else
     {
          return false;
     }
}

void ProducerConsumer::enqueue(std::string item)
{
     //If the queue is empty...
     if(isEmpty())
     {
          //Set the first element of the queue
          queueEnd++;
          queueFront++;

          queue[queueEnd] = item;
     }
     //If it is not empty and not full...
     else if(!isFull())
     {
          //Add the element too the queue
          queueEnd++;
          queue[queueEnd] = item;
     }
     //If the queue is full...
     else
     {
          std::cout << "Queue full, cannot add new item" << '\n';
     }
}

void ProducerConsumer::dequeue()
{
     //If the queue is empty...
     if(isEmpty())
     {
          std::cout << "Queue empty, cannot dequeue an item" << '\n';
     }
     //If the queue is not empty...
     else
     {
          //Remove items from the front of thbe queue
          queueFront++;
     }

     //If the queue is empty then reset the queue start and end too negetive 1
     if(queueFront > queueEnd)
     {
          queueEnd = -1;
          queueFront = -1;
     }
}

int ProducerConsumer::queueSize()
{
     //If the queue is empty then return 0
     if(isEmpty())
     {
          return 0;
     }
     //If the queue is not empty...
     else
     {
          return (queueEnd - queueFront+1);
     }
}

std::string ProducerConsumer::peek()
{
     //If the queue is empty...
     if(isEmpty())
     {
          std::cout << "Queue empty, cannot peek" << '\n';
          return "";
     }
     //If no then return the value
     else
     {
          return queue[queueFront];
     }
}
