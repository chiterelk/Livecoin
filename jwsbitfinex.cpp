#include "jwsbitfinex.h"
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JWSBitfinex::JWSBitfinex(QObject *parent) : QObject(parent)
{

    QObject::connect(WSocket,&QWebSocket::connected,this,&JWSBitfinex::connected);
    QObject::connect(WSocket,&QWebSocket::textMessageReceived,this,&JWSBitfinex::textMessageReceived);
}

JWSBitfinex::~JWSBitfinex()
{
    delete WSocket;
}

void JWSBitfinex::connect()
{
    qDebug()<<"I am here!";
    WSocket->open(QUrl("wss://api.bitfinex.com/ws/2"));
}

void JWSBitfinex::unsubscribe(int channelId)
{
    QJsonDocument doc;
    QJsonObject root;
    root.insert("event",QJsonValue(QString("unsubscribe")));
    root.insert("chanId",QJsonValue(channelId));
    doc.setObject(root);
    WSocket->sendTextMessage(doc.toJson());
}

void JWSBitfinex::connected()
{
    qDebug()<<"Conected!";
    QJsonDocument doc;
    QJsonObject root;
    root.insert("event",QJsonValue(QString("subscribe")));
    root.insert("channel",QJsonValue(QString("ticker")));
    root.insert("symbol",QJsonValue(QString("tBTCUSD")));
    doc.setObject(root);
    WSocket->sendTextMessage(doc.toJson());

}

void JWSBitfinex::textMessageReceived(QString message)
{
    //qDebug()<<message;
    QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
    QJsonArray root = doc.array();
    qDebug()<<root.at(0).toInt();
}
