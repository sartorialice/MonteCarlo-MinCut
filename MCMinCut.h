#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>

using namespace std;

//-------------------------------------GLOBAL VARIABLES, STRUCTURES AND FUNCTIONS-----------------------------------

  const int FNode = 9;  // Vertices in Fritsch graph
  const int FEdge = 21;  // Eedges in Fritsch graph
  const int run = pow(10,5); //Run of the program

  //Structure to represent an edge of the graph
  struct Edge{
      int v1;
      int v2;
  };

  // Structure to represent a vertex of the graph
  struct Vertex{
      int value;
  };

  //Structure of the graph
  struct FritschGraph{
      int NVertices; //Total vertices in the graph
      int NEdges; //Total edges in the graph
      vector<Vertex> vertex;
      vector<Edge> edge;
  };

  //FUNCTIONS
  void addVertex (FritschGraph* &FGraph, int v); //Add vertex to the graph
  void addEdge(FritschGraph* &FGraph, int v1, int v2); //Add edge to the graph
  void deleteVertex(FritschGraph* &FGraph, int v); //Delete vertex from the graph
  void deleteEdge(FritschGraph* FGraph, int v1, int v2); //Delete edge from the graph
  int MonteCarloMinCut(FritschGraph* graph); //Generates the MinCut
