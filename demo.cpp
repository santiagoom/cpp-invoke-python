//
// Created by admin on 2020/11/5.
//

#include <iostream>
#include <Python.h>
#include<string>
using namespace std;
int main()
{
    Py_Initialize();//使用python之前，要调用Py_Initialize();这个函数进行初始化
    if (!Py_IsInitialized())
    {
        printf("初始化失败！");
        return 0;
    }

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");//这一步很重要，修改Python路径


    PyObject * pModule = NULL;//声明变量
    PyObject * pFunc1 = NULL;// 声明变量
    PyObject * pFunc2 = NULL;// 声明变量
    PyObject * pFunc3 = NULL;// 声明变量
    pModule = PyImport_ImportModule("mytest");//这里是要调用的文件名hello.py
    if (pModule == NULL)
    {
//        cout << "没找到" << endl;
    };
    //1
    pFunc1 = PyObject_GetAttrString(pModule, "zip_file");//这里是要调用的函数名
    PyEval_CallObject(pFunc1, NULL);//调用无参数无返回值的python函数

//    2
    pFunc2 = PyObject_GetAttrString(pModule, "zip_file");//这里是要调用的函数名
    string readpath = R"(C:\Users\admin\Desktop\TestData)";
    string writepath = R"(C:\Users\admin\Desktop\TestData.zip)";
    PyObject* args = Py_BuildValue("ss", readpath.c_str(), writepath.c_str());//给python函数参数赋值

    PyObject_CallObject(pFunc2, args);//调用函数
    //3
    pFunc3 = PyObject_GetAttrString(pModule, "_getValue");//这里是要调用的函数名
    PyObject* args2 = Py_BuildValue("ii", 28, 103);//给python函数参数赋值

    PyObject* pRet = PyObject_CallObject(pFunc3, args2);//调用函数
    int res = 0;
    PyArg_Parse(pRet, "i", &res);//转换返回类型

    cout << "res:" << res << endl;//输出结果

    Py_Finalize(); // 与初始化对应
    system("pause");
    return 0;

}
