/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayMenu();

int main()
{
     char input;
     string messageInput;
     string countryInput;
     string lastCountryInput;
     CountryNetwork linkedCountries;

     do
     {
          displayMenu();
          cin >> input;

          switch(input)
          {
               case '1':
                    linkedCountries.loadDefaultSetup();
                    linkedCountries.printPath();
                    break;

               case '2':
                    linkedCountries.printPath();
                    break;

               case '3':
                    cout << "Enter name of the country to receive the message:" << '\n';
                    cin.ignore();
                    getline(cin, countryInput);

                    cout << "Enter the message to send:" << '\n';
                    getline(cin, messageInput);
                    cout << endl;

                    linkedCountries.transmitMsg(countryInput, messageInput);
                    break;

               case '4':
                    cout << "Enter a new country name:" << '\n';
                    cin.ignore();
                    getline(cin, countryInput);

                    cout << "Enter the previous country name (or First):" << '\n';
                    getline(cin, lastCountryInput);
                    cout << endl;

                    Country* lastCountry;
                    if(lastCountryInput != "First")
                    {
                         lastCountry = linkedCountries.searchNetwork(lastCountryInput);
                         while(lastCountry == NULL)
                         {
                              std::cout << "INVALID country...Please enter a VALID previous country name:" << '\n';
                              getline(cin, lastCountryInput);
                              if(lastCountryInput == "First")
                              {
                                   break;
                              }
                              else
                              {
                                   lastCountry = linkedCountries.searchNetwork(lastCountryInput);
                              }
                         }
                    }
                    else
                    {
                         lastCountry == NULL;
                    }
                    linkedCountries.insertCountry(lastCountry, countryInput);
                    linkedCountries.printPath();
                    break;

               case '5':
                    cout << "Enter a country name:" << '\n';
                    cin.ignore();
                    getline(cin, countryInput);

                    linkedCountries.deleteCountry(countryInput);
                    linkedCountries.printPath();
                    break;

               case '6':
                    linkedCountries.reverseEntireNetwork();
                    linkedCountries.printPath();
                    break;

               case '7':
                    linkedCountries.deleteEntireNetwork();
                    break;

               case '8':
                    std::cout << "Quitting... cleaning up path: " << '\n';
                    linkedCountries.printPath();
                    linkedCountries.deleteEntireNetwork();

                    if(linkedCountries.isEmpty())
                    {
                         std::cout << "Path cleaned" << '\n';
                    }
                    else
                    {
                         std::cout << "Error: Path NOT cleaned" << '\n';
                    }

                    std::cout << "Goodbye!" << '\n';
                    return 0;
                    break;

               default:
                    std::cout << "No no no" << '\n';
                    break;
          }
     }
     while (input != '8');
}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    cout << endl;
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Delete Country " << endl;
    cout << " 6. Reverse Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
