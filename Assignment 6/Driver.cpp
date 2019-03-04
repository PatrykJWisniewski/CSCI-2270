#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

void menu()
{
	std::cout << "======Main Menu======" << '\n';
     std::cout << "1. Print the inventory" << '\n';
     std::cout << "2. Delete a movie" << '\n';
     std::cout << "3. Quit" << '\n';
}

int main(int argc, char const *argv[])
{
     char input;
     std::string nameInput;
     LLMovieNode tempMN;
     MovieTree movieTree;

     std::ifstream data;
     std::string line;
     data.open(argv[1]);
     //For each line row in the file fill out the user information based off the cell information
     while(std::getline(data,line))
     {
         std::stringstream ss;
         ss<<line;
         std::string cell;

         std::getline(ss,cell,',');
         tempMN.ranking = stoi(cell);

         std::getline(ss,cell,',');
         tempMN.title = cell;

         std::getline(ss,cell,',');
         tempMN.year = stoi(cell);

         std::getline(ss,cell);
         tempMN.rating = stof(cell);

         movieTree.addMovie(tempMN.ranking, tempMN.title, tempMN.year, tempMN.rating);
    }

     do
     {
          menu();
          std::cin >> input;

          switch(input)
          {
               case '1':
				movieTree.printMovieInventory();
                    break;

               case '2':
				std::cout << "Enter a movie title:" << '\n';
				std::cin.ignore();
                    getline(std::cin, nameInput);
				movieTree.deleteMovie(nameInput);
                    break;

               case '3':
                    std::cout << "Goodbye!" << '\n';
                    break;

               default:
                    std::cout << "Eneter Valid option" << '\n';
                    break;
          }
     }
     while(input != '3');
}
