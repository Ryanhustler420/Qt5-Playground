#include "logger.h"

QString logger::filename = QDir::currentPath() + QDir::separator() + "log.txt";
bool logger::logging = false;

static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

logger::logger()
{

}

logger::logger(QObject *parent)
{

}

void logger::attach()
{
    logger::logging = true;
    qInstallMessageHandler(logger::handler);
}

void logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (logger::logging) {
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

        QFile file(logger::filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream ts(&file);
            ts << QDateTime::currentDateTime().toString() << " - " << txt << " file: " << context.file << " line " << context.line << endl;
            ts.flush();
            file.close();
        }
    }

    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg); // default message handler i.e qInfo(), qWarning(), etc. if above didn't worked out the above custom message handler.
}
