#include <Python.h>
#include <string.h>

static PyObject *
spam_string(PyObject *self, PyObject *args)
{
    char *arg;
    if(!PyArg_ParseTuple(args, "s", &arg))
        return NULL;
    char *spam = "spam";
    strncpy(arg, spam, strlen(spam));
    return PyLong_FromLong(0);
}

static PyMethodDef SpamMethods[] = {
    {"spammify", spam_string, METH_VARARGS, "turn a string into spam"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",
    NULL,
    -1,
    SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
    return PyModule_Create(&spammodule);
}

