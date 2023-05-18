#include <math.h>
#include <Python.h>

class MyClass{
  public:
    MyClass(int a, int b);
    int mysum(void);
  private:
    int a;
    int b;
};
int MyClass::mysum(void){
  return a+b;
};
