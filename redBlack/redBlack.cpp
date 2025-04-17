#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//creating node struct with data, color (red/black), left & right pinter, and parent node
struct node {
  int data;
  char color;
  node * left;
  node * right;
  node * parent;

};

/* Red black insertion by Mahika Bhan. Due APril 11th, 2025

   Mahika Bhan
*/

//func prototypes go here:

int main(){
  node * root = NULL;
  int space = 0;

  node * current = NULL;
  int num;

  while(true){
    char input[100];

    cout << "What would you like to do? add MANUALLY, from a FILE, PRINT, DELETE, or QUIT?" << endl;

    cin >> input;

    if(strcmp(input, "MANUALLY") == 0){
      int numbers;
      cout << "How many numbers would you like to add? ";
      cin >> numbers;

      for(int i = 0; i < numbers; i++){
	cout << "Please enter a number: ";
	cin >> num;

	cout << endl;
	
      }
    }else if(strcmp(input, "DELETE") == 0){
      cout << "will do later" << endl;
    }else if(strcmp(input, "PRINT") == 0){
      //call print func
    }else if(strcmp(input, "FILE") == 0){
      char fileName[100];
      cout << "Please enter file name including the extension (.txt): " << endl;
      cin >> fileName;
      cin.ignore();
      ifstream file;

      file.open(fileName);

      while(file >> num){
	//do something here
      }

      file.close();
      //print

      
    }else if(strcmp(input, "QUIT") == 0){
      exit(0);
    }

  }
  
  return 0;
}

//insert new node in RBT (initial BST insertion step only)
node * insert(noot * & root, int & num){

  //create new node w/ num
  //set color to red
  //set left, set right, set parent to NULL
  node * current = new node();
  current -> data = num;
  current -> color = 'R';
  current -> left = NULL;
  current -> right = NULL;
  current -> parent = NULL;
  
  //if root is NULL, set root to new node and return root
  if(root == NULL){
    root = current; //the root must be black  - handeled later in violations method
    return root;
  }else { //transverse BST recursively

    //If the value is less than the current node's data and left child exists
    if(num < root->data && root -> left){
      node * temp = root -> left; ///traverse down left subtree
      return insert(temp, num); //recursive call on the left child

   //if the value is less and left child does not exist (insert here)
    }else if(num < root -> data && !root -> left){
      root -> left = current; //set as left child
      current -> parent = root; //set parent pointer

      return current;

  //if the value is greater and right child exist
    }if(num > root -> data && root -> right){
      node * temp = root -> right; //traverse down the right subtree
      return insert(temp, num); //recursive call on the right child

  //if the value is greater and right child does not exist (insert here)
    }else if(num > root -> data && !root -> right){
      root -> right = current; //set as right child
      current -> parent = root; //set parent pointer

      return current;
    }
  }

  //just a default return
  return NULL;
  
}
void fixViolations(node * & root, node * & current){
  //while current is not root AND current is red and parent is red

       //if parent is left child of grandparent

          //case 1: uncle is red
          //case 2: unclie is black or null

      //ELSE
         //case 1: uncle is red
         //case 2: uncle is black or null

  //set root color to black
}

void print(node * root, int space){
  //if root is null, return and our base case!
  if(root == NULL){
    return;
  }
  //tree indented 5 spaces than previous level

  int count = 5;
  space += count;

  print(root -> right, space);

  cout << endl;

  for(int i = count; i < space; i++){
    cout << " ";
  }
  //increase space and print

  //print indentation then print


  //display color to understand what we're looking at!

  if(root -> color == 'R'){
    cout << root -> data << " (R)" << endl;
  }if(root -> color == 'B'){
    cout << root -> data << " (B)" << endl;
  }

  //print recursive call
  print(root -> left, space);
}

void rotateLeft(node * & x, node * & root){
  //
}

void rotateRight(node * & x, node * & root){

}
