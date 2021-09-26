#include "MCMinCut.h"

//----------------------------------------------------------MAIN-------------------------------

int main(){

    srand(time(NULL)); //Generates the random seed

    int how_many_MinCut=0; //Counter of the correct Min Cuts

    for(int i =0; i <run ;i++){

      //Creating the Fritsch Graph
      FritschGraph*FGraph = new FritschGraph;
      FGraph->NVertices = 0;
      FGraph->NEdges = 0;

      // Create vertex 0 and its edges
      addVertex(FGraph, 0);
      addEdge(FGraph, 0, 1);
      addEdge(FGraph, 0, 2);
      addEdge(FGraph, 0, 3);
      addEdge(FGraph, 0, 7);
      addEdge(FGraph, 0, 8);

  		// Create vertex 1 and its edges
      addVertex(FGraph, 1);
      addEdge(FGraph, 1, 2);
      addEdge(FGraph, 1, 5);
      addEdge(FGraph, 1, 6);
      addEdge(FGraph, 1, 7);

  		// Create vertex 2 and its edges
      addVertex(FGraph, 2);
      addEdge(FGraph, 2, 3);
      addEdge(FGraph, 2, 4);
      addEdge(FGraph, 2, 5);

  		// Create vertex 3 and its edges
      addVertex(FGraph, 3);
      addEdge(FGraph, 3, 4);
      addEdge(FGraph, 3, 8);

  		// Create vertex 4 and its edges
      addVertex(FGraph, 4);
      addEdge(FGraph, 4, 5);
      addEdge(FGraph, 4, 6);
      addEdge(FGraph, 4, 8);

  		// Create vertex 5 and its edges
      addVertex(FGraph, 5);
      addEdge(FGraph, 5, 6);

  		// Create vertex 6 and its edges
      addVertex(FGraph, 6);
      addEdge(FGraph, 6, 7);
      addEdge(FGraph, 6, 8);

      // Create vertex 7 and its edges
      addVertex(FGraph, 7);
      addEdge(FGraph, 7, 8);

      // Create vertex 8
      addVertex(FGraph, 8);

   		if(MonteCarloMinCut(FGraph) == 4) //4 is the correct value of the Min Cut for the Fritsch graph
   		   how_many_MinCut++;

    }

    cout<<"The correct Min Cut was obtained "<<how_many_MinCut<<" times uopn "<<run<<" run."<<endl;
    cout<<"The probability to obtain the Min Cut is "<<((float)how_many_MinCut/run)*100<<"%"<<endl;
    cout<<"The estimate value is "<<2/(pow(FNode,2))<<" and we are "<<((float)how_many_MinCut/run)-2/(pow(FNode,2))
    <<" above the estimate value."<<endl;

    return 0;
}

//-------------------------------------------------FUNCTIONS---------------------------------------------------

void addVertex (FritschGraph* &FGraph, int v){

  Vertex vert;
  vert.value=v;
  FGraph->vertex.push_back(vert);
  FGraph->NVertices++;
}

//Add edge to the graph
void addEdge(FritschGraph* &FGraph, int v1, int v2){

  Edge e;
  e.v1=v1;
  e.v2=v2;
  FGraph->edge.push_back(e); //Assigning the second vertex to the edge
  FGraph->NEdges++;
}

//Delete vertex from the graph
void deleteVertex(FritschGraph* &FGraph, int v){
  for (int i=0; i< FGraph->vertex.size(); i++){

    //When we find the vertex with the corresponding value we delete it from the graph
    if (FGraph->vertex[i].value==v){
      FGraph->vertex.erase(FGraph->vertex.begin()+i);
      FGraph->NVertices--;
    }
  }
}

//Delete edge between two vertices from the graph
void deleteEdge(FritschGraph* FGraph, int v1, int v2){
  for (int i=0; i<FGraph->edge.size(); i++){

    //When we find an edge between these two vertices we delete it from the graph
    if (FGraph->edge[i].v1==v1 && FGraph->edge[i].v2==v2 ||FGraph->edge[i].v1==v2 && FGraph->edge[i].v2==v1){
      FGraph->edge.erase(FGraph->edge.begin()+i);
      FGraph->NEdges--;
    }
  }

}

//Generates the MinCut
int MonteCarloMinCut(FritschGraph* FGraph){

    int RemainingEdges = 0;
    while (FGraph->NVertices > 2){

      int i = rand() % (FGraph->edge.size()-1); //Sample the edge randomly between all the edges of our graph

      int VToKeep = FGraph->edge[i].v1; //Find the first vertex of the edge
      int VToMerge = FGraph->edge[i].v2; //Find the second vertex of the edge (the one that we merge)

      for(int i=0; i<FGraph->edge.size();i++){

      //If the first vertex of the edge is the one that we have to merge and the second isn't the one we keep...
       if (FGraph->edge[i].v1== VToMerge && FGraph->edge[i].v2!= VToKeep)
          FGraph->edge[i].v1= VToKeep; //... link the first vertex of the edge with the one we decide to keep

      //If the second vertex of the edge is the one that we have to merge and the first isn't the one we keep...
      else if (FGraph->edge[i].v1!=VToKeep && FGraph->edge[i].v2==VToMerge)
          FGraph->edge[i].v2=VToKeep; //... link the second vertex of the edge with the one we decide to keep

      deleteEdge(FGraph, VToKeep, VToMerge); //Delete the sampled edge

      }
      deleteVertex(FGraph, VToMerge); //Delete the merged vertex from the edge

      }
      if (FGraph->edge.size() == 4) //If the number of the edges is 4 we reached the Min Cut
        RemainingEdges=4;

      return RemainingEdges;
}
