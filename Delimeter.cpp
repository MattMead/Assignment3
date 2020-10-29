#include <iostream>
#include "Delimeter.h"

using namespace std;

//Constructor
Delimeter::Delimeter(char delimeter, int numLines){
  this->delimeter = delimeter;
  this->numLines = numLines;
  isDelimMatch = false;
  checkDelimMatch();
}
//Deconstructor
Delimeter::~Delimeter(){
}

//method that set isDelimMatch to true
void Delimeter::matchFound(){
  this->isDelimMatch = true;
}

// method to determine the matching delimeters for each type of delimeter
void Delimeter::checkDelimMatch(){
  if(delimeter == '('){
    delimeterMatch = ')';
  }
  if(delimeter == '['){
    delimeterMatch = ']';
  }
  if(delimeter == '{'){
    delimeterMatch = '}';
  }
}

// method that returns true if it i a closing delimeter
bool Delimeter::closingDelim(){
  switch(delimeter){
    case '}':
      return true;
      break;
    case ')':
      return true;
      break;
    case ']':
      return true;
      break;
    default:
      return false;
   }
}
