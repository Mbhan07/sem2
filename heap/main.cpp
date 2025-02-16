#include <iostream>
#include <cstring>
#include <iterator>
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
int remove(int * heap, int index);
void heapStuff(int * heap, int index);





int main(){

  //create heap
  
  int heap[101];

  int size = 0;

  //set everything equal to 0
  
  for (int i = 1; i < 101; i++){
    
    heap[i] = 0;
    
  }

  while (true){

    int index = 0;
    
    
    cout << "Would you like to enter numbers MANUAL, through a FILE, QUIT, remove ALL the nodes, or remove the LARGEST node? ";

    char input[20];

    cin >> input;

    if(strcmp(input, "MANUAL") == 0){
      
      cout << "manual" << endl;

      int numbers = 0;

      //ask user how many numbers they want to add
      cout << "Enter the AMOUNT of numbers you would like to add: ";
      cin >> numbers;

      //we can only add up to 100 numbers
      if(numbers > 100){
	cout << "You can only add up to 100 numbers" << endl;
	;
      }else { //amount of numbers is less than 100
	for(int i = 0; i < numbers; i++){
	  int numberToAdd;
	  cout << "Please enter the NUMBER you would like to add: ";
	  cin >> numberToAdd;
	  add(heap, size, numberToAdd);
	  print(heap, 0, 0, size);
	  /*cout << endl;
	  cout << endl;
	  cout << endl;*/

	  //experimenting w/ what looks better
	  cout <<"\n \n \n" << endl;
	}
      }
      
      
    }else if(strcmp(input, "FILE") == 0){
      
      cout << "Enter the name of the file you would like to read: ";
      
      char fileName[30];
      cout << "Please enter the name of your file, including the file name (e.g. .txt or .tsv): ";
      cin >> fileName;
      cin.ignore();
      ifstream file;
      file.open(fileName);
      int input = 0;
      int index = 0;

      //read numbers in and add to heap

      while (file > input){
	add(heap, size, input);
	index++;
      }
      file.close();
      print(heap, 0, 0, size);
      
      //call file function via fstream
      
    }else if(strcmp(input, "QUIT") == 0){
      
      exit(0);
      
    }else if(strcmp(input, "ALL") == 0){
      
      cout << "remove all the nodes" << endl;
      while(heap[index] != 0){
	cout << remove(heap, index) << endl;
      }
      
    }else if(strcmp(input, "LARGEST") == 0){
      
      cout << "remove the largest node" << endl;
      cout << remove(heap, index) << endl;
      size --;
    }

    //will also need to delete largest or all nodes

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

  int sizes = 0;

  //get size of heap

  while (heap[sizes] != 0){
    
    sizes++;
    
  }

  sizes = sizes - 1;
  
  int rightNode = index;

  heap[index] = heap[sizes];

  heap[sizes] = 0;

  //if current node smaller than right/left
  
  while((heap[rightNode] < heap[rightNode *2 + 1]) || (heap[rightNode] < heap[rightNode*2 + 2])){
    
    cout << "something should occur here" << endl; //it is my lucky day! i figyured out what goes here
    //if left is bigger than right, replace root of heap with left
    if (heap[rightNode*2 + 1] > heap[rightNode * 2 + 2]){
      
    }else if (heap[rightNode*2 + 2] > heap[rightNode*2 + 1]){ //then inverse everything for the right conditgion
      
    }
  }

  return temps;
  
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
    swap(heap[parent], heap[index]);
    //call heap func
    heapStuff(heap, parent);
    
  }
}
