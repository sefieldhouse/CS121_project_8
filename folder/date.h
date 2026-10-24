
#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
  protected:
    std::string unformattedDate;
    int month; // easiest to parse if dealing w/ integers
    int day;
    int year;
  public:
    Date(); // doesn't need its own destructor because it doesn't own any heap pointers
    void init(std::string dateString);
    void printDate();
};

#endif

