#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "TsuiBoard5.hpp"
#include <string>

typedef struct {
    
    PyObject_HEAD
    /* Type-specific fields go here. */
        TsuiBoard5 *board;
} Py_Class_TsuiBoard;


static PyObject *board_moves(Py_Class_TsuiBoard *self);

//static PyObject *catch_or_moves(Py_Class_Board *self);
//static PyObject *get_information(Py_Class_Board *self);
//static PyObject *get_board(Py_Class_Board *self);
//static PyObject *get_tesu(Py_Class_Board *self);
//static PyObject *set_tesu(Py_Class_Board *self, PyObject *args);
//static PyObject *catch_moves(Py_Class_Board *self);
//static PyObject *rotate_board(Py_Class_Board *self);
//static PyObject *next_player(Py_Class_Board *self);
//static PyObject *push_move(Py_Class_Board *self, PyObject *args);
//static PyObject *pushed_board(Py_Class_Board *self, PyObject *args);
//static PyObject *pop_move(Py_Class_Board *self);
//static PyObject *is_end(Py_Class_Board *self);
static PyObject *my_debug1(Py_Class_TsuiBoard *self);


static int *board_init(Py_Class_TsuiBoard *self);
static PyObject *board_str(Py_Class_TsuiBoard *self);
//*
static PyObject *my_debug1(Py_Class_TsuiBoard *self){
    return Py_BuildValue("[ii]", 0, 0);
};
//*/
static PyMethodDef Py_Class_TsuiBoard_methods[] = {
    {"pseudo_moves", (PyCFunction)board_moves, METH_VARARGS, "(O_O)"},
    //{"catch", (PyCFunction)catch_moves, METH_VARARGS, "(^o^)v"},
    //{"tesu", (PyCFunction)get_tesu, METH_VARARGS, "(^o^)v"},
    //{"set_tesu", (PyCFunction)set_tesu, METH_VARARGS, "(^o^)v"},
    //{"catch_or_moves", (PyCFunction)catch_or_moves, METH_VARARGS, "(ToT)/\(^o^)v"},
    //{"rotate", (PyCFunction)rotate_board, METH_VARARGS, "(^q^)"},
    //{"push", (PyCFunction)push_move, METH_VARARGS, "(O_O)"},
    //{"pushed", (PyCFunction)pushed_board, METH_VARARGS, "{O_O}"},
    //{"is_end", (PyCFunction)is_end, METH_VARARGS, "\(-A-)/"},
    //{"get_info", (PyCFunction)get_information, METH_VARARGS, "v(^o^)"},
    //{"get_board", (PyCFunction)get_board, METH_VARARGS, "v(^o^)"},
    //{"next_player", (PyCFunction)next_player, METH_VARARGS, "(-_-)?"},
    {"debug", (PyCFunction)my_debug1, METH_VARARGS, "(x_x)"},
    {NULL} /* Sentinel */
};


static PyTypeObject CustomType = {
    PyVarObject_HEAD_INIT(NULL, 0) "custom.Custom", /* tp_name */
    sizeof(Py_Class_TsuiBoard),                           /* tp_basicsize */
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
    (reprfunc)*board_str,     /* tp_str */
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
    Py_Class_TsuiBoard_methods,/* tp_methods */
    0,                        /* tp_members */
    0,                        /* tp_getset */
    0,                        /* tp_base */
    0,                        /* tp_dict */
    0,                        /* tp_descr_get */
    0,                        /* tp_descr_set */
    0,                        /* tp_dictoffset */
    (initproc)board_init,     /* tp_init */
    0,                        /* tp_alloc */
    PyType_GenericNew,        /* tp_new */
};

