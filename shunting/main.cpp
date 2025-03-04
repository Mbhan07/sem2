
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

void push();
//void 

//probably would need a struct for the nodes in the tree as well


//function prototypes go here

//main logic goes here
int main(){
  Node * head = NULL;
  while true(){
    char input[101];
    cin << "Please enter yadayadyaydayadyayadyayadq" << endl;
    cin.getline(input, 100, '\n');
    int length = strlen(input);
    char output[101];
    char random = 0;

    //essentialy copy over to output from input the non-input with the non-space
    for (int i = 0; i < length; i++){
      if (input[i] != ' '){
	output[a] = input [i];
	a++;
      }
    }
    /// now we need to do the boogie

    //call shunting yard function
    //build the tree
    while (true){
      char secondInput[42];
      
      cout << "How would you like to display this? Prefix (Pr), Postfix (Po), Infix (In), etc...";

      cin.getline(secondInput, 40, '\n');

      if(strcmp(secondInput, "Pr") == 0){
	cout << "prefix" << endl;
      }else if(strcmp(secondInput, "Po") == 0){
	cout << "postfix"<< endl;
      }else if(strcmp(secondInput, "In") == 0){
	cout << "infix" << endl;
      }else if(strcmp(secondInput, "QUIT") == 0){
	cout "quit";
	exit(0);
      }

    }
  }
  return 0;
}


//probably need function for infix, prefix, postfic

//probably need function to build the tree
