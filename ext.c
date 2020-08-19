#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
这个模块包括 ext 模块的 fac 函数

python 代码中调用该函数的示例如下：
import ext
ext.fac(1)

内部传递机制大致是
1. 把 python 传递给 c
2. c 内部调用相关函数和计算
3. 把结果转换成 python 对象 返回给 python
*/
long long fac(long n) {
  if (n < 2)
    return (1);
  return (n)*fac(n - 1);
}

/* fac wrapper function */
static PyObject *ext_fac(PyObject *self, PyObject *args) {
  long long num;

  /* parse arg */
  if (!PyArg_ParseTuple(args, "L", &num))
    return NULL;

  /* compute fac and return result*/
  return (PyObject *)Py_BuildValue("L", fac(num));
}

/* define module methods */
static PyMethodDef ExtMethods[] = {{"fac", ext_fac, METH_VARARGS, "fac"},
                                   {NULL, NULL, 0, NULL}};

/* define module structure */
static struct PyModuleDef ext_module = {PyModuleDef_HEAD_INIT, "ext",
                                        "A module containing fac method", -1,
                                        ExtMethods};

/* define module init */
PyMODINIT_FUNC PyInit_ext() { return PyModule_Create(&ext_module); }
