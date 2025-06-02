#include <iostream>
#include <cstring>
#include <climits> //allows
/*

  This is graph creator by Mahika Bhan, due May 30th, 2025. Graph Creator is a project used to visualize graphs and calculate the shortest distance/path using Djikstra's Algorithim. This program can add a vertex, add an edge, remove a vertex or edge, and find the shortest path.


  Sources:


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
  int vertexNum = 0;

  int adjacentMatrix[20][20] = {0};
  char vertices[20];

  char input[25];

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

void shortestPath(char starting, char ending, int vertexNum, int adjacentMatrix[20][20], char vertices[20]){
  const int biggie = INT_MAX;
  int distance[20];
  bool visited[20] = {false};

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


 if(startIndex == -1 || endIndex == -1){
   cout << "Vertex label not valid. " << endl;
   return;
 }

 for(int i = 0; i < vertexNum; i++){
   distance[i] = biggie;
 }

distance[startIndex] = 0;

for(int count = 0; count < vertexNum -1; count++){
  int u = -1;
  int minimumDistance = biggie;

  for(int i = 0; i < vertexNum; i++){
    if(!visited[i] && distance[i] < minimumDistance) {
      minimumDistance = distance[i];
      u = i;
    }
  }
  if(u == -1){
    break;
  }

  visited[u] = true;
  for (int v = 0; v < vertexNum; v++){
    if(adjacentMatrix[u][v] > 0 && !visited[v]){
      if(distance[u] + adjacentMatrix[u][v] < distance[v]){
	distance[v] = distance[u] + adjacentMatrix[u][v];
      }
    }
  }

}
if(distance[endIndex] == biggie){
  cout << "No path from " << starting << " to " << ending << endl;
 }else {
  cout << "Shortest distance from " << starting << " to " << ending << " is " << distance[endIndex] << endl;
 }

}
void printMatrix(int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){
  cout << "Here is the table: " << endl;

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

void deleteEdge(char starting, char ending, int weight, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){
  int i = getIndex(starting, vertexNum, adjacentMatrix, vertices);
  int j = getIndex(ending, vertexNum, adjacentMatrix, vertices);

  if ( i == -1 || j == -1){
    cout << "Either one or both vertices do not exist. " << endl;
    cout << endl;

    return;
  }
  adjacentMatrix[i][j] = 0;
}

void addEdge(char starting, char ending, int weight, int &vertexNum,  int adjacentMatrix[20][20], char vertices[20]){
  int i = getIndex(starting,vertexNum,adjacentMatrix,vertices);
  int j = getIndex(ending,vertexNum,adjacentMatrix,vertices);

  if (i == -1 || j == -1){
    cout << "Either one or both verticies do not exist. " << endl;
    cout << endl;
    return;
  }
  adjacentMatrix[i][j] = weight;
}


void addVertex(char label, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){
  //in case there are more than 20 vertexes
  if (vertexNum >= 20){
    cout << "You can't add any more vertices" << endl;
    cout << endl;
    return;
  }

  //if vertex is not equal to 1

  if(getIndex(label, vertexNum, adjacentMatrix, vertices) != -1){
    cout << "Vertex already exists." << endl;
    cout << endl;
    return;
  }

  vertices[vertexNum++] = label;

}


int getIndex(char index, int & vertexNum, int adjacentMattrix[20][20], char vertices[20]){
  for(int i = 0; i < vertexNum; i++){
    if(vertices[i] == index){
      return i;
    }
  }

  return -1;

}

void deleteVertex(char label, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){
  int index = getIndex(label, vertexNum, adjacentMatrix, vertices);

  if(index == -1){
    cout << "Vertex not found. " << endl;
    return;
  }

  for(int i = index; i < vertexNum - 1; i++){
    vertices[i] = vertices[i + 1];
  }

  for(int i = index; i < vertexNum - 1; i++){
    for(int j = 0; j < vertexNum; j++){
      adjacentMatrix[i][j] = adjacentMatrix[i + 1][j];
    }
  }
  for(int i = 0; i < vertexNum - 1; i++){
    for(int j = index; j < vertexNum - 1; j++){
      adjacentMatrix[i][j] = adjacentMatrix[i][j + 1];
    }
  }

  vertexNum--;
}

