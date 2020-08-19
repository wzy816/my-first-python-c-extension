# my first python c extension

python 提供了用 c 语言编写 extension 的功能，可借助 c 提升性能。

本项目借用 factorial 函数，探索了两种编写 extension 的方式，并进行了测试。


## 方法 1
用 c 语言编写完整的模块和函数代码

1. 创建 ext.c 文件，编写 ext 模块代码和方法 fac
2. 创建 setup.py 文件，编写模块生成
3. 运行 `python3 setup.py build_ext --inplace` 生成
  - ext.cpython-36m-darwin.so
  - build/temp.macosx-10.7-x86_64-3.6/ext.o

## 方法 2
利用了 ctypes，省略了 c 中编写模块的代码部分，但是 python 代码调用时增加了代码

1. 创建fac.c 文件，编写 fac 函数
2. 运行`gcc -shared -fPIC fac.c -o fac.so` 生成 fac.so

## 测试
运行 `python3 test.py`

结果

    python method
    	result: 2432902008176640000
    	time: 4.6253204345703125e-05
    method 1
    	result: 2432902008176640000
    	time: 6.198883056640625e-06
    method 2
    	result: 2432902008176640000
    	time: 1.4066696166992188e-05
