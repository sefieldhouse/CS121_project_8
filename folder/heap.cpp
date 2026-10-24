#include <iostream>
#include <string>
#include <sstream>
#include "date.h"
#include "address.h"
#include "student.h"

Date::Date(){
  unformattedDate = "";
  month = 0;
  day = 0;
  year = 0;
} // end Date constructor

void Date::init(std::string dateString){
  unformattedDate = dateString;

  std::stringstream ss(dateString);
  std::string temp;

  std::getline(ss, temp, '/');
  month = std::stoi(temp);

  std::getline(ss, temp, '/');
  day = std::stoi(temp);

  std::getline(ss, temp);
  year = std::stoi(temp);
} // end init

void Date::printDate(){
  std::string months[12] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
  };

  std::cout << months[month - 1] << " "
            << day << ", " << year << std::endl;
} // end printDate


// Address

Address::Address(){
  street = "";
  city = "";
  state = "";
  zip = "";
} // end Address constructor

void Address::init(std::string street, std::string city,
                   std::string state, std::string zip){
  this->street = street;
  this->city = city;
  this->state = state;
  this->zip = zip;
} // end init

void Address::printAddress(){
  std::cout << street << std::endl;
  std::cout << city << " " << state << ", "
            << zip << std::endl;
} // end printAddress


// Student

Student::Student(){
  studentString = "";
  firstName = "";
  lastName = "";
  creditHours = 0;

  DOB = new Date();
  graduationDate = new Date();
  address = new Address();
} // end Student constructor

Student::~Student(){
  delete DOB;
  delete graduationDate;
  delete address;
} // end Student destructor

void Student::init(std::string studentString){
  this->studentString = studentString;

  std::stringstream ss(studentString);

  std::string street;
  std::string city;
  std::string state;
  std::string zip;
  std::string birthdate;
  std::string gradDate;
  std::string credits;

  std::getline(ss, firstName, ',');
  std::getline(ss, lastName, ',');

  std::getline(ss, street, ',');
  std::getline(ss, city, ',');
  std::getline(ss, state, ',');
  std::getline(ss, zip, ',');

  std::getline(ss, birthdate, ',');
  std::getline(ss, gradDate, ',');
  std::getline(ss, credits);

  address->init(street, city, state, zip);

  DOB->init(birthdate);
  graduationDate->init(gradDate);

  creditHours = std::stoi(credits);
} // end init

void Student::printStudent(){
  std::cout << firstName << " " << lastName << std::endl;

  address->printAddress();

  std::cout << "DOB: ";
  DOB->printDate();

  std::cout << "Grad: ";
  graduationDate->printDate();

  std::cout << "Credits: " << creditHours << std::endl;
  std::cout << "____________________________________"
            << std::endl;
} // end printStudent

std::string Student::getFirstName(){
  return firstName;
} // end getFirstName

std::string Student::getLastName(){
  return lastName;
} // end getLastName

int Student::getCreditHours(){
  return creditHours;
} // end getCreditHours

std::string Student::getLastFirst(){
  return lastName + ", " + firstName;
} // end getLastFirst
