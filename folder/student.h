
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "date.h"
#include "address.h"

class Student {
  protected:
    std::string studentString; // parse out data and put it in all of its subclasses, all data will be in
    std::string firstName;     // studentString at some point
    std::string lastName;
    Date* DOB; // goes on the heap
    Date* graduationDate; // goes on the heap; different instances of the same class
    Address* address; // goes on the heap
    int creditHours;
  public:
    Student();
    ~Student();
    void init(std::string studentString);
    void printStudent();
    std::string getFirstName();
    std::string getLastName();
    int getCreditHours();
    std::string getLastFirst();

}; // end class Student

#endif

