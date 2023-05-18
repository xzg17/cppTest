#include <math.h>
#include <Python.h>

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
  this->a = 0;
  this->b = 0;
};
MyClass::MyClass(int a, int b){
  this->a = a;
  this->b = b;
};

int MyClass::mysum(){
  int a = this->a;
  int b = this->b;
  return a+b;
};
