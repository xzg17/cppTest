#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "Class.h"
#include "Test.h"

typedef struct {
    
    PyObject_HEAD
    /* Type-specific fields go here. */
        MyClass *myclass;
        TestBoard *test_bo;
} Py_Class_Board;


static PyObject *Board_moves(Py_Class_Board *self);
static int *Dummy_init(Py_Class_Board *self, PyObject *args);


static PyMethodDef Py_Class_Board_methods[] = {
    {"moves", (PyCFunction)Board_moves, METH_VARARGS, "(ToT)"},
    {NULL} /* Sentinel */
};


static PyTypeObject CustomType = {
    PyVarObject_HEAD_INIT(NULL, 0) "custom.Custom", /* tp_name */
    sizeof(Py_Class_Board),                           /* tp_basicsize */
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
    Py_Class_Board_methods,     /* tp_methods */
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

static int *Dummy_init(Py_Class_Board *self, PyObject *args){
    PyObject *pyboard, *pyhands;
    if (!PyArg_ParseTuple(args, "OO", &pyboard, &pyhands)) {
        PyErr_SetString(PyExc_ValueError, "Dummy1!");
        return NULL;
    }
    
    if(PyList_Size(pyboard)!=14){
        PyErr_SetString(PyExc_ValueError, "Dummy2!");
        return NULL;
    }
    
    if(PyList_Size(pyhands)!=6){
        PyErr_SetString(PyExc_ValueError, "Dummy3!");
        return NULL;
    }
    int dummyint=(int)PyLong_AsLong(PyList_GetItem(pyboard, 0));
    int cboard[14];
    int chands[6];
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
//*
static PyObject *Board_moves(Py_Class_Board *self){
    int moves[48];
    int i,j,m;
    m=0;
    for(i=0;i<13;i++){
        int p=self->test_bo->board[i];
        if(0<p){
            if(p<3){
                if(p==1){
                    for(j=0;j<12;j++){
                        p=lion[i][j];
                        if(p+1){
                            moves[m]=i*13+p;
                            m++;
                        }else{
                            break;
                        }
                    };
                }else{
                    for(j=0;j<4;j++){
                        p=jiraffe[i][j];
                        if(p+1){
                            moves[m]=p;
                            m++;
                        }else{
                            break;
                        }
                    }
                }
            }else{
                if(5-p){
                    if(4-p){
                        for(j=0;j<4;j++){
                            p=elephant[i][j];
                            if(p+1){
                                moves[m]=p;
                                m++;
                            }else{
                                break;
                            }
                        }
                    }else{
                        p=chick[i][0];
                        if(p+1){
                            moves[m]=p;
                            m++;
                        }else{
                            break;
                        }
                    }
                }else{
                    for(j=0;j<6;j++){
                        p=hen[i][j];
                        if(p+1){
                            moves[m]=p;
                            m++;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
    PyObject *move_list = PyList_New(m);
    for(int i=0;i<m;i++){
        PyList_SET_ITEM(move_list, i, PyLong_FromLong((long)moves[i]));
    }
  
};
//*/
