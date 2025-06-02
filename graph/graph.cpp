#include <iostream>
#include <cstring>
#include <climits> //allows
/*

  This is graph creator by Mahika Bhan, due May 30th, 2025. Graph Creator is a project used to visualize graphs and calculate the shortest distance/path using Djikstra's Algorithim. This program can add a vertex, add an edge, remove a vertex or edge, and find the shortest path.


  CHECK BOTTOM FOR SOME REALLY COOL ASCII

  


 */


using namespace std;

//Function prototypess then main

void printMatrix(int & vertexNum, int adjacentMatrix[20][20], char vertices[20]);
void deleteEdge(char starting, char ending, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]);
void addEdge(char starting, char ending, int weight, int &vertexNum,  int adjacentMatrix[20][20], char vertices[20]);
void addVertex(char label, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]);
int getIndex(char index, int & vertexNum, int adjacentMattrix[20][20], char vertices[20]);
void shortestPath(char starting, char ending, int vertexNum, int adjacentMatrix[20][20], char vertices[20]);
void deleteVertex(char label, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]);

int main(){

  //number of vertices currently in graph
  int vertexNum = 0;

  //adjacency matrix initalized to all 0s
  int adjacentMatrix[20][20] = {0};

  ////array to store up to 20 vertex labels
  char vertices[20];

  char input[25];

  //get user input and call appropiate function
  while(true){


    cout << "What would you like to do? ADDEDGE, ADDVERTEX, REMOVEVERTEX, REMOVEEDGE, PRINTGRAPH, FINDSHORTEST, or QUIT." << endl;
    cin >> input;

    if(strcmp(input, "ADDVERTEX") == 0){

      char label;

      cout << "Vertex label? ";

      cin >> label;

      addVertex(label, vertexNum, adjacentMatrix, vertices);

      printMatrix(vertexNum, adjacentMatrix, vertices);
    }else if(strcmp(input, "ADDEDGE") == 0){
      char startPoint;
      char endPoint;
      int edgeLength;

      cout << "Start vertex? ";
      cin >> startPoint;

      cout << "End vertex? ";
      cin >> endPoint;

      cout << "Edge length? ";
      cin >> edgeLength;

      addEdge(startPoint, endPoint, edgeLength, vertexNum, adjacentMatrix, vertices);

      printMatrix(vertexNum, adjacentMatrix, vertices);
      
    }else if(strcmp(input, "REMOVEVERTEX") == 0){
      char label;
      cout << "Which vertex to delete? ";

      cin >> label;

      deleteVertex(label, vertexNum, adjacentMatrix, vertices);

      printMatrix(vertexNum, adjacentMatrix, vertices);
      
    }else if(strcmp(input, "REMOVEEDGE") == 0){
      char start;
      char end;

      cout << "Start vertex? ";
      cin >> start;

      cout << "End vertex? ";
      cin >> end;

      deleteEdge(start, end, vertexNum, adjacentMatrix, vertices);

      printMatrix(vertexNum, adjacentMatrix, vertices);

    }else if(strcmp(input, "PRINTGRAPH") == 0){

      printMatrix(vertexNum, adjacentMatrix, vertices);

    }else if(strcmp(input, "FINDSHORTEST") == 0){
      char starting;
      char ending;

      cout << "Enter starting point for algorithim: ";
      cin >> starting;

      cout << "Enter ending point for algorithim: ";
      cin >> ending;

      shortestPath(starting, ending, vertexNum, adjacentMatrix, vertices);
      
    }else if(strcmp(input, "QUIT") == 0){
      cout << "Goodbye." << endl;
      exit(0);
    }else{
      cout << "Invalid input. Please follow all syntax and pick: ADDEDGE, ADDVERTEX, REMOVEVERTEX, REMOVEEDGE, PRINTGRAPH, FINDSHORTEST, or QUIT." << endl;
      cin >> input;
    }
  }
  
  /*addVertex('A', vertexNum, adjacentMatrix, vertices);
  addVertex('B', vertexNum, adjacentMatrix, vertices);
  addVertex('C', vertexNum, adjacentMatrix, vertices);
  addVertex('D', vertexNum, adjacentMatrix, vertices);

  addEdge('A', 'B', 1, vertexNum, adjacentMatrix, vertices);
  addEdge('A', 'C', 4, vertexNum, adjacentMatrix, vertices);
  addEdge('B', 'C', 2, vertexNum, adjacentMatrix, vertices);
  addEdge('B', 'D', 5, vertexNum, adjacentMatrix, vertices);
  addEdge('C', 'D', 1, vertexNum, adjacentMatrix, vertices);

  printMatrix(vertexNum, adjacentMatrix, vertices);

  deleteEdge('B', 'C', 2, vertexNum, adjacentMatrix, vertices);

  printMatrix(vertexNum, adjacentMatrix, vertices);*/
   
  return 0;
}

