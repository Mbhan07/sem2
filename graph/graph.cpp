#include <iostream>
#include <cstring>
/*

  This is graph creator by Mahika Bhan, due May 30th, 2025. Graph Creator is a project used to visualize graphs and calculate the shortest distance/path using Djikstra's Algorithim. This program can add a vertex, add an edge, remove a vertex or edge, and find the shortest path.


  Sources:


 */


using namespace std;

//Function prototypes




int main(){

  while (true){
    char input[100];

    cout << "What would you like to do? ADD a vertex or edge, REMOVE a vertex or edge, or find the SHORTEST path? ";

    cin >> input;

    if(strcmp(input, "ADD") == 0){
      char toAdd[10];

      cout << "Would you like to add a VERTEX or EDGE" << endl;
	       

    }else if(strcmp(input, "REMOVE") == 0){

    }else if(strcmp(input, "SHORTEST") == 0){

    }else {
      cout << "Not a valid input. Please enter ADD, REMOVE, or SHORTEST (uppercase and no typos). " << endl;
    }
  }
  return 0;
}
