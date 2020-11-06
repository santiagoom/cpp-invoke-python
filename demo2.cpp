//
// Created by admin on 2020/11/5.
//

#include <iostream>
#include <Python.h>
//#include <numpy.h>
#include<string>
using namespace std;
//#include <afx.h>
int main()
{
    //此处代码我进行注释，个人认为电脑安装python，设有系统环境变量，此处应该可以省略，但是如果部署电脑不安装python，应该需要进行配置，此处还未验证，后续会更新。
    //CString PythonPath = _T("C:\Programs\Python37-32");
    //Py_SetPythonHome(PythonPath);//配置python3的环境变量
    Py_Initialize();    // 初始化

    // 将Python工作路径切换到待调用模块所在目录，一定要保证路径名的正确性
//    string path = "E:\\work\\SLGEM\\output\\Debug";
    PyRun_SimpleString("import sys");
//    PyRun_SimpleString(path.c_str());
//    PyRun_SimpleString("import sys");
//    PyRun_SimpleString("pip list;");
//    PyRun_SimpleString("sys.path.append('D:\\gitrepoe\\cpp-invoke-python\\cmake-build-release\\')");

    // 加载模块
    PyObject* pModule = PyImport_ImportModule("PythonTest");//此处是python文件名
    if (!pModule) // 加载模块失败
    {
        return -1;
    }

    // 加载函数
    PyObject* pv = PyObject_GetAttrString(pModule, "Test_add");//此处是python文件中的函数名称
    if (!pv || !PyCallable_Check(pv))  // 验证是否加载成功
    {
        return -2;
    }

    // 设置参数
    PyObject* args = PyTuple_New(2);   // 2个参数

    //构建两个参数
    PyTuple_SetItem(args, 0, Py_BuildValue("i", 8));//0--序号,i表示创建int型变量
    PyTuple_SetItem(args, 1, Py_BuildValue("i", 6));//1--序号,i表示创建int型变量

    // 调用函数
    PyObject* pRet = PyObject_CallObject(pv, args);

    //将返回值转换为int类型
    int result;
    PyArg_Parse(pRet, "i", &result);//i表示转换成int型变量
    cout << "6 + 8 = " << result << endl;

    Py_Finalize();

}
