#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "BST.hpp"

int getMaxDepth(Node *root)
{
     {
         if (root == NULL)
             return 0;
         else
         {
             /* compute the depth of each subtree */
             int lDepth = getMaxDepth(root->left);
             int rDepth = getMaxDepth(root->right);

             /* use the larger one */
             if (lDepth > rDepth)
                 return(lDepth + 1);
             else return(rDepth + 1);
         }
     }

}

int main()
{
     BST tree;

     tree.addNode(20);
     tree.addNode(30);
     tree.addNode(40);
     tree.addNode(15);
     tree.addNode(18);
     tree.addNode(9);
     tree.addNode(4);
     tree.addNode(7);

     tree.print2DUtil(5);

     std::cout << getMaxDepth(tree.root) << '\n';
}
