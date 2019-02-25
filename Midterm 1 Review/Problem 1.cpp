#include <iostream>

struct Node
{
     int key;
     Node* next;
};

bool lengthIsEven(Node *head)
{
     Node* temp = head;
     int Count = 1;

     if(head == NULL)
     {
          return true;
     }

     while(temp->next != NULL)
     {
          //std::cout << temp->key << '\n';
          Count++;
          temp = temp->next;
     }

     if(Count%2 == 0)
     {
          return true;
     }
     else
     {
          return false;
     }
}

int main()
{
     Node* head = NULL;
     Node* prev = NULL;

     for(int i=0; i<0; i++)
     {
          Node* newNode = new Node;

          if(i == 0)
          {
               newNode->key = 0;
               newNode->next = NULL;
               head = newNode;
               prev = newNode;
          }
          else
          {
               newNode->key = i;
               newNode->next = NULL;
               prev->next = newNode;
               prev = newNode;
          }
     }

     if(lengthIsEven(head))
     {
          std::cout << "true" << '\n';
     }
     else
     {
          std::cout << "false" << '\n';
     }
}
