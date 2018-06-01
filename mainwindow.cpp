#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wsbitfitex->connect();
    connect(livecoin,&JLivecoin::gotMaxBidMinAsk,this,&MainWindow::gotMaxBidMinAsk);
    //connect(timer,&QTimer::timeout,this,&MainWindow::on_pushButton_clicked);
    connect(livecoin,&JLivecoin::gotBalance,this,&MainWindow::gotBalance);
    connect(livecoin,&JLivecoin::openedSellLimit,this,&MainWindow::openedSellLimit);
    connect(livecoin,&JLivecoin::gotOrder,this,gotOrder);
    //wslivecoin->connect();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        livecoin->getExchengeMaxBidMinAsk();
    }else{
        livecoin->getExchengeMaxBidMinAsk(ui->lineEdit->text());
    }
    timer->setInterval(1000);
    timer->start();
}

void MainWindow::gotMaxBidMinAsk(JMaxBidMinAsk maxBidMinAsk)
{
    ui->labelAsk->setText(QString::number(maxBidMinAsk.getMinAsk()));
    ui->labelBid->setText(QString::number(maxBidMinAsk.getMaxBid()));

}

void MainWindow::gotBalance(QVector<JBalance *> _balance)
{
    for(int i = 0;i<_balance.count();i++)
    {
        qDebug()<<_balance.at(i)->getCurrency();
        qDebug()<<"Total: "<<_balance.at(i)->getTotal()<<";";
        qDebug()<<"Avalible: "<<_balance.at(i)->getAvailable()<<";";
        qDebug()<<"Trade: "<<_balance.at(i)->getTrade()<<";";
        qDebug()<<"AvailableWithdrawal: "<<_balance.at(i)->getAvailableWithdrawal()<<".";
    }
    _balance.clear();
}

void MainWindow::openedSellLimit(double orderId)
{
    qDebug()<<QString::number(orderId,'g',20);
}

void MainWindow::gotOrder(JOrder order)
{
    qDebug()<<order.getId();
    qDebug()<<order.getStatus();
}
void MainWindow::on_pushButton_2_clicked()
{
    livecoin->getPaymentBalances(apiKey,secretKey);
}

void MainWindow::on_pushButton_3_clicked()
{
    livecoin->sellLimit("DOGE/BTC",48.0000000000001,1000,apiKey,secretKey);
}

void MainWindow::on_pushButton_4_clicked()
{
    livecoin->cancelLimit("DOGE/BTC",ui->lineEditOrderId->text().toDouble(),apiKey,secretKey);
}

void MainWindow::on_pushButton_5_clicked()
{
    livecoin->getOrder(ui->lineEditOrder->text().toDouble(),apiKey,secretKey);
}

void MainWindow::on_pushButton_6_clicked()
{

}
