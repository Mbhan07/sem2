
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/******************************************
This is Shunting Yard, Mahika Bhan, 03/21/2025

The purpose of this project is to implement the Shunting Yard algorithim, to convert infix expressions into postfix notation, build a binary expression tree, and allows for users to output the expression in prefix, infix, or postfix notation using recursive tree traversal. It requires implementing a stack and queue using linked lists, constructing a binary tree, and ensuring that the program understands the math expression entered by the user, and that it properly converts it from one format to anotehr before buiding the expression tree. 
*/

//gonna need a node struct

struct Node {
  
  char data;
  Node * next;

  //left and right pointers --> similar to heap
  Node * right;
  Node * left;

};


//function prototypes go here

void push(Node *&head, Node * thingToAdd);
Node * peek(Node * head);
void pop(Node *&head);

void infix(Node * head);
void postfix(Node * head);
void prefix(Node * head);

void enqueue(Node *&head, char input);
void dequeue(Node * &head);

void treeBuilding(Node *&head);
void shuntingYard(Node *&head, char * output);

//main logic goes here
int main(){
  Node * head = NULL;
  while (true){
    char input[101];
    cout << "Please enter an equation: " << endl;
    cin.getline(input, 100, '\n');
    int length = strlen(input);
    char output[101];
    char random = 0;

    //essentialy copy over to output from input the non-input with the non-space
    int a = 0;
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
	cout << "quit";
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
  }else if(operators == '*' || operators == '/'){
    return 2;
  }else if(operators == '^'){
    return 3;
  }

  return 0;
}

//shunt yard method
void shuntingYard(Node * & head, char * output){
  cout << "Input Expression: " << output << endl;
  int length = strlen(output);
  Node * stackOperator = NULL; //we're gonna need this later
  for (int i = 0; i < length; i++){
    if(isdigit(output[i])){ //if digit
      enqueue(head, output[i]);
    }
    //open parantehsis
    else if(output[i] == '(') {
      Node * temp = new Node();
      temp -> data = '(';
      temp -> next = NULL;
      temp -> right = NULL;
      temp -> left = NULL;

      push(stackOperator, temp);
      
    } //closed parentheses
    else if(output[i] == ')'){
      while(peek(stackOperator) && peek(stackOperator) -> data != '('){
	enqueue(head, peek(stackOperator) -> data);
	pop(stackOperator);
      }
      if(peek(stackOperator) && peek(stackOperator) -> data == 'C'){
	pop(stackOperator);
      }
    }
    else if(!isdigit(output[i]) && output[i] != '(' && output[i] != ')'){
      while(peek(stackOperator) && precedence(peek(stackOperator) -> data) >= precedence(output[i]) && output[i] != '^'){
	enqueue(head, peek(stackOperator) -> data);
	pop(stackOperator);
      }
      Node * temp = new Node();
      temp -> data = output[i];
      temp -> next = NULL;
      temp -> right = NULL;
      temp -> left = NULL;
      push(stackOperator, temp);
    }
  }
  while(stackOperator != NULL){
    enqueue(head, peek(stackOperator)-> data);
    pop(stackOperator);
  }
}

//buiding the tree method
void treeBuilding(Node * & head){
  Node * current = head;

  Node * stackOperand = NULL;
  
  while (current != NULL){
    if(isdigit(current -> data)){
      //create new node and push out to stack
      Node * nodeOperand = new Node();
      //store operand data
      nodeOperand -> data = current -> data;
      push(stackOperand, nodeOperand); // pushoperand onto operand stack
    }else {
      
      Node * nodeOperator = new Node();
      nodeOperator -> data = current -> data;
      Node * rightOperand = new Node();

      rightOperand -> data = peek(stackOperand) -> data;
      rightOperand -> right = peek(stackOperand) -> right;
      rightOperand -> left = peek(stackOperand) -> left;

      nodeOperator -> right = rightOperand;

      pop(stackOperand);

      Node * leftOperand = new Node();

      leftOperand -> data = peek(stackOperand) -> data;
      leftOperand -> right = peek(stackOperand) -> right;
      leftOperand -> left = peek(stackOperand) -> left;

      nodeOperator-> left = leftOperand; 


      //push(stackOperand, nodeOperand);
      push(stackOperand, nodeOperator);
    }

    dequeue(head);
    current = head;
  }

  head = peek(stackOperand);
  
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




