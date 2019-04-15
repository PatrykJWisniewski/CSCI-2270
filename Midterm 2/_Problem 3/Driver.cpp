#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "graphs.hpp"

int main()
{
     Graph gr;

     gr.addVertex(1);
     gr.addVertex(2);
     gr.addVertex(3);
     gr.addVertex(4);
     gr.addVertex(5);

     gr.addEdge(1,4);
     gr.addEdge(4,2);
     gr.addEdge(4,5);
     gr.addEdge(5,2);
     gr.addEdge(5,3);

     std::cout << gr.countNodesWithDist(3,2) << '\n';
     std::cout << gr.countNodesWithDist(2,1) << '\n';
     std::cout << gr.countNodesWithDist(3,3) << '\n';
}
