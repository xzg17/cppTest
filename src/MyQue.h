#include <math.h>
#include <Python.h>

class MyRange{
  public:
    MyRange(int a);
    MyRange(int a, int b);
    MyRange(int a, int b, int c);
  private:
    int a;
    int b;
    int c;
};
MyRange::MyRange(int b){
  this->a = 0;
  this->b = b;
  thid->c = 1;
};
MyRange::MyRange(int a, int b){
  this->a = a;
  this->b = b;
  thid->c = 1;
};
MyRange::MyRange(int a, int b, int c){
  this->a = a;
  this->b = b;
  thid->c = c;
};
