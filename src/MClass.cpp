#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "Class.h"

typedef struct{
  PyObject_HEAD
    MyClass *myclass
} Py_Class;

static PyObject *Class_sum(Py_Class *self);

static PyMethodDef Py_Class_methods[] = {
  {"mysum", Class_sum, METH_VARARGS, NULL},
  {NULL} /* Sentinel */
};

static PyObject *Class_sum(Py_Class *self){
  return Py_BuildValue("i", self->myclass->mysum());
}

static PyModuleDef myClass = {
  PyModuleDef_HEAD_INIT,
  "xzg17Class",
  NULL,
  -1,
  Py_Class_methods
};

PyMODINIT_FUNC PyInit_xzg17Class(void) {
    return PyModule_Create(&myClass);
}
