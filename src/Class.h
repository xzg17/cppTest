#include <math.h>
#include <Python.h>
//*
class MyClass{
  public:
    int dummy_int;
    //MyClass(int a, int b);
    //int mysum(void);
  private:
    int a;
    int b;
};
/*
MyClass::MyClass(int a, int b){
  this->a = a;
  this->b = b;
};
int MyClass::mysum(void){
  return a+b;
};
//*/
int mydummy(int a){
  return a;
};
