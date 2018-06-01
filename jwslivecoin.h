#ifndef JWSLIVECOIN_H
#define JWSLIVECOIN_H

#include <QtWebSockets/QtWebSockets>
#include <QObject>


class JWSLivecoin : public QObject
{
    Q_OBJECT
public:
    explicit JWSLivecoin(QObject *parent = nullptr);
    ~JWSLivecoin();
    void connect();
    void disconnect();
    void unsubscribe(int channelId);

private:
    QWebSocket *WSocket = new QWebSocket();
    void disconnected();
    void connected();
    void textMessageReceived(QString message);
signals:

public slots:
};

#endif // JWSLIVECOIN_H
