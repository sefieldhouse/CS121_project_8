
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
  protected:
    std::string street;
    std::string city;
    std::string state;
    std::string zip; // keep it as a string bc we don't need it to be a number; less likely to crash this way
  public:       // and we aren't doing any math on it
    Address(); // doesn't need its own destructor because it doesn't own any heap pointers
    void init(std::string street, std::string city, std::string state, std::string zip);
    void printAddress();
};

#endif

