#include <iostream>
#include <cstring>
#include <fstream>
/*

  This is heap

  Mahika Bhan, 

*/
using namespace std;

int main(){

  //create heao
  cout << "Would you like to enter numbers MANUAL or through a FILE? ";

  char input[20];

  cin >> input;

  if(strcmp(input, "MANUAL") == 0){
    //call manual funcgtion
  }else if(strcmp(input, "FILE") == 0){
    cout << "Enter the name of the file you would like to read: ";
    char fileName[30];
    cin >> fileName;
    //call file function via fstream
    //this function will read the file then call the function that manual will use 
  }
  
  return 0;
}

void removeALL(){

}

void processFILE(){

  //call heapStuff once file processed
  
}

void heapStuff(){

}
