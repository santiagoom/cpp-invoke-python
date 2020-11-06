//
// Created by admin on 2020/11/5.
//

#include <stdio.h>
#include <Python.h>
#include <iostream>


using namespace std;

int main() {
    PyObject *pName, *pModule, *pTmp, *pFunc;
    char *sTmp;
    int data;

    Py_Initialize();
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault("executable file")); //Path of executable file
    pName = PyUnicode_DecodeFSDefault("test1");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "test");
        pTmp = PyObject_CallObject(pFunc, NULL);
        int pp = 0;
        cin >> pp;

    }
    Py_Finalize();

    return 0;
}