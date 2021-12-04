#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>
#include <QMainWindow>

class gps : public QMainWindow


{
public:
    QGeoCoordinate coord;
    gps()
    {
       QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(0);
       source->setUpdateInterval(1000);

       if(source)
       connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)), this, SLOT(positionUpdated(QGeoPositionInfo)));
       source->startUpdates();
    }

    inline void positionUpdated(const QGeoPositionInfo &info);
    QGeoCoordinate showcoord()     // Getter
    {
        return coord;
    }

};

void gps::positionUpdated(const QGeoPositionInfo &info)
{
    coord = info.coordinate();
}
