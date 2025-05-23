#include <iostream>
#include <cstring>
/*

  This is graph creator by Mahika Bhan, due May 30th, 2025. Graph Creator is a project used to visualize graphs and calculate the shortest distance/path using Djikstra's Algorithim. This program can add a vertex, add an edge, remove a vertex or edge, and find the shortest path.


  Sources:


 */


using namespace std;

//Functions then main

void printMatrix(int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){
  cout << "Here is the table: " << endl;

  //here's the print loop we all know and love wooooooohooo


  for (int i = 0; i < vertexNum; i++){
    cout << "\t" << vertices[i] << "\t";
  }
  cout << "\n"

  for(int i = 0; i < vertexNum; i++){
    cout << vertices[i] << " ";
    for(int j = 0; j < vertexNum; j++){
      cout << "\t" << adjacentMatrix[i][j] << "\t";
    }
    cout << "\n"
  }
}


void addVertex(char label, int & vertexNum, int adjacentMatrix[20][20], char vertices[20]){
  //in case there are more than 20 vertexes
  if (vertexNum >= 20){
    cout << "You can't add any more vertices" << endl;
    cout << endl;
    return;
  }

  //if vertex is not equal to 1

  if(getIndex(label, vertexNum, adjacentMatrix, vertices) != 1){
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
int main(){

 return 0;
}
