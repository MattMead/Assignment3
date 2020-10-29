#include <iostream>
#include "GenStack.h"
#include "Delimeter.h"

using namespace std;

class FileChecker{
public:

  // variables
  int numLines;
  string inputFile;

  // Constructor
  FileChecker(string inputFile);

  //Destructor
  ~FileChecker();

  // methods
  void ReadFile(string inputFile);
  void CheckDelims();
  void Results();

  // stack made for holding delimeters
  GenStack<Delimeter*> delimeterStack;

};
