#include "RPNCalculator.hpp"

RPNCalculator::RPNCalculator()
{
     stackHead = NULL;
}

RPNCalculator::~RPNCalculator()
{
     Operand* toBeDeleted;

     //While their is more then one Operand
     while(stackHead->next !=NULL)
     {
          toBeDeleted = stackHead;
          stackHead = stackHead->next;
          delete toBeDeleted;
     }

     //Deletes the final Operand
     delete stackHead;
}

bool RPNCalculator::isEmpty()
{
     if(stackHead == NULL)
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
     if(isEmpty())
     {
          stackHead->number = num;
     }
     else
     {
          Operand* op = new Operand;
          op->number = num;
          op->next = stackHead;
          stackHead = op;
     }
}
