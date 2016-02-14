#ifndef GTSERVER_H
#define GTSERVER_H


#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtSerialPort/QtSerialPort>

#include <QDebug>

class GTServer: public QObject
{
    Q_OBJECT

private:

    QTcpServer *server;
    QSerialPort *dev;

    int nPort;

public:

    explicit GTServer(QObject *parent = 0);
    ~GTServer();
    bool start();
    void stop();

    QString getSReadBuffer();

signals:
    void signalNewConnect();

    void debugSignal();

public slots:
    void newConnectProc();
    void readClient();

    void debugSlot();
};

#endif // GTSERVER_H
