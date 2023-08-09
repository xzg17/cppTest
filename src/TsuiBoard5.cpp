#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "Piece.hpp"
#include "Board.h"
#include "TsuiBoard5.hpp"


typedef struct {
    
    PyObject_HEAD
    /* Type-specific fields go here. */
        TsuiBoard5 *board;
} Py_Class_TsuiBoard;

static PyObject *board_moves(Py_Class_TsuiBoard *self);
static PyObject *get_tesu(Py_Class_TsuiBoard *self);
static PyObject *get_mochi(Py_Class_TsuiBoard *self);
static PyObject *set_board(Py_Class_TsuiBoard *self, PyObject *args);
static PyObject *set_hansoku(Py_Class_TsuiBoard *self, PyObject *args);
static PyObject *get_board(Py_Class_TsuiBoard *self);
static PyObject *get_hansoku(Py_Class_TsuiBoard *self);
static PyObject *is_lose(Py_Class_TsuiBoard *self);
static PyObject *rotate_board(Py_Class_TsuiBoard *self);
static PyObject *push_move(Py_Class_TsuiBoard *self, PyObject *args);
static PyObject *my_debug1(Py_Class_TsuiBoard *self);
static int *board_init(Py_Class_TsuiBoard *self);

static PyObject *Board_str(Py_Class_TsuiBoard *self);

static PyObject *my_debug1(Py_Class_TsuiBoard *self){
    int i = self->board->is_check();
    int j = self->board->kpos[0];
    int moves4[125] = {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };
    self->board->pseudo_moves4(moves4);
    int k = moves4[60];
    return Py_BuildValue("[iii]", i, j, k);
};

