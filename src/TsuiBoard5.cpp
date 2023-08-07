#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "Piece.hpp"
#include "Board.h"
#include "TsuiBoard5.hpp"


typedef struct {
    
    PyObject_HEAD
    /* Type-specific fields go here. */
        TsuiBoard5 *board2;
} Py_Class_TsuiBoard;

static PyObject *board_moves(Py_Class_TsuiBoard *self);
static PyObject *get_tesu(Py_Class_TsuiBoard *self);
static PyObject *rotate_board(Py_Class_TsuiBoard *self);
static PyObject *push_move(Py_Class_TsuiBoard *self, PyObject *args);
static PyObject *my_debug1(Py_Class_TsuiBoard *self);
static int *board_init(Py_Class_TsuiBoard *self);

static PyObject *Board_str(Py_Class_TsuiBoard *self);

static PyObject *my_debug1(Py_Class_TsuiBoard *self){
    return Py_BuildValue("[ii]", 0, 0);
};

static PyMethodDef Py_Class_TsuiBoard_methods[] = {
    {"moves", (PyCFunction)board_moves, METH_VARARGS, "(ToT)"},
    {"tesu", (PyCFunction)get_tesu, METH_VARARGS, "(^o^)v"},
    {"rotate", (PyCFunction)rotate_board, METH_VARARGS, "(^q^)"},
    {"push", (PyCFunction)push_move, METH_VARARGS, "(O_O)"},
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
    self->board2->rotate();
    Py_INCREF(Py_None);
    return Py_None;
};

static PyObject *push_move(Py_Class_TsuiBoard *self, PyObject *args){
    PyObject *move_tuple;
    Py_INCREF(Py_None);
    return Py_None;
    if (!PyArg_ParseTuple(args, "O", move_tuple)) {
        return NULL;
    };
    int move = (int)PyLong_AsLong(PyTuple_GetItem(move_tuple, 0));
    int move_from = (int)PyLong_AsLong(PyTuple_GetItem(move_tuple, 1));
    self->board2->push(move, move_from);
};


static PyObject *get_tesu(Py_Class_TsuiBoard *self){
    return Py_BuildValue("i", self->board2->board[37]);
};
//*/
static PyObject *Board_str(Py_Class_TsuiBoard *self){
    std::string dummy = "Dummy!";
    return PyUnicode_FromFormat(dummy.c_str());
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
};
//*
static int *board_init(Py_Class_TsuiBoard *self){
    self->board2 = new TsuiBoard5();
    return 0;
};
//*/
static PyObject *board_moves(Py_Class_TsuiBoard *self){
    PyObject *pseudo_moves = PySet_New(NULL);
    int moves1[200] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };//成でない「指す」手。移動先*方向=25*8=200
    int moves2[25] = {
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0,0,0
    };//可成域への成る手。移動先*方向=5*5=25(+200)
    int moves3[60] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };//非可成域への成る手。移動先*方向=20*3=(+225)
    int moves4[125] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };//打つ手。移動先*駒種=25*5=125(+285)
    //計410
    self->board2->pseudo_moves1(moves1);
    self->board2->pseudo_moves2(moves2);
    self->board2->pseudo_moves3(moves3);
    self->board2->pseudo_moves4(moves4);
    for(int i = 0;i < 200;i++){
        if(moves1[i]){
            PyObject *tuple = Py_BuildValue("(ii)", i, moves1[i]);
            if(PySet_Add(pseudo_moves, tuple)){
                return tuple;
            };
        };
    };
    for(int i = 0;i < 25;i++){
        if(moves2[i]){
            PyObject *tuple = Py_BuildValue("(ii)", i + 200, moves2[i]);
            if(PySet_Add(pseudo_moves, tuple)){
                return tuple;
            };
        };
    };
    return pseudo_moves;
    for(int i = 0;i < 60;i++){
        if(moves3[i]){
            PyObject *tuple = Py_BuildValue("(ii)", i + 225, moves3[i]);
            if(PySet_Add(pseudo_moves, tuple)){
                return tuple;
            };
        };
    };
    for(int i = 0;i < 125;i++){
        if(moves4[i]){
            PyObject *tuple = Py_BuildValue("(ii)", i + 285, 1);
            if(PySet_Add(pseudo_moves, tuple)){
                return tuple;
            };
        };
    };
    return pseudo_moves;
};
