#include <iostream>

#include "FileChecker.h"

using namespace std;

int main(int argc, char **argv){
  bool inUse = true;
  string inputFile;
  int userInput;
  inputFile = argv[1];

  while(inUse){
    try{
      //making FileChecker object that creates and checks the delimeter stack
      FileChecker* fc = new FileChecker(inputFile);
    }
    // prints out all errors
    catch(runtime_error error){
      cout << error.what() << endl;
    }

    cout << "Do you want to check the delimeters of another file? (1) for Yes, (2) for No. " << endl;
    cin >> userInput;

    if(userInput == 1){
      cout << "Enter the name of the file: " << endl;
      cin >> inputFile;
    }

    else if(userInput == 2){
      cout << "Exiting. " << endl;
      inUse = false;

    }
    else{
      throw runtime_error("The choice entered was not valid");
    }
  }
}
