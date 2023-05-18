#define PY_SSIZE_T_CLEAN
#include <Python.h>

typedef struct {
  PyObject_HEAD
    /* Type-specific fields go here. */
    Class *class
} Py_Class_Object;

static PyMethodDef Py_Class_Object_methods[] = {
    {NULL} /* Sentinel */
};


static PyTypeObject ClassType = {
    PyVarObject_HEAD_INIT(NULL, 0) "Class", /* tp_name */
    sizeof(Py_Class_Object),                           /* tp_basicsize */
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
    PyDoc_STR("Class objects"),/* tp_doc */
    0,                        /* tp_traverse */
    0,                        /* tp_clear */
    0,                        /* tp_richcompare */
    0,                        /* tp_weaklistoffset */
    0,                        /* tp_iter */
    0,                        /* tp_iternext */
    0,                        /* tp_methods */
    0,                        /* tp_members */
    0,                        /* tp_getset */
    0,                        /* tp_base */
    0,                        /* tp_dict */
    0,                        /* tp_descr_get */
    0,                        /* tp_descr_set */
    0,                        /* tp_dictoffset */
    0,                        /* tp_init */
    0,                        /* tp_alloc */
    PyType_GenericNew,        /* tp_new */
};


static PyModuleDef classmodule = {
    PyModuleDef_HEAD_INIT,
    "MyClass",
    "Example module that creates an extension type.",
    -1,
    NULL
};

PyMODINIT_FUNC
PyInit_custom(void){
    PyObject *m;
    
    m = PyModule_Create(&classmodule);
    if (m == NULL){
        return NULL;
    }
        
    if (PyType_Ready(&ClassType) < 0){
        return NULL;
    }

    Py_INCREF(&ClassType);
    PyModule_AddObject(m, "Custom", (PyObject *) &ClassType);

    return m;
}
