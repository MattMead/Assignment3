#include <iostream>

using namespace std;

template <class T>
class GenStack{
public:

  // variables needed for generating a stack
  int size;
  int top;

  //Constructor
  GenStack(){

    myStack = new T[128];
    size = 50;
    top = -1;
  }

  //Overloaded Constructor
  GenStack(int maxSize){
    myStack = new T[maxSize];
    size = maxSize;
    top = -1;
  }
  //Destructor
  ~GenStack(){

  }

  // returns true if the stack is full
  bool isFull(){
    return (top == size - 1);
  }

  // returns true if the stack is in fact empty
  bool isEmpty()
  {
    return (top == -1);
  }

  // returns the top element of the stack
  T Pop(){
    if(!isEmpty()){
      return myStack[top--];
    }
    else{
      throw runtime_error("No items to pop because stack is empty.");
    }
  }


  // allows us to add elements to the stack
  void Push(T d){
    if(isFull()){
      cout << "Stack is full. Resizing the stack." << endl;
      resizeStack();
      Push(d);

    }
    else{
      myStack[++top] = d;
    
    }
  }


  // returns the top element of the stack, but does not remove it
  T Peek(){
    if(isEmpty()){
      throw runtime_error("Stack is empty. Cannot peek stack.");
    }
    else{
      return myStack[top];
    }
  }

  T *myStack;


private:
  //method to double the size of the stack if it becomes full
  void resizeStack(){
    //making a stack that is double the size of the otherb stack
    T* tempStack = new T[size * 2];
    //copies elements from the original stack and puts it into the temporary stack
    for(int i = 0; i < size; ++i){
      tempStack[i] = myStack[i];
    }
    // doubling size to make it match the new size of the stack
    size = size * 2;
    //deletes the old stack since it has now been copied
    delete[] myStack;
    //sets the myStack to the temporary stack now that its size has been increase
    myStack = tempStack;

  }
};
