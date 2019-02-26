#include "MovieTree.hpp"
#include <iostream>

MovieNode* Insert(MovieNode* root, MovieNode* newNode)
{
     if(root == NULL)
     {
          //std::cout << "root" << newNode->title << '\n';
          root = newNode;
     }
     else if(newNode->title.compare(root->title) < 0)
     {
          //std::cout << "left" << '\n';
          root->leftChild = Insert(root->leftChild, newNode);
          root->parent = root;
     }
     else
     {
          //std::cout << "right" << '\n';
          root->rightChild = Insert(root->rightChild, newNode);
          root->parent = root;
     }

     return root;
}

void PrintInOrder(MovieNode* root)
{
     if(root == NULL)
     {
          return;
     }

     PrintInOrder(root->leftChild);

     std::cout << "Movie: " << root->title << " " << root->rating << "\n";

     PrintInOrder(root->rightChild);
}

MovieNode* Search(MovieNode* root, std::string title)
{
     if(root == NULL || root == nullptr)
     {
          return NULL;
     }
     else if(root->title == title)
     {
          return root;
     }
     else if(root->title.compare(title) > 0)
     {
          //std::cout << "left" << '\n';
          return Search(root->leftChild,title);
     }
     else
     {
          //std::cout << "right" << '\n';
          return Search(root->rightChild,title);
     }
}

void QuerySearch(MovieNode* root, float rating, int year)
{
     if(root == NULL)
     {
          return;
     }

     if(root->rating >= rating && root->year >= year)
     {
          std::cout << root->title << "(" << root->year << ") " << root->rating << "\n";
     }

     QuerySearch(root->leftChild, rating, year);

     QuerySearch(root->rightChild, rating, year);
}

void DeleteAllNodes(MovieNode* root)
{
     if(root == NULL)
     {
          return;
     }

     DeleteAllNodes(root->leftChild);
     DeleteAllNodes(root->rightChild);

     delete root;
}

float FindAvarage(MovieNode* root)
{
     if (root == nullptr)
     {
          return 0;
     }
     else
     {
          return root->rating + FindAvarage(root->leftChild) + FindAvarage(root->rightChild);
     }
}

int FindNumOfNodes(MovieNode* root)
{
     int count = 1;
     if (root == NULL)
     {
             return 0;
     }
     else
     {
         count += FindNumOfNodes(root->leftChild);
         count += FindNumOfNodes(root->rightChild);
         return count;
     }
}

MovieTree::MovieTree()
{
     root = NULL;
}

MovieTree::~MovieTree()
{
     DeleteAllNodes(root);
}

MovieNode* MovieTree::search(std::string title)
{
     return Search(root, title);
}

void MovieTree::printMovieInventory()
{
     PrintInOrder(root);
}

void MovieTree::addMovieNode(int ranking, std::string title, int year, float rating)
{
     MovieNode* newNode = new MovieNode(ranking, title, year, rating);
     root = Insert(root, newNode);
}

void MovieTree::findMovie(std::string title)
{
     MovieNode* foundMovie = search(title);

     if(foundMovie != NULL)
     {
          std::cout << "Movie Info:" << '\n';
          std::cout << "==================" << '\n';
          std::cout << "Ranking:" << foundMovie->ranking << '\n';
          std::cout << "Title  :" << foundMovie->title << '\n';
          std::cout << "Year   :" << foundMovie->year << '\n';
          std::cout << "rating :" << foundMovie->rating << '\n';
     }
     else
     {
          std::cout << "Movie not found." << '\n';
     }
}

void MovieTree::queryMovies(float rating, int year)
{
     std::cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << '\n';

     QuerySearch(root, rating, year);
}

void MovieTree::averageRating()
{
     float avg;

     if(root == NULL)
     {
          std::cout << "Average rating:0" << '\n';
     }
     else
     {
          avg = FindAvarage(root)/FindNumOfNodes(root);
          std::cout << "Average rating:" << avg << '\n';
     }
}
