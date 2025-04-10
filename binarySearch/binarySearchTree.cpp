#include <iostream>
#include <cstring>
#include <fstream>

struct binaryTree{
  int data;
  binaryTree * right;
  binaryTree * left;
};


using namespace std;

int main(){
  char input[100];

  cout << "Would you like to read in numbers MANUALLY (1-999, separated by a single space) or through a FILE?" << endl;
  cin >> input;

  if(strcmp(input, MANUALLY) == 0){
    cout << "manualy" << endl;
  }else if(strcmp(input, FILE) == 0){
    char fileName[30];
    cout << "what is the name of the file you want to use? make sure you include the file type as well (e.g. .txt)" << endl;
    
    
  }else{
    cout << "Not a valid input. Please enter MANUALLY or FILE in that exact format." << endl;
  }
  
  return 0;
}
