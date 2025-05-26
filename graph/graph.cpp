#include <iostream>
#include <cstring>
/*

  This is graph creator by Mahika Bhan, due May 30th, 2025. Graph Creator is a project used to visualize graphs and calculate the shortest distance/path using Djikstra's Algorithim. This program can add a vertex, add an edge, remove a vertex or edge, and find the shortest path.


  Sources:


 */


using namespace std;

//Function prototypess then main

void printMatrix(int & vertexNum, int adjacentMatrix[20][20], char vertices[20]);
void deleteEdge(char starting, char ending, int weight, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]);
void addEdge(char starting, char ending, int weight, int &vertexNum,  int adjacentMatrix[20][20], char vertices[20]);
void addVertex(char label, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]);
int getIndex(char index, int & vertexNum, int adjacentMattrix[20][20], char vertices[20]);



int main(){
  int vertexNum = 0;

  int adjacentMatrix[20][20] = {0};
  char vertices[20];

  addVertex('A', vertexNum, adjacentMatrix, vertices);
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

  printMatrix(vertexNum, adjacentMatrix, vertices);
  
 
  return 0;
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

