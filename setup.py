from distutils.core import setup, Extension

setup(
    name='ext',
    description='',
    ext_modules=[Extension('ext', sources=['ext.c'])],
)
