#ifndef JWSBITFINEX_H
#define JWSBITFINEX_H

#include <QObject>
#include <QWebSocket>


class JWSBitfinex : public QObject
{
    Q_OBJECT
public:
    explicit JWSBitfinex(QObject *parent = nullptr);
    ~JWSBitfinex();
    void connect();
    void unsubscribe(int channelId);
private:
    QWebSocket *WSocket = new QWebSocket();
    void connected();
    void textMessageReceived(QString message);
signals:

public slots:
};

#endif // JWSBITFINEX_H
