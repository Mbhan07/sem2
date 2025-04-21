
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/******************************************
This is Shunting Yard, Mahika Bhan, 03/21/2025

The purpose of this project is to implement the Shunting Yard algorithim, to convert infix expressions into postfix notation, build a binary expression tree, and allows for users to output the expression in prefix, infix, or postfix notation using recursive tree traversal. It requires implementing a stack and queue using linked lists, constructing a binary tree, and ensuring that the program understands the math expression entered by the user, and that it properly converts it from one format to anotehr before buiding the expression tree. 
*/

//gonna need a node struct

//checking if we a r okay here in terms of git
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
    cout << endl;
    cout << "Please enter a fully parenthesized mathematical expression (space-separated tokens only).\n"
     << "Note: You must use parentheses to enforce order of operations. For example:\n"
     << "Instead of:     3 + 4 * 2 / (1 - 5) ^ 2 ^ 3\n"
     << "Enter it as:    3 + ((4 * 2) / ((1 - 5) ^ (2 ^ 3)))\n";

    cout << endl;
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

    output[a] = '\0';
    /// now we need to do the boogie
    shuntingYard(head, output);
    treeBuilding(head);
    //call shunting yard function
    //build the tree
    while (true){
      char secondInput[100];

 
      cout << "How would you like to display this? Prefix (Pr), Postfix (Po), Infix (In), QUIT, or NEW: ";

      cin.getline(secondInput, 100, '\n');

      if(strcmp(secondInput, "Pr") == 0){
	cout << "prefix" << endl;
	prefix(head);
	cout << endl;
	//break;
      }else if(strcmp(secondInput, "Po") == 0){
	cout << "postfix"<< endl;
	postfix(head);
	cout << endl;
      }else if(strcmp(secondInput, "In") == 0){
	cout << "infix" << endl;
	infix(head);
	cout << endl;
      }else if(strcmp(secondInput, "QUIT") == 0){
	cout << "quit";
	exit(0);
      }else if(strcmp(secondInput, "NEW") == 0){
	cout << endl;
	main();
      }else{
	cout << endl;
	cout << "Invalid input. Please enter Pr. Po, In, or QUIT. " << endl;
      }

    }
  }
  return 0;
}

//add node to stack
void push(Node *&head, Node * thingToAdd){
  if (head == NULL) { // simple traversal here
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
  if(!head){
    return;
  }
  Node * temp = head -> next;
  delete head;
  head = temp;

  /*node * current = head;
  if(current -> next == NULL){
    head = NULL;
    delete current;
  }else if(current->next != NULL){
    node * temp = current -> next;
    head = NULL;
    delete current;
    head = temp;
  } //maybe recoding will nh
  /*Node * current = head;
  if(current -> next == NULL){
    head = NULL;
    delete current;
  }
  else if(current -> next != NULL){
    Node * temp = current -> next;
    head = NULL;
    delete current;
    head = temp;
    }*/
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

  head = NULL;
  Node * stackOperator = NULL;
  
  cout << "Input Expression: " << output << endl;
  int length = strlen(output);
  
  for (int i = 0; i < length; i++){
    cout << "\n--- Processing token: " << output[i] << " ---" << endl;

    
    if(isdigit(output[i])){ //if digit
      enqueue(head, output[i]);

      cout << "Added digit to output queue: " << output[i] << endl;
    }
    //open parantehsis
    else if(output[i] == '(') {
      
      
      Node * temp = new Node();
      temp -> data = '(';
      temp -> next = NULL;
      temp -> right = NULL;
      temp -> left = NULL;

      push(stackOperator, temp);

      cout << "Pushed '(' to operator stack" << endl;
      
    } //closed parentheses
    else if(output[i] == ')'){
      cout << "Handling ')' - popping until '(' found" << endl;
      while(peek(stackOperator) && peek(stackOperator) -> data != '('){
	 cout << "Popping " << peek(stackOperator)->data << " from operator stack to output queue" << endl;
	enqueue(head, peek(stackOperator) -> data);
	
	pop(stackOperator);
      }
      if(peek(stackOperator) && peek(stackOperator) -> data == '('){
        cout << "Popped '('" << endl;
	pop(stackOperator);
      }
    }
    else if(!isdigit(output[i]) && output[i] != '(' && output[i] != ')'){
      cout << "Handling operator: " << output[i] << endl;
      
      while(peek(stackOperator) && precedence(peek(stackOperator) -> data) >= precedence(output[i]) && output[i] != '^'){
	 cout << "Popping " << peek(stackOperator)->data << " from operator stack to output queue (due to precedence)" << endl;
	enqueue(head, peek(stackOperator) -> data);
	pop(stackOperator);
      }
      
      Node * temp = new Node();
      temp -> data = output[i];
      temp -> next = NULL;
      temp -> right = NULL;
      temp -> left = NULL;
      push(stackOperator, temp);
      cout << "Pushed operator to stack: " << output[i] << endl;
    }
    // Debug current operator stack (top only)
    if (peek(stackOperator)) {
      cout << "Top of operator stack: " << peek(stackOperator)->data << endl;
    } else {
      cout << "Operator stack is empty." << endl;
    }

    // Debug current output queue
    cout << "Current output queue: ";
    Node* temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  //idk whatever this is but chatGPT reccomended it for debugging when i asked it what else to print out LOLOL
  cout << "\n--- Draining remaining operators to output queue ---" << endl;
  while(stackOperator != NULL){
    cout << "Moving " << peek(stackOperator)->data << " from stack to output queue" << endl;
    enqueue(head, peek(stackOperator)-> data);
    pop(stackOperator);
  }

  cout << "\nFinal Postfix Queue: ";
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
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

      /* TEST CASES
	 2 + 3
	 2 + 3 * 4

      */


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

      pop(stackOperand);
      
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




