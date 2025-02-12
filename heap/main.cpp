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

void add();
void print();
int remove();
void heapStuff();





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

void print(){

}

int remove(){

}


//to sort the heap
void heapStuff(int * heap, int index){
  int parent = (index-1)/2;
  ///what elese goes here....
}
