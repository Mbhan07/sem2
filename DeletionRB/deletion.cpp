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

/* this is red black tree DELETION by Mahika Bhan. Due May 16th, 2025

   https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea

   https://www.geeksforgeeks.org/deletion-in-red-black-tree/
   Mahika Bhan
*/

//func prototypes go here:
node * insert(node * & root, int & num);
void fixViolations(node * & root, node * & current);
void print(node * root, int space);
void rotateLeft(node * & x, node * & root);
void rotateRight(node * & x, node * & root);
void deletion(node * & root, int num);
node * minimum(node * root);
bool search(node * root, int numToSearch);


int main(){
  node * root = NULL;
  int space = 0;

  node * current = NULL;
  int num;

  while(true){
    char input[100];

    cout << "What would you like to do? add MANUALLY, from a FILE, PRINT, DELETE, SEARCH, or QUIT?" << endl;

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
      cout << "What number do you want to delete?" << endl;
      int numInput;
      cin >> numInput;
      deletion(root, numInput);
    }else if(strcmp(input, "PRINT") == 0){
      //call print func
      print(root, space);
    }else if(strcmp(input, "SEARCH") == 0){
      cout << "What number would you like to search for? " << endl;
      cin >> num;
      if(search(root, num)){
	cout << "Found it: " << num << endl;
      }else{
	cout << "Not Present: " << num << endl;
      }
    
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

node * minimum(node * root){
  while (root -> left != NULL){
    root = root -> left;
  }

  return root;

}

bool search(node * root, int numToSearch){
  if (root == NULL){
    return false;
  }
  if(numToSearch == root -> data){
    return true;
  }
  if(numToSearch < root -> data){
    return search(root -> left, numToSearch);
  }else {
    return search(root -> right, numToSearch);
  }

}


//delete a node based on value inputted from user

void deletion(node * & root, int num){

  //let's get fired up by "targeting" a node

  node * target = root;

  //while we have not found the "target node" with the correct data value

  while(target && target -> data != num){

    // if value we're looking for is less than the current node's data
    if(num < target -> data){

      //move to the left child
      
      target = target -> left;

      
    }else { //else move to the right child 
      target = target -> right;
    }
 }
    //if number not in the tree, node not found

  if(!target){
     cout << "Node not found " << endl;
     return;
  }

  //y will be used to track the node actually removed or moved
  node * y = target;

  //store color of y, since deletion depends on whether its red or black

  char yOGcolor = y -> color;

  //x will eventually replace y in the tree
  node * x = NULL;

  //keep track of x parent, just in case

  node * xParent = NULL;


  /*according to gfg, "If the node has two children, find its successor and copy successor's value
This is standard two-child deletion logic from a binary search tree (BST),
with color tracking added for red-black tree fix-up later
(Finding the predecessor would be symmetric: maximum(target->left))" */

  
  if(target -> left && target -> right){
    y = minimum(target->right); //find the in order successor (smallest node in right subtree)
    yOGcolor = y -> color; //save original color
    target -> data = y -> data; //replace target data with successor data
    target = y; //now treat successor node as the node to actually delete
    
  }

  //the following logic is from gfg

  //replace target with its only child (or null if it has no children)

  x = (target -> left) ? target -> left: target -> right;
  xParent = target -> parent;

  // if x exists, update parent pointer to bypass the target node
  if (x){
    x -> parent = target -> parent;

  //if target node is the root, update the root pointer
  }if (!target-> parent){
    root = x;
  }else if(target == target -> parent -> left){ //else, update the appropiate child pointer of the parent
    target -> parent -> left = x;
  }else {
    target -> parent -> right = x;
  }

  // if the original node being deleted was black, we may have violated red-black properties
  if(yOGcolor == 'B'){

    //continue fixing up as long as x is not the root and is either null or black
    while (x != root && (!x || x -> color == 'B')){
      if (x == xParent -> left){
	node * sibling = xParent -> right; //get sibling of x

	//case 1: x sibling is red
	//recolor and perform a left rotation to transform into a case where sibling is black
	if (sibling && sibling -> color == 'R'){
	  sibling -> color = 'B'; //recolor sibling to black
	  xParent -> color = 'R'; //recolor parent to red

	  rotateLeft(xParent, root); // rotate to make sibling black and move up

	  sibling = xParent -> right; // update sibling after rotation
	}

	//case 2: sibling is black, and both of sibling's children are black
	//recolor sibling to red and move the problem up to the parent
	if ((!sibling -> left || sibling -> left -> color  == 'B') && (!sibling -> right || sibling -> right -> color  == 'B')){
	  if (sibling){
	    sibling -> color = 'R';
	  }
	  x = xParent;
	  xParent = x -> parent;
	//case 3 or 4: at least one red child exists on the sibling
	  
	}else {
	  //transform into case 4 by right rotating the sibling
	  if (!sibling -> right || sibling -> right -> color == 'B'){
	    if (sibling -> left) sibling -> left -> color = 'B';
	    sibling -> color = 'R';
	    rotateRight(sibling, root);
	    sibling = xParent -> right; //update sibling after rotatoin
	  }

	  //case 4: sibling is black, and its right child is red
	  //recolor and left rotate parent to fix double black
	  sibling -> color = xParent -> color;
	  xParent -> color = 'B';
	  if(sibling -> right) sibling -> right -> color = 'B';
	  rotateLeft(xParent, root);
	  break;

	}
      }else { //basically the same but for the left side
	node * sibling = xParent -> left;

	//case 1: red sibling
	if(sibling && sibling -> color == 'R'){
	  sibling -> color = 'B';
	  xParent -> color = 'R';
	  rotateRight(xParent, root);
	  sibling = xParent -> left;
	}

	//case 2: black sibling with two black children
	if((!sibling -> left || sibling -> left -> color == 'B') &&
	   (!sibling -> right || sibling -> right -> color == 'B')){
	  if (sibling) sibling -> color = 'R';
	  x = xParent;
	  xParent = xParent -> parent;
	}else {
	  if(!sibling -> left || sibling -> left -> color == 'B'){
	    if (sibling -> right) sibling -> right -> color = 'B';
	    sibling -> color = 'R';
	    rotateLeft(sibling, root);
	    sibling = xParent -> left;
	  }

	  //case 4: black sibling left child red
	  sibling -> color = xParent -> color;
	  xParent -> color = 'B';
	  if(sibling -> left) sibling -> left -> color = 'B';
	  rotateRight(xParent, root);
	  x = root;
	  break;

	}
      }
    }

    //once fix up is complete, make sure x (if not null) is black)
    if (x) {
      x -> color = 'B';
    }

  }

  //finally, delete the original node
  delete target;
  
  
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
