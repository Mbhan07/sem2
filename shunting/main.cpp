
#include <iostream>
#include <cstring>
#include <cctype>

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

//add node to stack
void push(Node *&head, Node * thingToAdd){
  if (head = NULL) { // simple traversal here
    head = thingToAdd;
  }else {
    //temporary pointer
    Node * current = head;
    while(current -> next != NULL){
      current = current -> next;
    }
    current -> next = thingToAdd;
  }
}

Node * peek(Node * head){
  Node * current = head;
  //traversion through the list
  while (current != NULL && current -> next != NULL){
    current = current -> next;
  }

  return current;
}

//pop
void pop(Node *& head){
  Node * current = head;

  if (current -> next == NULL){
    head = NULL;
    delete current;
    return;
  }

  while(current -> next -> next != NULL){
    current = current -> next;
  }

  delete current-> next;

  current-> next = NULL;

}

//enqueue

void enqueue(Node *& head, char input){
  Node * newNode = new Node();
  newNode -> data = input;
  newNode -> next = NULL;

  if(head == NULL){
    head = newNode;
  }else {
    Node * current = head;
    while(current -> next != NULL){
      current = current -> next;
    }
    current -> next = newNode;
  }
}

//dequeue
void dequeue(Node *&head){
  Node * current = head;
  if(current -> next == NULL){
    head = NULL;
    delete current;
  }
  else if(current -> next != NULL){
    Node * temp = current -> next;
    head = NULL;
    delete current;
    head = temp;
  }
}

//precedence
int precedence(char operators){
  if (operators == '+' || operators == '-'){
    return 1;
  }else if(operators == '*' || operators == "/"){
    return 2;
  }else if(operators == '^'){
    return 3;
  }

  return 0;
}

//shunt yard method
void shuntingYard(){

}

//buiding the tree method
void treeBuilding(Node * & head){

}
//infix func
void infix(Node * head) {
  if (head != NULL){
    infix(head -> left);
    cout << head -> data << " ";
    infix(head -> right);
  }

}
//postfix func
void postfix(Node * head){
  if(head != NULL){
    postfix(head -> left);
    postfix(head -> right);
    cout << head -> data << " ";
  }
}

//prefix func
void prefix(Node * head){
  if(head != NULL){
    cout << head -> data << " ";
    prefix(head -> left);
    prefix(head -> right);
  }
}




