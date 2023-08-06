#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "Piece.hpp"
#include "Board.h"
#include "TsuiBoard5.hpp"


typedef struct {
    
    PyObject_HEAD
    /* Type-specific fields go here. */
        Board *board;
        TsuiBoard5 *board2;
} Py_Class_Board;


static PyObject *Board_moves(Py_Class_Board *self);
static PyObject *board_moves(Py_Class_Board *self);
static PyObject *get_tesu(Py_Class_Board *self);
static PyObject *rotate_board(Py_Class_Board *self);
static PyObject *push_move(Py_Class_Board *self, PyObject *args);
static PyObject *is_end(Py_Class_Board *self);
static PyObject *my_debug1(Py_Class_Board *self);


static int *Dummy_init(Py_Class_Board *self, PyObject *args);
static PyObject *Board_str(Py_Class_Board *self);

static PyObject *my_debug1(Py_Class_Board *self){
    return Py_BuildValue("[ii]", 0, 0);
};

static PyMethodDef Py_Class_Board_methods[] = {
    {"moves", (PyCFunction)board_moves, METH_VARARGS, "(ToT)"},
    {"tesu", (PyCFunction)get_tesu, METH_VARARGS, "(^o^)v"},
    {"rotate", (PyCFunction)rotate_board, METH_VARARGS, "(^q^)"},
    {"push", (PyCFunction)push_move, METH_VARARGS, "(O_O)"},
    {"is_end", (PyCFunction)is_end, METH_VARARGS, "\(-A-)/"},
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
    self->board->rotate();
    Py_INCREF(Py_None);
    return Py_None;
};

static PyObject *push_move(Py_Class_Board *self, PyObject *args){
    int move;
    if (!PyArg_ParseTuple(args, "i", &move)) {
        PyErr_SetString(PyExc_ValueError, "PushError1!");
        return NULL;
    };
    self->board->push(move);
    Py_INCREF(Py_None);
    return Py_None;
};


static PyObject *get_tesu(Py_Class_Board *self){
    return Py_BuildValue("i", self->board->tesu);
};
//*/
static PyObject *is_end(Py_Class_Board *self){
    return Py_BuildValue("i", self->board->is_end());
};

static int *Dummy_init(Py_Class_Board *self, PyObject *args){
    int next;
    PyObject *pyboard;
    if (!PyArg_ParseTuple(args, "Oi", &pyboard, &next)) {
        PyErr_SetString(PyExc_ValueError, "InitError1!");
        return NULL;
    }
    
    if (PyList_Check(pyboard)) {
        if(PyList_Size(pyboard)!=14){
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
        self->board=new Board(cboard, next);
    }
    if (PyTuple_Check(pyboard)) {
        if(PyTuple_Size(pyboard)!=14){
            PyErr_SetString(PyExc_ValueError, "InitError3!");
            return NULL;
        }
        int cboard[14]={
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 0)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 1)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 2)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 3)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 4)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 5)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 6)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 7)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 8)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 9)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 10)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 11)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 12)),
            (int)PyLong_AsLong(PyTuple_GetItem(pyboard, 13))
        };
        self->board=new Board(cboard, next);
    }
    int end=1;
    if(self->board->board[0]==1){
        end=0;
    }
    if(self->board->board[1]==1){
        end=0;
    }
    if(self->board->board[2]==1){
        end=0;
    }
    if(self->board->board[3]==1){
        end=0;
    }
    if(self->board->board[4]==1){
        end=0;
    }
    if(self->board->board[5]==1){
        end=0;
    }
    if(self->board->board[6]==1){
        end=0;
    }
    if(self->board->board[7]==1){
        end=0;
    }
    if(self->board->board[8]==1){
        end=0;
    }
    if(self->board->board[9]==1){
        end=0;
    }
    if(self->board->board[10]==1){
        end=0;
    }
    if(self->board->board[11]==1){
        end=0;
    }
    if(self->board->board[12]==1){
        end=0;
    }
    if(self->board->board[13]==1){
        end=0;
    }
    if(end){
        self->board->end=1;
    }
    return 0;
};
static PyObject *Board_str(Py_Class_Board *self){
    return PyUnicode_FromFormat(self->board->to_string().c_str());
};


static PyModuleDef custommodule = {
    PyModuleDef_HEAD_INIT,
    "np_nd_DIDS",
    "Example module that creates an extension type.",
    -1,
    NULL
};

