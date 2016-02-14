#include "gtserver.h"

// Конструктор класса
GTServer::GTServer(QObject *parent) : QObject(parent){
    nPort = 2323;

    server = new QTcpServer;
    connect(server, SIGNAL(newConnection()), this, SIGNAL(signalNewConnect()));
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnectProc()));
}

// Деструктор класса
GTServer::~GTServer(){
    server->close();
    delete server;
}

// Запуск сервера
bool GTServer::start(){

    if(!server->listen(QHostAddress::Any, nPort)){
        server->close();
        return false;
    }else{

        return true;
    }
}

// Остановка сервера
void GTServer::stop(){
    server->close();
}

// Обработка нового входящего подключения
void GTServer::newConnectProc(){
    QTcpSocket* clientSocket = server->nextPendingConnection();

    //connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void GTServer::readClient(){
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    QDataStream in(clientSocket);
    //in.setVersion(QDataStream::Qt_4_2);
    quint8 buf;

    while (clientSocket->bytesAvailable()){
        qDebug() << "Bytes available:" << clientSocket->bytesAvailable();
        in >> buf;
        qDebug() << "Value: " << buf;
    }
}

// DEBUG
void GTServer::debugSlot(){
    qDebug() << "test";
}

