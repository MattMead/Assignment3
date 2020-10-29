#include <iostream>

using namespace std;

class Delimeter{
public:
  // Constructor
  Delimeter(char delimeter, int numLines);

  // Destructor
  ~Delimeter();

  //tracks the number of lines in file
  int numLines;
  //boolean that returns true if the matching delimeter is found
  bool isDelimMatch;
  //represent a delimeter '(', ')', '{', '}', '[', ']'
  char delimeter;
  //boolean that returns true if the matching delimeter is found
  char delimeterMatch;

  // methods
  void matchFound();
  void checkDelimMatch();
  bool closingDelim();




};
