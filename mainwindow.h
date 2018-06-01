#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jlivecoin.h"
#include "jwslivecoin.h"
#include "jwsbitfinex.h"
#include "jorder.h"
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString apiKey = "KH91fPFZ2c4fVeQVr4FtnadbaeYAg9YR";
    QString secretKey = "";

private slots:
    void on_pushButton_clicked();
    void gotMaxBidMinAsk(JMaxBidMinAsk maxBidMinAsk);
    void gotBalance(QVector<JBalance*>);
    void openedSellLimit(double orderId);
    void gotOrder(JOrder order);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    JLivecoin *livecoin = new JLivecoin(this);
    JWSLivecoin *wslivecoin = new JWSLivecoin(this);
    JWSBitfinex *wsbitfitex = new JWSBitfinex(this);
    QTimer * timer = new QTimer(this);

};

#endif // MAINWINDOW_H
