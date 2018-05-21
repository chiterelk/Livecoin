#include "jlivecoin.h"
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JLivecoin::JLivecoin(QObject *parent) : QObject(parent)
{
    connect(QNAM,&QNetworkAccessManager::finished,this,&JLivecoin::gotData);
}

void JLivecoin::getExchengeTicker()
{
    QNetworkRequest requsest;
    requsest.setUrl(QUrl(baseUrl+"/exchange/ticker"));
    QNAM->get(requsest);
}

void JLivecoin::getExchengeTicker(QString currencyPair)
{
    QNetworkRequest requsest;
    requsest.setUrl(QUrl(baseUrl+"/exchange/ticker?currencyPair="+currencyPair));
    QNAM->get(requsest);
}

void JLivecoin::gotData(QNetworkReply *reply)
{
    qDebug()<<reply->url().toString();
    if(!reply->error())
    {
        qDebug()<<"Good";

        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonArray arr = doc.array();


        qDebug()<<arr.at(1).toObject();
    }else{
        qDebug()<<"Error: "<<reply->errorString()<<'.';
    }
}
