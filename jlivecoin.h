#ifndef JLIVECOIN_H
#define JLIVECOIN_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>


class JLivecoin : public QObject
{
    Q_OBJECT
public:
    explicit JLivecoin(QObject *parent = nullptr);
    void getExchengeTicker();
    void getExchengeTicker(QString currencyPair);
private:
    QNetworkAccessManager *QNAM = new QNetworkAccessManager(this);
    QString baseUrl = "https://api.livecoin.net";

    void gotData(QNetworkReply *reply);

signals:

public slots:
};

#endif // JLIVECOIN_H
