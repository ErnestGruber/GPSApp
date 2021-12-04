#include "asd.h"
#include "ui_asd.h"
#include <QStringList>
#include <QString>
#include <QGuiApplication>
#include <QtQml>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include <QQmlContext>
#include <QMessageBox>
#include <QApplication>
#include <QGeoAddress>
#include <QGeoCodingManager>
#include <QGeoCoordinate>
#include <QGeoLocation>
#include <QGeoServiceProvider>
#include <iostream>
#include "gps.h"

using namespace std;

asd::asd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::asd)
{
    ui->setupUi(this);
}

void asd::getOldText(double longtitude){


     QMessageBox::critical(this, " Critical Error", QString::number(longtitude), QMessageBox::Ok, 0);
}

void asd::sendData(double latitude, double longitude, QString req)
{

    int b = 17;
    QUrl serviceUrl = QUrl("http://51.250.23.232/api/gps/");
    b = req.toInt();
    if(b<18)
    {
        b = 17;
    }
    //QByteArray json = " {\"gps\":{\"id\":\"3\", \"lat\":\"q\",\"lon\":\"1.4\", \"power\":\"24\", \"id_req\":\"2021-12-03T19:10:53Z\"}}";
    //QByteArray json = "{ \"key\":\"QJsonValue::fromVariant("")\" }";
    QJsonObject recordObject;
    QJsonObject objObject;
    objObject.insert("id", b);
    objObject.insert("lat", latitude);
    objObject.insert("lon", longitude);
    objObject.insert("power", 17);
    objObject.insert("id_req", "2021-12-04T02:16:24Z");
    recordObject.insert("gps",objObject);
    QJsonDocument doc(recordObject);
    QByteArray jsonString = doc.toJson(QJsonDocument::Indented);


    QNetworkRequest request(QUrl("http://51.250.23.232/api/"));
    QNetworkAccessManager *mngr = new QNetworkAccessManager(this);

   // QUrlQuery postData;
    //postData.addQueryItem("phones", QString::number());

    connect(mngr, SIGNAL(finished(QNetworkReply*)), this, SLOT(getResponse(QNetworkReply*)));
    mngr->get(request);
    QNetworkRequest networkRequest(serviceUrl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    mngr->post(networkRequest, jsonString);

    b++;

    emit transmitNewText(b);

}
void asd::getResponse(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}

asd::~asd()
{
    delete ui;
}
