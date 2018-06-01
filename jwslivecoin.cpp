#include "jwslivecoin.h"

#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include "jticker.h"

JWSLivecoin::JWSLivecoin(QObject *parent) : QObject(parent)
{
    QObject::connect(WSocket,&QWebSocket::connected,this,&JWSLivecoin::connected);
    QObject::connect(WSocket,&QWebSocket::textMessageReceived,this,&JWSLivecoin::textMessageReceived);
}

JWSLivecoin::~JWSLivecoin()
{
    disconnect();
    delete WSocket;


}

void JWSLivecoin::connect()
{
    WSocket->open(QUrl(QStringLiteral("ws://ws.api.livecoin.net/ws/beta")));
}

void JWSLivecoin::disconnect()
{
    WSocket->close();
    QObject::connect(WSocket,&QWebSocket::disconnected,this,disconnected);
}

void JWSLivecoin::disconnected()
{
    qDebug()<<"disconnected!";
    QObject::disconnect(WSocket,&QWebSocket::disconnected,this,disconnected);
}

void JWSLivecoin::connected()
{
    qDebug()<<"Connected!";
    QJsonDocument doc;
    QJsonObject root;
    root.insert("channelType","ticker");
    root.insert("symbol","ETH/USD");
    root.insert("frequency",QJsonValue());
    root.insert("depth",QJsonValue());

    QJsonObject sub;
    sub.insert("Subscribe",QJsonValue(root));

    doc.setObject(sub);
    //qDebug()<<doc.toJson();
    WSocket->sendTextMessage(doc.toJson());
}

void JWSLivecoin::textMessageReceived(QString message)
{
    qDebug()<<message;
    if(!(message==QString("")))
    {
        JTicker ticker;
        QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
        QJsonObject root = doc.object();
        if(!root.value("operation").isObject())//Игнорирую первое сообщение
        {
            ticker.setBidAndAsk(root.value("bestBid").toDouble(),root.value("bestAsk").toDouble());
        }
    }else{

    }

}

