#ifndef MYSERVER_H
#define MYSERVER_H

#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QMap>
#include <QSet>

class InterLayer;

class MyServer : public QTcpServer
{
    Q_OBJECT
    public:
        MyServer(QObject *parent=0);
        ~MyServer();
        void setInterLayer(InterLayer *interLayer);
        void sendData(QTcpSocket *,QByteArray);

    private slots:
        void readyRead();
        void disconnected();

    protected:
       void incomingConnection(int socketfd);

    private:
       InterLayer *_interLayer;
};

#endif // MYSERVER_H
