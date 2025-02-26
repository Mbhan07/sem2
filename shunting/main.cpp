
#include <iostream>
#include <cstring>

using namespace std;

/******************************************
This is Shunting Yard, Mahika Bhan, 03/21/2025

The purpose of this project is to implement the Shunting Yard algorithim, to convert infix expressions into postfix notation, build a binary expression tree, and allows for users to output the expression in prefix, infix, or postfix notation using recursive tree traversal. It requires implementing a stack and queue using linked lists, constructing a binary tree, and ensuring that the program understands the math expression entered by the user, and that it properly converts it from one format to anotehr before buiding the expression tree. 
*/

//gonna need a node struct

Struct Node {
  
  char data;
  node * next;

  //left and right pointers --> similar to heap
  node * right;
  node * left;

};

//probably would need a struct for the nodes in the tree as well


//function prototypes go here

//main logic goes here
int main(){

  return 0;
}


//probably need function for infix, prefix, postfic

//probably need function to build the tree
