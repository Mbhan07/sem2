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
struct Students {

  //for the sake of the assignment, we will assume that the average student's name will be 30 characters or less
  char firstName[32];
  char lastName[32];
  int id;
  int hash; // this is the hash key
  float gpa;
  Student * next = NULL;
};

// this is what the function should look like....

void addName(Students** &hashtable, int &size);

void GenerateName(Students** &hashtable, int &size);

Students** add(Student * student, Students** &hashtable, int &size);

void printName(Students** &hashtable, int &size);

Students** deleteName(Students** &hashtable, int &size);



int main(){

  //this is vector: (he is not wearing pajamas) --> i can't bear to delete this so let's commemorate my amazing sense of humor with a homage to my old despicable-me themed comments

  //vector <Student> studentList;

  int size = 100;

  //create hashtable
  Students** hashtable = new Students*[size];

  //random generator
  srand(time(NULL));
  
  while (true){

    //get user input

    char input[31];

    cout << "Would you like to ADD, GENERATE, PRINT, or DELETE a student or would you like to QUIT this portal?" << endl;

    cin >> input;

    //check user input and call the appropiate function based on the response
    if(strcmp(input, "ADD") == 0){

      //call add function
      AddName(hashtable, size);
    // may need to generate here
    }else if(strcmp(input, "GENERATE") == 0){
      GenerateName(hashtable, size);
      
    }else if(strcmp(input, "PRINT") == 0){

      //call print function
      printName(hashtable, size);
      
    }else if(strcmp(input, "DELETE") == 0){

      //call delete function
      deleteName(hashtable, size);
      
    }else if(strcmp(input, "QUIT") == 0){
      exit(0);
    }
  }

  return 0;
}


void addName(Students** &hashtable, int &size){

  //all variables that contain information needed from user
  char firstName[31];
  char lastName[31];
  int id;
  float gpa;

  Students* student = new Students();
  
  //prompt user for the information needed to add a student to the student hashtable

  cout << "Please enter the student's first name: ";

  cin >> firstName;

  cout << "Please enter the student's last name: ";

  cin >> lastName;

  cout << "Please enter the student's ID number: ";

  cin >> id;

  cout << "Please enter the student's GPA: ";

  cin >> gpa;

  //push to struct

  hashtable = add(student,hashtable, size);

  /*using strcpy to transfer the first name and last name char arrays into the struct
  strcpy(newPerson.firstName, firstName);
  strcpy(newPerson.lastName, lastName);

  
  // no need for strcpy as these are just ints/floats, so just adding into the struct
  newPerson.id = id;
  newPerson.gpa = gpa;

  
  //add newly created student to the studentList vector
  studentList.push_back(newPerson);*/

}

//used fstream documentation for help here: https://www.w3schools.com/cpp/ref_fstream_fstream.asp
//need a func to generate here
void GenerateName(students** &hashtable, int &size){
  cout << "How many students would you like to add" << endl;
  int studentNum;

  cin >> studentNum;

  //iterate through the students

  for (int i = 0; i < studentNum; i++){
    ifstream first("firstNames.txt");

    //there are 500 names in the firstNames.txt file, so need to generate random number betwen 0 and 500
    int randomNum = rand()%500;

    //let's assume that the average first name is 50 characters or less
    char first_Name[50];
    for (int i = 1; i <= randomNum; i ++){
      //break this down later from documentation (gist is copying over)
      first.getline(first_Name, sizeof(first_Name));
    }
    first.close();
  
  //same as above
  ifstream last("lastNames.txt");
  int randomerNum = rand()% 500;
  char last_Name[50];
  for (int j = 1; j <= randomerNum; j++){
    last.getline(last_Name, sizeof(last_Name));
  }
  last.close();

  //new student
  Students* student = new Students();
  //transfer over first name, last name, id gpa
  strcpy(student -> firstName, first_Name);
  cout << student -> firstName << endl;
  strcpy(student -> lastName, last_Name);
  cout << student -> lastName << endl;

  //iud caan be randomized
  int id = 100000 + rand()% 900000;
  student -> id = id;
  
  //float to two decimal places
  float gpa = (double)(rand()%41)/(10.0);
  student -> gpa = gpa;
  hashtable  = add(student, hashtable, size);
  }
}
//need a func to check for collisions
Students** add(Students * student, Students** &hashtable, int &size){

  //get to current spot in hashtable
  Students* current = hashtable[student->hash]
  int collisions = 0;

  //if no student in current space, add to hashtable
  if(current == NULL){
    hashtable[student->hash] = student;
  }else { //otherwise,if there is already something there
    while (current -> next != NULL){
      current = current -> next;
      collision++;
      cout << "if this is printing, then a collision occurred" << endl;
    }
    current -> next = student;
  }

  //acount for case of three collisions by rehashing the table (lord give me the strength to get through this.........)

  if (collisions == 3){
    //new tqable
    Students** newHashTable = new Students*[size*2]();
    //iterate through the table
    for (int i = 0; i < size; i++){
      Students* currentTemporary = hashtable[i];

      //ensure IDS are distributed evenly along larger table as part of resizing
      while (currentTemporary != NULL){
	int newHash = student -> id % (size % 2);
      }
    }
  }  
}

void printName(Students** &hashtable, int &size){
  for (int i = 0; i < size; i++){
    if(hashtable[i] != NULL){
      
      cout << hashtable[i]-> firstName << " " << hashtable[i]-> lastName << ", " << hashtable[i] -> id << ", " << hashtable[i] -> gpa << endl;
      Students * current = hashtable[i];
      while (current ->next != NULL){
	current = current -> next;
	cout << current-> firstName << " " << current->lastName << "," << current->id << "," << current->gpa << endl;
      }
    }else {
      ;
    }
  }
}


Students** deleteName(Students** &hashtable, int &size){

  //to hold the id of the student to be delted
  int deleteID;
  
  //get user input about which student to delete
  cout << "Enter the student's ID number that you want to delete : " << endl;

  cin >> deleteID;

  for (int i = 0; i < size; i++){
    if(hashtable[i] != NULL){
      Students* current = hashtable[i];
      Students* prev = NULL;

      while (current != NULL){
	if (current -> id == input){
	  if (prev == NULL){
	    hashtable[i] = current -> next;
	  }else {
	    prev-> next = current->next;
	  }
	  return hashtable;
	}
	prev = current;
	current = current->next;
      }
    }
    else {
      ;
    }
  }
  return hashtable;
}
