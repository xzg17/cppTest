#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "TestB.hpp"
#include <string>
/*
このへんにいろいろincludeして試すようのモジュール
*/
typedef struct {
    
    PyObject_HEAD
    /* Type-specific fields go here. */
        Test_Clas *test_class;
} Py_Test_Class;


static PyObject *test_func(Py_Test_Class *self, PyObject *args);
static PyObject *test_str(Py_Test_Class *self, PyObject *args);
static int test_init(Py_Test_Class *self, PyObject *args);

static PyMethodDef Py_Test_Class_methods[] = {
    {"test", (PyCFunction)test_func, METH_VARARGS, "(ToT)"},
    {NULL} /* Sentinel */
};


static PyTypeObject TestType = {
    PyVarObject_HEAD_INIT(NULL, 0) "Test", /* tp_name */
    sizeof(Py_Test_Class),                           /* tp_basicsize */
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
    (reprfunc)test_str,      /* tp_str */ //ここは0でも問題ないらしい
    0,                        /* tp_getattro */
    0,                        /* tp_setattro */
    0,                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,       /* tp_flags */
    PyDoc_STR("Test objects"),/* tp_doc */
    0,                        /* tp_traverse */
    0,                        /* tp_clear */
    0,                        /* tp_richcompare */
    0,                        /* tp_weaklistoffset */
    0,                        /* tp_iter */
    0,                        /* tp_iternext */
    Py_Test_Class_methods,    /* tp_methods */
    0,                        /* tp_members */
    0,                        /* tp_getset */
    0,                        /* tp_base */
    0,                        /* tp_dict */
    0,                        /* tp_descr_get */
    0,                        /* tp_descr_set */
    0,                        /* tp_dictoffset */
    (initproc)test_init,     /* tp_init */
    0,                        /* tp_alloc */
    PyType_GenericNew,        /* tp_new */
};

static PyObject *test_func(Py_Test_Class *self){
    return Py_BuildValue("i", 0);
};

static PyObject *test_str(Py_Test_Class *self, PyObject *args){
    std::string teststring = "test";
    return PyUnicode_FromFormat(teststring.c_str());
};

static int test_init(Py_Test_Class *self, PyObject *args){
    int num;
    if (PyArg_ParseTuple(args, "i", &num)) {
        self->test_class = new Test_Class(num);        
    };
    return 0;
};

static struct PyModuleDef TestMod = {
    PyModuleDef_HEAD_INIT,
    "TestMod",
    "Example module that creates an extension type.",
    -1,
    NULL
};

PyMODINIT_FUNC
PyInit_TestMod(void){//ここでNULLが返されるとSystemError: initialization of customZ failed without raising an exceptionとなる。
    PyObject *m;
    
    m = PyModule_Create(&TestMod);
    if (m == NULL){
        return NULL;
    }
        
    if (PyType_Ready(&TestType) < 0){
        return NULL;
    }

    Py_INCREF(&TestType);
    PyModule_AddObject(m, "TestMod", (PyObject *) &TestType);

    return m;
};
