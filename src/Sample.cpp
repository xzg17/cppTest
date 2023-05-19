#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "Class.h"

typedef struct {
    
    PyObject_HEAD
    /* Type-specific fields go here. */
        MyClass *myclass;
} CustomObject;

static PyObject *Class_sum(CustomObject *self);
static int *Dummy_init(CustomObject *self, PyObject *args);


static PyMethodDef CustomObject_methods[] = {
    {"mysum", (PyCFunction)Class_sum, METH_VARARGS, "sum of a and b."},
    {NULL} /* Sentinel */
};


static PyTypeObject CustomType = {
    PyVarObject_HEAD_INIT(NULL, 0) "custom.Custom", /* tp_name */
    sizeof(CustomObject),                           /* tp_basicsize */
    0,                                              /* tp_itemsize */
    /* methods */
    0, /* tp_dealloc */
    0,                        /* tp_print */
    0,                        /* tp_getattr */
    0,                        /* tp_setattr */
    0,                        /* tp_reserved */
    0,                        /* tp_repr */
    0,                        /* tp_as_number */
    0,                        /* tp_as_sequence */
    0,                        /* tp_as_mapping */
    0,                        /* tp_hash */
    0,                        /* tp_call */
    0,       /* tp_str */
    0,                        /* tp_getattro */
    0,                        /* tp_setattro */
    0,                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,       /* tp_flags */
    PyDoc_STR("Custom objects"),/* tp_doc */
    0,                        /* tp_traverse */
    0,                        /* tp_clear */
    0,                        /* tp_richcompare */
    0,                        /* tp_weaklistoffset */
    0,                        /* tp_iter */
    0,                        /* tp_iternext */
    CustomObject_methods,     /* tp_methods */
    0,                        /* tp_members */
    0,                        /* tp_getset */
    0,                        /* tp_base */
    0,                        /* tp_dict */
    0,                        /* tp_descr_get */
    0,                        /* tp_descr_set */
    0,                        /* tp_dictoffset */
    (initproc)Dummy_init,     /* tp_init */
    0,                        /* tp_alloc */
    PyType_GenericNew,        /* tp_new */
};

static PyObject *Class_sum(CustomObject *self){
    return Py_BuildValue("i", self->myclass->mysum());
};

static int *Dummy_init(CustomObject *self, PyObject *args){
    //*
    if(PyType_Check(args)){
        PyErr_SetString(PyExc_ValueError, "Dummy!");
    }//*/
    int a = 0;
    int b = 0;
    if (PyArg_ParseTuple(args, "|ii", &a, &b)) {
        self->myclass = new MyClass(a, b);        
    } else {
        PyErr_SetString(PyExc_ValueError, "Invalid arguments. Use {a, b}.\n for example: MyClass(10, 20)");        
    }
    return 0;
};

static PyModuleDef custommodule = {
    PyModuleDef_HEAD_INIT,
    "customZ",
    "Example module that creates an extension type.",
    -1,
    NULL
};

PyMODINIT_FUNC
PyInit_customZ(void){
    PyObject *m;
    
    m = PyModule_Create(&custommodule);
    if (m == NULL){
        return NULL;
    }
        
    if (PyType_Ready(&CustomType) < 0){
        return NULL;
    }

    Py_INCREF(&CustomType);
    PyModule_AddObject(m, "MyPyClass", (PyObject *) &CustomType);

    return m;
}
