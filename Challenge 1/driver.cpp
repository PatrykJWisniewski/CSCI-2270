#include <iostream>
#include "BST.hpp"
using namespace std;

int main ()
{
     BST tree;
     BST tree2;

     //Adds nodes too the first tree
     tree.addNode(3);
     tree.addNode(2);
     tree.addNode(8);
     tree.addNode(123);
     tree.addNode(1);
     tree.addNode(6);
     tree.addNode(1000);
     std::cout << "Tree 1" << '\n';
     tree.print2DUtil(2);

     //Adds nodes too the second tree
     tree2.addNode(3);
     tree2.addNode(4);
     tree2.addNode(9);
     tree2.addNode(38);
     tree2.addNode(20);
     tree2.addNode(-23);
     tree2.addNode(10000);
     std::cout << "Tree 2" << '\n';
     tree2.print2DUtil(2);

     //Mearges the trees
     tree.mergeTree(tree2.getRoot());
     std::cout << "Merged Tree" << '\n';
     tree.print2DUtil(2);
}
