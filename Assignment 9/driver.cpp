#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Graph.hpp"

int main(int argc, char const *argv[])
{
     Graph citiesGraph;
     std::vector<std::string> cityNames;

     std::ifstream data;
     std::string line;
     data.open(argv[1]);

     int lineNum = 0;
     while(std::getline(data,line))
     {
          std::stringstream ss;
          ss<<line;
          std::string info;

          if(lineNum == 0)
          {
               std::getline(ss,info,',');
               while(std::getline(ss,info,','))
               {
                    citiesGraph.addVertex(info);
                    cityNames.push_back(info);
               }
          }
          else
          {
               std::getline(ss,info,',');
               int collNum = 0;
               while(std::getline(ss,info,','))
               {
                    if(std::stoi(info) > 0)
                    {
                         citiesGraph.addEdge(cityNames[lineNum-1], cityNames[collNum], std::stoi(info));
                         std::cout << " ... Reading in " << cityNames[lineNum-1] << " -- " << cityNames[collNum] << " -- " << info << '\n';
                    }
                    collNum++;
               }
          }

          lineNum++;
     }

     std::cout << "------------------------------" << '\n';
     std::cout << "Breadth First Traversal" << '\n';
     std::cout << "------------------------------" << '\n';
     citiesGraph.printBFT();

     std::cout << "------------------------------" << '\n';
     std::cout << "Depth First Traversal" << '\n';
     std::cout << "------------------------------" << '\n';
     citiesGraph.printDFT();

     std::cout << "------------------------------" << '\n';
     std::cout << "Display Edges" << '\n';
     std::cout << "------------------------------" << '\n';
     citiesGraph.displayEdges();

     return 0;
}