PyMODINIT_FUNC
PyInit_np_nd_DIDS(void){
    PyObject *m;
    
    m = PyModule_Create(&custommodule);
    if (m == NULL){
        return NULL;
    }
        
    if (PyType_Ready(&CustomType) < 0){
        return NULL;
    }

    Py_INCREF(&CustomType);
    PyModule_AddObject(m, "DIBoard", (PyObject *) &CustomType);

    return m;
}
//*
static PyObject *Board_moves(Py_Class_Board *self){
    int board[14]={
        self->board->board[0],
        self->board->board[1],
        self->board->board[2],
        self->board->board[3],
        self->board->board[4],
        self->board->board[5],
        self->board->board[6],
        self->board->board[7],
        self->board->board[8],
        self->board->board[9],
        self->board->board[10],
        self->board->board[11],
        self->board->board[12],
        self->board->board[13]
    };
    int moves[48];
    int i,j,m;
    m=0;
    for(i=0;i<14;i++){
        int p=board[i];
        if(0<p){
            if(p<3){
                if(p==1){
                    for(j=0;j<13;j++){
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
/*
static int *board_init(Py_Class_Board *self){
    self->board2 = new TsuiBoard5();
    return 0;
};
*/
static PyObject *board_moves(Py_Class_Board *self){
    PyObject *pseudo_moves = PySet_New(NULL);
    /*
    int moves1[200];//成でない「指す」手。移動先*方向=25*8=200
    int moves2[25];//可成域への成る手。移動先*方向=5*5=25(+200)
    int moves3[60];//非可成域への成る手。移動先*方向=20*3=(+225)
    int moves4[125];//打つ手。移動先*駒種=25*5=125(+285)
    //計410
    self->board2->pseudo_moves1(moves1);
    self->board2->pseudo_moves2(moves2);
    self->board2->pseudo_moves3(moves3);
    self->board2->pseudo_moves4(moves4);
    for(int i = 0;i < 200;i++){
        if(moves1[i]){
            PyObject *tuple = PyTuple_New(2);
            if(!PyTuple_SetItem(tuple, 0, PyLong_FromLong((long)i)) || !PyTuple_SetItem(tuple, 1, PyLong_FromLong((long)moves1[i]))){
                PyErr_SetString(PyExc_ValueError, "Error in setting moves1!");
                return NULL;
            };
            if(!PySet_Add(pseudo_moves, tuple)){
                PyErr_SetString(PyExc_ValueError, "Error in addition of moves1!");
            };
        };
    };
    for(int i = 0;i < 25;i++){
        if(moves2[i]){
            PyObject *tuple = PyTuple_New(2);
            if(!PyTuple_SetItem(tuple, 0, PyLong_FromLong(200 + (long)i)) || !PyTuple_SetItem(tuple, 1, PyLong_FromLong((long)moves2[i]))){
                PyErr_SetString(PyExc_ValueError, "Error in setting moves2!");
                return NULL;
            };
            if(!PySet_Add(pseudo_moves, tuple)){
                PyErr_SetString(PyExc_ValueError, "Error in addition of moves2!");
            };
        };
    };
    for(int i = 0;i < 60;i++){
        if(moves3[i]){
            PyObject *tuple = PyTuple_New(2);
            if(!PyTuple_SetItem(tuple, 0, PyLong_FromLong(225 + (long)i)) || !PyTuple_SetItem(tuple, 1, PyLong_FromLong((long)moves3[i]))){
                PyErr_SetString(PyExc_ValueError, "Error in setting moves3!");
                return NULL;
            };
            if(!PySet_Add(pseudo_moves, tuple)){
                PyErr_SetString(PyExc_ValueError, "Error in addition of moves3!");
            };
        };
    };
    for(int i = 0;i < 125;i++){
        if(moves4[i]){
            PyObject *tuple = PyTuple_New(2);
            if(!PyTuple_SetItem(tuple, 0, PyLong_FromLong(285 + (long)i)) || !PyTuple_SetItem(tuple, 1, PyLong_FromLong(1))){
                PyErr_SetString(PyExc_ValueError, "Error in setting moves4!");
                return NULL;
            };
            if(!PySet_Add(pseudo_moves, tuple)){
                PyErr_SetString(PyExc_ValueError, "Error in addition of moves4!");
            };
        };
    };
    //*/
    return pseudo_moves;
};
