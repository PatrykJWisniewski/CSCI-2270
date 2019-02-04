/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
     head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
     if(head == NULL)
     {
          return true;
     }
     else
     {
          return false;
     }
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
     //If there have been no counries added yet...
     if(previous == NULL)
     {
          std::cout << "adding: " << countryName << " (HEAD)" << '\n';
          Country* newCountry = new Country();
          newCountry->name = countryName;
          //If the user wants to put in a country at the front of the list
          if(head != NULL)
          {
               newCountry->next = head;
          }
          head = newCountry; //Makes the first addition the head of the linked list
     }
     //If the head of the linked list is established
     else
     {
          std::cout << "adding: " << countryName << " (prev: " << previous->name << ")" << '\n';
          Country* newCountry = new Country();
          newCountry->name = countryName;
          if(previous->next != NULL)
          {
               newCountry->next = previous->next;
          }
          previous->next = newCountry; //Set the new country as the next element in the linked list
     }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName)
{
     bool countryFound = false; //A bool used to see if the country exists or not
     Country* p = head;

     //If the first element in the linked list should be deleted...
     if(p->name == countryName)
     {
          Country* toBeDeleated = p; //Store it in a new instance
          head = p->next; //Set a new head
          delete toBeDeleated; //Delete the node;
          countryFound = true;
     }

     //While there are elements in the linked list
     while(p->next != NULL)
     {
          //If the next item in the linked list is the one to be deleted...
          if((p->next)->name == countryName)
          {
               Country* toBeDeleated = p->next; //Store it in a new instance
               p->next = (p->next)->next; //Link the current node too the one for deletion was pointing too
               delete toBeDeleated; //Delete the node;
               countryFound = true;
          }
          //If the country was not found then keep working down the linked list
          else
          {
               p = p->next;
          }
     }

     //If there was no country found that could be deleted...
     if(countryFound == false)
     {
          std::cout << "Country does not exist." << '\n';
     }
}


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
     deleteEntireNetwork();
     insertCountry(NULL, "United States"); //Inserts the starting country

     Country* p = head;

     //Inserts the remaining 5 countries
     for(int i = 0; i<5; i++)
     {
          switch (i)
          {
               case 0:
                    insertCountry(p, "Canada");
                    break;

               case 1:
                    insertCountry(p, "Brazil");
                    break;

               case 2:
                    insertCountry(p, "India");
                    break;

               case 3:
                    insertCountry(p, "China");
                    break;

               case 4:
                    insertCountry(p, "Australia");
                    break;
          }

          p = p->next; //Makes p be the previous country that was just added
     }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
     Country* p = head;

     //Checks if the head has been established yet
     if(head == NULL)
     {
          return NULL;
     }

     //Checks if the first node is the one we are looking for
     if(p->name == countryName)
     {
          return p;
     }

     //While there are items in the linked list...
     while(p->next != NULL)
     {
          //If this node is the one we are looking for...
          if(p->name == countryName)
          {
               return p;
          }
          //Else move on too the next one.
          else
          {
               p = p->next;
          }
     }

     //Checks if the last node is the one we are looking for
     if(p->name == countryName)
     {
          return p;
     }

     return NULL;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
     if(head != NULL)
     {
          Country* p = head; //Sets a new instance of country so that we dont lose the head node
          Country* next; //Stores the next node to prevent memeory leaks

          //Deletes every country in the linked list but the last one
          while(p->next != NULL)
          {
               std::cout << "deleting: " << p->name << '\n';
               next = p->next;
               delete p;
               p = next;
          }

          //Deletes the last country in the linked list
          std::cout << "deleting: " << p->name << '\n';
          delete next;

          std::cout << "Deleted network" << '\n';
          head = NULL;
     }
}


/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
     if(head == NULL)
     {
          std::cout << "Empty list" << '\n';
     }
     else
     {
          Country* p = head;
          while(p->next != NULL)
          {
               p->message = message;
               p->numberMessages++;

               std::cout << p->name << " [# messages received: " << p->numberMessages << "] received: " << p->message << '\n';

               if(p->name == receiver)
               {
                    return;
               }
               else
               {
                    p = p->next;
               }
          }
     }
}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
     if(head == NULL)
     {
          std::cout << "== Current Path ==" << '\n';
          std::cout << "nothing in path" << '\n';
          std::cout << "===" << '\n';
          return;
     }

     std::cout << "== CURRENT PATH ==" << '\n';

     Country* p = head;
     while(p->next != NULL)
     {
          std::cout << p->name << " -> ";
          p = p->next;
     }

     std::cout << p->name << " -> NULL" <<'\n';
     std::cout << "===" << '\n';
}


/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork()
{
     Country* lastNode = NULL;
     Country* currentNode = head;
     Country* nextNode = NULL;

     while(currentNode != NULL)
     {
          nextNode = currentNode->next;
          currentNode->next = lastNode;
          lastNode = currentNode;
          currentNode = nextNode;
     }

     head = lastNode;
}
