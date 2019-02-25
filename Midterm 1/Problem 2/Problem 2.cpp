#include <iostream>
#include <string>
#include <iomanip>

struct Node
{
     int key;
     Node* next;
};

void print(Node *head) // example declaration
{
     Node* p = head;

     //Checks if the head has been established yet
     if(p == NULL)
     {
          std::cout << "This linked list is not established" << '\n';
     }
     else
     {
          while(p->next != NULL)
          {
               std::cout << p->key << '\n';
               p = p->next;
          }

          std::cout << p->key << '\n';
     }

     std::cout << '\n';
}

int main()
{
     Node* head = NULL;
     Node* prev = NULL;

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
               newNode->key = 0; //Change thie value for testing
               newNode->next = NULL;
               prev->next = newNode;
               prev = newNode;
          }
     }

     Node* headOfOdd = NULL;
     Node* prevOfOdd = NULL;

     Node* headOfEven = NULL;
     Node* prevOfEven = NULL;


     Node* p = head;
     //Checks if the head has been established yet
     if(p == NULL)
     {
          std::cout << "There is no linked list" << '\n';
     }
     else
     {
          while(p->next != NULL)
          {
               if(p->key%2 == 0)
               {
                    if(headOfEven == NULL)
                    {
                         Node* newNode = new Node;
                         newNode->key = p->key;
                         newNode->next = NULL;
                         headOfEven = newNode;
                         prevOfEven = newNode;
                    }
                    else
                    {
                         Node* newNode = new Node;
                         newNode->key = p->key;
                         newNode->next = NULL;
                         prevOfEven->next = newNode;
                         prevOfEven = newNode;
                    }

                    Node* toBeDeleated = p;
                    p = p->next;
                    delete toBeDeleated;
               }
               else if(p->key%2 == 1)
               {
                    if(headOfOdd == NULL)
                    {
                         Node* newNode = new Node;
                         newNode->key = p->key;
                         newNode->next = NULL;
                         headOfOdd = newNode;
                         prevOfOdd = newNode;
                    }
                    else
                    {
                         Node* newNode = new Node;
                         newNode->key = p->key;
                         newNode->next = NULL;
                         prevOfOdd->next = newNode;
                         prevOfOdd = newNode;
                    }

                    Node* toBeDeleated = p;
                    p = p->next;
                    delete toBeDeleated;
               }
          }

          if(p->key%2 == 0)
          {
               if(headOfEven == NULL)
               {
                    Node* newNode = new Node;
                    newNode->key = p->key;
                    newNode->next = NULL;
                    headOfEven = newNode;
                    prevOfEven = newNode;
               }
               else
               {
                    Node* newNode = new Node;
                    newNode->key = p->key;
                    newNode->next = NULL;
                    prevOfEven->next = newNode;
                    prevOfEven = newNode;
               }

               Node* toBeDeleated = p;
               p = p->next;
               delete toBeDeleated;
          }
          else if(p->key%2 == 1)
          {
               if(headOfOdd == NULL)
               {
                    Node* newNode = new Node;
                    newNode->key = p->key;
                    newNode->next = NULL;
                    headOfOdd = newNode;
                    prevOfOdd = newNode;
               }
               else
               {
                    Node* newNode = new Node;
                    newNode->key = p->key;
                    newNode->next = NULL;
                    prevOfOdd->next = newNode;
                    prevOfOdd = newNode;
               }

               Node* toBeDeleated = p;
               p = p->next;
               delete toBeDeleated;
          }


          print(headOfEven);
          print(headOfOdd);
     }
}
