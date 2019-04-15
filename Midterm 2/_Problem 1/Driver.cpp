#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "BST.hpp"

int main()
{
     BST tree;
     tree.addNode(9);
     tree.addNode(7);
     tree.addNode(16);
     tree.addNode(4);
     tree.addNode(8);
     tree.addNode(11);
     std::cout << tree.sumRange(8,12,tree.getRoot(),0) << '\n';

     BST tree2;
     std::cout << tree.sumRange(8,12,tree2.getRoot(),0) << '\n';

     BST tree3;
     tree.addNode(9);
     tree.addNode(7);
     tree.addNode(16);
     tree.addNode(4);
     tree.addNode(8);
     tree.addNode(11);
     std::cout << tree.sumRange(100,1000,tree3.getRoot(),0) << '\n';
}
