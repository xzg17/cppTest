from distutils.core import setup, Extension
import os

os.environ['CC'] = 'gcc'

src_dir = 'src'

ext_modules = [
  Extension(
    'customZ',
    [src_dir + '/Sample.cpp'],
    language='c++'),
  '''
  Extension(
    'TestZ',
    [src_dir + '/Test.cpp'],
    language='c++')
  #'''
]

setup(
  name='custom',
  ext_modules = ext_modules,
  url="https://github.com/xzg17/cppTest"
)
