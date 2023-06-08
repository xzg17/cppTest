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
static PyObject *get_information(Py_Class_Board *self);
static PyObject *catch_moves(Py_Class_Board *self);
static PyObject *rotate_board(Py_Class_Board *self);
static PyObject *get_tesu(Py_Class_Board *self);
static PyObject *next_player(Py_Class_Board *self);
static PyObject *push_move(Py_Class_Board *self, PyObject *args);
static PyObject *pop_move(Py_Class_Board *self);
static PyObject *is_end(Py_Class_Board *self);
static PyObject *my_debug1(Py_Class_Board *self);


static int *Dummy_init(Py_Class_Board *self, PyObject *args);
static PyObject *Board_str(Py_Class_Board *self);

static PyObject *my_debug1(Py_Class_Board *self){
    return Py_BuildValue("[ii]", self->test_bo->lost_history[4], self->test_bo->lost_history[7]);
};

static PyMethodDef Py_Class_Board_methods[] = {
    {"moves", (PyCFunction)Board_moves, METH_VARARGS, "(ToT)"},
    {"catch", (PyCFunction)catch_moves, METH_VARARGS, "(^o^)v"},
    {"rotate", (PyCFunction)rotate_board, METH_VARARGS, "(^q^)"},
    {"push", (PyCFunction)push_move, METH_VARARGS, "(O_O)"},
    {"pop", (PyCFunction)pop_move, METH_VARARGS, "\(^_^)/"},
    {"is_end", (PyCFunction)is_end, METH_VARARGS, "\(-A-)/"},
    {"get_tesu", (PyCFunction)get_tesu, METH_VARARGS, "(-_-)"},
    {"get_info", (PyCFunction)get_information, METH_VARARGS, "v(^o^)"},
    {"next_player", (PyCFunction)next_player, METH_VARARGS, "(-_-)?"},
    //{"debug", (PyCFunction)my_debug1, METH_VARARGS, "(x_x)"},
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

static PyObject *push_move(Py_Class_Board *self, PyObject *args){
    int move;
    if (!PyArg_ParseTuple(args, "i", &move)) {
        PyErr_SetString(PyExc_ValueError, "PushError1!");
        return NULL;
    };
    self->test_bo->push(move);
    Py_INCREF(Py_None);
    return Py_None;
};

static PyObject *pop_move(Py_Class_Board *self){
    int move;
    move = self->test_bo->pop();
    return Py_BuildValue("i", move);
};

static PyObject *is_end(Py_Class_Board *self){
    return Py_BuildValue("i", self->test_bo->is_end());
};

static PyObject *get_tesu(Py_Class_Board *self){
    return Py_BuildValue("i", self->test_bo->get_tesu());
};

static PyObject *next_player(Py_Class_Board *self){
    return Py_BuildValue("i", self->test_bo->next_player());
};

static int *Dummy_init(Py_Class_Board *self, PyObject *args){
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
    int chands[6]={0,0,0,0,0,0};
    self->test_bo=new TestBoard(cboard,chands);
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
        self->test_bo->board[0],
        self->test_bo->board[1],
        self->test_bo->board[2],
        self->test_bo->board[3],
        self->test_bo->board[4],
        self->test_bo->board[5],
        self->test_bo->board[6],
        self->test_bo->board[7],
        self->test_bo->board[8],
        self->test_bo->board[9],
        self->test_bo->board[10],
        self->test_bo->board[11],
        self->test_bo->board[12],
        self->test_bo->board[13]
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

static PyObject *catch_moves(Py_Class_Board *self){
    int board[14]={
        self->test_bo->board[0],
        self->test_bo->board[1],
        self->test_bo->board[2],
        self->test_bo->board[3],
        self->test_bo->board[4],
        self->test_bo->board[5],
        self->test_bo->board[6],
        self->test_bo->board[7],
        self->test_bo->board[8],
        self->test_bo->board[9],
        self->test_bo->board[10],
        self->test_bo->board[11],
        self->test_bo->board[12],
        self->test_bo->board[13]
    };
    int i,j;
    for(i=0;i<14;i++){
        int p=board[i];
        if(0<p){
            if(p<3){
                if(p==1){
                    for(j=0;j<12;j++){
                        p=lion[i][j];
                        if(p+1){
                            if((board[p]==-1)){
                                return Py_BuildValue("i",i*14+p);
                            }
                        }else{
                            break;
                        }
                    };
                }else{
                    for(j=0;j<4;j++){
                        p=jiraffe[i][j];
                        if(p+1){
                            if((board[p]==-1)){
                                return Py_BuildValue("i",i*14+p);
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
                                if((board[p]==-1)){
                                    return Py_BuildValue("i",i*14+p);
                                }
                            }else{
                                break;
                            }
                        }
                    }else{
                        p=chick[i][0];
                        if(p+1){
                            if((board[p]==-1)){
                                return Py_BuildValue("i",i*14+p);
                            }
                        }else{
                            break;
                        }
                    }
                }else{
                    for(j=0;j<6;j++){
                        p=hen[i][j];
                        if(p+1){
                            if((board[p]==-1)){
                                return Py_BuildValue("i",i*14+p);
                            }
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
    return Py_BuildValue("i",-1);
};
//*/

static PyObject *get_information(Py_Class_Board *self){
    int board[14]={
        self->test_bo->board[0],
        self->test_bo->board[1],
        self->test_bo->board[2],
        self->test_bo->board[3],
        self->test_bo->board[4],
        self->test_bo->board[5],
        self->test_bo->board[6],
        self->test_bo->board[7],
        self->test_bo->board[8],
        self->test_bo->board[9],
        self->test_bo->board[10],
        self->test_bo->board[11],
        self->test_bo->board[12],
        self->test_bo->board[13]
    };
    int i,j;
    int info[14]={-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9};
    for(i=0;i<14;i++){
        int p=board[i];
        if(0<p){
            info[i]=board[i];
            if(p<3){
                if(p==1){
                    for(j=0;j<12;j++){
                        p=lion[i][j];
                        if(p+1){
                            info[p]=board[p];
                        }else{
                            break;
                        }
                    };
                }else{
                    for(j=0;j<4;j++){
                        p=jiraffe[i][j];
                        if(p+1){
                            info[p]=board[p];
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
                                info[p]=board[p];
                            }else{
                                break;
                            }
                        }
                    }else{
                        p=chick[i][0];
                        if(p+1){
                            info[p]=board[p];
                        }else{
                            break;
                        }
                    }
                }else{
                    for(j=0;j<6;j++){
                        p=hen[i][j];
                        if(p+1){
                            info[p]=board[p];
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
    return Py_BuildValue(
        "(iiiiiiiiiiiiii)",
        info[0],
        info[1],info[2],info[3],
        info[4],info[5],info[6],
        info[7],info[8],info[9],
        info[10],info[11],info[12],
        info[13]
    );
};
