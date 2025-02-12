#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>


/*

  This is heap

  Mahika Bhan, 

*/
using namespace std;


//probably need an add, remove, print and heap function

void add(int * heap, int &size, int number);
void print(int pos, int depth, int size);
int remove();
void heapStuff(int * heap, int index);





int main(){

  //create heap
  int heap[10];

  int size = 0;

  //set everything equal to 0
  for (int i = 1; i < 101; i++){
    heap[i] = 0;
  }

  while (true){
    
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
    }

  }
  
  return 0;
}


void add(int * heap, int &size, int number){
  heap[size] = number;
  size++;
  heapStuff(heap, size - 1);
}

//used the code provided for print function on whiteboard
void print(int pos, int depth, int size){
  if(pos*2 + 1 < size){ //check right not null
    print(pos*2 + 1, depth + 1, size); //recurse right
  }
  for (int a = 0; a < depth; a +1){
    cout << '\t';
  }
  cout << heap[pos] << endl;
  if(pos*2 < size){ //check left not null
    print(pose*2, depth +1, size) // recurse left
  }
}

int remove(int * heap, int index){
  int temporary = heap[0];
  
}


//to sort the heap
void heapStuff(int * heap, int index){
  int parent = (index-1)/2;
  if (index == 0){
    return;
  }
  if(heap[parent] > heap[index]){
    return;
  }else {
    //swap
    //call heap func
    heapStuff(heap, parent);
  }
}
