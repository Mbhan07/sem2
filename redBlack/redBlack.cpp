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