/*
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

static PyObject *set_tesu(Py_Class_Board *self, PyObject *args){
    int tesu;
    if (!PyArg_ParseTuple(args, "i", &tesu)) {
        PyErr_SetString(PyExc_ValueError, "SetError1!");
        return NULL;
    };
    self->board->tesu = tesu;
    Py_INCREF(Py_None);
    return Py_None;
};

//*
static PyObject *pushed_board(Py_Class_Board *self, PyObject *args){
    int move;
    if (!PyArg_ParseTuple(args, "i", &move)) {
        PyErr_SetString(PyExc_ValueError, "PushError1!");
        return NULL;
    };
    Board child=self->board->pushed(move);
    return Py_BuildValue(
        "(iiiiiiiiiiiiii)",
        child.board[0],
        child.board[1],
        child.board[2],
        child.board[3],
        child.board[4],
        child.board[5],
        child.board[6],
        child.board[7],
        child.board[8],
        child.board[9],
        child.board[10],
        child.board[11],
        child.board[12],
        child.board[13]
    );
};
//*/
/*
static PyObject *is_end(Py_Class_Board *self){
    return Py_BuildValue("i", self->board->is_end());
};

static PyObject *next_player(Py_Class_Board *self){
    return Py_BuildValue("i", self->board->next_player());
};
//*/
static PyObject *board_str(Py_Class_TsuiBoard *self){
    std::string hoge = "hogehoge"
    return PyUnicode_FromFormat(hoge.c_str());
};
//*/

static int *board_init(Py_Class_TsuiBoard *self){
    self->board=new TsuiBoard5();
    return 0;
};

static PyModuleDef custommodule = {
    PyModuleDef_HEAD_INIT,
    "Tsuitate55",
    "Example module that creates an extension type.",
    -1,
    NULL
};

PyMODINIT_FUNC
PyInit_Tsuitate55(void){
    PyObject *m;
    
    m = PyModule_Create(&custommodule);
    if (m == NULL){
        return NULL;
    }
        
    if (PyType_Ready(&CustomType) < 0){
        return NULL;
    }

    Py_INCREF(&CustomType);
    PyModule_AddObject(m, "TsuiBoard5", (PyObject *) &CustomType);

    return m;
}
//*
static PyObject *board_moves(Py_Class_TsuiBoard *self){
    int moves1[200];//成でない「指す」手。移動先*方向=25*8=200
    int moves2[25];//可成域への成る手。移動先*方向=5*5=25(+200)
    int moves3[60];//非可成域への成る手。移動先*方向=20*3=(+225)
    int moves4[125];//打つ手。移動先*駒種=25*5=125(+285)
    //計410
    self->board->pseudo_moves1(moves1);
    self->board->pseudo_moves2(moves2);
    self->board->pseudo_moves3(moves3);
    self->board->pseudo_moves4(moves4);
    PyObject *pseudo_moves = PySet_New(NULL);
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
    return pseudo_moves;
};
/*
static PyObject *catch_moves(Py_Class_Board *self){
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
    int i,j;
    for(i=0;i<14;i++){
        int p=board[i];
        if(0<p){
            if(p<3){
                if(p==1){
                    for(j=0;j<13;j++){
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


static PyObject *get_information(Py_Class_Board *self){
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
    int i,j;
    int info[14]={-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9};
    for(i=0;i<14;i++){
        int p=board[i];
        if(0<p){
            info[i]=board[i];
            if(p<3){
                if(p==1){
                    for(j=0;j<13;j++){
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

static PyObject *get_board(Py_Class_Board *self){
    return Py_BuildValue(
        "(iiiiiiiiiiiiii)",
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
    );
};

static PyObject *catch_or_moves(Py_Class_Board *self){
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
                                if(board[p]+1){
                                    moves[m]=i*14+p;
                                    m++;
                                }else{
                                    return Py_BuildValue("[i]", i*14+p);
                                }
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
                                if(board[p]+1){
                                    moves[m]=i*14+p;
                                    m++;
                                }else{
                                    return Py_BuildValue("[i]", i*14+p);
                                }
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
                                    if(board[p]+1){
                                        moves[m]=i*14+p;
                                        m++;
                                    }else{
                                        return Py_BuildValue("[i]", i*14+p);
                                    }
                                }
                            }else{
                                break;
                            }
                        }
                    }else{
                        p=chick[i][0];
                        if(p+1){
                            if((board[p]<=0)){
                                if(board[p]+1){
                                    moves[m]=i*14+p;
                                    m++;
                                }else{
                                    return Py_BuildValue("[i]", i*14+p);
                                }
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
                                if(board[p]+1){
                                    moves[m]=i*14+p;
                                    m++;
                                }else{
                                    return Py_BuildValue("[i]", i*14+p);
                                }
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
