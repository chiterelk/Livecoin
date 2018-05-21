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
    if(!reply->error())
    {
        qDebug()<<reply->url().toString();
        QString url = reply->url().toString();
        if(url.indexOf("/exchange/ticker"))
        {
            if(!(url.indexOf("currencyPair=") == -1))
            {
                qDebug()<<"1";
                QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
                QJsonObject root = doc.object();
                qDebug()<<root;

            }else{
                qDebug()<<"2";
                QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
                QJsonArray root = doc.array();
                qDebug()<<root.at(0).toObject();
            }

        }
    }else{
        qDebug()<<"Error: "<<reply->errorString()<<'.';
    }
}
