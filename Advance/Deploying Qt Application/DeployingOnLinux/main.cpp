#include <QCoreApplication>
#include <QDebug>
/*

    Linux deploy
    Download linuxdeployqt
    https://github.com/probonopd/linuxdeployqt
    Make it executable



    Notice this is an app image!
    https://appimage.org/

    Download appimagetool
    https://github.com/AppImage/AppImageKit
    https://github.com/AppImage/AppImageKit/releases
    https://github.com/AppImage/AppImageKit/wiki/Creating-AppImages


    Build the app in release mode
    Navigate to the build dir and do an ldd on the binary
    ldd <PATH TO BINARY>
    show the dependancies

    clean the project
    remove the make file

    run linuxdeployqt-continuous-x86_64.AppImage
    ./linuxdeployqt-6-x86_64.AppImage <PATH TO BINARY> -qmake=<PATH TO QMAKE> -unsupported-allow-new-glibc


    copy the icon.png

    Make a desktop file (your_app.desktop)
    ------------------
[Desktop Entry]
Type=Application
Name=Qt Core Advanced 6-3
Comment=Qt Tutorial
Exec=qtca-6-3
Icon=icon
Categories=Office;
    ------------------

    Run appimagetool
    ./appimagetool-x86_64.AppImage <PATH TO APP FOLDER>


*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef QT_DEBUG
  qDebug() << "Running a debug build";
#else
  qDebug() << "Running a release build";
#endif

    return a.exec();
}
