#include "RPNCalculator.hpp"
#include <iostream>

RPNCalculator::RPNCalculator()
{
     stackHead = NULL;
}

RPNCalculator::~RPNCalculator()
{
     Operand* toBeDeleted;

     if(stackHead == NULL)
     {
          return;
     }

     //While their is more then one Operand
     while(stackHead->next != nullptr)
     {
          toBeDeleted = stackHead;
          //std::cout << "Del" << stackHead->number << '\n';
          stackHead = stackHead->next;
          delete toBeDeleted;
     }

     //Deletes the final Operand
     //std::cout << "Del" << stackHead->number << '\n';
     delete stackHead;
}

bool RPNCalculator::isEmpty()
{
     if(stackHead == nullptr)
     {
          return true;
     }
     else
     {
          return false;
     }
}

void RPNCalculator::push(float num)
{
     //If there is nothing in the stack...
     if(isEmpty())
     {
          //Create the first head
          Operand* op = new Operand;
          op->number = num;
          op->next = nullptr;
          stackHead = op;
     }
     //If there are already elements...
     else
     {
          //Make the new elelment the head
          Operand* op = new Operand;
          op->number = num;
          op->next = stackHead;
          stackHead = op;
     }

     //std::cout << stackHead->number << '\n';
}

void RPNCalculator::pop()
{
     //If the stack is empty...
     if(isEmpty())
     {
          std::cout << "Stack empty, cannot pop an item." << '\n';
     }
     //If the stack is not empty...
     else
     {
          //Remove the head and make the next item be the head
          Operand* temp = stackHead;
          stackHead = stackHead->next;
          delete temp;
     }
}

Operand* RPNCalculator::peek()
{
     if(isEmpty())
     {
          std::cout << "Stack empty, cannot peek." << '\n';
          return NULL;
     }
     else
     {
          return stackHead;
     }
}

bool RPNCalculator::compute(std::string symbol)
{
     float computedValue = 0;

     //If the user did not input the correct symbol...
     if(symbol != "*" && symbol != "+")
     {
          std::cout << "err: invalid operation" << '\n';
          return false;
     }

     //If the stack is empty...
     if(isEmpty())
     {
          std::cout << "err: not enough operands" << '\n';
     }
     //If the stack is not empty...
     else
     {
          //Remove it and add it too the computedValue
          computedValue = stackHead->number;
          pop();

          //If the stack is empty after poping the first element
          if(isEmpty())
          {
               std::cout << "err: not enough operands" << '\n';
               push(computedValue);
          }
          //If the stack is not empty
          else
          {
               //Add them
               if(symbol == "+")
               {
                    computedValue += stackHead->number;
                    pop();
               }
               //Multiply them
               else if(symbol == "*")
               {
                    computedValue *= stackHead->number;
                    pop();
               }
          }

     }
     push(computedValue); //Push the final value back too the stack
}
