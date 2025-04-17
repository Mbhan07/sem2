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

node * insert(noot * & root, int & num){
  //create new node w/ num
  //set color to red
  //set left, set right, set parent to NULL


  //if root is NULL, set root to new node and return root

  //transverse BST recursively
  
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
  //if root is null, return

  //increase space and print

  //print indentation then print
  
}

void rotateLeft(node * & x, node * & root){
  //
}

void rotateRight(node * & x, node * & root){

}
