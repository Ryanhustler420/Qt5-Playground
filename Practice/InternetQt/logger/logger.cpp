#include "logger.h"

bool Logger::logging = false;
bool Logger::dirty_console = false;

QString Logger::filename = "log.txt";
QString Logger::filepath = QDir::currentPath() + QDir::separator();

static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

Logger::Logger()
{

}

Logger::Logger(QObject *parent) : QObject(parent)
{

}

void Logger::attach()
{
    Logger::logging = true;
    Logger::dirty_console = true;
    qInstallMessageHandler(Logger::handler);
}

void Logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (Logger::logging) {
        QString txt;
        switch (type) {
        case QtInfoMsg:
            txt = QString("\"\"QtInfoMsg::\n\n%1\n\n\"\"").arg(msg);
            break;
        case QtDebugMsg:
            txt = QString("\"\"QtDebugMsg::\n\n%1\n\n\"\"").arg(msg);
            break;
        case QtCriticalMsg:
            txt = QString("\"\"QtCriticalMsg::\n\n%1\n\n\"\"").arg(msg);
            break;
        case QtFatalMsg:
            txt = QString("\"\"QtFatalMsg::\n\n%1\n\n\"\"").arg(msg);
            break;
        case QtWarningMsg:
            txt = QString("\"\"QtWarningMsg::\n\n%1\n\n\"\"").arg(msg);
            break;
        default:
            break;
        }

        QFile file(getPath());
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream ts(&file);
            ts << QDateTime::currentDateTime().toString() << " - File[" << context.file << "]" << " - Line[" << context.line << "]" << endl << txt << endl << endl << endl;
            ts.flush();
            file.close();
        }
    }
    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, Logger::dirty_console ? msg : ""); // default message handler i.e qInfo(), qWarning(), etc. if above didn't worked out the above custom message handler.
}

void Logger::setPath(QString path, QString name)
{
    Logger::filepath = path;
    Logger::filename = name;
    qInfo () << "Dumping Files @" << getPath() << Logger::logging;
}

QString Logger::getPath()
{
    return Logger::filepath + QDir::separator() + Logger::filename;
}
