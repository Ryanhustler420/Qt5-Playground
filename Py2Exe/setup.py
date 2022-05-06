from distutils.core import setup # Need this to handle modules
import py2exe 
import math # We have to import all modules used in our program

# setup(console=['code.py']) # Calls setup function to indicate that we're dealing with a single console application
# setup(windows=['code.py'])

setup(
	options = {'py2exe': {'bundle_files': 1, 'compressed': True}},
	console=['code.py'],
	zipfile = None,
)