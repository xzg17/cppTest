from distutils.core import setup, Extension
import os

os.environ['CC'] = 'gcc'

src_dir = 'src'

ext_modules = [Extension('MtRange', [src_dir + '/MyRange.cpp'], language='c++')]

setup(
  name='cppTest',
  ext_modules = ext_modules,
  url="https://github.com/xzg17/cppTest"
)
