#include <math.h>
#include <Python.h>
//*
class MyClass{
  public:
    int dummy_int;
    MyClass();
    MyClass(int a, int b);
    int mysum();
  private:
    int a;
    int b;
};

MyClass::MyClass(){
  a = 0;
  b = 0;
};
MyClass::MyClass(int a, int b){
  a = a;
  b = b;
};

int MyClass::mysum(){
  return a+b;
};
//*/
int mydummy(){
  return 0;
};