static PyMethodDef Py_Class_TsuiBoard_methods[] = {
    {"moves", (PyCFunction)board_moves, METH_VARARGS, "(ToT)"},
    {"tesu", (PyCFunction)get_tesu, METH_VARARGS, "(^o^)v"},
    {"get_hansoku", (PyCFunction)get_hansoku, METH_VARARGS, "(^p^)"},
    {"get_board", (PyCFunction)get_board, METH_VARARGS, "(^p^)"},
    {"get_mochi", (PyCFunction)get_mochi, METH_VARARGS, "(^p^)"},
    {"set_hansoku", (PyCFunction)set_hansoku, METH_VARARGS, "(^p^)"},
    {"set_board", (PyCFunction)set_board, METH_VARARGS, "(^p^)"},
    {"is_lose", (PyCFunction)is_lose, METH_VARARGS, "(^p^)"},
    {"get_tesu", (PyCFunction)get_hansoku, METH_VARARGS, "(^p^)"},
    {"rotate", (PyCFunction)rotate_board, METH_VARARGS, "(^q^)"},
    {"push", (PyCFunction)push_move, METH_VARARGS, "(O_O)"},
    {"debug1", (PyCFunction)my_debug1, METH_VARARGS, "('_')/debug!!"},
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
    Py_Class_TsuiBoard_methods,     /* tp_methods */
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


static PyObject *rotate_board(Py_Class_TsuiBoard *self){
    self->board->rotate();
    Py_INCREF(Py_None);
    return Py_None;
};

static PyObject *push_move(Py_Class_TsuiBoard *self, PyObject *args){
    PyObject *move_tuple;
    if(!PyArg_ParseTuple(args, "O", &move_tuple)){
        return NULL;
    };
    int move = (int)PyLong_AsLong(PyTuple_GetItem(move_tuple, 0));
    int move_from = (int)PyLong_AsLong(PyTuple_GetItem(move_tuple, 1));
    int result = self->board->push(move, move_from);
    return Py_BuildValue("i", result);
};


static PyObject *get_tesu(Py_Class_TsuiBoard *self){
    return Py_BuildValue("i", self->board->board[37]);
};
static PyObject *is_lose(Py_Class_TsuiBoard *self){
    if(self->board->board[35] < 0){
        return Py_BuildValue("i", 1);
    }else{
        return Py_BuildValue("i", 0);
    };
};
static PyObject *get_mochi(Py_Class_TsuiBoard *self){
    return Py_BuildValue("[iiiii]", self->board->board[25], self->board->board[26], self->board->board[27], self->board->board[28], self->board->board[29]);
};
//*/
static PyObject *Board_str(Py_Class_TsuiBoard *self){
    std::string dummy = "Dummy!";
    return PyUnicode_FromFormat(dummy.c_str());
};


static PyModuleDef custommodule = {
    PyModuleDef_HEAD_INIT,
    "BlindMiniShogi",
    "Example module that creates an extension type.",
    -1,
    NULL
};

PyMODINIT_FUNC
PyInit_BlindMiniShogi(void){
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
};
//*
static int *board_init(Py_Class_TsuiBoard *self){
    self->board = new TsuiBoard5();
    return 0;
};
static PyObject *get_hansoku(Py_Class_TsuiBoard *self){
    return Py_BuildValue("(ii)", self->board->board[35], self->board->board[36]);
};
static PyObject *get_board(Py_Class_TsuiBoard *self){
    PyObject *row0 = Py_BuildValue("[iiiii]", self->board->board[0], self->board->board[1], self->board->board[2], self->board->board[3], self->board->board[4]);
    PyObject *row1 = Py_BuildValue("[iiiii]", self->board->board[5], self->board->board[6], self->board->board[7], self->board->board[8], self->board->board[9]);
    PyObject *row2 = Py_BuildValue("[iiiii]", self->board->board[10], self->board->board[11], self->board->board[12], self->board->board[13], self->board->board[14]);
    PyObject *row3 = Py_BuildValue("[iiiii]", self->board->board[15], self->board->board[16], self->board->board[17], self->board->board[18], self->board->board[19]);
    PyObject *row4 = Py_BuildValue("[iiiii]", self->board->board[20], self->board->board[21], self->board->board[22], self->board->board[23], self->board->board[24]);
    return Py_BuildValue("[OOOOO]", row0, row1, row2, row3, row4);
};
//*/

static PyObject *set_hansoku(Py_Class_TsuiBoard *self, PyObject *args){
    PyObject *hansoku;
    if(!PyArg_ParseTuple(args, "O", &hansoku)){
        return NULL;
    };
    self->board->board[35] = (int)PyLong_AsLong(PyTuple_GetItem(hansoku, 0));
    self->board->board[36] = (int)PyLong_AsLong(PyTuple_GetItem(hansoku, 1));
    Py_INCREF(Py_None);
    return Py_None;
};
static PyObject *set_board(Py_Class_TsuiBoard *self, PyObject *args){
    PyObject *rows, *row0, *row1, *row2, *row3, *row4;
    if(!PyArg_ParseTuple(args, "O", &rows)){
        return NULL;
    };
    row0 = PyList_GetItem(rows, 0);
    row1 = PyList_GetItem(rows, 1);
    row2 = PyList_GetItem(rows, 2);
    row3 = PyList_GetItem(rows, 3);
    row4 = PyList_GetItem(rows, 4);
    self->board->board[0] = (int)PyLong_AsLong(PyList_GetItem(row0, 0));
    self->board->board[1] = (int)PyLong_AsLong(PyList_GetItem(row0, 1));
    self->board->board[2] = (int)PyLong_AsLong(PyList_GetItem(row0, 2));
    self->board->board[3] = (int)PyLong_AsLong(PyList_GetItem(row0, 3));
    self->board->board[4] = (int)PyLong_AsLong(PyList_GetItem(row0, 4));
    self->board->board[5] = (int)PyLong_AsLong(PyList_GetItem(row1, 0));
    self->board->board[6] = (int)PyLong_AsLong(PyList_GetItem(row1, 1));
    self->board->board[7] = (int)PyLong_AsLong(PyList_GetItem(row1, 2));
    self->board->board[8] = (int)PyLong_AsLong(PyList_GetItem(row1, 3));
    self->board->board[9] = (int)PyLong_AsLong(PyList_GetItem(row1, 4));
    self->board->board[10] = (int)PyLong_AsLong(PyList_GetItem(row2, 0));
    self->board->board[11] = (int)PyLong_AsLong(PyList_GetItem(row2, 1));
    self->board->board[12] = (int)PyLong_AsLong(PyList_GetItem(row2, 2));
    self->board->board[13] = (int)PyLong_AsLong(PyList_GetItem(row2, 3));
    self->board->board[14] = (int)PyLong_AsLong(PyList_GetItem(row2, 4));
    self->board->board[15] = (int)PyLong_AsLong(PyList_GetItem(row3, 0));
    self->board->board[16] = (int)PyLong_AsLong(PyList_GetItem(row3, 1));
    self->board->board[17] = (int)PyLong_AsLong(PyList_GetItem(row3, 2));
    self->board->board[18] = (int)PyLong_AsLong(PyList_GetItem(row3, 3));
    self->board->board[19] = (int)PyLong_AsLong(PyList_GetItem(row3, 4));
    self->board->board[20] = (int)PyLong_AsLong(PyList_GetItem(row4, 0));
    self->board->board[21] = (int)PyLong_AsLong(PyList_GetItem(row4, 1));
    self->board->board[22] = (int)PyLong_AsLong(PyList_GetItem(row4, 2));
    self->board->board[23] = (int)PyLong_AsLong(PyList_GetItem(row4, 3));
    self->board->board[24] = (int)PyLong_AsLong(PyList_GetItem(row4, 4));
    for(int i = 0; i < 25; i++){
        if(self->board->board[i] == -6){
            self->board->kpos[1] == i;
        };
        if(self->board->board[i] == 6){
            self->board->kpos[0] == i;
        };
    };
    Py_INCREF(Py_None);
    return Py_None;
};

static PyObject *board_moves(Py_Class_TsuiBoard *self){
    PyObject *pseudo_moves = PySet_New(NULL);
    int moves1[200] = {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };//成でない「指す」手。移動先*方向=25*8=200
    int moves2[25] = {
        -1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,
    };//可成域への成る手。移動先*方向=5*5=25(+200)
    int moves3[60] = {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };//非可成域への成る手。移動先*方向=20*3=(+225)
    int moves4[125] = {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };//打つ手。移動先*駒種=25*5=125(+285)
    //計410
    self->board->pseudo_moves1(moves1);
    self->board->pseudo_moves2(moves2);
    self->board->pseudo_moves3(moves3);
    self->board->pseudo_moves4(moves4);
    for(int i = 0;i < 200;i++){
        if(moves1[i] != -1){
            PyObject *tuple = Py_BuildValue("(ii)", i, moves1[i]);
            if(PySet_Add(pseudo_moves, tuple)){
                return tuple;
            };
        };
    };
    for(int i = 0;i < 25;i++){
        if(moves2[i] != -1){
            PyObject *tuple = Py_BuildValue("(ii)", i + 200, moves2[i]);
            if(PySet_Add(pseudo_moves, tuple)){
                return tuple;
            };
        };
    };
    for(int i = 0;i < 60;i++){
        if(moves3[i] != -1){
            PyObject *tuple = Py_BuildValue("(ii)", i + 225, moves3[i]);
            if(PySet_Add(pseudo_moves, tuple)){
                return tuple;
            };
        };
    };
    for(int i = 0;i < 125;i++){
        if(moves4[i] != -1){
            PyObject *tuple = Py_BuildValue("(ii)", i + 285, 1);
            if(PySet_Add(pseudo_moves, tuple)){
                return tuple;
            };
        };
    };
    return pseudo_moves;
};
