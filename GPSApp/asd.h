#ifndef ASD_H
#define ASD_H

#include <QMainWindow>
#include <QMessageBox>
#include <QApplication>
#include <QNetworkReply>
#include <QGeoLocation>

namespace Ui {
class asd;
}

class asd : public QMainWindow
{
    Q_OBJECT

public:
    explicit asd(QWidget *parent = nullptr);
    ~asd();

signals:
    void transmitNewText(int req);

public slots:
    void getOldText( double longtitude);
    void sendData(double latitude, double longtitude, QString req);
    void getResponse(QNetworkReply *reply);

private:
    Ui::asd *ui;
};

#endif // ASD_H
