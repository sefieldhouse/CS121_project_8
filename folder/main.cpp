#include <iostream>
#include "date.h"
#include "address.h"
#include "student.h"
#include <vector>
#include <string>
#include <cstdio>

void testAddress();
void testDate();
void testStudent();

void loadStudents(std::vector<Student*>&);
void printStudents(std::vector<Student*>&);
void showStudentNames(std::vector<Student*>&);
void findStudent(std::vector<Student*>&);
void delStudents(std::vector<Student*>&);
std::string menu();

int main(){
  std::vector<Student*> students;

  loadStudents(students);

  std::string choice;

  do {
    choice = menu();

    if(choice == "1"){
      showStudentNames(students);
    }
    else if(choice == "2"){
      printStudents(students);
    }
    else if(choice == "3"){
      findStudent(students);
    }
    else if(choice != "0"){
      std::cout << "Invalid choice!" << std::endl;
    }

  } while(choice != "0");

  delStudents(students);

  return 0;
} // end main


void loadStudents(std::vector<Student*>& students){
  FILE* file = fopen("students.csv", "r");

  if(file == nullptr){
    std::cout << "Error opening file!" << std::endl;
    return;
  }

  char line[1000];

  while(fgets(line, sizeof(line), file) != nullptr){
    std::string studentString = line;

    // remove newline characters from the end of the string
    while(!studentString.empty() &&
          (studentString.back() == '\n' ||
           studentString.back() == '\r')){
      studentString.pop_back();
    }

    if(!studentString.empty()){
      Student* student = new Student();

      student->init(studentString);

      students.push_back(student);
    }
  }

  fclose(file);
} // end loadStudents


void printStudents(std::vector<Student*>& students){
  for(int i = 0; i < students.size(); i++){
    students[i]->printStudent();
  }
} // end printStudents


void showStudentNames(std::vector<Student*>& students){
  for(int i = 0; i < students.size(); i++){
    std::cout << students[i]->getLastFirst() << std::endl;
  }
} // end showStudentNames


void findStudent(std::vector<Student*>& students){
  std::string lastName;

  std::cout << "last name of student: ";
  std::getline(std::cin, lastName);

  bool found = false;

  for(int i = 0; i < students.size(); i++){
    if(students[i]->getLastName().find(lastName)
       != std::string::npos){

      students[i]->printStudent();
      found = true;
    }
  }

  if(found == false){
    std::cout << "No students found." << std::endl;
  }
} // end findStudent


void delStudents(std::vector<Student*>& students){
  for(int i = 0; i < students.size(); i++){
    delete students[i];
  }

  students.clear();
} // end delStudents


std::string menu(){
  std::string choice;

  std::cout << std::endl;
  std::cout << "0) quit" << std::endl;
  std::cout << "1) print all student names" << std::endl;
  std::cout << "2) print all student data" << std::endl;
  std::cout << "3) find a student" << std::endl;

  std::cout << std::endl;
  std::cout << "please choose 0-3: ";
  std::getline(std::cin, choice);

  return choice;
} // end menu


void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress


void testDate(){
  Date d;
  d.init("01/27/1997");
  d.printDate();
} // end testDate


void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst();
  delete student;
} // end testStudent