//shortest path: computes and prints the shortest path between two vertices by using dijkstra's algorithim
void shortestPath(char starting, char ending, int vertexNum, int adjacentMatrix[20][20], char vertices[20]){

  //defines really big number and "infinite" distance
  const int biggie = INT_MAX;

  //to stor etenative distances
  int distance[20];

  //tracks which vertices have been visited
  bool visited[20] = {false};

  //to find starting/ending positions of the start and end vertices in the vertices array
  int startIndex = -1;
  int endIndex = -1;

  for(int i = 0; i < vertexNum; i++){
    if(vertices[i] == starting){
       startIndex = i;
    }
    if(vertices[i] == ending){
      endIndex = i;
    }

  }

  //if either labak not found
 if(startIndex == -1 || endIndex == -1){
   cout << "Vertex label not valid. " << endl;
   return;
 }

 //initialize arrays and set distance to rlly big
 for(int i = 0; i < vertexNum; i++){
   distance[i] = biggie;
 }
 //distance from start to iself = 0
distance[startIndex] = 0;

//repeat vertexNum -1 times, 
for(int count = 0; count < vertexNum -1; count++){
  int u = -1; //index of next vertex to finalize
  int minimumDistance = biggie; //track minimum distance

  //find invisited vertices with minimum distance, update minimum distance and record index
  for(int i = 0; i < vertexNum; i++){
    if(!visited[i] && distance[i] < minimumDistance) {
      minimumDistance = distance[i];
      u = i;
    }
  }
  // if no reachable unvisited vertex remains, exit loop
  if(u == -1){
    break;
  }

  //mark u as visited
  visited[u] = true;
  //for evert neighbor of u and v, weight of edge u + v, if edge exists and v not visited and path through u is shorter, update distance[v]
  for (int v = 0; v < vertexNum; v++){
    if(adjacentMatrix[u][v] > 0 && !visited[v]){
      if(distance[u] + adjacentMatrix[u][v] < distance[v]){
	distance[v] = distance[u] + adjacentMatrix[u][v];
      }
    }
  }

}

//if end is still "infinite" big then no path exists
if(distance[endIndex] == biggie){
  cout << "No path from " << starting << " to " << ending << endl;
 }else { //otherwise, print shortest distance
  cout << "Shortest distance from " << starting << " to " << ending << " is " << distance[endIndex] << endl;
 }

}

//display current adjacency-matrix with row/column labels
void printMatrix(int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){
  cout << "Here is the table: " << endl;
  //header line then a tab

  //here's the print loop we all know and love wooooooohooo


  for (int i = 0; i < vertexNum; i++){
    cout << "\t" << vertices[i] << "\t";
  }
  cout << "\n";

  

  for(int i = 0; i < vertexNum; i++){
    cout << vertices[i] << " ";
    for(int j = 0; j < vertexNum; j++){
      cout << "\t" << adjacentMatrix[i][j] << "\t";
    }
    cout << "\n";
  }
}

