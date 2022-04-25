# Create new > Others project > subdirs project
# Right Click On Left Panel Folder > New Sub Project > Application > Console Application
# Right Click On Left Panel Folder > New Sub Project > Library > C++ Library > [name that library mylib]

# Add Few Methods in mylib.h
# Write some code on the implementation of that method

# Right Click On Left Panel Folder > Add Library> Internal Library > Select mylib > Next Next Next Finish
# Now you can import the library in your project as header
# NOTE: you have to right click on your project/library to rebuild else it will not work, anyways this is always a great idea to rebuild your project

TEMPLATE = subdirs

SUBDIRS += \
    myApp \
    mylib
