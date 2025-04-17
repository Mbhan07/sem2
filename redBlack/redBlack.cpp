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
node * insert(node * & root, int & num);
void fixViolations(node * & root, node * & current);
void print(node * root, int space);
void rotateLeft(node * & x, node * & root);
void rotateRight(node * & x, node * & root);

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
	current = insert(root, num);
	fixViolations(root, current);
	print(root, space);
	cout << endl;
      }
    }else if(strcmp(input, "DELETE") == 0){
      cout << "will do later" << endl;
    }else if(strcmp(input, "PRINT") == 0){
      //call print func
      print(root, space);
    }else if(strcmp(input, "FILE") == 0){
      char fileName[100];
      cout << "Please enter file name including the extension (.txt): " << endl;
      cin >> fileName;
      cin.ignore();
      ifstream file;

      file.open(fileName);

      while(file >> num){
	//do something here
	current = insert(root, num);
	fixViolations(root, current);
	//root->color = 'B';
      }

      file.close();
      //print
      print(root, space);

      
    }else if(strcmp(input, "QUIT") == 0){
      exit(0);
    }

  }
  
  return 0;
}

//insert new node in RBT (initial BST insertion step only)
node * insert(node * & root, int & num){

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
      return insert(root->left, num);
      //node * temp = root -> left; ///traverse down left subtree
      //return insert(temp, num); //recursive call on the left child

   //if the value is less and left child does not exist (insert here)
    }else if(num < root -> data && !root -> left){
      root -> left = current; //set as left child
      current -> parent = root; //set parent pointer

      return current;

  //if the value is greater and right child exist
    }if(num > root -> data && root -> right){
      return insert(root->right, num);
      //node * temp = root -> right; //traverse down the right subtree
      //return insert(temp, num); //recursive call on the right child

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

//fix violations of red-black tree properties after inserting a node
void fixViolations(node * & root, node * & current){

  //initialize helper pointers to navigate the tree structure
  node * parent = NULL;
  node * grandparent = NULL;
  node * uncle = NULL;

  //while current is not root AND current is red and parent is red
  //while((current != root) && (current-> color != 'B') && (current->parent->color == 'R'))
  while(current != root && current->parent->color == 'R'){

    cout << "Fixing violation at node: " << current -> data << endl;

    //set up the family tree relationships
    parent = current -> parent;
    grandparent = current -> parent -> parent;
    
    //if parent is left child of grandparent
    if(parent == grandparent -> left){
      uncle = grandparent -> right; //uncle is right child of grandparent

      //case 1: uncle is red
      //simply recolor
      if(uncle && uncle -> color == 'R'){
	cout << "Case 1: Recoloring. Node: " << current->data << ", Parent: " << parent->data << ", Uncle: " << uncle->data << endl;

	grandparent-> color = 'R'; //push red upwards
	parent -> color = 'B'; //fix double red
	uncle -> color = 'B'; //both children of grandparent become black
	current = grandparent; //move up 

      }else { //case 2: uncle is black or null
	cout << "Case 2 triggered (rotation). Parent: " << parent->data << ", Current: " << current->data << endl;
	
	if (current == parent -> right){ //current is right child --> need left rotation
	  cout << "Case 2a: Left Rotation at Parent: " << parent->data << endl;
	  rotateLeft(parent, root); //rotate parent to left
	  current = parent; //move current up
	  parent = current -> parent; //update parent
	}

	//case 2b: current is now a left child
	//perform right rotation on grandparent and recolor
	cout << "Case 2b: Right Rotation at Grandparent: " << grandparent->data << endl;

	rotateRight(grandparent, root);
	parent -> color = 'B'; // new parent becomes black 
	grandparent -> color = 'R'; //old grandparent becomes red
	current = parent; //move current up the tree
      }
    }
    
    //ELSE --> parent is right child of grandparent (parent case)
    else {

      uncle = grandparent -> left; //uncle is on the left side
      if (uncle == NULL){
	cout << "Uncle is NULL for node: " << current->data << endl;
      }else{
	cout << "Uncle is " << uncle->data << " and is " << (uncle->color == 'R' ? "Red" : "Black") << endl;
      }
      //case1: uncle is red
      if((uncle != NULL) && (uncle -> color == 'R')){ // 
	grandparent -> color = 'R'; //push red upwards
	parent -> color = 'B'; // fix double red
	uncle -> color = 'B'; //recolor uncle
	current = grandparent; //move up to keep checking for violations
      }else { //case 2: uncle is black or null
	if(current == parent -> left){ //subcase: current is left child, need right rotation to transform to case 2b

	  cout << "Case 2a: Right Rotation at Parent: " << parent->data << endl;
	  rotateRight(parent, root); //rotate parent to right
	  current = parent;
	  parent = current -> parent;
	}
	//case 2b: current is now a right child
	cout << "Case 2b: Left Rotation at Grandparent: " << grandparent->data << endl;
	rotateLeft(grandparent, root); //rotate grandparent left
	parent -> color = 'B'; // new parent becomes black
	grandparent -> color = 'R'; //old grandparent becomes red
	current = parent; //move current up

      }
    }
  }
  //
  //cout << "Ensuring root " << root->data << " is black." << endl;
  //set root color to black
  root -> color = 'B';
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


//https://en.wikipedia.org/wiki/Tree_rotation
//https://www.programiz.com/dsa/red-black-tree
//https://www.geeksforgeeks.org/insertion-in-red-black-tree/
//https://www.youtube.com/watch?v=dCF_d-zc_bQ

//both rotateLeft and rotateRight are very similar 
void rotateLeft(node * & x, node * & root){
  node * y = x -> right;
  x -> right = y -> left;

  //if y has a left subtree, x becomes parent of left subtree of y
  if(y -> left) {
    y->left->parent = x;
  }

  y -> parent = x->parent;

  //if parent of x is null, make y as the root of the tree
  if(x->parent == NULL){
    root = y;
  }

  //else if x is the left child of p, make y as the left child of p
  else if(x == x->parent->left){
    x->parent->left = y;
  }
  else {
    x->parent->right = y;
  }
  y->left = x;

  //make y parent of x
  //x's parent should point to y

  x->parent = y;
  
}

void rotateRight(node * & x, node * & root){
  node * y = x->left;
  x->left = y->right;

  //if x has a right subtree, assign y as the parent of the right subtree of x

  if(y->right){
    y->right->parent = x;
  }
  y->parent = x->parent;

  //if parent of y is NULL, make x as the root of the tree

  if(x->parent == NULL){
    root = y;
  }
  //else if y is the right child of parent p, make x as right child of p
  else if(x == x->parent->right){
    x->parent->right = y;
  }
  //else assignn x as left child of p
  else{
    x->parent->left = y;
  }

  y->right = x;
  //make x as parent of y
  x->parent = y;
  
}
