#include <iostream>
#include <string>
#include <iomanip>

struct Node
{
     int key;
     Node* next;
};

int sumEvens(Node *head) // example declaration
{
     Node* temp = head;
     int Count = 0;

     if(head == NULL)
     {
          return 0;
     }

     while(temp->next != NULL)
     {
          //std::cout << temp->key << '\n';
          if(temp->key%2 == 0)
          {
               Count += temp->key;
          }
          temp = temp->next;
     }

     if(temp->key%2 == 0)
     {
          Count += temp->key;
     }

     return Count;
}

int main()
{
     Node* head = NULL;
     Node* prev = NULL;

     //The sum of this should be 20
     for(int i=0; i<10; i++) //Change i<1000 for testing
     {
          Node* newNode = new Node;

          if(i == 0)
          {
               newNode->key = 0; //Change this value for testing
               newNode->next = NULL;
               head = newNode;
               prev = newNode;
          }
          else
          {
               newNode->key = 2; //Change thie value for testing
               newNode->next = NULL;
               prev->next = newNode;
               prev = newNode;
          }
     }

     std::cout << sumEvens(head) << '\n';
}
