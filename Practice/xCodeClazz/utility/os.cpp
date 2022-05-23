#include "os.h"

Os::Os(CommonSuperClass *parent) : CommonSuperClass(parent)
{

}

bool Os::openIPConfig()
{
    QProcess ipconfig;
    ipconfig.start("ipconfig", QStringList() << "-all");

    if (!ipconfig.waitForStarted()) return false;

    ipconfig.write("qt rocks");
    ipconfig.closeWriteChannel();

    if (!ipconfig.waitForFinished()) return false;
    QByteArray result = ipconfig.readAll();

    qInfo() << "Result: " << result;
    return true;
}

void Os::systemInfo()
{
    QSysInfo sys;

    qInfo() << "System Info";
    qInfo() << "Boot Id: " << sys.bootUniqueId();
    qInfo() << "Build: " << sys.buildAbi();
    qInfo() << "Cpu: " << sys.buildCpuArchitecture();
    qInfo() << "Kernel: " << sys.kernelType();
    qInfo() << "Version: " << sys.kernelVersion();
    qInfo() << "Mac: " << sys.macVersion();
    qInfo() << "Window: " << sys.windowsVersion();
    qInfo() << "Host: " << sys.machineHostName();
    qInfo() << "Product: " << sys.prettyProductName();
    qInfo() << "Type: " << sys.productType();
    qInfo() << "Version: " << sys.productVersion();

    #if defined W_OS_WIN64
        qInfo() << "Windows code here";
    #elif Q_OS_LINUX
        qInfo() << "Linux code here";
    #elif defined (W_OS_MACX)
        qInfo() << "Mac code here";
    #else
        qInfo() << "Unknown code here";
    #endif
}
