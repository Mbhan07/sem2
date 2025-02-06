#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <string> // YAY, we get to use strings now!!!! I'M FREE

/*************************************************************************************
This is the hash table project, which is yet another pesky continuance of Student List.
Concepts of interests:
 - Hash Tables

List of first names and last names (sample of 500):
https://gist.github.com/elifiner/cc90fdd387449158829515782936a9a4

 Mahika Bhan, 02/01/2025
**************************************************************************************/

using namespace std;

//This project utilizes essentially the original version of Student List

//struct to represent a student
struct Student {

  //for the sake of the assignment, we will assume that the average student's name will be 30 characters or less
  char firstName[32];
  char lastName[32];
  int id;
  int hash; // this is the hash key
  float gpa;
  Student * next = NULL;
};

// function prototypes

void addName(Students** &hashtable, int &size);

void printName(vector <Student>& studentList);

void deleteName(vector <Student>& studentList);


int main(){

  //this is vector: (he is not wearing pajamas)

  //vector <Student> studentList;

  int size = 100;

  //create hashtable
  Students** hashtable = new Students*[size];

  //random generator
  srand(time(NULL));
  
  while (true){

    //get user input

    char input[31];

    cout << "Would you like to ADD, PRINT, or DELETE a student or would you like to QUIT this portal?" << endl;

    cin >> input;

    //check user input and call the appropiate function based on the response
    if(strcmp(input, "ADD") == 0){
      //call add function
      
    }else if(strcmp(input, "PRINT") == 0){
      //call print function
      
    }else if(strcmp(input, "DELETE") == 0){
      //call delete function
      
    }else if(strcmp(input, "QUIT") == 0){
      exit(0);
    }
  }

  return 0;
}


void addName(vector <Student> & studentList){

  // no global variables in C++ 🤠
  char firstName[31];
  char lastName[31];
  int id;
  float gpa;

  //prompt user for the information needed to add a student to the student list"

  cout << "Please enter the student's first name: ";

  cin >> firstName;

  cout << "Please enter the student's last name: ";

  cin >> lastName;

  cout << "Please enter the student's ID number: ";

  cin >> id;

  cout << "Please enter the student's GPA: ";

  cin >> gpa;

  //add to struct

  Student newPerson;

  //using strcpy to transfer the first name and last name char arrays into the struct
  strcpy(newPerson.firstName, firstName);
  strcpy(newPerson.lastName, lastName);

  
  // no need for strcpy as these are just ints/floats, so just adding into the struct
  newPerson.id = id;
  newPerson.gpa = gpa;

  
  //add newly created student to the studentList vector
  studentList.push_back(newPerson);

}

void printName(vector <Student> & studentList){

  // test case
  //cout << "Come back to this" << endl;

  //create an iterator for the vector, called myItr
  vector < Student> :: iterator myItr;

  //iterate through eachstudent in the studentList and print last name, first name, gpa, id
  for(myItr = studentList.begin(); myItr != studentList.end(); myItr++){
    cout << myItr->firstName << " " << myItr->lastName << " , "
         << myItr->id << " , " << fixed << setprecision(2) << myItr->gpa << endl;
  }  

  //source for using iterators for vectors: https://www.geeksforgeeks.org/how-to-use-iterator-with-vector-in-cpp/
  
}


void deleteName(vector <Student> & studentList){

  //to hold the id of the student to be delted
  int deleteID;
  
  //get user input about which student to delete
  cout << "Enter the student's ID number: " << endl;

  cin >> deleteID;

  //counter to keep track of position in the vector
  int index = 0;

  //create an iterator to go through the vector called myIterator
  vector < Student> :: iterator myIterator;


  //find the student with the given ID
  for(myIterator = studentList.begin(); myIterator != studentList.end(); myIterator++){
    index = index + 1; //increment for each student in the list

    //check if the current student's ID matches the ID to delete

    // '->' is used to access id from Student, essentially like a pointer
    if(myIterator ->id == deleteID){

      int value = index - 1;

      //erase the student from the vector if a match is found

      studentList.erase(studentList.begin() + value);

      //exit the loop after deleted the statement
      break;
      
    }else { //otherwise continue as usual
      ;
    }
  }
  //for easse of use, notify the user that student has been deleted
  cout << "The student has been deleted from the system." << endl;
}
