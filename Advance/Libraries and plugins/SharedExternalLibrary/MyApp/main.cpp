#include <QCoreApplication>

#include "MyExternalLib_global.h" // this is nessessory, because it will help use to import the blob
#include "myexternallib.h" // this will help us to know the method signature

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create A New Project I.e: MyApp (Run a quick rebuild and see if everything is fine)

    // Create A New Library
    // - New Project > Library > C++ Library > Name That Anything
    // - Open .h file (not the global one) and define one method and also implement that
    // - Run or build on that library so it will create /build folder where .a file will create

    // On this project click on left panel > Add Library > External Library > Select The Library Type (based on os) > Choose the library file (find in build/ of library project) > Next > Finish

    // Bring the .h global.h file into this project
    // Right click on left panel of this project and click add existing files and select all the .h files
    // #include the library header in this file at the above
    // Run a quick rebuild

    MyExternalLib mel;
    mel.greet("Fuck Pakistan");

    return a.exec();
}
