#include <iostream>

struct Node
{
     int key;
     Node* next;
};

Node *deleteNegatives(Node *head)
{
     Node* p = head;

     if(p->key < 0)
     {
          Node* toBeDeleated = p;
          head = p->next;
          delete toBeDeleated;
          p = head->next;
     }

     while(p->next != NULL)
     {
          if((p->next)->key < 0)
          {
               Node* toBeDeleated = p->next;
               p->next = (p->next)->next;
               delete toBeDeleated;
          }
          else
          {
               p = p->next;
          }
     }

     if(p->key < 0)
     {
          delete p;
     }

     return head;
}

int main()
{
     Node* head = NULL;
     Node* prev = NULL;

     //Test case 1
     /*
     Node* head = new Node;
     Node* two = new Node;
     Node* three = new Node;
     Node* four = new Node;

     head->key = 3;
     head->next = two;
     two->key = 434;
     two->next = three;
     three->key = 44597345;
     three->next = four;
     four->key = 4;
     four->next = NULL;

     head = deleteNegatives(head);

     while(head->next != NULL)
     {
          std::cout << head->key << '\n';
          head = head->next;
     }

     std::cout << head->key << '\n';
     */

     for(int i=0; i<1234; i++)
     {
          Node* newNode = new Node;

          if(i == 0)
          {
               newNode->key = 0;
               newNode->next = NULL;
               head = newNode;
               prev = newNode;
          }
          else if(i%2 == 1)
          {
               newNode->key = i;
               newNode->next = NULL;
               prev->next = newNode;
               prev = newNode;
          }
          else
          {
               newNode->key = -i;
               newNode->next = NULL;
               prev->next = newNode;
               prev = newNode;
          }
     }

     head = deleteNegatives(head);

     while(head->next != NULL)
     {
          std::cout << head->key << '\n';
          head = head->next;
     }

     std::cout << head->key << '\n';
}