//remove a directed edge by setting its weight to 0
void deleteEdge(char starting, char ending, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){

  //get index of source and destination
  int i = getIndex(starting, vertexNum, adjacentMatrix, vertices);
  int j = getIndex(ending, vertexNum, adjacentMatrix, vertices);

  //if either index is invalid, 
  if ( i == -1 || j == -1){
    cout << "Either one or both vertices do not exist. " << endl;
    cout << endl;

    return;
  }

  //set edge weight
  adjacentMatrix[i][j] = 0;
}

//insert a directed, weighted edge from starting to ending
void addEdge(char starting, char ending, int weight, int &vertexNum,  int adjacentMatrix[20][20], char vertices[20]){

  //get index of source and destination
  int i = getIndex(starting,vertexNum,adjacentMatrix,vertices);
  int j = getIndex(ending,vertexNum,adjacentMatrix,vertices);

  //same as above, if either index is invalud
  if (i == -1 || j == -1){
    cout << "Either one or both verticies do not exist. " << endl;
    cout << endl;
    return;
  }

  //set edge weight, except to specified value by user
  adjacentMatrix[i][j] = weight;
}

//append a new vertex with the given label
void addVertex(char label, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){
  //in case there are more than 20 vertexes
  if (vertexNum >= 20){
    cout << "You can't add any more vertices" << endl;
    cout << endl;
    return;
  }

  //if vertex is not equal to -1, meaning that it exists

  if(getIndex(label, vertexNum, adjacentMatrix, vertices) != -1){
    cout << "Vertex already exists." << endl;
    cout << endl;
    return;
  }

  //append label and increment count
  vertices[vertexNum++] = label;

}

// return the array index of the given vertex label or -1 if not found
int getIndex(char index, int & vertexNum, int adjacentMattrix[20][20], char vertices[20]){

  //search vertices array and if match found, return index

  for(int i = 0; i < vertexNum; i++){
    if(vertices[i] == index){
      return i;
    }
  }

  //otherwise return -1 to signfify not found
  return -1;

}

//remove a vertex and all incident edges by shifting arrays and matrix
void deleteVertex(char label, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){

  //find index to delete

  int index = getIndex(label, vertexNum, adjacentMatrix, vertices);

  //if vertex not found
  if(index == -1){
    cout << "Vertex not found. " << endl;
    return;
  }

  //shift remaining labels left and overwrite current with next
  for(int i = index; i < vertexNum - 1; i++){
    vertices[i] = vertices[i + 1];
  }

  //shift rows up from index and copy next row into current
  for(int i = index; i < vertexNum - 1; i++){
    for(int j = 0; j < vertexNum; j++){
      adjacentMatrix[i][j] = adjacentMatrix[i + 1][j];
    }
  }
  //shift columns left from index and copy next column into current
  for(int i = 0; i < vertexNum - 1; i++){
    for(int j = index; j < vertexNum - 1; j++){
      adjacentMatrix[i][j] = adjacentMatrix[i][j + 1];
    }
  }

  //decrement vertex count
  vertexNum--;
}

//this is it, i'm out!

/*
       (A)
      /   \
   7 /     \ 12
    /       \
  (B)───3───(C)

             /\
            /**\
           /****\
          /******\
         /********\
        /**********\
       /************\
      /**************\
             ||
             ||
             ||
             /\
            /  \
           /    \
          /      \


                   |>>>                    |>>>
                     |                        |
                 _  _|_  _                _  _|_  _
                |;|_|;|_|;|              |;|_|;|_|;|
                \\.    .  /              \\.    .  /
                 \\:  .  /                \\:  .  /
                  ||:   |                  ||:   |
                  ||:.  |                  ||:.  |
                  ||:  .|                  ||:  .|
                  ||:   |                  ||:   |
                  ||: , |                  ||: , |
                 _||_   |                 _||_   |
    ,-"'''''''`-._\__/_/.-'"""""""""""""""`-._\__/_/.-'
   (  .-'''-.   .-'''-.   .-'''-.   .-'''-.   .-'''-.  )
    '._     _.' '._     _.' '._     _.' '._     _.' '._'
       ```'       ```'       ```'       ```'       ```'  


*/
