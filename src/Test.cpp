#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "Test.h"
//0,1,2,3,4,5<->null,lion,jiraffe,elephant,chick,hen
typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    TestBoard *test_bo
} Py_Class_Board;

static PyObject *Board_moves(Py_Class_Board *self);
static int *Dummy_init(Py_Class_Board *self, PyObject *args);

static PyMethodDef Py_Class_Board_methods[] = {
    {"moves", (PyCFunction)Board_moves, METH_VARARGS, "generate moves."},
    {NULL} /* Sentinel */
};


static PyTypeObject ClassType = {
    PyVarObject_HEAD_INIT(NULL, 0) "Test", /* tp_name */
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
    PyDoc_STR("Class objects"),/* tp_doc */
    0,                        /* tp_traverse */
    0,                        /* tp_clear */
    0,                        /* tp_richcompare */
    0,                        /* tp_weaklistoffset */
    0,                        /* tp_iter */
    0,                        /* tp_iternext */
    Py_Class_Board_methods,   /* tp_methods */
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
//*
static PyObject *Board_moves(Py_Class_Board *self){return Py_BuildValue("i", 1);};
/*/
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
                        for(j=0;j<4;j++){
                            p=chick[i][j];
                            if(p+1){
                                moves[m]=p;
                                m++;
                            }else{
                                break;
                            }
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
static int *Dummy_init(Py_Class_Board *self, PyObject *args){
    return 0;
};

static PyModuleDef classmodule = {
    PyModuleDef_HEAD_INIT,
    "TestBoard",
    "(^o^)/",
    -1,
    NULL
};

PyMODINIT_FUNC
PyInit_TestBoard(void){
    PyObject *m;
    
    m = PyModule_Create(&classmodule);
    if (m == NULL){
        return NULL;
    }
        
    if (PyType_Ready(&ClassType) < 0){
        return NULL;
    }

    Py_INCREF(&ClassType);
    PyModule_AddObject(m, "Class", (PyObject *) &ClassType);

    return m;
}
