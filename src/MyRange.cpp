#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "MyRange.h"

typedef struct{
  PyObject_HEAD
    My_Range *range
} Py_Range;

static PyObject *Range_range(Py_Range *self, PyObject *args);

static PyMethodDef Py_Range_methods[] = {
  {"range", Range_range, METH_VARARGS, NULL},
  {NULL} /* Sentinel */
};

static PyObject *Range_range(Py_Range *self, PyObject *args){
  int a, b, c;
  a = self->range->a;
  b = self->range->b;
  c = self->range->c;
  
  int n = 0; 
  for(int i=a;i<b;i+=c){
    n++;
  }
  PyObject *list = PyList_New(n);
  for(int i=a;i<b;i+=c){
    PyList_SET_ITEM(list, i, PyLong_FromLong((long)i));
  }

  return list;
}

static PyModuleDef myRange = {
  PyModuleDef_HEAD_INIT,
  "MyRange",
  NULL,
  -1,
  Py_Range_methods
};

PyMODINIT_FUNC PyInit_MyRange(void) {
    return PyModule_Create(&myRange);
}
