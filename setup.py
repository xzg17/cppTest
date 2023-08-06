from distutils.core import setup, Extension
import os

os.environ['CC'] = 'gcc'

src_dir = 'src'

#ext_modules = [Extension('customZ',[src_dir + '/Sample.cpp'])]
#ext_modules = [Extension('customZ',[src_dir + '/Test.cpp'])]
ext_modules = [Extension('customZ',[src_dir + '/Test.cpp']),Extension('np_nd_DIDS',[src_dir + '/Board.cpp'])]
setup(
  name='custom',
  ext_modules = ext_modules,
  url="https://github.com/xzg17/cppTest"
)
