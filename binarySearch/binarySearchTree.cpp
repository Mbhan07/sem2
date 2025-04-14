#include <iostream>
#include <cstring>
#include <fstream>

struct binaryTree{
  int data;
  binaryTree * right;
  binaryTree * left;
};

//function prototypes for add, print, search, and delete functions

void add(binaryTree * newTree, int toAdd);
void printTree(binaryTree * newTree, int depth);
binaryTree * deleteTree(binaryTree * newTree, int toDelete);
bool search(binaryTree * newTree, int numToSearchFor);

using namespace std;

int main(){

  //make a new tree + set root node = -1
  binaryTree * newTree = new binaryTree();
  newTree -> data = -1;

  while (true){
    char input[100];

    cout << "Would you like to read in numbers MANUALLY (1-999, separated by a single space), through a FILE, PRINT, SEARCH, DELETE, or QUIT?" << endl;
    cin >> input;

    if(strcmp(input, "MANUALLY") == 0){

      cout << "manualy" << endl;

      int numbers;

      cout << "How many numbers would you like to add? ";
      cin >> numbers;

      for(int i = 0; i < numbers; i++){

	int numInput;

	cout << "Please enter a number: ";
	cin >> numInput;

	//call add function
	add(newTree, numInput);
	
	//then print function
	printTree(newTree, 0);

	cout << endl;
	cout << endl;
      }
      
    }else if(strcmp(input, "FILE") == 0){

      char fileName[30];

      cout << "what is the name of the file you want to use? make sure you include the file type as well (e.g. .txt)" << endl;

      cin >> fileName;
      cin.ignore();

      ifstream file;

      file.open(fileName);

      int input = 0;

      //read numbers in and add

      while(file >> input){
	//call add function
	add(newTree, input);
      }
      file.close();
      
      //print function

      printTree(newTree, 0);
      
      
    }else if(strcmp(input, "PRINT") == 0){

      cout << "print" << endl;

      //call print function

      printTree(newTree, 0);

    }else if(strcmp(input, "SEARCH")== 0){

      cout << "search" << endl;

      int value;

      cout << "What number would you like to search for? " << endl;

      cin >> value;

      if(search(newTree, value) == true){

	cout << "Number found: " << value << endl;

      }else {
	cout << "Number not found: " << value << endl;
      }
    }else if(strcmp(input, "DELETE") == 0){
      
      int toDelete;
      
      cout << "What value would you like to delete? ";
      cin >> toDelete;
      
      //call delete function
      deleteTree(newTree, toDelete);
    }else if(strcmp(input, "QUIT") == 0){
      exit(0);
    }else{
      cout << "Not a valid input. Please enter MANUALLY or FILE in that exact format." << endl;
      cin >> input;
    }
  }
  
  return 0;
}

void add(binaryTree * newTree, int toAdd){
  if(newTree->data = -1){
    newTree->data = toAdd;
    return;
  }else {
    if(toAdd < newTree->data && newTree-> left){
      newTree = newTree -> left;
      add(newTree, toAdd);
    }else if(toAdd < newTree -> data && !newTree -> left){
      binaryTree * newNode = new binaryTree();
      newNode -> data = toAdd;
      newTree->left = newNode;
      return;
    }if(toAdd > newTree->data && newTree->right){
      newTree = newTree->right;
      add(newTree, toAdd);
    }else if(toAdd > newTree->data && !newTree->right){
      binaryTree * newNode = new binaryTree();
      newNode->data = toAdd;
      newTree->right = newNode;
      return;
    }
  }
}
//similar to heap
void printTree(binaryTree * newTree, int depth){
  if(newTree -> right){
    printTree(newTree->right, depth+1);
  }

  for(int i = 0; i < depth; i++){
    cout << "\t";
    
  }
  cout << newTree->data << endl;
  if(newTree-> left){
    printTree(newTree->left, depth+1);
  }
}

binaryTree * deleteTree(binaryTree * newTree, int toDelete){

  return newTree;
}

bool search(binaryTree * newTree, int numToSearchFor){
  if(numToSearchFor == newTree->data){
    return true;
    exit(0);
  }else if(numToSearchFor < newTree->data){
    if(!newTree -> left){
      
    }else {
      search(newTree->left, numToSearchFor);
    }
  }else if(numToSearchFor > newTree->data){
    if(!newTree -> right){
      
    }else {
      search(newTree->right, numToSearchFor);
    }
  }else{
    return false;
  }
}
