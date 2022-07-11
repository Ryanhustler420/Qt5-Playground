#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/import_single_repo_product.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // save the .sh bash and cron will invoke every 10 minutes
    // what if the software didn't response

    // remove all the crontab
    // resadualling all the crontab
    // remove specific crontab

    // how to dynamically add to crontab using bash script
    // please make sure the debug.log file has json formet on all qt release

    // First Practice RowLayout and Column Layout
    // Then decide which of our layout should build first,
    // Then bring them together and see the responsiveness of the entire application

    return app.exec();
}
