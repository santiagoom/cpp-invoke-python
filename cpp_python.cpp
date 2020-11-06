//
// Created by admin on 2020/11/4.
//

#include <Python.h>

using namespace std;


int main() {

    Py_Initialize();              //初始化，创建一个Python虚拟环境
    PyRun_SimpleString("print('hello!')");
    Py_Finalize();
    return 0;
}



//int main()
//{
//    Py_Initialize();              //初始化，创建一个Python虚拟环境
//    if (Py_IsInitialized())
//    {
//        PyObject* pModule = NULL;
//        PyObject* pFunc = NULL;
//        pModule = PyImport_ImportModule("test_python");  //参数为Python脚本的文件名
//        if (pModule)
//        {
//            pFunc = PyObject_GetAttrString(pModule, "Hello");   //获取函数
//            PyEval_CallObject(pFunc, NULL);           //执行函数
//        }
//        else
//        {
//            printf("导入Python模块失败...\n");
//        }
//    }
//    else
//    {
//        printf("Python环境初始化失败...\n");
//    }
//    Py_Finalize();
//}