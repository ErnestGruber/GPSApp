#include <QApplication>
#include <QtQml>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include <QMessageBox>

#include "gpstrack.h"
#include "gpstrackstat.h"
#include "storagemodel.h"
#include "filesystemmodel.h"
#include "asd.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<GPSTrack>("org.simplegpstrack.gpstrack", 1, 0, "GPSTrack");
    qmlRegisterType<GPSTrackStat>("org.simplegpstrack.gpstrack", 1, 0, "GPSTrackStat");
    qmlRegisterType<StorageModel>("org.simplegpstrack.gpstrack", 1, 0, "StorageModel");
    qmlRegisterType<FileSystemModel>("org.simplegpstrack.gpstrack", 1, 0, "FileSystemModel");

    QApplication app(argc, argv);


    QQmlApplicationEngine engine;
    asd ASD;
    //ASD.show();
     //Создаём ядро приложения
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("ASD", &ASD);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    return app.exec();
}
