#include "Graph.hpp"
#include <list>

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::addVertex(std::string cityName)
{
     vertex *newVertex = new vertex();
     newVertex->name = cityName;
     newVertex->visited = false;
     vertices.push_back(*newVertex);
}

void Graph::addEdge(std::string city1, std::string city2, int distance)
{
     vertex *c1 = findVertex(city1);
     vertex *c2 = findVertex(city2);

     Edge *newEdge = new Edge();
     newEdge->v = c2;
     newEdge->distance = distance;

     c1->Edges.push_back(*newEdge);
}

void Graph::displayEdges()
{
     for(int i=0; i<vertices.size(); i++)
     {
          std::cout << vertices[i].name << "-->";

          for(int j=0; j<vertices[i].Edges.size(); j++)
          {
               std::cout << vertices[i].Edges[j].v->name;
               std::cout << " (" << vertices[i].Edges[j].distance << " miles)";
               if(j+1 != vertices[i].Edges.size())
               {
                    std::cout << "***";
               }
          }

          std::cout << '\n';
     }
}

void Graph::printDFT()
{
     setAllVerticesUnvisited();

     for(int i = 0; i<vertices.size(); i++)
     {
          if(!vertices[i].visited)
          {
               DFT_traversal(&vertices[i]);
          }
     }
}

void Graph::printBFT()
{
     setAllVerticesUnvisited();
     for(int i = 0; i<vertices.size(); i++)
     {
          if(!vertices[i].visited)
          {
               BFT_traversal(&vertices[i]);
          }
     }
}

void Graph::setAllVerticesUnvisited()
{
     for(int i=0; i<vertices.size(); i++)
     {
          vertices[i].visited = false;
     }
}

vertex* Graph::findVertex(std::string name)
{
     for(int i=0; i<vertices.size(); i++)
     {
          if(vertices[i].name == name)
          {
               return &vertices[i];
          }
     }
}

void Graph::BFT_traversal(vertex *v)
{
     std::list<vertex*> queue;

     v->visited = true;
     queue.push_back(v);

     while(!queue.empty())
     {
          v = queue.front();
          std::cout << v->name << '\n';
          queue.pop_front();

          for(int i=0; i<v->Edges.size(); i++)
          {
               if(!v->Edges[i].v->visited)
               {
                    v->Edges[i].v->visited = true;
                    queue.push_back(v->Edges[i].v);
               }
          }
     }
}

void Graph::DFT_traversal(vertex *v)
{
     v->visited = true;
     std::cout << v->name << '\n';

     for(int i=0; i<v->Edges.size(); i++)
     {
          if(!v->Edges[i].v->visited)
          {
               DFT_traversal(v->Edges[i].v);
          }
     }
}
