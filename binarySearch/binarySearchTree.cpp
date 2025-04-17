#include <iostream>
#include <cstring>
#include <fstream>


//making sure i have everything
//doubly linked list struct to represent binary tree
struct binaryTree{
  int data;
  binaryTree * right; //right points to greater values
  binaryTree * left; //left points to lesser values
};

//function prototypes for add, print, search, and delete functions

void add(binaryTree * newTree, int toAdd); //add value to BST
void printTree(binaryTree * newTree, int depth); // display BST
binaryTree * deleteTree(binaryTree * newTree, int toDelete); //delete value from BST
bool search(binaryTree * newTree, int numToSearchFor); //search for value in BST

using namespace std;

int main(){

  //make a new tree + set root node = -1 (indicates an empty tree)
  binaryTree * newTree = new binaryTree();
  newTree -> data = -1;

  while (true){
    char input[100];

    //figure out what user wants to do
    cout << "Would you like to read in numbers MANUALLY (1-999, separated by a single space), through a FILE, PRINT, SEARCH, DELETE, or QUIT?" << endl;
    cin >> input;

    if(strcmp(input, "MANUALLY") == 0){

      //cout << "manualy" << endl;

      int numbers;

      cout << "How many numbers would you like to add? ";
      cin >> numbers;

      for(int i = 0; i < numbers; i++){

	int numInput;

	cout << "Please enter a number: ";
	cin >> numInput;

	//call add function to insert into BST
	add(newTree, numInput);
	
	//then print function to display BST
	printTree(newTree, 0);

	//cout << endl;
	cout << endl;
      }
      
    }else if(strcmp(input, "FILE") == 0){

      char fileName[30];

      //read in file via fstream
      cout << "what is the name of the file you want to use? make sure you include the file type as well (e.g. .txt)" << endl;

      //get filename
      cin >> fileName;
      cin.ignore();

      ifstream file;

      file.open(fileName);

      int input = 0;

      //read numbers in and add

      while(file >> input){
	//call add function to add each number from the file 
	add(newTree, input);
      }
      file.close();
      
      //print function

      printTree(newTree, 0); //print full tree after file input
      
      
    }else if(strcmp(input, "PRINT") == 0){

      //cout << "print" << endl;

      //call print function

      printTree(newTree, 0);

    }else if(strcmp(input, "SEARCH")== 0){

      //cout << "search" << endl;

      int value;

      cout << "What number would you like to search for? " << endl;

      cin >> value;

      //if search returns true, then value is found
      if(search(newTree, value) == true){

	cout << "Number found: " << value << endl;

      }else {//else value not found
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

//add new value into the binary tree
void add(binaryTree * newTree, int toAdd){
  if(newTree->data == -1){
    //tree is empty (first value), just send root
    newTree->data = toAdd;
    return;
  }else {
    //go left if value is smaller
    if(toAdd < newTree->data && newTree-> left){
      newTree = newTree -> left;
      add(newTree, toAdd);
      
    }else if(toAdd < newTree -> data && !newTree -> left){
      binaryTree * newNode = new binaryTree();
      newNode -> data = toAdd;
      newTree->left = newNode;
      return;

    //go right if value is larger
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
//similar to heap, print BST rotates sideways
void printTree(binaryTree * newTree, int depth){
  if(newTree -> right){
    printTree(newTree->right, depth+1); //right child first(will appear on top)
  }

  for(int i = 0; i < depth; i++){
    cout << "\t"; //indent based on tree depth
    
  }
  cout << newTree->data << endl;
  if(newTree-> left){
    printTree(newTree->left, depth+1); //left child second (will appear below)
  }
}

binaryTree * deleteTree(binaryTree * newTree, int toDelete){
  if(newTree == NULL){
    return newTree;
  }if(newTree->data > toDelete){
    newTree->left = deleteTree(newTree->left, toDelete); //search left
  }else if(newTree->data < toDelete){
    newTree->right = deleteTree(newTree->right, toDelete); //search right
  }else { //actually deletion now because node found
    if(newTree->left == NULL){
      binaryTree * temp = newTree->right;
      delete newTree;
      return temp;
    }if(newTree->right == NULL){

      binaryTree * temp = newTree->left;
      delete newTree;
      return temp;
    }else { //node with two children, replace with inorder successor 
      binaryTree * beginning = newTree -> right;
      while(beginning->left != NULL){
	beginning = beginning->left;
      }//replace current w successor, delete successor
      binaryTree * smallest = beginning;
      newTree->data = smallest->data;
      newTree->right = deleteTree(newTree->right, smallest->data);
    }
  }
  
  return newTree;
}

//recursively search for value in BST
bool search(binaryTree * newTree, int numToSearchFor){
  //base case where we reach a null node
  if(newTree == NULL){
    return false;
  //value matches current node's data
  }if(numToSearchFor == newTree->data){
    return true;
  //if value is smaller, search left subtree
  }else if(numToSearchFor < newTree->data){
    return search(newTree->left, numToSearchFor);
  //if value is greater, search right tree
  }else{
    return search(newTree->right, numToSearchFor);
  }
  /*
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

  return false;*/
}


//7 numbers: 50 30 70 20 40 60 80
