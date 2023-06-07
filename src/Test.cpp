#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include "Class.h"
#include "Test.h"


typedef struct {
    
    PyObject_HEAD
    /* Type-specific fields go here. */
        MyClass *myclass;
        TestBoard *test_bo;
} Py_Class_Board;


static PyObject *Board_moves(Py_Class_Board *self);
static PyObject *rotate_board(Py_Class_Board *self);

static int *Dummy_init(Py_Class_Board *self, PyObject *args);
static PyObject *Board_str(Py_Class_Board *self);


static PyMethodDef Py_Class_Board_methods[] = {
    {"moves", (PyCFunction)Board_moves, METH_VARARGS, "(ToT)"},
    {"rotate", (PyCFunction)rotate_board, METH_VARARGS, "\(^o^)/"},
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
    (reprfunc)*Board_str,     /* tp_str */
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
static PyObject *rotate_board(Py_Class_Board *self){
    self->test_bo->rotate();
    
    Py_INCREF(Py_None);
    return Py_None;
};
static int *Dummy_init(Py_Class_Board *self, PyObject *args){
    printf("Hello World!\n");
    PyObject *pyboard, *pyhands;
    if (!PyArg_ParseTuple(args, "OO", &pyboard, &pyhands)) {
        PyErr_SetString(PyExc_ValueError, "InitError1!");
        return NULL;
    }
    if (!PyList_Check(pyboard) || !PyList_Check(pyhands)) {
        PyErr_SetString(PyExc_ValueError, "InitError2!");
        return NULL;
    }
    
    if((PyList_Size(pyboard)!=14)||(PyList_Size(pyhands)!=6)){
        PyErr_SetString(PyExc_ValueError, "InitError3!");
        return NULL;
    }
    int dummyint=(int)PyLong_AsLong(PyList_GetItem(pyboard, 0));
    int cboard[14]={
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 0)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 1)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 2)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 3)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 4)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 5)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 6)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 7)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 8)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard, 9)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard,10)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard,11)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard,12)),
        (int)PyLong_AsLong(PyList_GetItem(pyboard,13))
    };
    //*
    int chands[6]={0,0,0,0,0,0};
    //*
    self->test_bo=new TestBoard(cboard,chands);
    //*/
    return 0;
};
static PyObject *Board_str(Py_Class_Board *self){
    return PyUnicode_FromFormat(self->test_bo->to_string().c_str());
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
    int board[14]={
        board[0]=self->test_bo->board[0],
        board[1]=self->test_bo->board[1],
        board[2]=self->test_bo->board[2],
        board[3]=self->test_bo->board[3],
        board[4]=self->test_bo->board[4],
        board[5]=self->test_bo->board[5],
        board[6]=self->test_bo->board[6],
        board[7]=self->test_bo->board[7],
        board[8]=self->test_bo->board[8],
        board[9]=self->test_bo->board[9],
        board[10]=self->test_bo->board[10],
        board[11]=self->test_bo->board[11],
        board[12]=self->test_bo->board[12],
        board[13]=self->test_bo->board[13]
    };
    int moves[48];
    int i,j,m;
    m=0;
    for(i=0;i<14;i++){
        int p=board[i];
        if(0<p){
            if(p<3){
                if(p==1){
                    for(j=0;j<12;j++){
                        p=lion[i][j];
                        if(p+1){
                            if((board[p]<=0)){
                                moves[m]=i*14+p;
                                m++;
                            }
                        }else{
                            break;
                        }
                    };
                }else{
                    for(j=0;j<4;j++){
                        p=jiraffe[i][j];
                        if(p+1){
                            if((board[p]<=0)){
                                moves[m]=i*14+p;
                                m++;
                            }
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
                                if((board[p]<=0)){
                                    moves[m]=i*14+p;
                                    m++;
                                }
                            }else{
                                break;
                            }
                        }
                    }else{
                        p=chick[i][0];
                        if(p+1){
                            if((board[p]<=0)){
                                moves[m]=i*14+p;
                                m++;
                            }
                        }else{
                            break;
                        }
                    }
                }else{
                    for(j=0;j<6;j++){
                        p=hen[i][j];
                        if(p+1){
                            if((board[p]<=0)){
                                moves[m]=i*14+p;
                                m++;
                            }
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
    return move_list;
};
//*/

