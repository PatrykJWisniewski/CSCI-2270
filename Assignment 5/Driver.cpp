#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

void menu()
{
	std::cout << "======Main Menu======" << '\n';
     std::cout << "1. Find a movie" << '\n';
     std::cout << "2. Query movies" << '\n';
     std::cout << "3. Print the inventory" << '\n';
     std::cout << "4. Average Rating of movies" << '\n';
     std::cout << "5. Quit" << '\n';
}

int main(int argc, char const *argv[])
{
     char input;
     std::string nameInput;
     std::string ratingInput;
     std::string yearInput;
     MovieNode tempMN;
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

         movieTree.addMovieNode(tempMN.ranking, tempMN.title, tempMN.year, tempMN.rating);
     }

     do
     {
          menu();
          std::cin >> input;

          switch(input)
          {
               case '1':
                    std::cout << "Enter title:" << '\n';
                    std::cin.ignore();
                    getline(std::cin, nameInput);
                    movieTree.findMovie(nameInput);
                    break;

               case '2':
                    std::cout << "Enter minimum rating:" << '\n';
                    std::cin >> ratingInput;
                    std::cout << "Enter minimum year:" << '\n';
                    std::cin >> yearInput;
                    movieTree.queryMovies(stof(ratingInput), stoi(yearInput));
                    break;

               case '3':
                    movieTree.printMovieInventory();
                    break;

               case '4':
                    movieTree.averageRating();
                    break;

               case '5':
                    std::cout << "Goodbye!" << '\n';
                    break;

               default:
                    std::cout << "Eneter Valid option" << '\n';
                    break;
          }
     }
     while(input != '5');
}
