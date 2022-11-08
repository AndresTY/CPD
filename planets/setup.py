## Cython: setup.py
from distutils.core import setup, Extension
from Cython.Build import cythonize

planets = Extension('planets_cy', ['planets_cy.pyx'])
objects = Extension('planets_object', ['planets_object.pyx'])
exts = (cythonize([planets, objects],
                  compiler_directives={'language_level': "3"}))

setup(ext_modules=exts)
