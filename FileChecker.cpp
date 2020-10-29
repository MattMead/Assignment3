#include <iostream>
#include "FileChecker.h"
#include <fstream>

using namespace std;

  // Constructor
  FileChecker::FileChecker(string inputFile){
    this->inputFile = inputFile;
    numLines = 0;
    delimeterStack = GenStack<Delimeter*>();
    ReadFile(inputFile);
    CheckDelims();
    Results();
  }

  // Destructor
  FileChecker::~FileChecker(){
  }

  //method that takes in an input file and adds each delimiter to our stack
  void FileChecker::ReadFile(string inputFile){
    ifstream fileStream;
    fileStream.open(inputFile);
    string line;

    //checking if input file is valid
    if(!fileStream){
      throw runtime_error("File you entered is not valid");
    }

    char delimeter;
    // Will iterate through the file line by line scanning for delimeters
    while(getline(fileStream,line)){
      numLines++;
      for (int i = 0; i < line.length(); ++i){

        // checking if the line is a comment. Will skip this line if it is
        if(line[i]== '/' && line[i+1]== '/'){
          break;
        }
        //if not a comment we can proceed to check for delimeters and add them to the stack
        else{
          if(line[i] == '('){
            delimeter = '(';
            Delimeter* d =  new Delimeter(delimeter, numLines);
            delimeterStack.Push(d);
          }
          if(line[i] == ')'){
            delimeter = ')';
            Delimeter* d =  new Delimeter(delimeter, numLines);
            delimeterStack.Push(d);
          }
          if(line[i] == '{'){
            delimeter = '{';
            Delimeter* d =  new Delimeter(delimeter, numLines);
            delimeterStack.Push(d);
          }
          if(line[i] == '}'){
            delimeter = '}';
            Delimeter* d =  new Delimeter(delimeter, numLines);
            delimeterStack.Push(d);
          }
          if(line[i] == '['){
            delimeter = '[';
            Delimeter* d =  new Delimeter(delimeter, numLines);
            delimeterStack.Push(d);
          }
          if(line[i] == ']'){
            delimeter = ']';
            Delimeter* d =  new Delimeter(delimeter, numLines);
            delimeterStack.Push(d);
          }
        }
      }
    }
    fileStream.close();
  }

    // method that checks delimeter objects in the stack
    void FileChecker::CheckDelims(){
      // iterate through stack
      for(int i = 0; i <= delimeterStack.top; ++i){
        Delimeter* currentDelimeter = delimeterStack.myStack[i];

          // will not check a delimeter if it already has a match
          if(currentDelimeter->isDelimMatch == true){
            continue;
          }

          // skipping closing delimeters that do not have matches
          else if(currentDelimeter -> closingDelim()){
            continue;
          }
          else{
            // checking delimeters after the index of current delimeter we are checking
            for(int j = i; j <= delimeterStack.top; ++j){
              Delimeter* checkDelimeter = delimeterStack.myStack[j];

              //checking if they are matches. If they match, then they are changed to having matches
              if(checkDelimeter->delimeter == currentDelimeter->delimeterMatch){
                currentDelimeter->matchFound();
                checkDelimeter->matchFound();
                break;
              }
            }
          }
        }
      }

  // method that goes through the entire stack to check all of the unmatched delimeters
  void FileChecker::Results(){
    for(int i = 0; i <= delimeterStack.top; ++i){
      if(delimeterStack.myStack[i] -> isDelimMatch == false){
        string error = "Missing match for ' " + string(1, delimeterStack.myStack[i]->delimeter) + " '" + " on line " + to_string(delimeterStack.myStack[i]->numLines);
        throw runtime_error(error);
      }
    }
    cout << "The delimeter syntax is correct for this file." << endl;
  }
