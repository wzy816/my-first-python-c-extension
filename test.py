"""performance test for fac."""

from time import time
from ext import fac as fac1
from ctypes import cdll, c_int64


# python method
def fac(n):
    """
    Factorial 函数.

    Args:
        n 整数
    Returns:
        n 的阶乘
    """
    if n < 2:
        return n
    return n * fac(n-1)


start = time()
print("python method")
print("\tresult:", fac(20))
print("\ttime:", time() - start)

# method 1
print("method 1")
start = time()
print("\tresult:", fac1(20))
print("\ttime:", time() - start)

# method 2
print("method 2")
fac2 = cdll.LoadLibrary(
    '/Users/zhiyang.wang/Desktop/my-first-python-c-extension/fac.so').fac
fac2.restype = c_int64
start = time()
print("\tresult:", fac2(20))
print("\ttime:", time() - start)
