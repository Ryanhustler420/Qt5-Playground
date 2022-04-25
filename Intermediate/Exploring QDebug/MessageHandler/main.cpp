#include <QCoreApplication>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QFile>

const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

void lhandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QString txt;
    switch (type) {
        case QtInfoMsg:
            txt = QString("Info: %1").arg(msg);
            break;
        case QtDebugMsg:
            txt = QString("Info: %1").arg(msg);
            break;
        case QtCriticalMsg:
            txt = QString("Info: %1").arg(msg);
            break;
        case QtFatalMsg:
            txt = QString("Info: %1").arg(msg);
            break;
        default:
            break;
    }

    QFile file("log.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream stream(&file);
        stream << QDateTime::currentDateTime().toString() << " - " << txt << " file: " << context.file << " line " << context.line << " \r\n";
        stream.flush();
        file.close();
    }

    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInstallMessageHandler(lhandler);

    qCritical() << "Fucked Up System";
    return a.exec();
}
