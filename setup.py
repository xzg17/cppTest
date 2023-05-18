from distutils.core import setup, Extension
import os

os.environ['CC'] = 'gcc'

src_dir = 'src'

ext_modules = [Extension('MyRange', [src_dir + '/MyClass.cpp'], language='c++')]

setup(
  name='cppTest',
  ext_modules = ext_modules,
  url="https://github.com/xzg17/cppTest"
)
